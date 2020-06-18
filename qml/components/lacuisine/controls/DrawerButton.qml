import QtQuick 2.0
import QtQuick.Controls 2.12
import QtQuick.Layouts 1.12
import lacuisine.responsive.theme 1.0

Button {
    id: button
    implicitWidth: drawerIcon.width
    implicitHeight: drawerIcon.height

    property alias source: drawerIcon.source

    background: Rectangle {
        opacity: button.down ? 0.3 : 1
        color: "transparent"

        Image {
            id: drawerIcon
            fillMode: Image.PreserveAspectFit
            anchors.horizontalCenter: parent.horizontalCenter
            anchors.verticalCenter: parent.verticalCenter
        }
    }
}

/*##^##
Designer {
    D{i:0;autoSize:true;height:480;width:640}
}
##^##*/
