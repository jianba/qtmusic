# QT blank project
# author    hancq
# date      2016-08-05

QT += multimedia
QT += core gui sql

QT += widgets

TARGET = qtmusic

SOURCES += \
    lyricwidget.cpp \
    main.cpp \
    mainwidget.cpp \
    music.cpp \
    musiclist.cpp \
    musiclistwidget.cpp

HEADERS += \
    lyricwidget.h \
    mainwidget.h \
    music.h \
    musiclist.h \
    musiclistdialog.h \
    musiclistwidget.h \
    myQSS.h

FORMS += \
    lyricwidget.ui \
    mainwidget.ui

RESOURCES += \
    image.qrc
