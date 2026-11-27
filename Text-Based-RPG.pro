QT += widgets

CONFIG += c++17

# You can make your code fail to compile if it uses deprecated APIs.
# In order to do so, uncomment the following line.
#DEFINES += QT_DISABLE_DEPRECATED_BEFORE=0x060000    # disables all the APIs deprecated before Qt 6.0.0

SOURCES += \
    assets/entity/entity.cpp \
    assets/entity/character.cpp \
    assets/entity/item.cpp \
    assets/environment/environment.cpp \
    assets/environment/tilelist.cpp \
    assets/widgets/boardsetup.cpp \
    assets/widgets/gamewidget.cpp \
    assets/widgets/characterselect.cpp \
    main.cpp \


HEADERS += \
    assets/entity/entity.h \
    assets/entity/character.h \
    assets/entity/item.h \
    assets/environment/environment.h \
    assets/environment/tilelist.h \
    assets/widgets/boardsetup.h \
    assets/widgets/gamewidget.h \
    assets/widgets/characterselect.h


FORMS += \
    assets/widgets/boardsetup.ui \
    assets/widgets/gamewidget.ui \
    assets/widgets/characterselect.ui

# Default rules for deployment.
qnx: target.path = /tmp/$${TARGET}/bin
else: unix:!android: target.path = /opt/$${TARGET}/bin
!isEmpty(target.path): INSTALLS += target
