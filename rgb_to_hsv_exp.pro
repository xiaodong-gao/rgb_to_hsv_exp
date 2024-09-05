QT       += core gui

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

CONFIG += c++20

# The following define makes your compiler emit warnings if you use
# any Qt feature that has been marked deprecated (the exact warnings
# depend on your compiler). Please consult the documentation of the
# deprecated API in order to know how to port your code away from it.
DEFINES += QT_DEPRECATED_WARNINGS

CODECFORTR = UTF-8

# Windows 特定配置
win32 {
    3DPARTY_DIR = ../3dParty
    CONFIG(debug, debug|release) {
        INCLUDEPATH += $$3DPARTY_DIR/opencv-4.10.0-windows/Debug-x64/include
        LIBS += -L$$3DPARTY_DIR/opencv-4.10.0-windows/Debug-x64/x64/vc17/lib -lopencv_world4100d
    }
    else{
        INCLUDEPATH += $$3DPARTY_DIR/opencv-4.10.0-windows/Debug-x64/include
        LIBS += -L$$3DPARTY_DIR/opencv-4.10.0-windows/Release-x64/x64/vc17/lib -lopencv_world4100
    }
}

# You can also make your code fail to compile if it uses deprecated APIs.
# In order to do so, uncomment the following line.
# You can also select to disable deprecated APIs only up to a certain version of Qt.
#DEFINES += QT_DISABLE_DEPRECATED_BEFORE=0x060000    # disables all the APIs deprecated before Qt 6.0.0

SOURCES += \
    MImageAugmentation.cpp \
    main.cpp \
    mainwindow.cpp

HEADERS += \
    MImageAugmentation.h \
    mainwindow.h

FORMS += \
    mainwindow.ui

# Default rules for deployment.
qnx: target.path = /tmp/$${TARGET}/bin
else: unix:!android: target.path = /opt/$${TARGET}/bin
!isEmpty(target.path): INSTALLS += target
