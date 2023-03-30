TEMPLATE = app
CONFIG += console c++11
CONFIG -= app_bundle
CONFIG -= qt

INCLUDEPATH += bib
INCLUDEPATH += gui_glut
INCLUDEPATH += src

LIBS += -lGL -lGLU -lglut -l3ds -lSDL_image

SOURCES += main.cpp \
    bib/Camera.cpp \
    bib/CameraDistante.cpp \
    bib/CameraJogo.cpp \
    bib/Desenha.cpp \
    bib/model3ds.cpp \
    bib/Vetor3D.cpp \
    gui_glut/extra.cpp \
    gui_glut/gui.cpp \
    src/Armario.cpp \
    src/Balcao.cpp \
    src/Barril.cpp \
    src/Caneca.cpp \
    src/Mesa.cpp \
    src/Objeto.cpp \
    src/Parede.cpp \
    src/Prateleira.cpp \
    src/Tamborete.cpp \ 

HEADERS += \
    bib/Camera.h \
    bib/CameraDistante.h \
    bib/CameraJogo.h \
    bib/Desenha.h \
    bib/model3ds.h \
    bib/Vetor3D.h \
    bib/json.hpp \
    gui_glut/extra.h \
    gui_glut/gui.h \
    src/Armario.h \
    src/Balcao.h \
    src/Barril.h \
    src/Caneca.h \
    src/Mesa.h \
    src/Objeto.h \
    src/Parede.h \
    src/Prateleira.h \
    src/Tamborete.h \