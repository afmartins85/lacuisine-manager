import QtQuick 2.12
import QtQuick.Layouts 1.12
import QtQuick.Controls 2.12
import QtQuick.Controls.Material 2.12
import Qt.labs.settings 1.0
import lacuisine.controls 1.0
import lacuisine.responsive.theme 1.0
import LaCuisine 1.0
import "pages"

ApplicationWindow {
    id: window
    width: AppTheme.screenWidth
    height: AppTheme.screenHeight
    maximumWidth: AppTheme.screenWidth
    maximumHeight: AppTheme.screenHeight
    visible: true
//    visibility: Window.FullScreen
    title: "LaCuisine Gestor"

    // Configurar novas fontes aqui
    FontLoader { id: roboto; name: "Roboto" }
    readonly property var robotoFont: roboto

    property alias stackView: stackView

    Settings {
        id: settings
        property string style: "Material"
    }

    Component.onCompleted: {
        loginScreen.open();
    }

    Shortcut {
        sequence: "Ctrl+Q"
        onActivated: Qt.quit()
    }

    Login {
        id: loginScreen
    }

    SysInfoScreen {
        id: sysInfoScreen
    }

    ListModel {
        id: menuListModel
        ListElement {
            title: "Profile"
        }
        ListElement {
            title: "Pedidos"
        }
        ListElement {
            title: "Mesas"
        }
        ListElement {
            title: "Pessoal"
        }
        ListElement {
            title: "Caixa"
        }
        ListElement {
            title: "Cardápio"
        }
    }

    header: ToolBar {

        width: parent.width
        height: AppTheme.leftToolBarHeight

        RowLayout {
            anchors.fill: parent
            spacing: AppTheme.columnSpacing_20

            Label {
                id: userLogin
                text: "afmartins85"
                elide: Label.ElideRight
                verticalAlignment: Qt.AlignLeft
                Layout.leftMargin: AppTheme.columnSpacing_20
                font.family: robotoFont.name
                font.pixelSize: AppTheme.textSize_12
                color: "white"
            }

            Label {
                id: dateTimeInfo
                text: "Quarta-feira, 27/05/2020\n08:00"
                elide: Label.ElideRight
                horizontalAlignment: Qt.AlignHCenter
                verticalAlignment: Qt.AlignVCenter
                Layout.fillWidth: true
                font.family: robotoFont.name
                font.pixelSize: AppTheme.textSize_12
                color: "white"
            }

            ToolButton {
                id: optionsMenuAction

                Layout.alignment: Qt.AlignRight
                Layout.rightMargin: AppTheme.columnSpacing_20

                icon.name: "menu"
                icon.color: "white"

                onClicked: optionsMenu.open()

                Menu {
                    id: optionsMenu
                    MenuItem {
                        text: "Configurações"
                    }

                    MenuItem {
                        text: "Sistema.."
                        onTriggered: {
                            sysInfoScreen.open();
                        }
                    }

                    MenuItem {
                        text: "Sobre"
                    }
                }
            }
        }
    }

    Rectangle {
        width: AppTheme.leftToolBarWidth
        height: parent.height
        anchors {
            left: parent.left
            verticalCenter: parent.verticalCenter
        }
        color: "#263238"
    }

    RowLayout {
        anchors.fill: parent
        spacing: 0

        ListView {
            id: menuList
            width: AppTheme.leftToolBarWidth
            Layout.fillHeight: true
            Layout.fillWidth: false
            Layout.alignment: Qt.AlignLeft | Qt.AlignTop
            orientation: ListView.Vertical
            spacing: -10
            model: menuListModel
            delegate: GeneralButton {
                implicitWidth: AppTheme.leftToolBarWidth
                implicitHeight: AppTheme.leftToolBarHeight
                color: "white"
                colorText: "#263238"
                fontPxSize: AppTheme.textSize
                text: title
            }
        }

        StackView {
            id: stackView
            Layout.alignment: Qt.AlignLeft | Qt.AlignTop
            Layout.fillHeight: true
            Layout.fillWidth: true
            initialItem: Profile {}
        }
    }
}
