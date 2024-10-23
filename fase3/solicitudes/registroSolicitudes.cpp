#include "registroSolicitudes.h"
#include <functional>
#include <string>

/*
    RESTRICCIONES:

    para estado == "PENDIENTE"
    1) si el EMISOR (el que entro como parámetro al método) en su pila ya tiene un objeto Solicitud con el correo del RECEPTOR en el atributo emisor, la solicitud debe ser cancelada, e imprimir un mensaje: "Usted tiene una Solicitud pendiente de esta persona"
    2) si el EMISOR en su lista de Solicitudes ya tiene un objeto Solicitud con el correo del RECEPTOR en el atributo de Receptor debe imprimirce por pantalla: "Usted ya le envio una solicitud a esta persona"
    
    para estado == "ACEPTADA"
    si el ID del RECEPTOR ya esta en la lista_amigos del EMISOR, se debe cancelar la solicitud, y debe imprimirce por pantalla: "Usted ya es amigo de esta persona"
    si el EMISOR en su pila ya tiene un objeto Solicitud con el correo del RECEPTOR en el atributo del emisor
        debe eliminar el objeto Solicitud de su pila y de la listaSolicitudes del RECEPTOR y agregar el ID de RECEPTOR actual a su lista_amigos.
    
    PAra estado == "RECHAZADA"
    si en la pilaSolicitudes (del EMISOR) no hay un objeto Solicitud del RECEPTOR (en el objeto el actual RECEPTOR debe estar en el atributo del emisor)deber imprimirce por pantalla: "Usted no tiene ninguan solicitud de amistad de esta persona"
    si en la pilaSolicitudes si existe este objeto, debe ser eliminado al igual que en la listaSOlicitudes del RECEPTOR 


    (no implementado)
    si el EMISOR NO tiene en su pila un objeto Solicitud con el correo del RECEPTOR en el atributo del emisor, deber imprimirce por pantalla: "Usted no tiene ninguan solicitud de amistad de esta persona"
    si el EMISOR trata de enviarse una solicitud a si mismo.

 *  Emisor o Receptor no existen -> return 0
 *                   arbol vacio -> return 1
 *                    si existen -> return 2
 * 
 *  ACEPTADA -> return 3 (ya son amigos)
 *              return 4 (agregados como amigos)
 * 
 *  PENDIENTE -> return 5 (Usted tiene una Solicitud pendiente de esta persona)
 *               return 6 (Usted ya le envió una solicitud a esta persona)
 *               return 7 (Solicitud pendiente agregada.)
 * 
 *  RECHAZADA -> return 8 (Rechaza con exito)
 *               return 9 (Error no hay que rechazar.)
 */
