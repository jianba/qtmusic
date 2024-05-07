# QT blank project
# author    hancq
# date      2016-08-05

QT += multimedia
QT += core gui sql

QT += widgets

TARGET = qtmusic

SOURCES += \
    main.cpp \
    mainwidget.cpp \
    music.cpp \
    musiclist.cpp \
    musiclistwidget.cpp

HEADERS += \
    mainwidget.h \
    music.h \
    musiclist.h \
    musiclistdialog.h \
    musiclistwidget.h

FORMS += \
    mainwidget.ui

RESOURCES += \
    image.qrc
