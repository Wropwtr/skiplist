TEMPLATE = app
CONFIG += console
CONFIG -= app_bundle
CONFIG -= qt

SOURCES += \
    sample_skiplist.cpp

include(deployment.pri)
qtcAddDeployment()

