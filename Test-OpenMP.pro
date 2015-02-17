TEMPLATE = app
CONFIG += console
CONFIG -= app_bundle
CONFIG -= qt
QMAKE_CXXFLAGS += -std=c++11
#QMAKE_CXXFLAGS += -march=ivybridge
QMAKE_CXXFLAGS += -mavx
QMAKE_CXXFLAGS += -fverbose-asm -g
QMAKE_CXXFLAGS+= -fopenmp
QMAKE_LFLAGS +=  -fopenmp

LIBS +=

SOURCES += main.cpp \
    vecteur3.cpp \
    calcul_vent_seq.cpp \
    calcul_vent_openmp.cpp

HEADERS += \
    vecteur3.h \
    calcul_vent_seq.h \
    calcul_vent_openmp.h

