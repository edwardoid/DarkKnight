QT       += core gui

TARGET = $$qtLibraryTarget(FilesystemPlugin)
DESTDIR = ./../../bin/datastores
TEMPLATE = lib
CONFIG += plugin

HEADERS += \
    FilesystemPlugin.h \
    SettingsPage.h

SOURCES += \
    FilesystemPlugin.cpp \
    SettingsPage.cpp

INCLUDEPATH += ./../../Framework \
               ./../../Interfaces

FORMS += \
    SettingsPage.ui

LIBS += -L./../../bin/ -lFramework -lInterfaces
