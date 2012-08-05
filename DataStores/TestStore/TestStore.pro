#-------------------------------------------------
#
# Project created by QtCreator 2012-06-22T22:14:40
#
#-------------------------------------------------

QT       -= gui

TARGET = $$qtLibraryTarget(TestStore)
DESTDIR = ./../../bin/datastores
TEMPLATE = lib
CONFIG += plugin

SOURCES += TestStore.cpp

HEADERS += TestStore.h

LIBS += -L./../../bin/ -lFramework -lInterfaces
INCLUDEPATH += ./../../Framework \
               ./../../Interfaces
