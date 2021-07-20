QT       += core gui

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

CONFIG += c++11

# You can make your code fail to compile if it uses deprecated APIs.
# In order to do so, uncomment the following line.
#DEFINES += QT_DISABLE_DEPRECATED_BEFORE=0x060000    # disables all the APIs deprecated before Qt 6.0.0

SOURCES += \
    changebirthday.cpp \
    changename.cpp \
    changepass.cpp \
    changephone.cpp \
    formchange.cpp \
    formchangeinformation.cpp \
    formforget.cpp \
    forminfogame.cpp \
    forminformation.cpp \
    formlogin.cpp \
    formregister.cpp \
    formscore.cpp \
    game.cpp \
    main.cpp \
    mainwindow.cpp

HEADERS += \
    Function.h \
    LoginAndRegister.h \
    Structure.h \
    changebirthday.h \
    changename.h \
    changepass.h \
    changephone.h \
    formchange.h \
    formchangeinformation.h \
    formforget.h \
    forminfogame.h \
    forminformation.h \
    formlogin.h \
    formregister.h \
    formscore.h \
    game.h \
    mainwindow.h

FORMS += \
    changebirthday.ui \
    changename.ui \
    changepass.ui \
    changephone.ui \
    formchange.ui \
    formchangeinformation.ui \
    formforget.ui \
    forminfogame.ui \
    forminformation.ui \
    formlogin.ui \
    formregister.ui \
    formscore.ui \
    game.ui \
    mainwindow.ui

# Default rules for deployment.
qnx: target.path = /tmp/$${TARGET}/bin
else: unix:!android: target.path = /opt/$${TARGET}/bin
!isEmpty(target.path): INSTALLS += target

RESOURCES += \
    res.qrc
