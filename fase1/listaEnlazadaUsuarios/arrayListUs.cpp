#include "arrayListUs.h"

// Constructor
arrayList_us::arrayList_us(){
    primero = nullptr;
    ultimo = nullptr;
}

// Destructor
arrayList_us::~arrayList_us() {
    usuarios_Nodo *tempo = primero;
    usuarios_Nodo *aux;
    while (tempo != nullptr) {
        aux = tempo->getSig();
        delete tempo;
        tempo = aux;
    }
}

usuarios_Nodo* arrayList_us::getPrimero() {
    return primero;
}

// ----------- METODOS ----------------

// Insertar un nodo al inicio de la lista
void arrayList_us::push(Usuarios usuario) {
    usuarios_Nodo *nuevo_Nodo = new usuarios_Nodo(usuario);
    if (primero == nullptr) {
        primero = nuevo_Nodo;
        ultimo = nuevo_Nodo;
    } else {
        nuevo_Nodo->setSig(primero);
        primero = nuevo_Nodo;
    }
}

// Insertar un nodo al final de la lista
void arrayList_us::append(Usuarios usuario) {
    usuarios_Nodo *nuevo_Nodo = new usuarios_Nodo(usuario);
    if (primero == nullptr) {
        primero = nuevo_Nodo;
        ultimo = nuevo_Nodo;
    } else {
        ultimo->setSig(nuevo_Nodo);
        ultimo = nuevo_Nodo;
    }
}

// Método para obtener el tamaño de la lista
int arrayList_us::size() {
    int count = 0;
    usuarios_Nodo *actual = primero;
    
    while (actual != nullptr) {
        count++;
        actual = actual->getSig();
    }
    
    return count;
}

// Método para eliminar el último elemento de la lista
void arrayList_us::pop() {
    if (primero == nullptr) {
        // La lista está vacía, no hay nada que eliminar
        return;
    }
    
    if (primero == ultimo) {
        // Solo hay un elemento en la lista
        delete primero;
        primero = nullptr;
        ultimo = nullptr;
    } else {
        // Hay más de un elemento en la lista
        usuarios_Nodo *actual = primero;
        
        // Recorrer la lista hasta el penúltimo nodo
        while (actual->getSig() != ultimo) {
            actual = actual->getSig();
        }
        
        // Eliminar el último nodo
        delete ultimo;
        ultimo = actual;
        ultimo->setSig(nullptr);
    }
}

void arrayList_us::removeIf(bool (*condition)(const Usuarios&)) {
    usuarios_Nodo *actual = primero;
    usuarios_Nodo *anterior = nullptr;

    while (actual != nullptr) {
        if (condition(actual->getDato())) {
            // El nodo actual debe ser eliminado
            if (anterior == nullptr) {
                // Estamos eliminando el primer nodo
                primero = actual->getSig();
                delete actual;
                actual = primero;
            } else {
                // Estamos eliminando un nodo intermedio o el último
                anterior->setSig(actual->getSig());
                if (actual == ultimo) {
                    ultimo = anterior;
                }
                delete actual;
                actual = anterior->getSig();
            }
        } else {
            // Mover al siguiente nodo
            anterior = actual;
            actual = actual->getSig();
        }
    }
}


// Método para imprimir todos los usuarios en la lista
void arrayList_us::printAll() {
    usuarios_Nodo *actual = primero;  // Empezar desde el primer nodo

    // Recorrer toda la lista
    while (actual != nullptr) {
        actual->getDato().printUsuario();  // Llamar al método printUsuario de cada objeto Usuario
        actual = actual->getSig();  // Avanzar al siguiente nodo
    }
}

Usuarios* arrayList_us::buscarPorCorreo(const std::string& correo) {
    usuarios_Nodo* actual = primero;
    while (actual != nullptr) {
        if (actual->getDato().getCorreo() == correo) {
            return &(actual->getDato());
        }
        actual = actual->getSig();
    }
    return nullptr;
}

Usuarios* arrayList_us::buscarPorID(int id) {
    usuarios_Nodo* actual = primero;
    while (actual != nullptr) {
        if (actual->getDato().getID() == id) {
            return &(actual->getDato());
        }
        actual = actual->getSig();
    }
    return nullptr;
}

void arrayList_us::eliminarUsuario(const std::string& correo) {
    usuarios_Nodo* actual = primero;
    usuarios_Nodo* anterior = nullptr;

    while (actual != nullptr) {
        if (actual->getDato().getCorreo() == correo) {
            if (anterior == nullptr) {
                primero = actual->getSig();
            } else {
                anterior->setSig(actual->getSig());
            }
            if (actual == ultimo) {
                ultimo = anterior;
            }
            delete actual;
            return;
        }
        anterior = actual;
        actual = actual->getSig();
    }
}


// ----- SETTER DE PRIMERO -----
void arrayList_us::setPrimero(usuarios_Nodo* nuevoPrimero) {
    primero = nuevoPrimero;
    if (primero == nullptr) {
        ultimo = nullptr; // Si la lista queda vacía, también actualizamos el último a nullptr
    }
}

// ----- GETTER DE ULTIMO -----
usuarios_Nodo* arrayList_us::getUltimo() {
    return ultimo;
}

// ----- SETTER DE ULTIMO -----
void arrayList_us::setUltimo(usuarios_Nodo* nuevoUltimo) {
    ultimo = nuevoUltimo;
    if (ultimo == nullptr) {
        primero = nullptr; // Si la lista queda vacía, también actualizamos el primero a nullptr
    }
}


