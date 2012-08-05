#-------------------------------------------------
#
# Project created by QtCreator 2012-06-09T20:18:51
#
#-------------------------------------------------

QT       += core gui

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TARGET = DarkKnight
DESTDIR = ./../bin
TEMPLATE = app


SOURCES += main.cpp \
        DarkKnight.cpp \
        SplashScreen.cpp \
    AboutDialog.cpp \
    AuthorsDialog.cpp

HEADERS  += DarkKnight.h \
            SplashScreen.h \
    AboutDialog.h \
    AuthorsDialog.h

FORMS    += DarkKnight.ui \
    AboutDialog.ui \
    AuthorsDialog.ui

INCLUDEPATH += ./../Interfaces \
               ./../Framework \
               ./../Utils \
               ./../Widgets

LIBS += -L./../bin/ -lFramework -lInterfaces -lUtils -lWidgets

RESOURCES += \
    resources.qrc
