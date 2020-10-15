QT       += core gui

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

CONFIG += c++11

# You can make your code fail to compile if it uses deprecated APIs.
# In order to do so, uncomment the following line.
#DEFINES += QT_DISABLE_DEPRECATED_BEFORE=0x060000    # disables all the APIs deprecated before Qt 6.0.0

SOURCES += \
    adminchinese.cpp \
    admindiscount.cpp \
    admindisplay.cpp \
    adminnonveg.cpp \
    adminveg.cpp \
    customer.cpp \
    logindialog.cpp \
    main.cpp \
    mainwindow.cpp \
    orderbill.cpp \
    orderchinese.cpp \
    orderdisplaly.cpp \
    ordernonveg.cpp \
    orderprice.cpp \
    orderveg.cpp

HEADERS += \
    adminchinese.h \
    admindiscount.h \
    admindisplay.h \
    adminnonveg.h \
    adminveg.h \
    customer.h \
    logindialog.h \
    mainwindow.h \
    orderbill.h \
    orderchinese.h \
    orderdisplaly.h \
    ordernonveg.h \
    orderprice.h \
    orderveg.h

FORMS += \
    adminchinese.ui \
    admindiscount.ui \
    admindisplay.ui \
    adminnonveg.ui \
    adminveg.ui \
    customer.ui \
    logindialog.ui \
    mainwindow.ui \
    orderbill.ui \
    orderchinese.ui \
    orderdisplaly.ui \
    ordernonveg.ui \
    orderprice.ui \
    orderveg.ui

# Default rules for deployment.
qnx: target.path = /tmp/$${TARGET}/bin
else: unix:!android: target.path = /opt/$${TARGET}/bin
!isEmpty(target.path): INSTALLS += target

RESOURCES += \
    IMAGES.qrc
