#-------------------------------------------------
#
# Project created by QtCreator 2012-06-22T21:18:43
#
#-------------------------------------------------

QT       -= gui

TARGET = $$qtLibraryTarget(Framework)
DESTDIR = ./../bin
TEMPLATE = lib

SOURCES += Framework.cpp \
    Settings.cpp \
    PluginLoader.cpp

HEADERS += Framework.h \
    Settings.h \
    PluginLoader.h

INCLUDEPATH += ./../Interfaces

LIBS += -L./../bin -lInterfaces
