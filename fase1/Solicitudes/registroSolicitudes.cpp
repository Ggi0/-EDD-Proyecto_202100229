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
    
    (no implementado)
    si el EMISOR NO tiene en su pila un objeto Solicitud con el correo del RECEPTOR en el atributo del emisor, deber imprimirce por pantalla: "Usted no tiene ninguan solicitud de amistad de esta persona"
    si el EMISOR trata de enviarse una solicitud a si mismo.

*/
void registroSolicitudes(std::string emisor, std::string receptor, std::string estado) {
    // 1) Verificar que la listaGlobal_usuarios no esté vacía
    if (listaGlobal_usuarios.size() == 0) {
        std::cout << "Error: No hay usuarios en la aplicacion (lista vacia)." << std::endl;
        return;
    }

    int indexEmisor = -1;
    int indexReceptor = -1;
    usuarios_Nodo* actualEmisor = listaGlobal_usuarios.getPrimero();
    Solicitud nuevaSolicitud;
    
    // 2) Buscar el EMISOR
    while (actualEmisor != nullptr) {
        indexEmisor++;
        if (actualEmisor->getDato().getCorreo() == emisor) {
            // Emisor encontrado
            usuarios_Nodo* actualReceptor = listaGlobal_usuarios.getPrimero();
            int indexReceptorTemp = 0;

            // 3)Buscar el RECEPTOR
            while (actualReceptor != nullptr) {
                if (actualReceptor->getDato().getCorreo() == receptor) {
                    // Receptor encontrado
                    indexReceptor = indexReceptorTemp;
                    
                    // Lógica para manejar los estados (ACEPTADA/PENDIENTE/RECHAZADA)
                    std::cout << "Emisor encontrado en índice: " << indexEmisor << std::endl;
                    std::cout << "Receptor encontrado en índice: " << indexReceptor << std::endl;
                    std::cout << "Estado de la solicitud: " << estado << std::endl;
                    
                    // ------------- ACEPTADA ---------
                    if (estado == "ACEPTADA") {
                        // 1) Verificar si ya son amigos
                        // Verifica si los usuarios ya son amigos. Si lo son, no se realiza ninguna acción.
                        if (actualEmisor->getDato().esAmigo(actualReceptor->getDato().getID())) {
                            std::cout << "Usted ya es amigo de esta persona" << std::endl;
                            return;
                        }

                        // 2) Verificar si hay una solicitud pendiente del receptor al emisor
                        solicitud_pila& pilaEmisor = actualEmisor->getDato().getPilaSolicitudes();
                        solicitud_pila pilaTemp;
                        bool solicitudPendienteEncontrada = false;
                        Solicitud solicitudPendiente;
                        
                        // Recorre la pila de solicitudes del emisor para encontrar y eliminar una solicitud pendiente del receptor.
                        while (!pilaEmisor.estaVacia()) {
                            Solicitud solicitudActual = pilaEmisor.top();
                            pilaEmisor.pop();

                            if (solicitudActual.getEmisor() == receptor && solicitudActual.getReceptor() == emisor) {
                                solicitudPendienteEncontrada = true;
                                solicitudPendiente = solicitudActual;
                                std::cout << "Solicitud eliminada de la pila" << std::endl;
                            } else {
                                pilaTemp.push(solicitudActual);
                            }
                        }

                        // Restaura la pila del emisor, sin la solicitud pendiente si fue encontrada.
                        while (!pilaTemp.estaVacia()) {
                            pilaEmisor.push(pilaTemp.top());
                            pilaTemp.pop();
                        }

                        if (solicitudPendienteEncontrada) {
                            // Si se encontró la solicitud pendiente, se elimina de la lista del emisor original (receptor actual).
                            arrayList_soli& listaEmisorOriginal = actualReceptor->getDato().getListaSolicitudes();
                            solicitud_Nodo* actual = listaEmisorOriginal.getPrimero();
                            solicitud_Nodo* anterior = nullptr;
                            bool eliminadoDeLista = false;

                            // Recorre la lista de solicitudes para eliminar la solicitud específica.
                            while (actual != nullptr) {
                                if (actual->getDato().getEmisor() == receptor && actual->getDato().getReceptor() == emisor) {
                                    if (anterior == nullptr) {
                                        listaEmisorOriginal.setPrimero(actual->getSig());
                                    } else {
                                        anterior->setSig(actual->getSig());
                                    }
                                    delete actual;
                                    eliminadoDeLista = true;
                                    std::cout << "Solicitud eliminada de lista del emisor original" << std::endl;
                                    break;
                                }
                                anterior = actual;
                                actual = actual->getSig();
                            }

                            if (!eliminadoDeLista) {
                                std::cout << "No se encontró la solicitud en la lista del emisor original" << std::endl;
                            }

                           // Agrega a los usuarios como amigos si la solicitud pendiente fue encontrada.
                            actualEmisor->getDato().agregarAmigo(actualReceptor->getDato().getID());
                            actualReceptor->getDato().agregarAmigo(actualEmisor->getDato().getID());

                            std::cout << "Solicitud pendiente previa aceptada. Usuarios agregados como amigos." << std::endl<< std::endl;
                        } else {
                            // Si no había solicitud pendiente previa, proceder con la aceptación normal
                            actualEmisor->getDato().agregarAmigo(actualReceptor->getDato().getID());
                            actualReceptor->getDato().agregarAmigo(actualEmisor->getDato().getID());
                            std::cout << "Solicitud aceptada. Usuarios agregados como amigos." << std::endl<<std::endl;
                        }

                        /*
                        std::cout << "Amigos emisor: " << actualEmisor->getDato().getLista_amigos().size() << std::endl;
                        std::cout << "Amigos receptor: " << actualReceptor->getDato().getLista_amigos().size() << std::endl;
                        */

                        
                        std::cout << "Amigos del emisor: ";
                        actualEmisor->getDato().imprimirAmigos();
                        std::cout << "Amigos del receptor: ";
                        actualReceptor->getDato().imprimirAmigos();
                        


                    // ------------- PENDIENTE ---------
                    }else if (estado == "PENDIENTE"){
                        /*
                            Cada usuario tiene como parametro una listasSolicitudes y una pilaSolicitudes:
                            agregar el objeto Solicitud a la listaSolicitude (lista simplemente enlazada) del emisor
                            agregar el objeto Solicitud a la pilaSolicitudes (Pila) del receptor 
                        */

                       // Verificar si el EMISOR ya tiene una solicitud pendiente del RECEPTOR
                        solicitud_pila& pilaEmisor = actualEmisor->getDato().getPilaSolicitudes();
                        solicitud_pila pilaTemp;
                        bool solicitudPendienteEncontrada = false;
                        
                        while (!pilaEmisor.estaVacia()) {
                            Solicitud solicitudActual = pilaEmisor.top();
                            if (solicitudActual.getEmisor() == receptor) {
                                solicitudPendienteEncontrada = true;
                                break;
                            }
                            pilaTemp.push(solicitudActual);
                            pilaEmisor.pop();
                        }
                        
                        // Restaurar la pila
                        while (!pilaTemp.estaVacia()) {
                            pilaEmisor.push(pilaTemp.top());
                            pilaTemp.pop();
                        }
                        
                        if (solicitudPendienteEncontrada) {
                            std::cout << "ERROR: Usted tiene una Solicitud pendiente de esta persona" << std::endl;
                            return;
                        }
                        
                        // Verificar si el EMISOR ya envió una solicitud al RECEPTOR
                        arrayList_soli& listaEmisor = actualEmisor->getDato().getListaSolicitudes();
                        solicitud_Nodo* nodoActual = listaEmisor.getPrimero();
                        
                        while (nodoActual != nullptr) {
                            if (nodoActual->getDato().getReceptor() == receptor) {
                                std::cout << "ERROR; Usted ya le envió una solicitud a esta persona" << std::endl;
                                return;
                            }
                            nodoActual = nodoActual->getSig();
                        }
                        
                        // Si no se encontraron restricciones, proceder con la creación de la nueva solicitud
    

                        // Crear objeto Solicitud
                        Solicitud nuevaSolicitud(emisor, receptor, estado);

                        // Agregar a la lista de solicitudes del emisor
                        actualEmisor->getDato().agregarSolicitud(nuevaSolicitud);

                        // Agregar a la pila de solicitudes del receptor
                        actualReceptor->getDato().agregarSolicitudPila(nuevaSolicitud);
                        std::cout << "Solicitud pendiente agregada." << std::endl<<std::endl;            
                        
                    }else if(estado == "RECHAZADA"){
                        /*
                            Eliminar el objeto Solicitud de la pila del receptor y de la lista del emisor 
                        */

                        // Verificar si hay una solicitud pendiente del receptor al emisor
                        solicitud_pila& pilaEmisor = actualEmisor->getDato().getPilaSolicitudes();
                        solicitud_pila pilaTemp;
                        bool solicitudPendienteEncontrada = false;
                        Solicitud solicitudPendiente;

                        while (!pilaEmisor.estaVacia()) {
                            Solicitud solicitudActual = pilaEmisor.top();
                            pilaEmisor.pop();

                            if (solicitudActual.getEmisor() == receptor && solicitudActual.getReceptor() == emisor) {
                                solicitudPendienteEncontrada = true;
                                solicitudPendiente = solicitudActual;
                                std::cout << "Solicitud eliminada de la pila del receptor" << std::endl;
                            } else {
                                pilaTemp.push(solicitudActual);
                            }
                        }

                        // Restaurar la pila sin la solicitud pendiente si se encontró
                        while (!pilaTemp.estaVacia()) {
                            pilaEmisor.push(pilaTemp.top());
                            pilaTemp.pop();
                        }

                        if (solicitudPendienteEncontrada) {
                            // Eliminar la solicitud de la lista del emisor original (receptor actual)
                            arrayList_soli& listaEmisorOriginal = actualReceptor->getDato().getListaSolicitudes();
                            solicitud_Nodo* actual = listaEmisorOriginal.getPrimero();
                            solicitud_Nodo* anterior = nullptr;
                            bool eliminadoDeLista = false;

                            while (actual != nullptr) {
                                if (actual->getDato().getEmisor() == receptor && actual->getDato().getReceptor() == emisor) {
                                    if (anterior == nullptr) {
                                        listaEmisorOriginal.setPrimero(actual->getSig());
                                    } else {
                                        anterior->setSig(actual->getSig());
                                    }
                                    delete actual;
                                    eliminadoDeLista = true;
                                    std::cout << "Solicitud eliminada de lista del emisor original" << std::endl;
                                    break;
                                }
                                anterior = actual;
                                actual = actual->getSig();
                            }

                            if (!eliminadoDeLista) {
                                std::cout << "No se encontró la solicitud en la lista del emisor original" << std::endl;
                            }

                            std::cout << "Solicitud pendiente previa rechazada y eliminada." << std::endl<<std::endl;
                        } else {
                            std::cout << "No se encontró ninguna solicitud pendiente para rechazar." << std::endl;
                        }

                    }else{
                        std::cout<< "Error: estado indefinido"<< std::endl;
                    }
                    return; // Terminamos la función una vez que se ha procesado la solicitud
                }
                actualReceptor = actualReceptor->getSig();
                indexReceptorTemp++;
            }
            
            if (indexReceptor == -1) {
                std::cout << "Error: el correo del RECEPTOR no encontrado." << std::endl;
                return;
            }
        }
        actualEmisor = actualEmisor->getSig();
    }
    
    if (indexEmisor == -1) {
        std::cout << "Error: el correo del EMISOR no encontrado." << std::endl;
        return;
    }
}
