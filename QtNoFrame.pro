#-------------------------------------------------
#
# Project created by QtCreator 2017-12-05T15:49:38
#
#-------------------------------------------------

QT       += core gui

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TARGET = QtNoFrame
TEMPLATE = app

# The following define makes your compiler emit warnings if you use
# any feature of Qt which as been marked as deprecated (the exact warnings
# depend on your compiler). Please consult the documentation of the
# deprecated API in order to know how to port your code away from it.
DEFINES += QT_DEPRECATED_WARNINGS

# You can also make your code fail to compile if you use deprecated APIs.
# In order to do so, uncomment the following line.
# You can also select to disable deprecated APIs only up to a certain version of Qt.
#DEFINES += QT_DISABLE_DEPRECATED_BEFORE=0x060000    # disables all the APIs deprecated before Qt 6.0.0


SOURCES += \
        main.cpp \
        main_dialog.cpp \
        dialog_plug/title_bar.cpp \
    dialog_plug/frameless_helper.cpp

HEADERS += \
        main_dialog.h \
        dialog_plug/title_bar.h \
    dialog_plug/frameless_helper.h

RESOURCES += \
    res/res.qrc
