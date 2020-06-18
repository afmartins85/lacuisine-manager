import QtQuick 2.0
import QtQuick.Controls 2.12
import QtQuick.Layouts 1.12
import lacuisine.responsive.theme 1.0

Button {
    id: button
    implicitWidth: AppTheme.hscale(100)
    implicitHeight: AppTheme.vscale(58)

    property alias source: smallRestaurantLogo.source

    background: Rectangle {
        opacity: button.down ? 0.3 : 1
        color: "#ff9900"

        Image {
            id: smallRestaurantLogo
            width: AppTheme.smallRestaurantLogoWidth
            height: AppTheme.smallRestaurantLogoHeight
            anchors.horizontalCenter: parent.horizontalCenter
            anchors.verticalCenter: parent.verticalCenter
            fillMode: Image.PreserveAspectFit
        }
    }
}
