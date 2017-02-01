QT += core
QT -= gui

CONFIG += c++11

TARGET = String
CONFIG += console
CONFIG -= app_bundle

TEMPLATE = app

SOURCES += main.cpp \
    string.cpp

HEADERS += \
    string.h
