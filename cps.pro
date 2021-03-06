#-------------------------------------------------
#
# Project created by QtCreator 2019-04-15T08:06:22
#
#-------------------------------------------------

QT       += core gui
QT += network
greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TARGET = cps
TEMPLATE = app

# The following define makes your compiler emit warnings if you use
# any feature of Qt which has been marked as deprecated (the exact warnings
# depend on your compiler). Please consult the documentation of the
# deprecated API in order to know how to port your code away from it.
DEFINES += QT_DEPRECATED_WARNINGS

# You can also make your code fail to compile if you use deprecated APIs.
# In order to do so, uncomment the following line.
# You can also select to disable deprecated APIs only up to a certain version of Qt.
#DEFINES += QT_DISABLE_DEPRECATED_BEFORE=0x060000    # disables all the APIs deprecated before Qt 6.0.0

CONFIG += c++11

SOURCES += \
        main.cpp \
        mainwindow.cpp   \
        mode_base.cpp \
    mode_abc.cpp \
    mode_2abc.cpp \
    mode_abcn.cpp \
    mode_abc2n.cpp \
    mode_2abcn.cpp \
    mode_2abc2n.cpp \
    mode_abcnpe.cpp \
    mode_abcn2pe.cpp \
    mode_abc2npe.cpp \
    mode_abc2n2pe.cpp \
    mode_2abcnpe.cpp \
    mode_2abcn2pe.cpp \
    mode_2abc2npe.cpp \
    mode_2abc2n2pe.cpp \
    mode_4abcn.cpp \
    mode_4abcnpe.cpp \
    mode_pm.cpp \
    mode_prepeatnum.cpp \
    mode_price.cpp \
    mode_pricem.cpp \
    mode_42abc2n.cpp \
    mode_42abc2npe.cpp \
    mode_paimt.cpp \
    mode_prepeat.cpp \
    mode_segmentplus.cpp \
    mode_selectplus.cpp \
    mode_merge.cpp \
    mode_mergevalue.cpp \
    man.cpp \
    man_painumber.cpp \
    man_price.cpp \
    man_pricenumber.cpp \
    man_painumbertaishu.cpp \
    man_repeatlast.cpp \
    man_repeatlastnumber.cpp \
    man_segmentnumbercishu.cpp \
    man_segmentabcnumber.cpp \
    man_mergenumber.cpp \
    man_getmergenumber.cpp

HEADERS += \
        mainwindow.h \
        mode_base.h \
    mode_abc.h \
    mode_2abc.h \
    mode_abcn.h \
    mode_abc2n.h \
    mode_2abcn.h \
    mode_2abc2n.h \
    mode_abcnpe.h \
    mode_abcn2pe.h \
    mode_abc2npe.h \
    mode_abc2n2pe.h \
    mode_2abcnpe.h \
    mode_2abcn2pe.h \
    mode_2abc2npe.h \
    mode_2abc2n2pe.h \
    mode_4abcn.h \
    mode_4abcnpe.h \
    mode_pm.h \
    mode_prepeatnum.h \
    mode_price.h \
    mode_pricem.h \
    mode_42abc2n.h \
    mode_42abc2npe.h \
    mode_paimt.h \
    mode_prepeat.h \
    mode_segmentplus.h \
    mode_selectplus.h \
    mode_merge.h \
    mode_mergevalue.h \
    man.h \
    man_painumber.h \
    man_price.h \
    man_pricenumber.h \
    man_painumbertaishu.h \
    man_repeatlast.h \
    man_repeatlastnumber.h \
    man_segmentnumbercishu.h \
    man_segmentabcnumber.h \
    man_mergenumber.h \
    man_getmergenumber.h

FORMS += \
        mainwindow.ui

# Default rules for deployment.
qnx: target.path = /tmp/$${TARGET}/bin
else: unix:!android: target.path = /opt/$${TARGET}/bin
!isEmpty(target.path): INSTALLS += target

DISTFILES += \
    readme.md



RESOURCES +=
