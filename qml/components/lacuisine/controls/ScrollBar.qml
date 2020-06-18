import QtQuick 2.0
import QtQuick.Controls 2.12
import QtQuick.Layouts 1.12
import lacuisine.responsive.theme 1.0

Item {
    id: root
    anchors{right: parent.right}
    width: AppTheme.scrollItemWidth
    property alias scrollDownButton: scrollDownButton
    property alias scrollUpButton: scrollUpButton

    property var scrollScale: (AppTheme.scrollItemHeight * 100) / parent.height
    property var contentY: parent.contentY * (scrollScale / 100)
    property var contentHeight: parent.contentHeight * (scrollScale / 100)
    property var parentHeight: AppTheme.scrollItemHeight

    Column {
        width: parent.width
        spacing: AppTheme.columnSpacing_10

        Button {
            id: scrollUpButton
            width: parent.width
            height: width
            visible: parentHeight < contentHeight
            background: Image {
                fillMode: Image.PreserveAspectFit
                source: "qrc:/images/scrollbar_seta_cima.png"
            }
        }

        Image {
            id: scrollBackground
            width: AppTheme.scrollItemWidth
            height: AppTheme.scrollItemHeight
            source: "qrc:/images/scrollbar_bg.png"
            visible: parentHeight < contentHeight

            Rectangle { // ScrollBar to be placed as a direct child of a ListView or GridView (ScrollBar won't run by itself and gives errors)
                id: indicatorPosition
                color: "#bdc0c2"
                width: parent.width
                radius: 0.5 * width // size controlled by width
                anchors.margins: radius
                height:  (parentHeight / contentHeight * parentHeight) //+ (radius * 2)//(scrollUpButton.height * 2)
                y:       contentY / contentHeight * parentHeight
                visible: parent.height   < contentHeight

                Column {
                    anchors.verticalCenter: parent.verticalCenter
                    anchors.horizontalCenter: parent.horizontalCenter
                    spacing: AppTheme.columnSpacing_5
                    Rectangle {
                        height: 1
                        width: AppTheme.scrollLineCntIndicatorSmallWidh
                        anchors.horizontalCenter: parent.horizontalCenter
                        color: "#90a4ae"
                    }
                    Rectangle {
                        height: 1
                        width: AppTheme.scrollLineCntIndicatorNormalWidn
                        anchors.horizontalCenter: parent.horizontalCenter
                        color: "#90a4ae"
                    }
                    Rectangle {
                        height: 1
                        width: AppTheme.scrollLineCntIndicatorSmallWidh
                        anchors.horizontalCenter: parent.horizontalCenter
                        color: "#90a4ae"
                    }
                }
            }
        }

        Button {
            id: scrollDownButton
            width: parent.width
            height: width
            visible: parentHeight < contentHeight
            background: Image {
                fillMode: Image.PreserveAspectFit
                source: "qrc:/images/scrollbar_seta_baixo.png"
            }
        }
    }
}
