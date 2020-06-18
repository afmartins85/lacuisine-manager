QT += qml quick sql network quickcontrols2

CONFIG += c++11

TARGET = lacuisine
!android: !ios: qtHaveModule(widgets): QT += widgets

include(src/src.pri)
include(src/paystation/paystation.pri)
include(src/gsoap/gsoap.pri)

#qml.files = $$files(*.qml)
#qml.files += $$files(pages/*.qml)
#qml.files += $$files(components/lacuisine/responsive/theme/*.qml)
#qml.files += $$files(components/lacuisine/controls/*.qml)
#qml.prefix = /pages
#RESOURCES += qml

#images.files = $$files(images/*.png)
#images.files += $$files(images-assets/*.png)
#images.prefix = /images
#RESOURCES += images

RESOURCES += \
    icons/lacuisine/index.theme \
    icons/lacuisine/20x20/menu.png \
    icons/lacuisine/20x20@2/menu.png \
    icons/lacuisine/20x20@3/menu.png \
    icons/lacuisine/20x20@4/menu.png \
    images-assets/images-assets.qrc \
    lacuisine_manager.qrc \
    qtquickcontrols2.conf
#    components/lacuisine/responsive/theme/qmldir \
#    components/lacuisine/controls/qmldir


QML_IMPORT_PATH += $$PWD/qml/components

target.path = /home/pi/lacuisine_manager
INSTALLS += target
