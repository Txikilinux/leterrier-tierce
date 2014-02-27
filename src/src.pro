#-------------------------------------------------
#
# Project created by QtCreator 2011-03-11T18:28:34
#
#-------------------------------------------------

QT       += core gui sql svg

TARGET = leterrier-tierce
TEMPLATE = app

SOURCES += main.cpp\
        mainwindow.cpp \
    btncase.cpp

HEADERS  += version.h \
    mainwindow.h \
    btncase.h

FORMS    += mainwindow.ui

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
  OTHER_FILES += ../windows/windows.rc
  RC_FILE = ../windows/windows.rc
}

macx {
 ICON = ../macos/icones/leterrier-tierce.icns
}

include(lang/lang.pri)
include(lib/abuleduapplicationv1/abuleduapplicationv1.pri)
include(lib/abuleduconstantesv1/abuleduconstantesv1.pri)
include(lib/abuledunetworkaccessmanagerv1/abuledunetworkaccessmanagerv1.pri)
include(lib/abuledumessageboxv1/abuledumessageboxv1.pri)
include(lib/abuleduidentitesv1/abuleduidentitesv1.pri)
include(lib/abuleduflatboutonv1/abuleduflatboutonv1.pri)
include(lib/maia/maia.pri)
include(lib/abuledufilev1/abuledufilev1.pri)
include(lib/abuledustackedwidgetv1/abuledustackedwidgetv1.pri)
include(lib/abuledulangv1/abuledulangv1.pri)
include(lib/abuledumenufeuillev1/abuledumenufeuillev1.pri)
include(lib/abuledusingletonv1/abuledusingletonv1.pri)
include(lib/abuledupluginloaderv1/abuledupluginloaderv1.pri)
include(lib/abuleduloggerv1/abuleduloggerv1.pri)
include(lib/abuleduaproposv1/abuleduaproposv1.pri)
include(lib/abuleduandroidsupportv1/abuleduandroidsupportv1.pri)
include(lib/abuleduloadinganimationv1/abuleduloadinganimationv1.pri)
