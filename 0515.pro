TEMPLATE = app
CONFIG += console
CONFIG -= app_bundle
CONFIG -= qt

SOURCES += \
    CsckFactoryImp1.cpp \
    CSckFactoryImp2.cpp \
    HwEncDec.cpp \
    des.cpp \
    mainclass02.cpp \
          \
    mainclass01.cpp

HEADERS += \
    CSocketProtcol.h \
    CSckFactoryImp1.h \
    CSckFactoryImp2.h \
    CEncDesProtocol.h \
    HwEncDec.h \
    des.h

