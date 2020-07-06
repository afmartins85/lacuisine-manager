import QtQuick 2.12
import QtQuick.Layouts 1.12
import QtQuick.Controls 2.12
import QtQuick.Controls.Material 2.12
import Qt.labs.settings 1.0
import lacuisine.controls 1.0
import lacuisine.responsive.theme 1.0
import LaCuisine 1.0

Dialog {
    id: systemDialog
    modal: true
    focus: true
    background: Rectangle {
        color: "#263238"
    }

    x: Math.round((window.width - width) / 2)
    y: Math.round((window.height - height) / 6)
    width: Math.min(window.width, window.height) / 2 * 2
    contentHeight: aboutColumn.height

    Material.foreground: "white"

    property alias sysInfo: sysInfo
    SysInfo {
        id: sysInfo
    }

    ColumnLayout {
        id: aboutColumn
        spacing: AppTheme.columnSpacing_20

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
            text: "LaCuisine Manager"
            Layout.alignment: Qt.AlignLeft
            Layout.leftMargin: AppTheme.columnSpacing_20
            Layout.fillWidth: false
            font.pixelSize: AppTheme.textSizeVerySmall
            font.bold: true
        }

        ColumnLayout {
            spacing: AppTheme.columnSpacing_2

            RowLayout {
                spacing: 0

                Layout.alignment: Qt.AlignLeft
                Layout.leftMargin: AppTheme.columnSpacing_20
                Label {
                    text: "Build ABI: "
                    font.pixelSize: AppTheme.textSize_10
                }

                Label {
                    text: sysInfo.buildAbi
                    font.pixelSize: AppTheme.textSize_10
                }
            }

            RowLayout {
                spacing: 0
                Layout.alignment: Qt.AlignLeft
                Layout.leftMargin: AppTheme.columnSpacing_20
                Label {
                    text: "CPU Architecture: "
                    font.pixelSize: AppTheme.textSize_10
                }
                Label {
                    text: sysInfo.cpuArch
                    font.pixelSize: AppTheme.textSize_10
                }
            }

            RowLayout {
                spacing: 0
                Layout.alignment: Qt.AlignLeft
                Layout.leftMargin: AppTheme.columnSpacing_20
                Label {
                    text: "Unique ID: "
                    font.pixelSize: AppTheme.textSize_10
                }
                Label {
                    text: sysInfo.uniqueID
                    font.pixelSize: AppTheme.textSize_10
                }
            }

            RowLayout {
                spacing: 0
                Layout.alignment: Qt.AlignLeft
                Layout.leftMargin: AppTheme.columnSpacing_20
                Label {
                    text: "Kernel Type: "
                    font.pixelSize: AppTheme.textSize_10
                }
                Label {
                    text: sysInfo.kernelType
                    font.pixelSize: AppTheme.textSize_10
                }
            }

            RowLayout {
                spacing: 0
                Layout.alignment: Qt.AlignLeft
                Layout.leftMargin: AppTheme.columnSpacing_20
                Label {
                    text: "Kernel Version: "
                    font.pixelSize: AppTheme.textSize_10
                }
                Label {
                    text: sysInfo.kernelVersion
                    font.pixelSize: AppTheme.textSize_10
                }
            }

            RowLayout {
                spacing: 0
                Layout.alignment: Qt.AlignLeft
                Layout.leftMargin: AppTheme.columnSpacing_20
                Label {
                    text: "Host Name: "
                    font.pixelSize: AppTheme.textSize_10
                }
                Label {
                    text: sysInfo.hostName
                    font.pixelSize: AppTheme.textSize_10
                }
            }

            RowLayout {
                spacing: 0
                Layout.alignment: Qt.AlignLeft
                Layout.leftMargin: AppTheme.columnSpacing_20
                Label {
                    text: "Product Name: "
                    font.pixelSize: AppTheme.textSize_10
                }
                Label {
                    text: sysInfo.productName
                    font.pixelSize: AppTheme.textSize_10
                }
            }

            RowLayout {
                spacing: 0
                Layout.alignment: Qt.AlignLeft
                Layout.leftMargin: AppTheme.columnSpacing_20
                Label {
                    text: "Product Type: "
                    font.pixelSize: AppTheme.textSize_10
                }
                Label {
                    text: sysInfo.productType
                    font.pixelSize: AppTheme.textSize_10
                }
            }

            RowLayout {
                spacing: 0
                Layout.alignment: Qt.AlignLeft
                Layout.leftMargin: AppTheme.columnSpacing_20
                Label {
                    text: "Product Version: "
                    font.pixelSize: AppTheme.textSize_10
                }
                Label {
                    text: sysInfo.productVersion
                    font.pixelSize: AppTheme.textSize_10
                }
            }
        }
    }
}
