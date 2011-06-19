#-------------------------------------------------
#
# Project created by QtCreator 2011-03-11T18:28:34
#
#-------------------------------------------------

QT       += core gui script xml network

TARGET = Tierce
TEMPLATE = app


SOURCES += main.cpp\
        mainwindow.cpp \
    btncase.cpp \
    abuleduaproposv0.cpp

HEADERS  += mainwindow.h \
    btncase.h \
    abuleduaproposv0.h

FORMS    += mainwindow.ui \
    abuleduaproposv0.ui

OTHER_FILES += \
    images/background-1024x600.png \
    images/pagefold-50x45.png \
    data/images/redo.png \
    data/images/help60x42.png \
    data/images/help.png \
    data/images/help.png \
    data/images/up.png \
    data/images/down.png

RESOURCES += \
    data_images.qrc

include(lang/lang.pri)
