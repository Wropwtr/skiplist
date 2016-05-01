#-------------------------------------------------
#
# Project created by QtCreator 2016-05-01T13:29:26
#
#-------------------------------------------------

QT       -= core gui

TARGET = skiplist_lib
TEMPLATE = lib
CONFIG += staticlib

SOURCES +=

HEADERS += \
    skiplist_lib.h
unix {
    target.path = /usr/lib
    INSTALLS += target
}
