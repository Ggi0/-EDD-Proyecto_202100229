#include <iostream>
#include "menuUsuario.h"
#include "../Herramientas/enter.h"
#include "../Registro/global_data.h"
#include "../Registro/Usuarios.h"

#include "../publicaciones/registroPublicaciones.h"


/*
    Interfas que en la que interactuara el usuario promedio luego de iniciar sesion
    
    En donde tendra opciones para:
    * Perfil 
        ->ver/eliminar cuenta
    * Solicitudes de amistar
        ->aceptar/rechazar
        -> enviar
    * Publicaciones 
        -> ver/crear/eliminar
    * Reportes
    * Salir (cerrar sesión)

*/
void menuUsuario(std::string correo){
    int opcion;
    int opcionSolicitudes;
    
    do{
        // ----- MENU USUARIO ------
        std::cout <<std::endl<<"-!-!-!-!-!-!-!-!-!-!-!-!-!-!-!-"<< std::endl;
        std::cout << "      Social Structure"<< std::endl;
        std::cout << "- - - - - - - - - - - - - - - -"<< std::endl;
        std::cout << "1) Mi Perfil"<< std::endl;
        std::cout << "2) Solicitudes "<< std::endl;
        std::cout << "3) Publicaiones"<< std::endl;
        std::cout << "4) Reportes"<< std::endl;
        std::cout << "5) Salir"<< std::endl<<std::endl;

        // capturar la entrada
        std::cout<<"Seleccione una opcion: ";
        std::cin >> opcion;

        // Verificar si la entrada es válida
        if (std::cin.fail()) {
            std::cin.clear(); // Limpiar el estado de error
            std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n'); // Descartar la entrada inválida
            opcion = 0; // Asignar un valor inválido para que el switch maneje la opción por defecto
        }
        std::cout <<"-¡-¡-¡-¡-¡-¡-¡-¡-¡-¡-¡-¡-¡-¡-¡-"<< std::endl<< std::endl<<std::endl;
        
        switch(opcion){
            case 1:
                opcion = 0;
                std::cout << "   Mi perfil: "<< std::endl;
                std::cout << "- - - - - - - - - - - - - - - -"<< std::endl;
                std::cout << "      1) Ver perfil"<< std::endl;
                std::cout << "      2) Eliminar cuenta "<< std::endl;
                std::cout << "      3) Regresar (<-) "<< std::endl;
                std::cout<<"Seleccione una opcion: ";
                std::cin >> opcion;

                if (opcion == 1){
                    verPerfil(correo);
                }else if (opcion == 2){
                    eliminarCuenta(correo);
                }else if(opcion == 3){
                    break;
                }else{
                    std::cout << "opcion NO valida. Seleccione una de la 3 opciones";
                    enter();
                }
                break;

            case 2:
                opcion = 0;
                std::cout << "   Solicitudes: "<< std::endl;
                std::cout << "- - - - - - - - - - - - - - - -"<< std::endl;
                std::cout << "      1) Ver Solicitudes"<< std::endl;
                std::cout << "      2) Enviar "<< std::endl;
                std::cout << "      3) Regresar (<-) "<< std::endl;
                std::cout<<"Seleccione una opcion: ";
                std::cin >> opcion;
                std::cout<< std::endl;

                if (opcion == 1){
                   verSolicitud(correo);
                }else if (opcion == 2){
                    enviarSolicitud(correo);
                }else if(opcion == 3){
                    break;
                }else{
                    std::cout << "opcion NO valida. Seleccione una de la 3 opciones";
                    enter();
                }
                break;

            case 3:
                opcion = 0;
                std::cout << "3) Publicaciones: "<< std::endl;
                std::cout << "- - - - - - - - - - - - - - - -"<< std::endl;
                std::cout << "      1) Ver Publicaciones"<< std::endl;
                std::cout << "      2) Crear una Publicacion "<< std::endl;
                std::cout << "      3) Regresar (<-) "<< std::endl;
                std::cout<<"Seleccione una opcion: ";
                std::cin >> opcion;
                std::cout<< std::endl;

                if (opcion == 1){
                   verPublicaciones(correo);
                }else if (opcion == 2){
                    hacerPublicacion(correo);
                }else if(opcion == 3){
                    break;
                }else{
                    std::cout << "opcion NO valida. Seleccione una de la 3 opciones";
                    enter();
                }
                break;

            case 4:
                std::cout << "4) Reportes: "<< std::endl;
                std::cout << "- - - - - - - - - - - - - - - -"<< std::endl<<std::endl;
                imprimirReportes(correo);
                break;

            case 5:
                std::cout << "5) Salir: "<< std::endl;
                std::cout << "- - - - - - - - - - - - - - - -"<< std::endl;
                std::cout << "Regresando al menu principal ... "<< std::endl;
                break;

            default:
                std::cout << "opcion NO valida. Seleccione una de la 4 opciones";
                enter();
        }

    }while(opcion != 5);

}

