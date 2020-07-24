SOURCES += \
    $$PWD/paystation.cpp \
    $$PWD/sitefapi.cpp

unix:!macos:LIBS += -L$$PWD../../lib\ -lclisitef32

HEADERS += \
    $$PWD/paystation.h \
    $$PWD/clisitef.h \
    $$PWD/sitefapi.h

