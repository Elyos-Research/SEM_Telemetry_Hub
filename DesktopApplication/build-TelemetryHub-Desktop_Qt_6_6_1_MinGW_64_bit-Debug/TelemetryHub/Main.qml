import QtQuick
import QtQuick.Controls
import QtQuick.Layouts
import Qt.labs.settings
import Qt.labs.platform
import QtQuick.Dialogs
import Qt.labs.qmlmodels
import QtQuick.Controls.Material
import QtQuick3D
import com.Elyos.serial
import com.Elyos.heatPlot
import com.Elyos.track


Window {
    id: mainWindow
    width: 640
    height: 480
    visible: true
    title: qsTr("Elyos Telemetry")
    opacity: 0.9

    property string selectedPort: ""
    property int selectedBaudRate: 0
    property bool isPortOpen: false
    property bool darkMode: false
    //Material.theme: Material.Dark
    color: Material.backgroundColor;
    onDarkModeChanged: windowManager.setDarkMode(darkMode)

    MenuBar {
        Menu {
            title: qsTr("File")
            MenuItem {
                text: qsTr("Open Track...")
                onTriggered: { onClicked: fileDialog.open() }
            }
            MenuItem {
                text: qsTr("Recent Tracks")
                // onTriggered: {  }
            }
            Menu {
                title: qsTr("Preferences")
                Menu {
                    title: qsTr("Appearance")
                    MenuItem {
                        id: lightModeSelector
                        text: qsTr("Light Mode")
                        checkable: true
                        checked: !mainWindow.darkMode
                        onTriggered: {
                            mainWindow.darkMode = false
                        }
                    }
                    MenuItem {
                        id: darkModeSelector
                        text: qsTr("Dark Mode")
                        checkable: true
                        checked: mainWindow.darkMode
                        onTriggered: {
                            mainWindow.darkMode = true
                        }
                    }
                }
            }
        }
        Menu {
            title: qsTr("Serial")
            Menu {
                id: portMenu
                title: qsTr("Port")
                ListModel {
                    id: portListModel
                    ListElement { portName: qsTr("None") } // Initial "None" item
                }
                Repeater {
                    model: portListModel
                    delegate: MenuItem {
                        text: portName
                        onTriggered: {
                            SerialHandle.setComPort(portName);
                            mainWindow.selectedPort = portName === qsTr("None") ? "" : portName;
                        }
                    }
                }
                onAboutToShow: {
                    portListModel.clear();
                    portListModel.append({"portName": qsTr("None")}); // Re-add "None" item
                    var ports = SerialHandle.availablePorts();
                    for (var i = 0; i < ports.length; ++i) {
                        portListModel.append({"portName": ports[i]});
                    }
                }
            }
            Menu {
                title: qsTr("Baud Rate")
                MenuItem {
                    text: qsTr("None")
                    onTriggered: {
                        SerialHandle.setBaudRate("0");
                        mainWindow.selectedBaudRate = 0;
                    }
                }
                MenuItem {
                    text: qsTr("1200")
                    onTriggered: {
                        SerialHandle.setBaudRate("1200");
                        mainWindow.selectedBaudRate = 1200;
                    }
                }
                MenuItem {
                    text: qsTr("2400")
                    onTriggered: {
                        SerialHandle.setBaudRate("2400");
                        mainWindow.selectedBaudRate = 2400;
                    }
                }
                MenuItem {
                    text: qsTr("4800")
                    onTriggered: {
                        SerialHandle.setBaudRate("4800");
                        mainWindow.selectedBaudRate = 0;
                    }
                }
                MenuItem {
                    text: qsTr("9600")
                    onTriggered: {
                        SerialHandle.setBaudRate("9600");
                        mainWindow.selectedBaudRate = 9600;
                    }
                }
                MenuItem {
                    text: qsTr("19200")
                    onTriggered: {
                        SerialHandle.setBaudRate("19200");
                        mainWindow.selectedBaudRate = 19200;
                    }
                }
                MenuItem {
                    text: qsTr("38400")
                    onTriggered: {
                        SerialHandle.setBaudRate("38400");
                        mainWindow.selectedBaudRate = 38400;
                    }
                }
                MenuItem {
                    text: qsTr("57600")
                    onTriggered: {
                        SerialHandle.setBaudRate("57600");
                        mainWindow.selectedBaudRate = 57600;
                    }
                }
                MenuItem {
                    text: qsTr("115200")
                    onTriggered: {
                        SerialHandle.setBaudRate("115200");
                        mainWindow.selectedBaudRate = 115200;
                    }
                }
            }
            MenuItem {
                text: qsTr("Serial Monitor")
                onTriggered: {
                    windowManager.createWindow("serialMonitor", "qrc:/TelemetryHub/serialMonitorWindow.qml")
                }
            }
        }
    }
    FileDialog {
        id: fileDialog
        title: "Please choose a CSV file"
        currentFolder: StandardPaths.standardLocations(StandardPaths.DesktopLocation)[0]
        nameFilters: ["CSV files (*.csv)"] // Set name filters to allow only CSV files

        onAccepted: {
            console.log(fileDialog.selectedFile)
            Track.loadData(fileDialog.selectedFile) // Call loadData from Track class
        }
    }
    HeatPlot {
        id: heatPlot
        anchors.fill: parent
        pointSize: 5
        scalingFactor: 1
        padding: 10
        anchors.margins: 50
    }
    RowLayout {
        width: 300
        anchors.top: parent.top
        anchors.right: parent.right
        anchors.topMargin: 10
        anchors.rightMargin: 50
        spacing: 20
        height: connectButton.height
        Item {
            height: connectButton.height
            width: connectButton.width
            Layout.fillHeight: true
            Layout.alignment: Qt.AlignCenter
            Text {
                id: portLabel
                color: isPortOpen ? (darkMode ? "lime" : "green") : (darkMode ? "lightgray" : "black")
                text: "Port: " + (selectedPort !== "" ? selectedPort : "None")
                anchors.verticalCenter: parent.verticalCenter
            }
        }
        Item {
            height: connectButton.height
            width: connectButton.width
            Layout.fillHeight: true
            Layout.alignment: Qt.AlignCenter
            Text {
                id: baudRateLabel
                color: isPortOpen ? (darkMode ? "lime" : "green") : (darkMode ? "lightgray" : "black")
                text: "Baud Rate: " + (selectedBaudRate !== 0 ? selectedBaudRate.toString() : "None")
                anchors.verticalCenter: parent.verticalCenter
            }
        }
        Item {
            height: connectButton.height
            width: connectButton.width
            Layout.alignment: Qt.AlignRight
            Button{
                id: connectButton
                text: isPortOpen ? "Disconnect" : "Connect"
                height: 50
                onClicked: {
                    if (isPortOpen) {
                        SerialHandle.closeSerialPort();
                        isPortOpen = false;
                    } else if (mainWindow.selectedPort !== "" && mainWindow.selectedBaudRate !== 0) {
                        var success = SerialHandle.openSerialPort(mainWindow.selectedPort, SerialHandle.ReadWrite, mainWindow.selectedBaudRate);
                        isPortOpen = success; // Update the status based on whether the port was successfully opened
                    } else {
                        console.log("Please select a port and baud rate before connecting.");
                    }
                }
            }
        }
    }

    Connections {
        target: Track
        function onDataLoaded() {
            console.log("Data loaded, updating heat plot");
            var trackData = Track.getTableModel();
            var heatData = trackData.map(function(item) {
                return {
                    "x": item.longitude,
                    "y": item.latitude,
                    "heat": item.elevation
                };
            });
            heatPlot.setHeatData(heatData);
        }
    }
}
