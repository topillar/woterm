QT       += core gui network
greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TEMPLATE=app
include(../qtermwidget/qtermwidget.pri)
include($$PWD/../third/aes/aes.pri)

DESTDIR = $$PROJECT_BINDIR
unix:QMAKE_RPATHDIR+=$$PROJECT_LIBDIR
SOURCES += main.cpp \
    ipchelper.cpp \
    qwotermwidget.cpp \
    qwotermwidgetimpl.cpp \
    qwoprocess.cpp \
    qwosshprocess.cpp \
    qwoevent.cpp \
    qwosetting.cpp \
    qwomainwindow.cpp \
    qwoshower.cpp \
    qwowidget.cpp \
    qwosessionmanager.cpp \
    qwosshconf.cpp \
    qwohostinfolist.cpp \
    qwoutils.cpp \
    qwohostinfoedit.cpp \
    qwohostsimplelist.cpp \
    qwohostlistmodel.cpp \
    qwosessionproperty.cpp \
    qwoaes.cpp

HEADERS += \
    ipchelper.h \
    qwotermwidget.h \
    qwotermwidgetimpl.h \
    qwoprocess.h \
    qwosshprocess.h \
    qwoevent.h \
    qwosetting.h \
    qwomainwindow.h \
    qwoshower.h \
    qwowidget.h \
    qwosessionmanager.h \
    qwosshconf.h \
    qwoglobal.h \
    qwohostinfolist.h \
    qwoutils.h \
    qwohostinfoedit.h \
    qwohostsimplelist.h \
    qwohostlistmodel.h \
    qwosessionproperty.h \
    qwoaes.h

FORMS += \
    qwohostlist.ui \
    qwohostinfolist.ui \
    qwohostinfo.ui \
    qwomainwindow.ui \
    qwosessionproperty.ui
