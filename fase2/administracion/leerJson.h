#ifndef LEER_JSON_H
#define LEER_JSON_H

#include <iostream>
#include <fstream>
#include "json.hpp"
#include "../usuarios/registroUsuarios.h"
#include "../publicaciones/registroPublicaciones.h"
#include "../solicitudes/registroSolicitudes.h"
#include "../publicaciones/comentario/listaComentarios/lista_comentarios.h"



void leerUsuarios(const std::string& pathDelArchivo);
void leerSolicitudes(const std::string& pathDelArchivo);
void leerPublicaciones(const std::string& pathDelArchivo);

#endif // LEER_JSON_H

///Users/gio/Desktop/Edd_2s24/lab_edd_2s24/-EDD-Proyecto_202100229/fase1/archivos Json