#ifndef REGISTRO_PUBLICACIONES_H
#define REGISTRO_PUBLICACIONES_H

// para LISTA DOBLEMENTE ENLAZADA de publicaciones
#include "global_data_publicaciones.h"
#include "../usuarios/global_usuariosAVL.h"

#include "comentario/listaComentarios/lista_comentarios.h"
#include <string>


// ----- METODOS -----
    /* 
    verificar Correo:
        verificarCorreo_publicacion()
        ver si hay un Usuario con el correo de la publicacion
    */
    void verificarCorreo_publicacion(std::string correo, std::string contenido, std::string fecha, std::string hora, lista_comentarios lista_comentarios);
  //Void verificarCorreo_publicacion(const std::string& correo, const std::string& contenido, const std::string& fecha, const std::string& hora, const lista_comentarios& lista_comentarios)
    bool validarFormatoFecha(std::string fecha);

    // asignar a listaGlobal_publicaciones
    void asignarListaGlobal_publicaciones(Publicacion Publicacion);

    void asignarBSTpersonal(Publicacion nuevaPublicacion, std::string correo, std::string fecha);

    void graficar();

#endif // REGISTRO_USUARIOS_PUBLICACIONES_H
