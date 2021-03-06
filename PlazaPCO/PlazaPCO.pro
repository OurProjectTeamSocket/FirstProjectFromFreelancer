QT       += core gui concurrent

TEMPLATE = app
TARGET = PlazaPCO
TEMPLATE = app

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

CONFIG += c++11

# You can make your code fail to compile if it uses deprecated APIs.
# In order to do so, uncomment the following line.
#DEFINES += QT_DISABLE_DEPRECATED_BEFORE=0x060000    # disables all the APIs deprecated before Qt 6.0.0

SOURCES += \
    main.cpp \
    mainwindow.cpp

HEADERS += \
    mainwindow.h

FORMS += \
    mainwindow.ui

LIBS += -L/usr/local/lib

 INCLUDEPATH += /usr/local/include

 QT_CONFIG -= no-pkg-config
 CONFIG += link_pkgconfig
 PKGCONFIG += opencv

# Default rules for deployment.
qnx: target.path = /tmp/$${TARGET}/bin
else: unix:!android: target.path = /opt/$${TARGET}/bin
!isEmpty(target.path): INSTALLS += target

RESOURCES += \
    images.qrc

macx: LIBS += -L$$PWD/../../../../Downloads/chilkat-9.5.0-macosx/libStatic/ -lchilkat_x86_64

INCLUDEPATH += $$PWD/../../../../Downloads/chilkat-9.5.0-macosx/include
DEPENDPATH += $$PWD/../../../../Downloads/chilkat-9.5.0-macosx/include

macx: PRE_TARGETDEPS += $$PWD/../../../../Downloads/chilkat-9.5.0-macosx/libStatic/libchilkat_x86_64.a