// Método para graficar la lista usando Graphviz
void arrayList_us::graficar() const {
    std::ofstream archivo("listaGlobal_usuarios.dot");  // Crear el archivo .dot

    if (!archivo.is_open()) {
        std::cerr << "No se pudo crear el archivo .dot" << std::endl;
        return;
    }

    archivo << "digraph G {" << std::endl;
    archivo << "  rankdir=LR;" << std::endl;  // Direccionar de izquierda a derecha

    usuarios_Nodo* actual = primero;
    while (actual != nullptr) {
        // Escribir el nodo
        archivo << "  " << actual->getDato().getID() << " [label=\"ID: " 
                << actual->getDato().getID() << "\\nNombres: " 
                << actual->getDato().getNombres() << "\\nApellidos: " 
                << actual->getDato().getApellidos() << "\\nCorreo: " 
                << actual->getDato().getCorreo() << "\"];" << std::endl;

        // Escribir las conexiones
        if (actual->getSig() != nullptr) {
            archivo << "  " << actual->getDato().getID() << " -> " 
                    << actual->getSig()->getDato().getID() << ";" << std::endl;
        }

        actual = actual->getSig();
    }

    archivo << "}" << std::endl;
    archivo.close();  // Cerrar el archivo

    std::cout << "Archivo listaGlobal_usuarios.dot generado correctamente." << std::endl;
}

// Método para obtener los 5 usuarios con más publicaciones
std::vector<Usuarios*> arrayList_us::top5UsuariosConMasPublicaciones() {
    std::vector<Usuarios*> todosUsuarios;
    usuarios_Nodo* actual = primero;
    while (actual != nullptr) {
        todosUsuarios.push_back(&(actual->getDato()));
        actual = actual->getSig();
    }

    std::sort(todosUsuarios.begin(), todosUsuarios.end(), 
        [](Usuarios* a, Usuarios* b) {
            return a->getLista_publicacionesP().obtenerTamanio() > b->getLista_publicacionesP().obtenerTamanio();
        });

    return std::vector<Usuarios*>(todosUsuarios.begin(), todosUsuarios.begin() + std::min(5, static_cast<int>(todosUsuarios.size())));
}

// Método para obtener los 5 usuarios con menos amigos
std::vector<Usuarios*> arrayList_us::top5UsuariosConMenosAmigos() {
    std::vector<Usuarios*> todosUsuarios;
    usuarios_Nodo* actual = primero;
    while (actual != nullptr) {
        todosUsuarios.push_back(&(actual->getDato()));
        actual = actual->getSig();
    }

    std::sort(todosUsuarios.begin(), todosUsuarios.end(), 
        [](Usuarios* a, Usuarios* b) {
            return a->getLista_amigos().size() < b->getLista_amigos().size();
        });

    return std::vector<Usuarios*>(todosUsuarios.begin(), todosUsuarios.begin() + std::min(5, static_cast<int>(todosUsuarios.size())));
}

// Método para graficar los 5 usuarios con más publicaciones
void arrayList_us::graficarTop5ConMasPublicaciones() {
    std::vector<Usuarios*> top5 = top5UsuariosConMasPublicaciones();
    std::ofstream archivo("top5_mas_publicaciones.dot");

    archivo << "digraph G {" << std::endl;
    archivo << "  rankdir=LR;" << std::endl;
    archivo << "  node [shape=record];" << std::endl;

    for (int i = 0; i < top5.size(); ++i) {
        archivo << "  node" << i << " [label=\"{Correo: " << top5[i]->getCorreo() 
                << "| Publicaciones: " << top5[i]->getLista_publicacionesP().obtenerTamanio() << "}\"];" << std::endl;
        if (i > 0) {
            archivo << "  node" << i-1 << " -> node" << i << ";" << std::endl;
        }
    }

    archivo << "}" << std::endl;
    archivo.close();

    std::cout << "Archivo top5_mas_publicaciones.dot generado correctamente." << std::endl;
}

// Método para graficar los 5 usuarios con menos amigos
void arrayList_us::graficarTop5ConMenosAmigos() {
    std::vector<Usuarios*> top5 = top5UsuariosConMenosAmigos();
    std::ofstream archivo("top5_menos_amigos.dot");

    archivo << "digraph G {" << std::endl;
    archivo << "  rankdir=LR;" << std::endl;
    archivo << "  node [shape=record];" << std::endl;

    for (int i = 0; i < top5.size(); ++i) {
        archivo << "  node" << i << " [label=\"{Correo: " << top5[i]->getCorreo() 
                << "| Amigos: " << top5[i]->getLista_amigos().size() << "}\"];" << std::endl;
        if (i > 0) {
            archivo << "  node" << i-1 << " -> node" << i << ";" << std::endl;
        }
    }

    archivo << "}" << std::endl;
    archivo.close();

    std::cout << "Archivo top5_menos_amigos.dot generado correctamente." << std::endl;
}


Usuarios* arrayList_us::buscarUsuarioPorID(int id) const {
    usuarios_Nodo* actual = primero;

    while (actual != nullptr) {
        if (actual->getDato().getID() == id) {
            return &actual->getDato();
        }
        actual = actual->getSig();
    }

    return nullptr; // Retorna nullptr si no se encuentra el usuario con el ID dado
}
