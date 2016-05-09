TEMPLATE = app
CONFIG += console
CONFIG -= app_bundle
CONFIG -= qt

SOURCES += \
    test_listdata.cpp \
    test_skiplist.cpp \
    main.cpp \
    test_skiptable.cpp

include(deployment.pri)
qtcAddDeployment()

HEADERS +=

