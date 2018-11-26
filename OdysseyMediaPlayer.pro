#-------------------------------------------------
#
# Project created by QtCreator 2018-11-26T07:40:17
#
#-------------------------------------------------

QT       += core gui multimedia multimediawidgets

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TARGET = OdysseyMediaPlayer
TEMPLATE = app

# The following define makes your compiler emit warnings if you use
# any feature of Qt which as been marked as deprecated (the exact warnings
# depend on your compiler). Please consult the documentation of the
# deprecated API in order to know how to port your code away from it.
DEFINES += QT_DEPRECATED_WARNINGS

# You can also make your code fail to compile if you use deprecated APIs.
# In order to do so, uncomment the following line.
# You can also select to disable deprecated APIs only up to a certain version of Qt.
#DEFINES += QT_DISABLE_DEPRECATED_BEFORE=0x060000    # disables all the APIs deprecated before Qt 6.0.0


SOURCES += \
        main.cpp \
        mainwindow.cpp \
    videoplayer.cpp \
    nodecotroller.cpp \
    video.cpp \
    nodedisk.cpp \
    raid5.cpp \
    filemanagement.cpp

HEADERS += \
        mainwindow.h \
    videoplayer.h \
    nodecotroller.h \
    linkedlist.h \
    node.h \
    video.h \
    nodedisk.h \
    raid5.h \
    filemanagement.h

FORMS += \
        mainwindow.ui \
    videoplayer.ui \
    nodecotroller.ui

# Default rules for deployment.
qnx: target.path = /tmp/$${TARGET}/bin
else: unix:!android: target.path = /opt/$${TARGET}/bin
!isEmpty(target.path): INSTALLS += target

RESOURCES += \
    resources.qrc
