QT       += core gui

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

CONFIG += c++17

# You can make your code fail to compile if it uses deprecated APIs.
# In order to do so, uncomment the following line.
#DEFINES += QT_DISABLE_DEPRECATED_BEFORE=0x060000    # disables all the APIs deprecated before Qt 6.0.0

SOURCES += \
    addcharacter.cpp \
    addlightcone.cpp \
    addrelic.cpp \
    changech.cpp \
    changelc.cpp \
    changerl.cpp \
    characters.cpp \
    connection.cpp \
    lightcones.cpp \
    main.cpp \
    mainwindow.cpp \
    panel.cpp \
    relics.cpp

HEADERS += \
    addcharacter.h \
    addlightcone.h \
    addrelic.h \
    changech.h \
    changelc.h \
    changerl.h \
    characters.h \
    connection.h \
    lightcones.h \
    mainwindow.h \
    panel.h \
    relics.h

FORMS += \
    addcharacter.ui \
    addlightcone.ui \
    addrelic.ui \
    changech.ui \
    changelc.ui \
    changerl.ui \
    mainwindow.ui \
    panel.ui

# Default rules for deployment.
qnx: target.path = /tmp/$${TARGET}/bin
else: unix:!android: target.path = /opt/$${TARGET}/bin
!isEmpty(target.path): INSTALLS += target
QT += sql

VERSION = 1.0.0
QMAKE_TARGET_COMPANY = "Chieko3020"
QMAKE_TARGET_DESCRIPTION = "HSRDB"
QMAKE_TARGET_COPYRIGHT = "Copyright(C) 2024"
QMAKE_TARGET_PRODUCT = "HSRDB"
RC_LANG = 0x0800
RC_ICONS = ./res/icon.ico





