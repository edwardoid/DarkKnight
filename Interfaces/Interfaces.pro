#-------------------------------------------------
#
# Project created by QtCreator 2012-06-22T21:11:49
#
#-------------------------------------------------

QT       += core gui

TARGET = $$qtLibraryTarget(Interfaces)
DESTDIR = ./../bin
TEMPLATE = lib
CONFIG += plugin

DEFINES += INTERFACES_LIBRARY

SOURCES += \
    DataStore.cpp \
    Concept.cpp \
    SettingsPage.cpp \
    FrameworkUser.cpp

HEADERS += \
    Plugin.h \
    DataStore.h \
    Concept.h \
    SettingsPage.h \
    FrameworkUser.h \
    Logger.h

INCLUDEPATH += ./../Framework/
