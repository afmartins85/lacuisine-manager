import QtQuick 2.12

WelcomePanelForm {

    qrCodeGetStartedButton {
        onClicked: {
            console.log("BUTTON CLICKED");
        }
    }

    touchStartArea {
        onClicked: {
            console.log("GET STARTER");
        }
    }
}
