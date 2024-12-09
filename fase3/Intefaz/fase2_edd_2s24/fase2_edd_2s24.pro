QT       += core gui

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

CONFIG += c++11

# You can make your code fail to compile if it uses deprecated APIs.
# In order to do so, uncomment the following line.
#DEFINES += QT_DISABLE_DEPRECATED_BEFORE=0x060000    # disables all the APIs deprecated before Qt 6.0.0

# Define directories
USUARIOS_DIR = $$PWD/../../usuarios
ARBOLAVL_DIR = $$USUARIOS_DIR/arbolAVL
LISTAAMIGOS_DIR = $$USUARIOS_DIR/listaEnlazadaInt
SOLICITUDES_DIR = $$PWD/../../solicitudes
LISTSOLICITUDES_DIR = $$SOLICITUDES_DIR/listaEnlazadaSolicitudes
PILASOLICITUDES_DIR = $$SOLICITUDES_DIR/pilaSolicitudes
ADYACENCIA_DIR = $$SOLICITUDES_DIR/listaAdyacencia
SUGERENCIAS_DIR = $$ADYACENCIA_DIR/sugerenciaAmistad
PUBLICACIONES_DIR = $$PWD/../../publicaciones
ARBOLBB_DIR = $$PUBLICACIONES_DIR/arbolBinario
COMENTARIOS_DIR = $$PUBLICACIONES_DIR/comentario
LISTACOMENTARIOS_DIR = $$COMENTARIOS_DIR/listaComentarios
ARBOLB_DIR = $$COMENTARIOS_DIR/arbolB
LISTADEPUBLI_DIR = $$PUBLICACIONES_DIR/listaDobleEnlazada
ADMIN_DIR = $$PWD/../../administracion
MODELOS_DIR = $$PWD/../modelosTablas
MODENVIARSOLI_DIR = $$MODELOS_DIR/modeloEnviarSoli
MODACEPTARSOLI_DIR = $$MODELOS_DIR/modeloPila
MODLISTAENVSOLI_DIR = $$MODELOS_DIR/modeloLista
SEGURIDAD_DIR = $$PWD/../../seguridad
MERKLE_DIR = $$SEGURIDAD_DIR/merkle
HUFFMAN_DIR = $$SEGURIDAD_DIR/huffman
BLOCKCHAIN_DIR = $$SEGURIDAD_DIR/bloques
LISTABLOCK_DIR = $$BLOCKCHAIN_DIR/listaBloques

SOURCES += \
    form_admin.cpp \
    form_registrarusuarios.cpp \
    form_usuario.cpp \
    main.cpp \
    mainwindow.cpp \
    $$PUBLICACIONES_DIR/*.cpp \
    $$USUARIOS_DIR/*.cpp \
    $$ARBOLAVL_DIR/*.cpp \
    $$LISTAAMIGOS_DIR/*.cpp \
    $$SOLICITUDES_DIR/*.cpp \
    $$LISTSOLICITUDES_DIR/*.cpp \
    $$PILASOLICITUDES_DIR/*.cpp \
    $$ADYACENCIA_DIR/*.cpp \
    $$SUGERENCIAS_DIR/*.cpp \
    $$ARBOLBB_DIR/*.cpp \
    $$COMENTARIOS_DIR/*.cpp \
    $$LISTADEPUBLI_DIR/*.cpp \
    $$LISTACOMENTARIOS_DIR/*.cpp \
    $$ARBOLB_DIR/*.cpp \
    $$ADMIN_DIR/*.cpp \
    $$MODENVIARSOLI_DIR/*.cpp \
    $$MODACEPTARSOLI_DIR/*.cpp \
    $$MODLISTAENVSOLI_DIR/*.cpp \
    $$SEGURIDAD_DIR/*.cpp \
    $$MERKLE_DIR/*.cpp \
    $$HUFFMAN_DIR/*.cpp \
    $$BLOCKCHAIN_DIR/*.cpp \
    $$LISTABLOCK_DIR/*.cpp

HEADERS += \
    form_admin.h \
    form_registrarusuarios.h \
    form_usuario.h \
    mainwindow.h \
    $$PUBLICACIONES_DIR/*.h \
    $$USUARIOS_DIR/*.h \
    $$ARBOLAVL_DIR/*.h \
    $$LISTAAMIGOS_DIR/*.h \
    $$SOLICITUDES_DIR/*.h \
    $$LISTSOLICITUDES_DIR/*.h \
    $$PILASOLICITUDES_DIR/*.h \
    $$ADYACENCIA_DIR/*.h \
    $$SUGERENCIAS_DIR/*.h \
    $$ARBOLBB_DIR/*.h \
    $$COMENTARIOS_DIR/*.h \
    $$LISTADEPUBLI_DIR/*.h \
    $$LISTACOMENTARIOS_DIR/*.h \
    $$ARBOLB_DIR/*.h \
    $$ADMIN_DIR/*.h \
    $$MODENVIARSOLI_DIR/*.h \
    $$MODACEPTARSOLI_DIR/*.h \
    $$MODLISTAENVSOLI_DIR/*.h \
    $$SEGURIDAD_DIR/*.h \
    $$MERKLE_DIR/*.h \
    $$HUFFMAN_DIR/*.h \
    $$BLOCKCHAIN_DIR/*.h \
    $$LISTABLOCK_DIR/*.h

FORMS += \
    form_admin.ui \
    form_registrarusuarios.ui \
    form_usuario.ui \
    mainwindow.ui

# Include directories
INCLUDEPATH += \
    $$USUARIOS_DIR \
    $$ARBOLAVL_DIR \
    $$LISTAAMIGOS_DIR \
    $$SOLICITUDES_DIR \
    $$LISTSOLICITUDES_DIR \
    $$PILASOLICITUDES_DIR \
    $$ADYACENCIA_DIR \
    $$SUGERENCIAS_DIR \
    $$PUBLICACIONES_DIR \
    $$ARBOLBB_DIR \
    $$COMENTARIOS_DIR \
    $$LISTACOMENTARIOS_DIR \
    $$ARBOLB_DIR \
    $$LISTADEPUBLI_DIR \
    $$ADMIN_DIR \
    $$MODENVIARSOLI_DIR \
    $$MODACEPTARSOLI_DIR \
    $$MODLISTAENVSOLI_DIR \
    $$SEGURIDAD_DIR \
    $$MERKLE_DIR \
    $$HUFFMAN_DIR \
    $$BLOCKCHAIN_DIR \
    $$LISTABLOCK_DIR

# Default rules for deployment.
qnx: target.path = /tmp/$${TARGET}/bin
else: unix:!android: target.path = /opt/$${TARGET}/bin
!isEmpty(target.path): INSTALLS += target
