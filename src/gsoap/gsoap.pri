SOURCES += \
    $$PWD/lacuisineBindingServiceImpl.cpp \
    $$PWD/stdsoap2.cpp \
    $$PWD/soapC.cpp \
    $$PWD/soapLacuisineBindingService.cpp \
    $$PWD/soapLacuisineBindingProxy.cpp
HEADERS += \
    $$PWD/stdsoap2.h \
    $$PWD/soapH.h \
    $$PWD/soapStub.h \
    $$PWD/soapLacuisineBindingService.h \
    $$PWD/soapLacuisineBindingProxy.h

DEFINES += WITH_OPENSSL

macos:INCLUDEPATH += /usr/local/opt/openssl/include
macos:LIBS += "-L/usr/local/opt/openssl/lib"

#unix:!macosx: LIBS += -lssl -lcrypto -ldl
LIBS += -lssl -lcrypto -ldl
#LIBS += -lgsoap++
