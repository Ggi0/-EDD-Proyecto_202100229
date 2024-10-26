#ifndef REGISTRO_USUARIOS_H
#define REGISTRO_USUARIOS_H

// Arbol AVL globla de USUARIOS
#include "global_usuariosAVL.h"
#include "../solicitudes/global_relacionesAmistad.h"


// ----- METODOS -----

// Verificar si el correo esta repetido,sino lo esta crea al usuario
int verificarCorreo(std::string nombres, std::string apellidos, std::string fechaN, std::string correo, std::string contrasenia);

// Para iniciar sesion 
int iniciarSesion(std::string correo, std::string contrasenia);

void verListaGlobal();

#endif // REGISTRO_USUARIOS_H