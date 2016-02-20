QT += core
QT += gui

CONFIG += link_pkgconfig
PKGCONFIG += yaml-cpp

QMAKE_CXXFLAGS += --std=c++11 -Wall #-Werror
QMAKE_CXXFLAGS_DEBUG = -g3 -O0 -fno-inline

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TARGET = MTKPartitionEditor
TEMPLATE = app


SOURCES += \
    main.cpp \
    mainwindow.cpp \
    mtkscatter.cpp \
    mtkpartition.cpp

HEADERS += \
    mainwindow.h \
    mtkscatter.h \
    mtkpartition.h \
    qtyaml.h

FORMS += \
    mainwindow.ui
