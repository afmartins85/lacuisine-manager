import QtQuick 2.0
import QtQuick.Controls 2.12
import QtQuick.Layouts 1.12
import lacuisine.responsive.theme 1.0

Button {
    id: button
    text: qsTr("Button")
    font.pixelSize: AppTheme.textSizeSmall
    implicitWidth: AppTheme.getStartedWidth
    implicitHeight: AppTheme.getStartedHeight

    property alias color: rectButton.color
    property alias colorText: textButton.color
    property alias fontPxSize: button.font.pixelSize

    contentItem: Text {
        id: textButton
        text: button.text
        font: button.font
        opacity: button.down ? 0.3 : 1
        horizontalAlignment: Text.AlignHCenter
        verticalAlignment: Text.AlignVCenter
        elide: Text.ElideRight
    }

    background: Rectangle {
        id: rectButton
        opacity: button.down ? 0.3 : 1
    }
}
