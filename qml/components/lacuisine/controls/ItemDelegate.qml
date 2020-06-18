import QtQuick 2.0
import QtQuick.Controls 2.12
import QtQuick.Layouts 1.12
import lacuisine.responsive.theme 1.0

Component {

    Item {
        implicitWidth: parent.width - AppTheme.offsetScroolBarWidth
        implicitHeight: AppTheme.itemHeight
        opacity: itemTouchableArea.pressed ? 0.3 : 1

        property alias source: illustration.source
        property alias cost: cost.text
        property alias dishDescription: dishDescription.text
        property alias dishName: dishName.text
        property alias itemTouchableArea: itemTouchableArea

        Rectangle {
            id: itemDelegate
            anchors.fill: parent
            color: "white"

            RowLayout {
                spacing: AppTheme.columnSpacing_20
                Layout.alignment: Qt.AlignLeft
                Image {
                   id: illustration
                   width: AppTheme.dishIllustrationSmallWidth
                   height: AppTheme.dishIllustrationSmallHeight
                   Layout.alignment: Qt.AlignVCenter
                   source: dishImage
                   fillMode: Image.PreserveAspectFit
                }

                ColumnLayout {
                    id: columnDescription
                    spacing: AppTheme.columnSpacing_5
                    Text {
                        id: dishName
                        text: name
                        font.pixelSize: AppTheme.textSizeVerySmall
                        font.family: "Roboto"
                        font.bold: true
                        color: "#607d8b"
                    }
                    Text {
                        id: dishDescription
                        text: description
                        font.pixelSize: AppTheme.textSizeUltraSmall
                        font.family: "Roboto"
                        color: "#37474f"
                    }
                }
            }

            Column {
                id: columnCost
                anchors.right: parent.right
                anchors.rightMargin: 15
                anchors.verticalCenter: parent.verticalCenter
                Text {
                    text: qsTr("R$")
                    anchors.right: parent.right
                    font.pixelSize: AppTheme.textSizeUltraSmall
                    font.family: "Roboto"
                    font.bold: true
                    color: "#37474f"
                }

                Text {
                    id: cost
                    text: dishCost
                    font.pixelSize: AppTheme.textSizeVerySmall
                    font.family: "Roboto"
                    font.bold: true
                    color: "#607d8b"
                }
            }

        }

        MouseArea {
            id: itemTouchableArea
            anchors.fill: parent
        }
    }
}
