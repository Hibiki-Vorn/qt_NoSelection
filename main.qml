import QtQuick 2.15
import QtQuick.Window 2.15
import QtQuick.Controls 2.15
import QtQuick.Controls.Material 2.15

Window {
    width: 640
    height: 480
    visible: true
    id: mainWindow
    color: "#121212"
    Material.theme: Material.Dark
    title: qsTr("Are you idiot ?")
    Material.accent: Material.DeepPurple
    Component.onCompleted:WindowAction.bindButtons(button_yes,button_no)

    Text {
        height: 100
        color: "white"
        font.pixelSize: 70
        width: mainWindow.width
        text: qsTr("Are you idiot ?")
        padding: ( mainWindow.width - 490 ) / 2
    }

    Button {
        x: 400
        y: 300
        text: "NO"
        id:button_no
        font.pixelSize: 60

        MouseArea {
            hoverEnabled: true
            anchors.fill: parent
            onPositionChanged: WindowAction.onMouseMovedOnButtonNo()
        }
    }

    Button {
        x: 80
        y: 300
        text: "YES"
        id:button_yes
        font.pixelSize: 60
        onClicked: WindowAction.dialog_no()
    }
}
