#include "registroPublicaciones.h"


ListaDoblementeEnlazadaP listaGlobal_publicaciones; 
 
bool validarFormatoFecha(std::string fecha) {
    int dia = 0, mes = 0, anio = 0;
    char delim1, delim2;

    // Separar la fecha usando '/' como delimitador
    std::istringstream ss(fecha);
    ss >> dia >> delim1 >> mes >> delim2 >> anio;

    // Validar formato general
    if (delim1 != '/' || delim2 != '/' || ss.fail()) {
        return false;
    }

    // Validar día, mes y año
    if (dia < 1 || dia > 31 || mes < 1 || mes > 12) {
        return false;
    }

    // Validar días específicos de febrero y meses de 30 días
    if (mes == 2) {
        bool esBisiesto = (anio % 4 == 0 && (anio % 100 != 0 || anio % 400 == 0));
        if (dia > (esBisiesto ? 29 : 28)) {
            return false;
        }
    } else if (mes == 4 || mes == 6 || mes == 9 || mes == 11) {
        if (dia > 30) {
            return false;
        }
    }

    // Si todo está bien, retorna true
    return true;
}
/*
    1) verificar si el arbol global de usuarios no este vacia.
    2) recorrer la arbolGlobal_usuarios hasta encontrar un correo con el que coincida el paramtreo correo
*/
void verificarCorreo_publicacion(std::string correo, std::string contenido, std::string fecha, std::string hora, lista_comentarios lista_comentarios) {
    std::cout << "Iniciando verificación para publicación de: " << correo << std::endl;
    std::cout << "Número de comentarios: " << lista_comentarios.size() << std::endl;
    
    // 1) Verificar el formato de la fecha de la publicación
    if (!validarFormatoFecha(fecha)) {
        std::cout << "Error: Formato de fecha inválido. Debe ser DD/MM/YYYY." << std::endl;
        return;
    }

    // 2) Verificar que el árbol global de usuarios no esté vacío
    if (arbolGlobal_usuarios.getRaiz() == nullptr) {
        std::cout << "Error: No hay usuarios en la aplicación." << std::endl;
        return;
    }

    // Buscar el usuario por correo en el árbol AVL
    NodoAVL* usuarioEncontrado = arbolGlobal_usuarios.buscarPorCorreo(correo);

    if (usuarioEncontrado != nullptr) {
        // Usuario encontrado, crear y asignar la publicación
        Publicacion nuevaPublicacion(correo, contenido, fecha, hora);        
        
        int contador = 0;
        // 3) Recorrer la lista de comentarios y agregar cada uno al árbol B de la publicación
        Nodo_com* nodoActual = lista_comentarios.getPrimero();
        while (nodoActual != nullptr) {
            std::cout << "Procesando comentario " << ++contador << std::endl;
            Comentario comentarioActual = nodoActual->getData();
            //nuevaPublicacion.getArbolB_comentarios().insertar(comentarioActual);
            nodoActual = nodoActual->getSig();
        }
        std::cout << "Finalizando inserción de comentarios..." << std::endl;

        //nuevaPublicacion.getArbolB_comentarios().graficar();

        asignarListaGlobal_publicaciones(nuevaPublicacion);
        //agregar la publicación al feed del usuario y al de sus amigos
        asignarBSTpersonal(nuevaPublicacion, correo, fecha);
        
        // Imprimir el estado del BST después de la inserción
        Usuarios& usuario = usuarioEncontrado->getData();
        BST& bstPersonal = usuario.getBST_feedPublicaciones();
        std::cout << "Estado del BST después de la inserción:" << std::endl;
        if (bstPersonal.estaVacio()) {
            std::cout << "El BST está vacío." << std::endl;
        } else {
            std::cout << "El BST no está vacío. Contenido:" << std::endl;
            bstPersonal.inOrden(); // Esto imprimirá el contenido del BST
            //usuario.generarGraficoBSTPersonal();
        }

        std::cout << "Publicación creada y asignada correctamente." << std::endl << std::endl;
    } else {
        std::cout << "Error: El correo no corresponde a ningún usuario registrado." << std::endl;
    }
}


