#ifndef REGISTRO_PUBLICACIONES_H
#define REGISTRO_PUBLICACIONES_H

// para LISTA DOBLEMENTE ENLAZADA de publicaciones
#include "global_data_publicaciones.h"
#include "../Registro/global_data.h"
#include "publicacion.h"


// ----- METODOS -----
    /* 
    verificar Correo:
        verificarCorreo_publicacion()
        ver si hay un Usuario con el correo de la publicacion
    */
   void verificarCorreo_publicacion(std::string correo, std::string contenido, std::string fecha, std::string hora);


    // asignar a listaGlobal_publicaciones
    void asignarListaGlobal_publicaciones(Publicacion Publicacion);

    /*
    asignar a listaPersonal_publicaciones de cada usuario
        -> de igual modo recorrer la lista de amigos y asiganar la misma publicación al usuario
    */
    void asignarListaPersonal_publicaciones(Publicacion publicacion, std::string correo);

    void graficar();

#endif // REGISTRO_USUARIOS_PUBLICACIONES_H
