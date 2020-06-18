import QtQuick 2.0
import QtQuick.Controls 2.12
import QtQuick.Layouts 1.12
import lacuisine.responsive.theme 1.0

Component {

    Item {
        implicitWidth: AppTheme.hscale(100)
        implicitHeight: AppTheme.vscale(58)

        property alias colorBackground: selectMenuDelegate.color

        Rectangle {
            id: selectMenuDelegate
            implicitWidth: AppTheme.hscale(100)
            implicitHeight: AppTheme.vscale(58)
            color: "#607d8b"

            Text {
                text: title
                horizontalAlignment: Text.AlignHCenter
                anchors.horizontalCenter: parent.horizontalCenter
                anchors.verticalCenter: parent.verticalCenter
                font.pixelSize: AppTheme.textSizeUltraSmall
                font.bold: true
                color: "white"
            }

            MouseArea {
                anchors.fill: parent
                onPressed: {
                    selectMenuDelegate.opacity = 0.3
                }
                onReleased: {
                    selectMenuDelegate.opacity = 1
                }
            }
        }

        Rectangle {
            id: delimiter
            height: parent.height
            width: 1
            anchors.right: parent.right
            color: "#879ea8"
        }
    }
}

/*##^##
Designer {
    D{i:0;autoSize:true;height:480;width:640}
}
##^##*/
