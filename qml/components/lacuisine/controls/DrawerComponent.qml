import QtQuick 2.0
import QtQuick.Controls 2.12
import QtQuick.Layouts 1.12
import lacuisine.responsive.theme 1.0

Item {
    id: drawerComponent
    width: AppTheme.drawerClosedWidth
    height: AppTheme.drawerClosedHeight
    property alias placeOrder: placeOrder
    property alias removeAllItens: removeAllItens
    property alias payDrawer: payDrawer
    property alias openedDrawer: openedDrawer
    property alias helpDrawer: helpDrawer
    property alias followDrawer: followDrawer
    property alias openDrawer: openDrawer
//    property alias name: value

    property string currentState: ""

    Rectangle {
        id: rectangle
        anchors.fill: parent
        color: "#90a4ae"
    }

    RowLayout {
        id: rowDrawerTabBar

        Container {
            id: drawerTabBar
            Layout.alignment: Qt.AlignHCenter | Qt.AlignVCenter
            currentIndex: 1
            enabled: true

            ButtonGroup {
                buttons: drawerTabBar.children
            }

            contentItem: ColumnLayout {
                id: columnDrawerButtom
                spacing: AppTheme.columnSpacing_20

                Repeater {
                    model: drawerTabBar.contentModel
                }
            }

            DrawerButton {
                id: openDrawer
                Layout.alignment: Qt.AlignHCenter
                source: "qrc:/icons/_ic_idle_abrir_gaveta_fechado.png"
            }
            DrawerButton {
                id: followDrawer
                Layout.alignment: Qt.AlignHCenter
                source: "qrc:/icons/ic_idle_acompanhar.png"
            }
            DrawerButton {
                id: helpDrawer
                Layout.alignment: Qt.AlignHCenter
                source: "qrc:/icons/ic_idle_chamar_atendente.png"
            }
            DrawerButton {
                id: openedDrawer
                Layout.alignment: Qt.AlignHCenter
                source: "qrc:/icons/ic_idle_em_aberto.png"
            }
            DrawerButton {
                id: payDrawer
                Layout.alignment: Qt.AlignHCenter
                source: "qrc:/icons/ic_idle_pagamento.png"
            }
        }
    }

    GeneralButton {
        id: removeAllItens
        anchors.bottom: placeOrder.top
        implicitWidth: parent.width
        implicitHeight: AppTheme.drawerButtonsHeight
        text: "EXCLUIR TODOS"
        font.pixelSize: AppTheme.textSizeUltraSmall
        color: "#607d8b"
        colorText: "white"
        enabled: false
        opacity: 0
    }
    GeneralButton {
        id: placeOrder
        anchors.bottom: parent.bottom
        implicitWidth: parent.width
        implicitHeight: AppTheme.drawerButtonsHeight
        text: "EFETUAR PEDIDO"
        font.pixelSize: AppTheme.textSizeUltraSmall
        color: "#439110"
        colorText: "white"
        enabled: false
        opacity: 0
    }

    states: [
        State {
            name: "openedState"
            PropertyChanges {
                target: drawerComponent
                width: AppTheme.drawerOpenedWidth
            }
            PropertyChanges {
                target: removeAllItens
                enabled: true
                opacity: 1
            }
            PropertyChanges {
                target: placeOrder
                enabled: true
                opacity: 1
            }
            PropertyChanges {
                target: itemListView
                width: AppTheme.itemWidth
            }
    }
    ]
}
