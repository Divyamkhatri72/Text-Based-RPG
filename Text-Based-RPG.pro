TEMPLATE = app
CONFIG += console c++17
CONFIG -= app_bundle
CONFIG -= qt

SOURCES += main.cpp \
        assets/Entity/entity.cpp \
        assets/Environment/environment.cpp


HEADERS += \
    assets/Entity/entity.h \
    assets/Environment/environment.h