void verPerfil(std::string correo) {
    usuarios_Nodo* actual = listaGlobal_usuarios.getPrimero();
    
    while (actual != nullptr) {
        if (actual->getDato().getCorreo() == correo) {
            Usuarios& usuario = actual->getDato();
            std::cout << "\n╔═══════════════════════════════════════════════╗" << std::endl;
            std::cout << "║              SOCIAL STRUCTURE                 ║" << std::endl;
            std::cout << "╔═══════════════════════════════════════════════╗" << std::endl;
            std::cout << "║              PERFIL DE USUARIO                ║" << std::endl;
            std::cout << "╠═══════════════════════════════════════════════╣" << std::endl;
            std::cout << "║ ID: " << std::setw(42) << std::left << usuario.getID() << "║" << std::endl;
            std::cout << "║ Nombre: " << std::setw(38) << std::left << usuario.getNombres() << "║" << std::endl;
            std::cout << "║ Apellidos: " << std::setw(35) << std::left << usuario.getApellidos() << "║" << std::endl;
            std::cout << "║ Fecha de Nacimiento: " << std::setw(25) << std::left << usuario.getFechaN() << "║" << std::endl;
            std::cout << "║ Correo: " << std::setw(38) << std::left << usuario.getCorreo() << "║" << std::endl;
            std::cout << "╠═══════════════════════════════════════════════╣" << std::endl;
            std::cout << "║ Amigos: " << std::setw(38) << std::left << usuario.getLista_amigos().size() << "║" << std::endl;
            std::cout << "║ Publicaciones: " << std::setw(32) << std::left << usuario.getLista_publicacionesP().obtenerTamanio() << "║" << std::endl;
            std::cout << "║ Solicitudes Enviadas: " << std::setw(25) << std::left << usuario.getListaSolicitudes().size() << "║" << std::endl;
            std::cout << "║ Solicitudes Recibidas: " << std::setw(24) << std::left << usuario.getPilaSolicitudes().size() << "║" << std::endl;
            std::cout << "╚═══════════════════════════════════════════════╝" << std::endl;
            return;
        }
        actual = actual->getSig();
    }
    std::cout << "No se encontró ningún usuario con el correo: " << correo << std::endl;
}

/*
    1) recorrer la lista de amigos y elimiarse de ahí
    2) eliminar el Usuario
*/
void eliminarCuenta(std::string correo) {
    usuarios_Nodo* actual = listaGlobal_usuarios.getPrimero();
    usuarios_Nodo* anterior = nullptr;

    // Buscar el usuario a eliminar
    while (actual != nullptr && actual->getDato().getCorreo() != correo) {
        anterior = actual;
        actual = actual->getSig();
    }

    if (actual == nullptr) {
        std::cout << "No se encontró ningún usuario con el correo: " << correo << std::endl;
        return;
    }

    Usuarios& usuarioAEliminar = actual->getDato();
    int idAEliminar = usuarioAEliminar.getID();

    // Eliminar el usuario de las listas de amigos de otros usuarios
    listaSimpleEnlazada& amigosDelUsuario = usuarioAEliminar.getLista_amigos();
    usuarios_Nodo* otroUsuario = listaGlobal_usuarios.getPrimero();
    
    while (otroUsuario != nullptr) {
        if (otroUsuario->getDato().getID() != idAEliminar) {
            otroUsuario->getDato().eliminarAmigo(idAEliminar);
        }
        otroUsuario = otroUsuario->getSig();
    }

    // Eliminar el usuario de la lista global
    if (anterior == nullptr) {
        listaGlobal_usuarios.setPrimero(actual->getSig());
    } else {
        anterior->setSig(actual->getSig());
    }

    if (actual == listaGlobal_usuarios.getUltimo()) {
        listaGlobal_usuarios.setUltimo(anterior);
    }

    delete actual;

    std::cout << "Usuario con correo " << correo << " ha sido eliminado exitosamente." << std::endl;
}

