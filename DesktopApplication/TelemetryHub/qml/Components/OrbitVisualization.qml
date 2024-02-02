import QtQuick
import QtQuick.Window
import QtQuick.Controls
import QtQuick.Layouts
import Qt.labs.platform
import QtCore
import QtQuick3D
import QtQuick3D.Helpers
import QtQuick3D.AssetUtils
import QtQuick.Controls.Material

Item {
    id: windowRoot
    visible: true
    //anchors.fill: parent


    //Material.theme: Material.dark

    property url modelUrl
    property bool isOrbitControlEnabled
    property bool boundsVisualizer

    View3D {
        id: view3D
        anchors.fill: parent

        environment: SceneEnvironment {
            id: environment
            backgroundMode: SceneEnvironment.Color
            clearColor: "lightgray"

            InfiniteGrid {
                visible: true
                gridInterval: 15
            }
        }

        camera: cameraController.isOrbitControllerEnabled ? orbitCamera : wasdCamera

        DirectionalLight {
            id: directionalLight
            eulerRotation.x: -35
            eulerRotation.y: -90
            castsShadow: true
        }

        Node {
            id: orbitCameraNode

            PerspectiveCamera {
                id: orbitCamera
            }
        }

        PerspectiveCamera {
            id: wasdCamera
            onPositionChanged: {

                let distance = position.length()
                clipNear = distance < 1 ? 0.01 : (distance < 100 ? 0.1 : 1)
                clipFar = distance < 1 ? 100 : (distance < 100 ? 1000 : 10000)
            }
        }

        OrbitCameraController {
            id: orbitController
            camera: orbitCamera
            origin: orbitCameraNode
            enabled: cameraController.isOrbitControllerEnabled
        }

        WasdController {
            id: wasdController
            controlledObject: wasdCamera
            enabled: !cameraController.isOrbitControllerEnabled
        }

        RuntimeLoader {
            id: modelLoader
            source: modelUrl
            onBoundsChanged: cameraController.updateBounds(bounds)
        }

        Model {
            id: mainModel
            parent: modelLoader
            source: "#Cube"
            materials: PrincipledMaterial { baseColor: "red" }
            opacity: 0.2
            visible: boundsVisualizer
            position: cameraController.boundsCenter
            scale: Qt.vector3d(cameraController.boundsSize.x / 100,
                               cameraController.boundsSize.y / 100,
                               cameraController.boundsSize.z / 100)
        }

        QtObject {
            id: cameraController
            property real boundsDiameter: 0
            property vector3d boundsCenter
            property vector3d boundsSize
            property bool isOrbitControllerEnabled: true

            function updateBounds(bounds) {
                boundsSize = Qt.vector3d(bounds.maximum.x - bounds.minimum.x,
                                         bounds.maximum.y - bounds.minimum.y,
                                         bounds.maximum.z - bounds.minimum.z)
                boundsDiameter = Math.max(boundsSize.x, boundsSize.y, boundsSize.z)
                boundsCenter = Qt.vector3d((bounds.maximum.x + bounds.minimum.x) / 2,
                                           (bounds.maximum.y + bounds.minimum.y) / 2,
                                           (bounds.maximum.z + bounds.minimum.z) / 2)

                wasdController.speed = boundsDiameter / 1000.0
                wasdController.shiftSpeed = 3 * wasdController.speed
                wasdCamera.clipNear = boundsDiameter / 100
                wasdCamera.clipFar = boundsDiameter * 10
                resetView()
            }

            function resetView() {
                if (modelLoader.status === RuntimeLoader.Success) {
                    orbitCameraNode.eulerRotation = Qt.vector3d(0, 0, 0)
                    orbitCameraNode.position = boundsCenter
                    orbitCamera.position = Qt.vector3d(0, 0, 2 * boundsDiameter)
                    orbitCamera.eulerRotation = Qt.vector3d(0, 0, 0)
                    isOrbitControllerEnabled = true
                }
            }

            function switchController(useOrbitController) {
                isOrbitControllerEnabled = useOrbitController
                if (!useOrbitController) {
                    wasdCamera.position = orbitCamera.scenePosition
                    wasdCamera.rotation = orbitCamera.sceneRotation
                    wasdController.focus = true
                }
            }
        }
    }

    FileDialog {
        id: elementLoader
        nameFilters: ["glTF files (*.gltf *.glb)", "All files (*)"]
        onAccepted: {
            modelUrl = file
        }
    }

    function defaultView(){
        cameraController.resetView();
    }

    function toggleView(){
        cameraController.switchController(!cameraController.isOrbitControllerEnabled);
    }

    function setEnvironment(env) {
        var debugSettingsModel = [
            { value: DebugSettings.None, text: "None"},
            { value: DebugSettings.BaseColor, text: "Base Color"},
            { value: DebugSettings.Roughness, text: "Roughness"},
            { value: DebugSettings.Metalness, text: "Metalness"},
            { value: DebugSettings.Diffuse, text: "Diffuse"},
            { value: DebugSettings.Specular, text: "Specular"},
            { value: DebugSettings.ShadowOcclusion, text: "Shadow Occlusion"},
            { value: DebugSettings.Emission, text: "Emission"},
            { value: DebugSettings.AmbientOcclusion, text: "Ambient Occlusion"},
            { value: DebugSettings.Normals, text: "Normals"},
            { value: DebugSettings.Tangents, text: "Tangents"},
            { value: DebugSettings.Binormals, text: "Binormals"},
            { value: DebugSettings.F0, text: "F0"}
        ];

        for (var i = 0; i < debugSettingsModel.length; i++) {
            if (debugSettingsModel[i].text === env) {
                environment.debugSettings.materialOverride = debugSettingsModel[i].value;
                return; // Exit the function once the correct setting is applied
            }
        }
        console.log("Environment setting not found for:", env);
    }

    function loadElement(){
        elementLoader.open()
    }
}
