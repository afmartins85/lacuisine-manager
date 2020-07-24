QT += qml quick sql network quickcontrols2

CONFIG += c++11

TARGET = lacuisine
!android: !ios: qtHaveModule(widgets): QT += widgets

include(src/src.pri)
include(src/paystation/paystation.pri)
include(src/gsoap/gsoap.pri)

qml.files = $$files(qml/*.qml)
qml.files += $$files(qml/pages/*.qml)
qml.files += $$files(qml/components/lacuisine/responsive/theme/*.qml)
qml.files += $$files(qml/components/lacuisine/responsive/theme/qmldir)
qml.files += $$files(qml/components/lacuisine/controls/*.qml)
qml.files += $$files(qml/components/lacuisine/controls/qmldir)
qml.prefix = /
RESOURCES += qml

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

OTHER_FILES += \
    src/gsoap/generate/common.xsd \
    src/gsoap/generate/lacuisine.wsdl \
    src/gsoap/generate/service.wsdl

QML_IMPORT_PATH += $$PWD/qml/components

target.path = /home/pi/lacuisine_manager
INSTALLS += target

DISTFILES += \
    qml/pages/Login.qml \
    qml/pages/LoginForm.ui.qml
