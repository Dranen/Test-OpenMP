TEMPLATE = app
CONFIG += console
CONFIG -= app_bundle
CONFIG -= qt
QMAKE_CXXFLAGS += -std=c++11
QMAKE_CXXFLAGS += -O2

SOURCES += main.cpp \
    vecteur3.cpp \
    calcul_vent_seq.cpp

HEADERS += \
    vecteur3.h \
    calcul_vent_seq.h

