######################################################################
# Automatically generated by qmake (3.1) Thu Dec 6 09:50:29 2018
######################################################################
include ( ../../../libs/qwt-6.1.4/features/qwt.prf )

TEMPLATE = app
TARGET = QtEspUdpClient
INCLUDEPATH += .

CONFIG += qwt file_copies
COPIES += config_files
config_files.files = $$files(*.cfg)
config_files.path = $$OUT_PWD

# The following define makes your compiler warn you if you use any
# feature of Qt which has been marked as deprecated (the exact warnings
# depend on your compiler). Please consult the documentation of the
# deprecated API in order to know how to port your code away from it.
DEFINES += QT_DEPRECATED_WARNINGS

# You can also make your code fail to compile if you use deprecated APIs.
# In order to do so, uncomment the following line.
# You can also select to disable deprecated APIs only up to a certain version of Qt.
#DEFINES += QT_DISABLE_DEPRECATED_BEFORE=0x060000    # disables all the APIs deprecated before Qt 6.0.0

# Input
HEADERS += \
    configwizard.h \
    configwizard.h \
    mainwindow.h \
    controller.h \
    controller/ataritiacontroller.h \
    ui/tab_atari_tia.h \
    ui/tab_saa1099.h \
    ui/tab_ym2149.h \
    ui/atari_tia_audiochannel_widget.h \
    ui/saa1099_audiochannel_widget.h \
    ui/saa1099_noise_widget.h \
    ui/saa1099_envelope_widget.h \
    ui/tab_sn76489.h \
    ui/sn76489_audiochannel_widget.h \
    ui/sn76489_noise_widget.h \
    net/network_handler.h \
    net/coap_handler.h \
    net/udp_handler.h \
    net/mqtt_handler.h
FORMS += mainwindow.ui
SOURCES += main.cpp mainwindow.cpp \
    configwizard.cpp \
    controller/ataritiacontroller.cpp \
    ui/tab_atari_tia.cpp \
    ui/tab_saa1099.cpp \
    ui/tab_ym2149.cpp \
    ui/atari_tia_audiochannel_widget.cpp \
    ui/saa1099_audiochannel_widget.cpp \
    ui/saa1099_noise_widget.cpp \
    ui/saa1099_envelope_widget.cpp \
    ui/tab_sn76489.cpp \
    ui/sn76489_audiochannel_widget.cpp \
    ui/sn76489_noise_widget.cpp \
    net/network_handler.cpp \
    net/coap_handler.cpp \
    net/udp_handler.cpp \
    net/mqtt_handler.cpp

QT += widgets core gui network testlib

INCLUDEPATH += ../../../libs/qwt-6.1.4/include
DEPENDPATH += ../../../libs/qwt-6.1.4/include
LIBS += -L../../../libs/qwt-6.1.4/lib/ -lqwt


//unix:!macx: LIBS += qtcoap/libqtcoap/build/build-libqtcoap-Debug/ -lqtcoap1

//INCLUDEPATH += qtcoap/coap
INCLUDEPATH += sndchips
//DEPENDPATH += qtcoap/coap

LD_LIBRARY_PATH=../../../libs/qwt-6.1.4/lib:$LD_LIBRARY_PATH

unix:!macx: LIBS += -L$$PWD/qtcoap/libqtcoap/build/build-libqtcoap-Debug/ -lqtcoap1

INCLUDEPATH += $$PWD/qtcoap/coap
DEPENDPATH += $$PWD/qtcoap/coap


