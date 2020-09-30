#-------------------------------------------------
#
# Project created by QtCreator 2019-08-07T17:17:58
#
#-------------------------------------------------

QT       += core gui
QMAKE_CXXFLAGS += -std=c++11
greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TARGET = reversi
TEMPLATE = app


SOURCES += main.cpp\
        mainwindow.cpp \
    operations.cpp \
    process.cpp

HEADERS  += mainwindow.h \
    chessboard.h \
    definition.h \
    direction.h \
    process.h

RESOURCES += \
    image.qrc
