TEMPLATE = app
CONFIG += console c++11
CONFIG -= app_bundle
CONFIG -= qt

SOURCES += \
        Vector2d.cpp \
        main.cpp \
        node.cpp \
        quadtree.cpp

HEADERS += \
    GameObject.h \
    Vector2d.h \
    node.h \
    quadtree.h