void verSolicitud(std::string correo) {
    // Buscar el usuario en listaGlobal_usuarios cuyo correo coincida
    usuarios_Nodo* actual = listaGlobal_usuarios.getPrimero();
    while (actual != nullptr && actual->getDato().getCorreo() != correo) {
        actual = actual->getSig();
    }

    if (actual == nullptr) {
        std::cout << "No se encontró ningún usuario con el correo: " << correo << std::endl;
        return;
    }

    // Usuario encontrado
    Usuarios& usuario = actual->getDato();
    solicitud_pila& pilaSolicitudes = usuario.getPilaSolicitudes();

    // Verificar si la pila está vacía
    if (pilaSolicitudes.estaVacia()) {
        std::cout << "No hay solicitudes pendientes para este usuario." << std::endl;
        return;
    }

    // Pila temporal para restaurar el estado original al final
    solicitud_pila pilaTemporal;

    // Variables para almacenar emisor y receptor
    std::string emisorActual;
    std::string receptorActual;
    std::string estadoActual;

    // Recorrer la pila de solicitudes
    while (!pilaSolicitudes.estaVacia()) {
        Solicitud solicitudActual = pilaSolicitudes.top();
        emisorActual = solicitudActual.getEmisor();
        receptorActual = solicitudActual.getReceptor();

        // Mostrar la solicitud actual
        std::cout<< std::endl << "Solicitud de amistad:" << std::endl;
        std::cout << " ***  " << emisorActual <<" Quiere ser tu amigo!!!"<< std::endl;
        //std::cout << "Receptor: " << receptorActual << std::endl;
        std::cout << " *** Estado: " << solicitudActual.getEstado() << std::endl;

        // Mostrar opciones
        std::cout << std::endl<< "  Opciones: " << std::endl;
        std::cout << "      1) Aceptar" << std::endl;
        std::cout << "      2) Rechazar" << std::endl;
        std::cout << "      3) Siguiente" << std::endl;
        std::cout << "  Ingrese la opcion: ";
        int opcion;
        std::cin >> opcion;

        //registroSolicitudes(std::string emisor, std::string receptor, std::string estado)

        switch (opcion) {
            case 1:
                // Aceptar la solicitud
                estadoActual = "ACEPTADA";
                registroSolicitudes(receptorActual, emisorActual, estadoActual);
                break;
            case 2:
                // Rechazar la solicitud
                estadoActual = "RECHAZADA";
                registroSolicitudes(receptorActual, emisorActual, estadoActual);
                break;
            case 3:
                // Pasar a la siguiente solicitud
                std::cout << "Siguiente solicitud..." << std::endl<< std::endl;
                break;
            default:
                std::cout << "Opción no válida." << std::endl;
                continue;
        }

        // Mover la solicitud actual a la pila temporal
        pilaTemporal.push(solicitudActual);
        pilaSolicitudes.pop();
    }

    // Restaurar las solicitudes a la pila original
    while (!pilaTemporal.estaVacia()) {
        pilaSolicitudes.push(pilaTemporal.top());
        pilaTemporal.pop();
    }
}

void enviarSolicitud(std::string correo) {

    std::string receptor = "";
    std::string estado = "PENDIENTE";
    std::cout <<std::endl << "A quien deseas mandarle una solicitud de amistad?"<<std::endl;
    std::cout << "por favor, Ingrese correo electrónico: ";
    std::getline(std::cin >> std::ws, receptor);
    registroSolicitudes(correo, receptor, estado);
    std::cout <<std::endl;

}

