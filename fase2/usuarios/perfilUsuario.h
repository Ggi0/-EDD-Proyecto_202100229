#ifndef PERFIL_USUARIO_H
#define PERFIL_USUARIO_H
#include <iostream>
#include <iomanip>  // Para std::setw y std::setfill
#include <ctime>    // Para std::time y std::tm
#include <sstream>  // Para std::ostringstream
#include "../publicaciones/comentario/listaComentarios/lista_comentarios.h"
#include "../publicaciones/registroPublicaciones.h"



void hacerPublicacion(const std::string& correo, const std::string& contenido);

std::string obtenerFechaActual();
std::string obtenerHoraActual();


#endif // MENU_USUARIO_H