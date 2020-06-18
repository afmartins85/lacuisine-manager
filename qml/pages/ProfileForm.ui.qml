import QtQuick 2.4
import QtQuick.Controls 2.12
import QtQuick.Layouts 1.12
import QtGraphicalEffects 1.0
import Qt.labs.platform 1.0
import lacuisine.controls 1.0
import lacuisine.responsive.theme 1.0

Page {
    id: pane
    implicitWidth: parent.width
    implicitHeight: parent.height

    property alias companyLogo: companyLogo
    property alias companyName: companyName
    property alias mouse: mouse
    property alias openLogoDialog: openLogoDialog
    property alias editButtom: editButtom
    property alias editAcceptButtom: editAcceptButtom
    property alias editCancelButtom: editCancelButtom

    property bool isLoadedImage: false
    property bool editMode: false
    property bool editButtomHovered: false
    property string restorCompanyLogo: ""
    property string restoreCompanyName: ""
    property alias logo: logo

    FileDialog {
        id: openLogoDialog
        currentFile: logo.source
        modality: Qt.WindowModal
        title: "Carregar Imagem"
        nameFilters: ["(*.png *.jpg *.jpeg)", "Todos arquivos (*)"]
        selectedNameFilter.index: 0
    }

    RowLayout {
        Layout.alignment: Qt.AlignLeft | Qt.AlignTop

        ColumnLayout {
            spacing: AppTheme.columnSpacing_30

            Item {
                id: companyLogo
                width: AppTheme.normalRestaurantLogoWidth
                height: AppTheme.normalRestaurantLogoHeight

                Layout.alignment: Qt.AlignLeft
                Layout.margins: AppTheme.columnSpacing_30

                Rectangle {
                    width: companyLogo.width * 1.05
                    height: companyLogo.height * 1.05
                    anchors.verticalCenter: companyLogo.verticalCenter
                    anchors.horizontalCenter: companyLogo.horizontalCenter
                    border.color: "brown"
                    border.width: 3
                    radius: 100
                    visible: editMode ? true : false
                    antialiasing: true
                }

                Image {
                    id: logo
                    source: isLoadedImage ? openLogoDialog.file : "qrc:/images/restaurant_logo.png"
                    fillMode: Image.PreserveAspectFit
                    sourceSize: Qt.size(parent.width, parent.height)
                    smooth: true
                    visible: false
                }

                Image {
                    id: imageMask
                    source: "../../images/restaurant_logo.png"
                    fillMode: Image.PreserveAspectFit
                    sourceSize: Qt.size(parent.width, parent.height)
                    smooth: true
                    visible: false
                }

                OpacityMask {
                    anchors.fill: logo
                    source: logo
                    maskSource: imageMask
                }

                MouseArea {
                    id: mouse
                    anchors.fill: parent
                    hoverEnabled: true
                }
            }

            TextField {
                id: companyName
                placeholderText: "Nome da empresa"
                Layout.alignment: Qt.AlignLeft
                Layout.margins: AppTheme.columnSpacing_30
                enabled: editMode ? true : false
                hoverEnabled: true
                font.pixelSize: AppTheme.textSizeSmall
                font.family: "Roboto"
                font.bold: editMode ? false : true
                font.italic: editMode ? true : false
                color: editMode ? "brown" : "#546e7a"
            }
        }

        ColumnLayout {
            Layout.alignment: Qt.AlignRight | Qt.AlignTop
            Layout.margins: AppTheme.columnSpacing_30
            Button {
                id: editButtom
                background: Image {
//                    source: "qrc:/images/edit_profile.png"
                    sourceSize: Qt.size(AppTheme.mallRestaurantLogoWidth / 2,
                                        AppTheme.smallRestaurantLogoHeight / 2)
                    fillMode: Image.PreserveAspectFit
                }
            }
            RowLayout {
                enabled: editMode ? true : false
                visible: editMode ? true : false

                Button {
                    id: editCancelButtom
                    background: Image {
//                        source: "qrc:/images/edit_cancel.png"
                        sourceSize: Qt.size(
                                        AppTheme.mallRestaurantLogoWidth / 1.15,
                                        AppTheme.smallRestaurantLogoHeight / 1.15)
                        fillMode: Image.PreserveAspectFit
                    }
                }

                Button {
                    id: editAcceptButtom
                    background: Image {
//                        source: "qrc:/images/edit_accept.png"
                        sourceSize: Qt.size(AppTheme.mallRestaurantLogoWidth,
                                            AppTheme.smallRestaurantLogoHeight)
                        fillMode: Image.PreserveAspectFit
                    }
                }
            }
        }
    }
}
