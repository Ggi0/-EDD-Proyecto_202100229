#include "registroPublicaciones.h"
#include "../Registro/global_data.h"

#include <string>

ListaDoblementeEnlazadaP listaGlobal_publicaciones; 

/*

    1) verificar si la lista global de usuarios no este vacia.
    2) recorrer la listaGlobal_usuarios hasta encontrar un correo con el que coincida el paramtreo correo
 */
void verificarCorreo_publicacion(std::string correo, std::string contenido, std::string fecha, std::string hora) {
    // 1) Verificar que la listaGlobal_usuarios no esté vacía
    if (listaGlobal_usuarios.size() == 0) {
        std::cout << "Error: No hay usuarios en la aplicacion (lista vacia)." << std::endl;
        return;
    }

    // 2) Recorrer la lista global de usuarios
    usuarios_Nodo* actual = listaGlobal_usuarios.getPrimero();
    bool correoEncontrado = false;

    while (actual != nullptr) {
        if (actual->getDato().getCorreo() == correo) {
            correoEncontrado = true;
            break;
        }
        actual = actual->getSig();
    }

    // 3) Si se encuentra el correo, crear y asignar la publicación
    if (correoEncontrado) {
        Publicacion nuevaPublicacion(correo, contenido, fecha, hora);
        asignarListaGlobal_publicaciones(nuevaPublicacion);
        asignarListaPersonal_publicaciones(nuevaPublicacion, correo);
        std::cout << "Publicacion creada y asignada correctamente." << std::endl<< std::endl;
    } else {
        std::cout << "Error: El correo no corresponde a ningun usuario registrado." << std::endl;
    }
}

// asignar a listaGlobal_publicaciones
void asignarListaGlobal_publicaciones(Publicacion publicacion) {
    // Agregar la publicación a la lista global de publicaciones
    listaGlobal_publicaciones.append(publicacion);
}

/*
    la publicación debe verse en el feed de los amigos del usuario.
    por lo tanto se recorrera la lista de amigos (tienen el ID)
    y a cada usuario de esa lista se le agregara a su lista personal de publicaciones la Publicacion actual.

    si la publicación ya se encuentra no se agrega.

    son 2 asignaciones:
        la primera a ListaCircular_Dpp lista_publicacionesP;
        la segunda a ListaCircular_Dpp lista_publicacionesP de cada usuario que este en la lista de amigos 

*/
void asignarListaPersonal_publicaciones(Publicacion publicacion, std::string correo) {
    // 1. Recorrer la lista global de usuarios para encontrar el usuario con el correo dado
    usuarios_Nodo* usuarioActual = listaGlobal_usuarios.getPrimero();
    while (usuarioActual != nullptr) {
        if (usuarioActual->getDato().getCorreo() == correo) {
            // Agregar la publicación a la lista de publicaciones del usuario
            usuarioActual->getDato().agregarPublicacion(publicacion);
            
            // 2. Recorrer la lista de amigos del usuario
            listaSimpleEnlazada& listaAmigos = usuarioActual->getDato().getLista_amigos();
            Nodo* amigoActual = listaAmigos.getPrimero();
            while (amigoActual != nullptr) {
                int idAmigo = amigoActual->getData();
                
                // Buscar el amigo en la lista global de usuarios
                usuarios_Nodo* amigoUsuario = listaGlobal_usuarios.getPrimero();
                while (amigoUsuario != nullptr) {
                    if (amigoUsuario->getDato().getID() == idAmigo) {
                        // Verificar si el usuario es realmente un amigo (para mayor seguridad)
                        if (amigoUsuario->getDato().esAmigo(usuarioActual->getDato().getID())) {
                            // Agregar la publicación a la lista de publicaciones del amigo
                            amigoUsuario->getDato().agregarPublicacion(publicacion);
                            std::cout<<"Publicación agregada a: "<<amigoUsuario->getDato().getNombres()<<std::endl;
                        }
                        break;  // Salir del bucle interno una vez que se encuentra el amigo
                    }
                    amigoUsuario = amigoUsuario->getSig();
                }
                
                amigoActual = amigoActual->getSig();
            }
            
            break;  // Salir del bucle principal una vez que se encuentra el usuario
        }
        usuarioActual = usuarioActual->getSig();
    }
}



