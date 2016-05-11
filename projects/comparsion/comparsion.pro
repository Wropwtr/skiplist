TEMPLATE = app
CONFIG += console
CONFIG -= app_bundle
CONFIG -= qt

QMAKE_CXXFLAGS -= -O0

SOURCES += main.cpp

include(deployment.pri)
qtcAddDeployment()

