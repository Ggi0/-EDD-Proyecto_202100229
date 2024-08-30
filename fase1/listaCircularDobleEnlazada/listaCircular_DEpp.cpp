#include "listaCircular_DEpp.h"
#include <iostream>

// ---------- CONSTRUCTOR ----------
ListaCircular_Dpp::ListaCircular_Dpp() : primero(nullptr), tamanio(0) {}

// ---------- DESTRUCTOR ------------
ListaCircular_Dpp::~ListaCircular_Dpp() {
    limpiarLista();
}

// Inserta una nueva publicación al inicio de la lista.
void ListaCircular_Dpp::insertarInicio(const Publicacion& pub) {
    pPersonal_Nodo* nuevo = new pPersonal_Nodo(pub);

    if (estaVacia()) {
        // Si la lista está vacía, el nuevo nodo apunta a sí mismo como siguiente y anterior.
        nuevo->setSiguiente(nuevo);
        nuevo->setAnterior(nuevo);
        primero = nuevo;
    } else {
        // Actualizamos los enlaces para insertar el nuevo nodo al inicio.
        nuevo->setSiguiente(primero);
        nuevo->setAnterior(primero->getAnterior());
        primero->getAnterior()->setSiguiente(nuevo);
        primero->setAnterior(nuevo);
        primero = nuevo;
    }

    tamanio++; // Incrementamos el tamaño de la lista.
}

// Inserta una nueva publicación al final de la lista.
void ListaCircular_Dpp::insertarFinal(const Publicacion& pub) {
    if (estaVacia()) {
        insertarInicio(pub); // Si la lista está vacía, usamos insertarInicio.
    } else {
        pPersonal_Nodo* nuevo = new pPersonal_Nodo(pub);

        // Actualizamos los enlaces para insertar el nuevo nodo al final.
        nuevo->setAnterior(primero->getAnterior());
        nuevo->setSiguiente(primero);
        primero->getAnterior()->setSiguiente(nuevo);
        primero->setAnterior(nuevo);

        tamanio++; // Incrementamos el tamaño de la lista.
    }
}

// Elimina el primer nodo de la lista.
void ListaCircular_Dpp::eliminarInicio() {
    if (!estaVacia()) {
        pPersonal_Nodo* temp = primero;

        if (tamanio == 1) {
            // Si solo hay un nodo, la lista queda vacía.
            primero = nullptr;
        } else {
            // Actualizamos los enlaces para eliminar el primer nodo.
            primero->getAnterior()->setSiguiente(primero->getSiguiente());
            primero->getSiguiente()->setAnterior(primero->getAnterior());
            primero = primero->getSiguiente();
        }

        delete temp; // Liberamos la memoria del nodo eliminado.
        tamanio--; // Decrementamos el tamaño de la lista.
    }
}

// Elimina el último nodo de la lista.
void ListaCircular_Dpp::eliminarFinal() {
    if (!estaVacia()) {
        if (tamanio == 1) {
            eliminarInicio(); // Si solo hay un nodo, usamos eliminarInicio.
        } else {
            pPersonal_Nodo* ultimo = primero->getAnterior();

            // Actualizamos los enlaces para eliminar el último nodo.
            ultimo->getAnterior()->setSiguiente(primero);
            primero->setAnterior(ultimo->getAnterior());

            delete ultimo; // Liberamos la memoria del nodo eliminado.
            tamanio--; // Decrementamos el tamaño de la lista.
        }
    }
}

// Elimina el nodo que contiene la publicación con el correo especificado.
void ListaCircular_Dpp::eliminarPublicacion(const std::string& correo) {
    if (!estaVacia()) {
        pPersonal_Nodo* actual = primero;

        do {
            if (actual->getData().getCorreoP() == correo) {
                if (actual == primero) {
                    eliminarInicio(); // Si el nodo a eliminar es el primero, usamos eliminarInicio.
                } else {
                    // Actualizamos los enlaces para eliminar el nodo específico.
                    actual->getAnterior()->setSiguiente(actual->getSiguiente());
                    actual->getSiguiente()->setAnterior(actual->getAnterior());
                    delete actual; // Liberamos la memoria del nodo eliminado.
                    tamanio--; // Decrementamos el tamaño de la lista.
                }
                return;
            }
            actual = actual->getSiguiente();
        } while (actual != primero);
    }
}

// Busca un nodo con una publicación cuyo correo coincida con el especificado.
pPersonal_Nodo* ListaCircular_Dpp::buscarPublicacion(const std::string& correo) const {
    if (!estaVacia()) {
        pPersonal_Nodo* actual = primero;

        do {
            if (actual->getData().getCorreoP() == correo) {
                return actual; // Retorna el nodo encontrado.
            }
            actual = actual->getSiguiente();
        } while (actual != primero);
    }
    return nullptr; // Retorna nullptr si no se encuentra el nodo.
}

// Muestra todas las publicaciones en la lista.
void ListaCircular_Dpp::mostrarLista() const {
    if (!estaVacia()) {
        pPersonal_Nodo* actual = primero;

        do {
            actual->getData().printPublicacion(); // Imprime la publicación del nodo actual.
            actual = actual->getSiguiente();
        } while (actual != primero);
    } else {
        std::cout << "La lista está vacía." << std::endl;
    }
}

// Verifica si la lista está vacía.
bool ListaCircular_Dpp::estaVacia() const {
    return tamanio == 0; // Retorna true si el tamaño es 0.
}

// Obtiene el número de nodos en la lista.
int ListaCircular_Dpp::obtenerTamanio() const {
    return tamanio; // Retorna el tamaño actual de la lista.
}

// Libera toda la memoria ocupada por los nodos en la lista.
void ListaCircular_Dpp::limpiarLista() {
    while (!estaVacia()) {
        eliminarInicio(); // Elimina nodos hasta que la lista esté vacía.
    }
}

pPersonal_Nodo* ListaCircular_Dpp::getPrimero() const {
    return primero;
}


void ListaCircular_Dpp::grafica() const {
    if (!estaVacia()) {
        std::ofstream archivo("listaCircular.dot");
        archivo << "digraph G {" << std::endl;
        archivo << "    rankdir=LR;" << std::endl;
        archivo << "    node [shape=record];" << std::endl;

        pPersonal_Nodo* actual = primero;
        int contador = 0;

        // Generar nodos con su contenido
        do {
            archivo << "    node" << contador << " [label=\"{<ant> | " 
                    << "Correo: " << actual->getData().getCorreoP() << "\\n"
                    << "Contenido: " << actual->getData().getContenido() << "\\n"
                    << "Fecha: " << actual->getData().getFecha() << "\\n"
                    << "Hora: " << actual->getData().getHora() << " | <sig>}\"];" << std::endl;
            actual = actual->getSiguiente();
            contador++;
        } while (actual != primero);

        // Generar conexiones entre nodos
        for (int i = 0; i < contador; i++) {
            archivo << "    node" << i << ":sig -> node" << (i + 1) % contador << ":ant;" << std::endl;
            archivo << "    node" << (i + 1) % contador << ":ant -> node" << i << ":sig;" << std::endl;
        }

        archivo << "}" << std::endl;
        archivo.close();

        // Comando para generar la imagen a partir del archivo .dot
        system("dot -Tpng listaCircular.dot -o listaCircular.png");
    } else {
        std::cout << "La lista está vacía. No se puede generar la gráfica." << std::endl;
    }
}
