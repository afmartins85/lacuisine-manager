import QtQuick 2.12
import QtQuick.Layouts 1.12
import QtQuick.Controls 2.12
import QtQuick.Controls.Material 2.12
import QtQuick.Controls.Universal 2.12
import Qt.labs.settings 1.0
import Qt.labs.platform 1.0
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
        sysInfoScreen.open();
    }

    Shortcut {
        sequence: "Ctrl+Q"
        onActivated: Qt.quit()
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
        height: AppTheme.toolBarHeight

        Rectangle {
            anchors.fill: parent
            color: "#607d8b"
        }

        RowLayout {
            anchors.fill: parent
            spacing: AppTheme.columnSpacing_20

            Label {
                id: dateTimeInfo
                text: "Quarta-feira, 27/05/2020\n08:00"
                elide: Label.ElideRight
                verticalAlignment: Qt.AlignVCenter
                Layout.leftMargin: AppTheme.columnSpacing_20
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
//                            sysInfoScreen.visible = true;
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
        width: AppTheme.toolBarButtonWidth
        height: parent.height
        anchors {
            left: parent.left
            verticalCenter: parent.verticalCenter
        }
        color: "#607d8b"
    }

    RowLayout {
        anchors.fill: parent
        spacing: 0

        ListView {
            id: menuList
            width: AppTheme.toolBarButtonWidth
            Layout.fillHeight: true
            Layout.fillWidth: false
            Layout.alignment: Qt.AlignLeft | Qt.AlignTop
            orientation: ListView.Vertical
            model: menuListModel
            delegate: GeneralButton {
                implicitWidth: AppTheme.toolBarButtonWidth
                implicitHeight: AppTheme.toolBarButtonHeight
                color: "#263238"
                colorText: "white"
                fontPxSize: AppTheme.textSizeExtraSmall
                text: title
            }
        }

        StackView {
            id: stackView
            Layout.fillHeight: true
            Layout.alignment: Qt.AlignLeft | Qt.AlignTop
            Layout.fillWidth: true
            initialItem: Profile {}
        }
    }
}