// asignar a listaGlobal_publicaciones
void asignarListaGlobal_publicaciones(Publicacion publicacion) {
    // Agregar la publicación a la lista global de publicaciones
    listaGlobal_publicaciones.append(publicacion);
    listaGlobal_publicaciones.graficar();
}


void asignarBSTpersonal(Publicacion nuevaPublicacion, std::string correo, std::string fecha) {
    // 1. Buscar el usuario por correo en el árbol AVL global
    NodoAVL* usuarioEncontrado = arbolGlobal_usuarios.buscarPorCorreo(correo);
    
    if (usuarioEncontrado == nullptr) {
        std::cout << "Error: Usuario no encontrado." << std::endl;
        return;
    }
    
    Usuarios& usuario = usuarioEncontrado->getData();

    // 2. Obtener el BST personal del usuario
    BST& bstPersonal = usuario.getBST_feedPublicaciones();

    // 3. Buscar o insertar la fecha en el BST y obtener el nodo correspondiente
    NodoBST* nodoFecha = bstPersonal.buscarNodoPorFecha(fecha);
    if (nodoFecha == nullptr) {
        // Si el nodo no existe, lo insertamos
        nodoFecha = bstPersonal.insertAndGetNode(fecha);
    }

    if (nodoFecha == nullptr) {
        std::cout << "Error: No se pudo insertar la fecha en el BST." << std::endl;
        return;
    }

    // 4. Agregar la nueva publicación a la lista de publicaciones del nodo
    if (fecha == nodoFecha->getFechaID()){
        nodoFecha->getListaPublicaciones().append(nuevaPublicacion);
        std::cout << "Publicación agregada a la lista del nodo con fecha " << fecha << ". Contenido: " << nuevaPublicacion.getContenido() << std::endl;

        // Graficar la lista de publicaciones del nodo
        std::string fechaSinBarras = fecha;
        std::replace(fechaSinBarras.begin(), fechaSinBarras.end(), '/', '_');
        std::string nombreArchivo = "lista_publicaciones_" + fechaSinBarras + "_" + correo;
        nodoFecha->getListaPublicaciones().graficarNodo(nombreArchivo);
        std::cout << "Publicación agregada al feed del usuario " << correo << " en la fecha " << fecha << std::endl;

        
    }
    
    // 5. Agregar la publicación al feed de los amigos del usuario

    NodoAVL* usuarioEncontrado2 = arbolGlobal_usuarios.buscarPorCorreo(correo);
    
    if (usuarioEncontrado2 == nullptr) {
        std::cout << "Error: Usuario no encontrado." << std::endl;
        return;
    }
    
    Usuarios& usuario2 = usuarioEncontrado2->getData();

    listaSimpleEnlazada& listaAmigos = usuario2.getLista_amigos();
    Nodo* nodoAmigo = listaAmigos.getPrimero();

    while (nodoAmigo != nullptr) {
        int idAmigo = nodoAmigo->getData();
        
        // Buscar al amigo por ID en el árbol global
        NodoAVL* amigoEncontrado = arbolGlobal_usuarios.buscarPorID(idAmigo);
        
        if (amigoEncontrado != nullptr) {
            Usuarios& amigo = amigoEncontrado->getData();
            BST& bstAmigo = amigo.getBST_feedPublicaciones();
            
            // Buscar o insertar la fecha en el BST del amigo y obtener el nodo correspondiente
            NodoBST* nodoFechaAmigo = bstAmigo.buscarNodoPorFecha(fecha);
            if (nodoFechaAmigo == nullptr) {
                nodoFechaAmigo = bstAmigo.insertAndGetNode(fecha);
            }
            
            // Agregar la nueva publicación a la lista de publicaciones del nodo del amigo
            nodoFechaAmigo->getListaPublicaciones().append(nuevaPublicacion);
            
            std::cout << "Publicación agregada al feed del amigo con ID " << idAmigo << std::endl;
        } else {
            std::cout << "Advertencia: Amigo con ID " << idAmigo << " no encontrado en el árbol global." << std::endl;
        }
        
        // Avanzar al siguiente amigo en la lista
        nodoAmigo = nodoAmigo->getSig();
    }
}
