import QtQuick 2.12
import QtQuick.Window 2.12

Window {
    id: root
    visible: true
    width: 640
    height: 480
    title: qsTr("Auto Update QML")
    color: "#303030"

    Loader {
        id: ldrNewQml
        anchors.fill: parent
        source: "LoadedQml.qml"
    }
}
