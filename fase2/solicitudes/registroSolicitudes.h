#include "../usuarios/global_usuariosAVL.h"

// para los objetos solicitudes
#include "solicitud.h"

/*
    -> buscar EMISOR (lista_global)
    si EMISOR existe
        -> buscar RECEPTOR (lista_global)
        si RECEPTOR existe
            -> verificar estado (ACEPTADA / PENDIENTE / RECHAZADA)
                si estado == "ACEPTADA"
                    append(ID) a listaAmigos del emisor y receptor
                si estado == "PENDIENTE"
                    -> append(solicitud) a lista_solicitudes del emisor
                    -> push(solicitud) a la pila del receptor 
                si estado == "RECHAZADA"
                    -> buscar Solicitud en Pila quien la recibio (emisor) y eliminar
                    -> buscar Solicitud en lista_solicitudes del quien primero la envio y eliminar
 */
//void registroSolicitudes1(std::string emisor, std::string receptor, std::string estado);
int registroSolicitudes(std::string emisor, std::string receptor, std::string estado);
