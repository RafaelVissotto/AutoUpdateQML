import QtQuick 2.12

Item {
    id: root
    anchors.fill: parent
    anchors.margins: 50

    Text {
        id: txtTryChange
        text: qsTr("TRY TO CHANGE ME!")
        color: "white"
        font.pixelSize: 30

        Behavior on x { NumberAnimation { duration: 1000 } }
        Behavior on y { NumberAnimation { duration: 1000 } }

        Timer {
            id: tmrTryChange
            running: true
            repeat: true
            interval: 400

            onTriggered: {
                parent.x = Math.floor(Math.random() * (root.width - txtTryChange.width));
                parent.y = Math.floor(Math.random() * (root.height - txtTryChange.height));
            }
        }
    }
}
