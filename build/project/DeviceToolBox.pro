#-------------------------------------------------
#
# Project created by QtCreator 2013-12-30T11:11:10
#
#-------------------------------------------------

QT       += core gui

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TARGET = DeviceToolBox

CONFIG(debug, debug|release) {
TARGET = DeviceToolbox-d
}
else {
TARGET = DeviceToolbox
}

TEMPLATE = app

CONFIG += static

DESTDIR = ../../bin

DEFINES += \
    ENABLE_ULTIMATE_DECODER

SOURCES += \
    ../../src/main.cpp \
    ../../src/widget.cpp \
    ../../src/ConfigDialog.cpp \
    ../../src/BatchCodecDeviceDiscoveryManager.cpp \
    ../../src/CallBackAndEvent.cpp \
    ../../src/AbuoutDialog.cpp

HEADERS  += \
    ../../src/widget.h \
    ../../src/ConfigDialog.h \
    ../../src/BatchCodecDeviceDiscoveryManager.h \
    ../../src/CallBackAndEvent.h \
    ../../src/AbuoutDialog.h

FORMS    += \
    ../../src/widget.ui \
    ../../src/ConfigDialog.ui \
    ../../src/AbuoutDialog.ui

INCLUDEPATH += ../../../../share
DEPENDPATH += ../../../../share

unix:!macx:{

equals(Platform, "") {
Platform = linux_$$system(arch)
} else {
Platform = $$Platform
}

CONFIG(debug,debug|release) {
BuildType = debug
} else {
BuildType = release
}

isEmpty(CV5_SDK_ROOT) {
    CV5_SDK_ROOT = $$system(echo ${CV5_SDK_ROOT:-~/bqvision/clearvision})
}
BaseDir = $$CV5_SDK_ROOT/$$Platform/$$BuildType

QMAKE_CXXFLAGS += \
    -isystem $$BaseDir/include

INCLUDEPATH += \
    $$BaseDir/include/DeviceLayer

LIBS += -L$$BaseDir/lib

LIBS += \
    -lDeviceLayer -lPTZDataPacker \
    -lswift-1.0.0-gcc -ltinyxpath
}

equals(Platform, "linux_i686") {
QMAKE_CFLAGS += -m32
QMAKE_CXXFLAGS += -m32
QMAKE_LFLAGS += -m32
} else:equals(Platform, "linux_x86_64") {
# not support yet
QMAKE_CFLAGS += -m64
QMAKE_CXXFLAGS += -m64
QMAKE_LFLAGS += -m64
}

QMAKE_LFLAGS += '-Wl,-rpath,\'\$$ORIGIN/../lib:\$$ORIGIN/../../lib\''

RESOURCES += \
    ../../src/FileIcon.qrc


