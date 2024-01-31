import QtQuick
import QtQuick.Controls
import QtQuick.Layouts
import QtQuick.Controls.Material
import com.Elyos.serial
import com.Elyos.parsers

ApplicationWindow {
    visible: true
    width: 600
    height: 400
    title: "Serial Monitor"
    property bool darkMode: false
    property string buffer: "" // Buffer to accumulate incoming data
    property var dataLabels: []
    property var parsedDataArray: ([])
    Material.theme: darkMode ? Material.Dark : Material.Light
    background: Material.backgroundColor;
    onDarkModeChanged: windowManager.setDarkMode(darkMode)

    ColumnLayout{
        anchors.fill: parent
        RowLayout {
            width: parent.width
            spacing: 0
            MenuBar {
                Layout.alignment: Qt.AlignTop
                Menu {
                    title: qsTr("Functions")
                    MenuItem {
                        text: qsTr("Parse Data")
                        onTriggered: {
                            // Add logic to parse the data received
                        }
                    }
                    // Add other menu items for additional functions
                }
            }
            Item {
                Layout.fillWidth: true // Spacer to push the next MenuBar to the right
            }
            Button {
                Layout.alignment: Qt.AlignTop
                Layout.rightMargin: 10
                text: "Show Data"
                onClicked: dataDrawer.visible = !dataDrawer.visible
            }
        }
        RowLayout{
            id: mainContent
            Layout.fillWidth: true
            Layout.fillHeight: true

            Flickable {
                id: flickable
                Layout.fillWidth: true
                Layout.fillHeight: true

                TextEdit {
                    id: serialOutput
                    width: flickable.width
                    height: Math.max(flickable.height, flickable.contentHeight)
                    readOnly: true
                    wrapMode: TextEdit.WrapAnywhere
                    color: darkMode ? "white" : "black"

                    function appendText(newText) {
                        text += newText;
                        Qt.callLater(function() {
                            flickable.contentHeight = contentHeight;
                            // Scroll to the bottom of the Flickable
                            flickable.contentY = Math.max(0, flickable.contentHeight - flickable.height);
                        });
                    }
                }
            }
        }
    }
    Drawer {
        id: dataDrawer
        width: parent.width * 0.3
        height: parent.height
        edge: Qt.RightEdge
        visible: false

        ListView {
            id: dataList
            anchors.fill: parent
            model: DataParser.getLabels() // Get labels from the DataParser
            delegate: Item {
                width: dataList.width
                height: Math.max(textLabel.implicitHeight, textValue.implicitHeight) + 4
                RowLayout{
                    anchors.centerIn: parent
                    spacing: 8
                    Text {
                        id: textLabel
                        text: modelData.label // Display the label
                        font.bold: true
                    }
                    Text {
                        id: textValue
                        text: modelData.value // Display the value associated with the label
                    }
                }
            }
        }
    }

    Connections {
        target: SerialHandle
        function onDataReceived(newData) {
            buffer += newData;
            if (buffer.includes("\n")) {
                serialOutput.appendText(buffer);
                DataParser.parseLabelData(buffer);
                buffer = "";
            }
        }
    }
    Connections {
        target: DataParser
        function onDataUpdated() {
            parsedDataArray = [];
            for (var i = 0; i < dataLabels.length; i++) {
                var label = dataLabels[i];
                var value = DataParser.getLabelData(label); // Get value for this label from DataParser
                parsedDataArray.push({ label: label, value: value });
            }
            dataList.model = parsedDataArray; // Update ListView model
        }
        function onNewLabelAdded() {
            dataLabels = DataParser.getLabels();
            console.log(dataLabels);
        }
    }
}
