
QT += sql
LIBS += -lmariadb
INCLUDEPATH += /usr/include/mysql/

TEMPLATE = app
CONFIG += console c++11
CONFIG -= app_bundle
CONFIG -= qt

SOURCES += \
        main.cpp
