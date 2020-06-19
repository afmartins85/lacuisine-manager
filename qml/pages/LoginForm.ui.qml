import QtQuick 2.12
import QtQuick.Layouts 1.12
import QtQuick.Controls 2.12
import QtQuick.Controls.Material 2.12
import Qt.labs.settings 1.0
import lacuisine.controls 1.0
import lacuisine.responsive.theme 1.0
import LaCuisine 1.0

Popup {
    id: login
    x: (window.width - width) / 2
    y: (window.height - height) / 6
    modal: true
    focus: true
    contentWidth: Math.min(window.width, window.height) / 3 * 2
    closePolicy: Popup.NoAutoClose
    background: Rectangle {
        color: "#263238"
    }

    property alias userName: userName
    property alias passwd: passwd
    property alias submmit: submmit
    property bool loginErrorFlag: false

    Material.foreground: "white"

    contentItem: ColumnLayout {
        id: aboutColumn
        spacing: 8

        RowLayout {
            id: columnPowered
            spacing: AppTheme.columnSpacing_15

            Layout.margins: AppTheme.columnSpacing_15

            Image {
                id: tthLogo
                Layout.alignment: Qt.AlignLeft | Qt.AlignBottom
                fillMode: Image.PreserveAspectFit
                source: "qrc:/images/logo.png"
                sourceSize.height: AppTheme.normalTthLogoHeight
                sourceSize.width: AppTheme.normalTthLogoWidth
            }

            Image {
                id: tipografiaLogo
                Layout.alignment: Qt.AlignLeft | Qt.AlignBottom
                fillMode: Image.PreserveAspectFit
                source: "qrc:/images/tipografia_logo.png"
                sourceSize.width: AppTheme.normalTipoGrLogoWidth
                sourceSize.height: AppTheme.normalTipoGrLogoHeight
            }
        }

        Label {
            text: "Login"
            font.bold: true
            font.pixelSize: AppTheme.textSize_32
        }

        Label {
            id: loginError
            width: parent.width
            wrapMode: Label.Wrap
            Layout.alignment: Qt.AlignJustify
            font.pixelSize: AppTheme.textSize_24
            text: "Login ou senha inválida!"
            color: "red"
            opacity: loginErrorFlag
        }

        TextField {
            id: userName
            Layout.fillWidth: true
            font.pixelSize: AppTheme.textSize_24
        }

        TextField {
            id: passwd
            Layout.fillWidth: true
            echoMode: TextInput.Password
            font.pixelSize: AppTheme.textSize_32
            width: parent.width
        }

        Button {
            id: submmit
            highlighted: true
            Material.accent: Material.Gray
            Material.elevation: 0
            Layout.fillWidth: true
            text: "ENTRAR"
        }
    }
}

/*##^##
Designer {
    D{i:0;autoSize:true;height:480;width:640}
}
##^##*/

