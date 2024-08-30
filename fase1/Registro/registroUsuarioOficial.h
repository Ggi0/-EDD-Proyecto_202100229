#ifndef REGISTRO_USUARIOS_OFICIAL_H
#define REGISTRO_USUARIOS_OFICIAL_H

// PARA HACER EL OBJETO DE LA LISTA DE USUARIOS
#include "../Registro/global_data.h"


//arrayList_us listaGlobal_usuarios;

// ----- METODOS -----

    // Verifica si el correo esta repetido de lo contrario crea al usuario
    int verificarCorreo(std::string nombres, std::string apellidos, std::string fechaN, std::string correo, std::string contrasenia);

    // Para iniciar sesion 
    int iniciarSesion(std::string correo, std::string contrasenia);

    void verListaGlobal();

#endif // REGISTRO_USUARIOS_OFICIAL_H