void verPublicaciones(std::string correo) {
    // Buscar el usuario en listaGlobal_usuarios cuyo correo coincida
    usuarios_Nodo* actual = listaGlobal_usuarios.getPrimero();
    while (actual != nullptr && actual->getDato().getCorreo() != correo) {
        actual = actual->getSig();
    }

    if (actual == nullptr) {
        std::cout << "No se encontró ningún usuario con el correo: " << correo << std::endl;
        return;
    }

    // Usuario encontrado
    Usuarios& usuario = actual->getDato();
    ListaCircular_Dpp& listaPublicaciones = usuario.getLista_publicacionesP();

    // Verificar si la lista de publicaciones está vacía
    if (listaPublicaciones.estaVacia()) {
        std::cout << "El usuario no tiene publicaciones." << std::endl;
        return;
    }

    // Variables para la navegación
    pPersonal_Nodo* actualNodo = listaPublicaciones.getPrimero();
    char opcion;
    
    // Mostrar publicaciones y navegar
    do {
        actualNodo->getData().printPublicacion();

        std::cout << std::endl<< "Opciones: " << std::endl;
        std::cout << "1) Avanzar" << std::endl;
        std::cout << "2) Retroceder" << std::endl;
        std::cout << "3) Salir" << std::endl;
        std::cout <<std::endl<< "Ingresar opcion: ";
        std::cin >> opcion;

        switch (opcion) {
            case '1': // Avanzar
                actualNodo = actualNodo->getSiguiente();
                break;
            case '2': // Retroceder
                actualNodo = actualNodo->getAnterior();
                break;
            case '3': // Salir
                return;
            default:
                std::cout << "Opción no válida. Inténtalo de nuevo." << std::endl;
                break;
        }
    } while (opcion != '3');
}



// Obtener la fecha actual en formato DD/MM/YYYY
std::string obtenerFechaActual() {
    std::time_t tiempo = std::time(nullptr);
    std::tm* tm_local = std::localtime(&tiempo);

    std::ostringstream fecha;
    fecha << std::setw(2) << std::setfill('0') << tm_local->tm_mday << "/"
          << std::setw(2) << std::setfill('0') << (tm_local->tm_mon + 1) << "/"
          << (tm_local->tm_year + 1900);
    return fecha.str();
}

// Obtener la hora actual en formato HH:MM
std::string obtenerHoraActual() {
    std::time_t tiempo = std::time(nullptr);
    std::tm* tm_local = std::localtime(&tiempo);

    std::ostringstream hora;
    hora << std::setw(2) << std::setfill('0') << tm_local->tm_hour << ":"
         << std::setw(2) << std::setfill('0') << tm_local->tm_min;
    return hora.str();
}

// Método para hacer una publicación
void hacerPublicacion(std::string correo) {
    std::string fecha = obtenerFechaActual();
    std::string hora = obtenerHoraActual();
    std::string contenido = "";

    std::cout <<std::endl << "Contenido de la publicacion: "<<std::endl;
    std::cout << "->  ";
    std::getline(std::cin >> std::ws, contenido);


    verificarCorreo_publicacion(correo, contenido, fecha, hora);
}

void imprimirReportes(std::string correo) {
    // Obtenemos el primer nodo de la lista global
    usuarios_Nodo* actual = listaGlobal_usuarios.getPrimero();

    // Recorremos toda la lista de usuarios
    while (actual != nullptr) {
        // Obtenemos la referencia al usuario actual
        Usuarios& usuario = actual->getDato();

        // Comparamos los correos
        if (usuario.getCorreo() == correo) {
            // Si los correos coinciden, generamos las gráficas
            usuario.getListaSolicitudes().grafica();
            usuario.getPilaSolicitudes().grafica();
            usuario.getLista_publicacionesP().grafica();
            usuario.graficaAmigos();

            // Terminamos el bucle ya que encontramos el usuario
            break;
        }

        // Avanzamos al siguiente nodo
        actual = actual->getSig();
    }
}
