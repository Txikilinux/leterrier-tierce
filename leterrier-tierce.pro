#-------------------------------------------------
#
# Project created by QtCreator 2011-03-11T18:28:34
#
#-------------------------------------------------

QT       += core gui webkit sql svg
system(ccache -V):QMAKE_CXX = ccache g++

CONFIG += debug
#a activer ou pas si on souhaite compiler pour tablette
tablette {
    DEFINES += __ABULEDUTABLETTEV1__MODE__=1
    #AbulEduVirtualKeyboardV1
    include(lib/abuleduvirtualkeyboardv1/abuleduvirtualkeyboardv1.pri)
}

TARGET = leterrier-tierce
TEMPLATE = app

SOURCES += main.cpp\
        mainwindow.cpp \
    btncase.cpp \
    abuleduaproposv0.cpp

HEADERS  += version.h \
    mainwindow.h \
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

win32{
  OTHER_FILES += windows/windows.rc
  RC_FILE = windows/windows.rc
  LIBS += -lversion
}

macx {
 ICON = macos/icones/abuledu-alacarte.icns
}

include(lang/lang.pri)
include(lib/abuleduapplicationv1/abuleduapplicationv1.pri)
include(lib/abuleduconstantesv1/abuleduconstantesv1.pri)
include(lib/abuledunetworkaccessmanagerv1/abuledunetworkaccessmanagerv1.pri)
include(lib/abuledumessageboxv1/abuledumessageboxv1.pri)
include(lib/abuleduidentitesv1/abuleduidentitesv1.pri)
include(lib/abuleduflatboutonv1/abuleduflatboutonv1.pri)
include(lib/maia/maia.pri)