int registroSolicitudes(std::string emisor, std::string receptor, std::string estado) {
    // 1) Verificar que arbolGlobal_usuarios no esté vacío
    if (arbolGlobal_usuarios.getRaiz() == nullptr) {
        std::cout << "Error: No hay usuarios en la aplicación (árbol vacío)." << std::endl;
        return 1;
    }

    // 2) Buscar al emisor y receptor en el arbolGlobal_usuarios
    NodoAVL* nodoEmisor = arbolGlobal_usuarios.buscarPorCorreo(emisor);
    NodoAVL* nodoReceptor = arbolGlobal_usuarios.buscarPorCorreo(receptor);

    if (nodoEmisor == nullptr || nodoReceptor == nullptr) {
        std::cout << "Error: Emisor o receptor no encontrado." << std::endl;
        return 0;
    }

    Usuarios& usuarioEmisor = nodoEmisor->getData();
    Usuarios& usuarioReceptor = nodoReceptor->getData();

    /// ------ ACEPTADA ----------
    if (estado == "ACEPTADA") {
        // Verificar si ya son amigos
        if (usuarioEmisor.esAmigo(usuarioReceptor.getID())) {
            std::cout << "Los usuarios ya son amigos." << std::endl;
            return 3; // Código: ya son amigos
        }

        // Verificar si hay una solicitud pendiente del emisor al receptor en la lista del receptor
        arrayList_soli& listaReceptor = usuarioReceptor.getListaSolicitudes();
        solicitud_Nodo* actual = listaReceptor.getPrimero();
        solicitud_Nodo* anterior = nullptr;
        bool solicitudEncontrada = false;

        std::cout << "Buscando solicitud de " << emisor << " a " << receptor << " en la lista del receptor" << std::endl;

        while (actual != nullptr) {
            std::cout << "Revisando solicitud: Emisor=" << actual->getDato().getEmisor() 
                    << ", Receptor=" << actual->getDato().getReceptor() 
                    << ", Estado=" << actual->getDato().getEstado() << std::endl;

            if (actual->getDato().getEmisor() == receptor && 
                actual->getDato().getReceptor() == emisor && 
                actual->getDato().getEstado() == "PENDIENTE") {
                solicitudEncontrada = true;
                std::cout << "Solicitud ACEPTADA encontrada en la lista del receptor" << std::endl;
                
                // Eliminar la solicitud de la lista
                if (anterior == nullptr) {
                    listaReceptor.setPrimero(actual->getSig());
                } else {
                    anterior->setSig(actual->getSig());
                }
                delete actual;
                break;
            }
            anterior = actual;
            actual = actual->getSig();
        }

        if (solicitudEncontrada) {
            std::cout << "-----------para eliminar de la pila--------" << std::endl;
            // Eliminar la solicitud de la pila del emisor si existe
            solicitud_pila& pilaEmisor = usuarioEmisor.getPilaSolicitudes();
            solicitud_pila pilaTemp;
            
            while (!pilaEmisor.estaVacia()) {
                Solicitud solicitudActual = pilaEmisor.top();
                pilaEmisor.pop();

                if (solicitudActual.getEmisor() == receptor && solicitudActual.getEstado() == "PENDIENTE") {
                    std::cout << "Solicitud eliminada de la pila del emisor" << std::endl;
                } else {
                    pilaTemp.push(solicitudActual);
                }
            }

            // Restaurar la pila del emisor sin la solicitud aceptada
            while (!pilaTemp.estaVacia()) {
                pilaEmisor.push(pilaTemp.top());
                pilaTemp.pop();
            }

            // Agregar a los usuarios como amigos
            usuarioEmisor.agregarAmigo(usuarioReceptor.getID());
            usuarioReceptor.agregarAmigo(usuarioEmisor.getID());

            std::cout << "Solicitud pendiente ACEPTADA y procesada correctamente." << std::endl;
            std::cout << "EMISOR: " << std::endl;
            usuarioEmisor.printUsuario();
            usuarioEmisor.imprimirAmigos();

            std::cout << "RECEPTOR: " << std::endl;
            usuarioReceptor.printUsuario();
            usuarioReceptor.imprimirAmigos();

            return 4; // Código: solicitud aceptada y procesada
        }else {
            // Si no había solicitud pendiente previa, proceder con la aceptación normal
            usuarioEmisor.agregarAmigo(usuarioReceptor.getID());
            usuarioReceptor.agregarAmigo(usuarioEmisor.getID());
            std::cout << "Solicitud ACEPTADA. Usuarios agregados como amigos." << std::endl;
            std::cout << "EMISOR, " << usuarioEmisor.getCorreo() << " ahora es amigo de: " << usuarioReceptor.getCorreo() << std::endl;
            std::cout << "RECEPTOR: "<< usuarioReceptor.getCorreo() << " ahora es amigo de: " << usuarioEmisor.getCorreo() << std::endl;
            
            std::cout << "EMISOR: "<<std::endl;
            usuarioEmisor.printUsuario();
            usuarioEmisor.imprimirAmigos();


            std::cout << "RECEPTOR: "<<std::endl;
            usuarioReceptor.printUsuario();
            usuarioReceptor.imprimirAmigos();
            return 4; // Código para indicar que la solicitud fue aceptada y procesada
        }  
    }
    // ESTADO == PENDIENTE  
    else if (estado == "PENDIENTE") {

        // Verificar si ya son amigos
        if (usuarioEmisor.esAmigo(usuarioReceptor.getID())) {
            std::cout << "Los usuarios ya son amigos." << std::endl;
            return 3; // Código: ya son amigos
        }
        
        // Verificar si el EMISOR ya tiene una solicitud pendiente del RECEPTOR
        solicitud_pila& pilaEmisor = usuarioEmisor.getPilaSolicitudes();
        solicitud_pila pilaTemp;
        bool solicitudPendienteEncontrada = false;
        
        while (!pilaEmisor.estaVacia()) {
            Solicitud solicitudActual = pilaEmisor.top();
            pilaEmisor.pop();
            if (solicitudActual.getEmisor() == receptor) {
                solicitudPendienteEncontrada = true;
                break;
            }
            pilaTemp.push(solicitudActual);
        }
        
        // Restaurar la pila
        while (!pilaTemp.estaVacia()) {
            pilaEmisor.push(pilaTemp.top());
            pilaTemp.pop();
        }
        
        if (solicitudPendienteEncontrada) {
            std::cout << "ERROR: Usted tiene una Solicitud pendiente de esta persona" << std::endl;
            return 5;
        }
        
        // Verificar si el EMISOR ya envió una solicitud al RECEPTOR
        arrayList_soli& listaEmisor = usuarioEmisor.getListaSolicitudes();
        solicitud_Nodo* nodoActual = listaEmisor.getPrimero();
        
        while (nodoActual != nullptr) {
            if (nodoActual->getDato().getReceptor() == receptor) {
                std::cout << "ERROR: Usted ya le envió una solicitud a esta persona" << std::endl;
                return 6;
            }
            nodoActual = nodoActual->getSig();
        }
        
        // Si no se encontraron restricciones, proceder con la creación de la nueva solicitud
        Solicitud nuevaSolicitud(emisor, receptor, estado);

        // Agregar a la lista de solicitudes del emisor
        usuarioEmisor.agregarSolicitud(nuevaSolicitud);
        // Agregar a la pila de solicitudes del receptor
        usuarioReceptor.agregarSolicitudPila(nuevaSolicitud);

        std::cout << "Solicitud pendiente agregada." << std::endl;
        std::cout << "EMISOR, " << usuarioEmisor.getCorreo() << " envio una solicitud a: " << usuarioReceptor.getCorreo() << std::endl;
        std::cout << "RECEPTOR: "<< usuarioReceptor.getCorreo() << " ahora tiene una solicitud de: " << usuarioEmisor.getCorreo() << std::endl;
        
        std::cout << "EMISOR: "<<std::endl;
        usuarioEmisor.printUsuario();
        usuarioEmisor.imprimirAmigos();


        std::cout << "RECEPTOR: "<<std::endl;
        usuarioReceptor.printUsuario();
        usuarioReceptor.imprimirAmigos();
        
        return 7;
    }

    // ------ RECHAZADA ----------
    else if (estado == "RECHAZADA") {

        // Verificar si hay una solicitud pendiente del receptor al emisor en la pila del emisor
        solicitud_pila& pilaEmisor = usuarioEmisor.getPilaSolicitudes();
        solicitud_pila pilaTemp;
        bool solicitudEncontrada = false;

        while (!pilaEmisor.estaVacia()) {
            Solicitud solicitudActual = pilaEmisor.top();
            pilaEmisor.pop();

            if (solicitudActual.getEmisor() == receptor && solicitudActual.getEstado() == "PENDIENTE") {
                solicitudEncontrada = true;
                std::cout << "Solicitud eliminada de la pila del emisor" << std::endl;
            } else {
                pilaTemp.push(solicitudActual);
            }
        }

        // Restaurar la pila del emisor sin la solicitud rechazada
        while (!pilaTemp.estaVacia()) {
            pilaEmisor.push(pilaTemp.top());
            pilaTemp.pop();
        }

        if (solicitudEncontrada) {
            // Eliminar la solicitud de la lista del receptor
            arrayList_soli& listaReceptor = usuarioReceptor.getListaSolicitudes();
            listaReceptor.eliminarSolicitud(receptor, emisor);

            std::cout << "Solicitud rechazada y eliminada de la lista del receptor." << std::endl;
            std::cout << "EMISOR: "<<std::endl;
            usuarioEmisor.printUsuario();
            usuarioEmisor.imprimirAmigos();


            std::cout << "RECEPTOR: "<<std::endl;
            usuarioReceptor.printUsuario();
            usuarioReceptor.imprimirAmigos();
            return 8;
        } else {
            std::cout << "Usted no tiene ninguna solicitud de amistad de esta persona" << std::endl;
            return 9;
        }
    }

    // Si llegamos aquí, tanto el emisor como el receptor existen
    std::cout << "Emisor y receptor encontrados en el árbol." << std::endl;
    return 2; // Indicando que ambos usuarios fueron encontrados
}