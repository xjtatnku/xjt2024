CONFIG += resources_big
QT       += core gui multimedia

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TARGET = ../PlantsVsZombies
TEMPLATE = app
DEFINES += QT_DEPRECATED_WARNINGS

CONFIG += c++11

SOURCES += \
    src/other/button.cpp \
    src/other/card.cpp \
    src/other/dialog.cpp \
    src/other/map.cpp \
    src/other/mower.cpp \
    src/other/other.cpp \
    src/other/pea.cpp \
    src/other/shop.cpp \
    src/other/shovel.cpp \
    src/other/startwindow.cpp \
    src/other/sun.cpp \
    src/other/main.cpp \
    src/other/mainwindow.cpp \
    src/plant/cherrybomb.cpp \
    src/plant/peashooter.cpp \
    src/plant/plant.cpp \
    src/plant/potatomine.cpp \
    src/plant/repeater.cpp \
    src/plant/snowpea.cpp \
    src/plant/sunflower.cpp \
    src/plant/wallnut.cpp \
    src/zombie/basiczombie.cpp \
    src/zombie/bucketzombie.cpp \
    src/zombie/conezombie.cpp \
    src/zombie/rugbyzombie.cpp \
    src/zombie/zombie.cpp

HEADERS += \
    src/other/button.h \
    src/other/card.h \
    src/other/dialog.h \
    src/other/map.h \
    src/other/mower.h \
    src/other/other.h \
    src/other/pea.h \
    src/other/shop.h \
    src/other/shovel.h \
    src/other/startwindow.h \
    src/other/sun.h \
    src/other/mainwindow.h \
    src/plant/cherrybomb.h \
    src/plant/peashooter.h \
    src/plant/plant.h \
    src/plant/potatomine.h \
    src/plant/repeater.h \
    src/plant/snowpea.h \
    src/plant/sunflower.h \
    src/plant/wallnut.h \
    src/zombie/basiczombie.h \
    src/zombie/bucketzombie.h \
    src/zombie/conezombie.h \
    src/zombie/rugbyzombie.h \
    src/zombie/zombie.h \
    src/other/init.h

qnx: target.path = /tmp/$${TARGET}/bin
else: unix:!android: target.path = /opt/$${TARGET}/bin
!isEmpty(target.path): INSTALLS += target

RESOURCES += \
    images.qrc


# 图标
RC_ICONS += \
    ./images/window.ico

FORMS += \
    src/other/dialog.ui
