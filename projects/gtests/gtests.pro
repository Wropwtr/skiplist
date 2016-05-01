#-------------------------------------------------
#
# Project created by QtCreator 2016-05-01T13:26:19
#
#-------------------------------------------------

QT       -= core gui

TARGET = gtests
TEMPLATE = lib
CONFIG += staticlib

SOURCES +=

HEADERS += \
    gtests.h
unix {
    target.path = /usr/lib
    INSTALLS += target
}
