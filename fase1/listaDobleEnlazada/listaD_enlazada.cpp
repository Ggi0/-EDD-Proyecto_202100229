#include "listaD_enlazadaP.h"


// Constructor
ListaDoblementeEnlazadaP::ListaDoblementeEnlazadaP() : primero(nullptr), ultimo(nullptr) {}

// Destructor
ListaDoblementeEnlazadaP::~ListaDoblementeEnlazadaP() {
    PublicacionNodo* temp = primero;
    PublicacionNodo* aux;

    // Recorre la lista liberando la memoria de cada nodo
    while (temp != nullptr) {
        aux = temp->getSig();  // Guarda el puntero al siguiente nodo
        delete temp;           // Libera la memoria del nodo actual
        temp = aux;            // Avanza al siguiente nodo
    }

    // No es necesario establecer primero y ultimo a nullptr
    // ya que el objeto será destruido de todas formas
}

// Inserta una nueva publicación al inicio de la lista
void ListaDoblementeEnlazadaP::push(const Publicacion& data) {
    PublicacionNodo* nuevo = new PublicacionNodo(data);

    if (primero == nullptr) {
        // Si la lista está vacía, el nuevo nodo es tanto el primero como el último
        primero = nuevo;
        ultimo = nuevo;
    } else {
        // Si la lista no está vacía, insertamos al inicio
        nuevo->setSig(primero);
        primero->setPrev(nuevo);
        primero = nuevo;
    }
}

// Inserta una nueva publicación al final de la lista
void ListaDoblementeEnlazadaP::append(const Publicacion& data) {
    PublicacionNodo* nuevo = new PublicacionNodo(data);

    if (primero == nullptr) {
        // Si la lista está vacía, el nuevo nodo es tanto el primero como el último
        primero = nuevo;
        ultimo = nuevo;
    } else {
        // Si la lista no está vacía, insertamos al final
        nuevo->setPrev(ultimo);
        ultimo->setSig(nuevo);
        ultimo = nuevo;
    }
}

// Inserta una nueva publicación en una posición específica
void ListaDoblementeEnlazadaP::insert(int indice, const Publicacion& data) {
    PublicacionNodo* nuevo = new PublicacionNodo(data);
    PublicacionNodo* actual = primero;

    if (primero == nullptr || indice == 0) {
        // Si la lista está vacía o se inserta al inicio, usamos push
        push(data);
        return;
    }

    int i = 0;
    while (actual->getSig() != nullptr && i < indice - 1) {
        actual = actual->getSig();
        i++;
    }

    if (i < indice - 1) {
        // Si el índice es mayor que el tamaño de la lista, insertamos al final
        append(data);
        return;
    }

    // Insertamos el nuevo nodo en la posición correcta
    nuevo->setSig(actual->getSig());
    nuevo->setPrev(actual);
    if (actual->getSig() != nullptr) {
        actual->getSig()->setPrev(nuevo);
    } else {
        ultimo = nuevo;
    }
    actual->setSig(nuevo);
}

// Imprime la lista de inicio a fin
void ListaDoblementeEnlazadaP::print() const {
    PublicacionNodo* temp = primero;
    std::cout<<"lista global de publicaciones (desde el metodo): "<<std::endl;
    while (temp != nullptr) {
        temp->getData().printPublicacion();  // Imprime los datos de la publicación
        std::cout << " -> "<<std::endl;
        temp = temp->getSig();
    }
    std::cout << "nullptr" << std::endl;
}

// Imprime la lista de fin a inicio
void ListaDoblementeEnlazadaP::revPrint() const {
    PublicacionNodo* temp = ultimo;

    while (temp != nullptr) {
        temp->getData().printPublicacion();  // Imprime los datos de la publicación
        std::cout << " -> ";
        temp = temp->getPrev();
    }
    std::cout << "nullptr" << std::endl;
}


void ListaDoblementeEnlazadaP::graficar() const {
    std::ofstream archivo("lista_doblemente_enlazada.dot");
    archivo << "digraph G {" << std::endl;
    archivo << "    node [shape=record];" << std::endl;
    
    PublicacionNodo* temp = primero;
    int i = 0;
    
    while (temp != nullptr) {
        archivo << "    node" << i << " [label=\"{";
        archivo << "Correo: " << temp->getData().getCorreoP() << "\\n";
        archivo << "Contenido: " << temp->getData().getContenido() << "\\n";
        archivo << "Fecha: " << temp->getData().getFecha() << "\\n";
        archivo << "Hora: " << temp->getData().getHora() << "}\"];" << std::endl;
        
        if (temp->getSig() != nullptr) {
            archivo << "    node" << i << " -> node" << i+1 << ";" << std::endl;
        }
        
        if (temp->getPrev() != nullptr) {
            archivo << "    node" << i << " -> node" << i-1 << ";" << std::endl;
        }
        
        temp = temp->getSig();
        i++;
    }
    
    archivo << "}" << std::endl;
    archivo.close();
    
    std::cout << "Archivo DOT generado: lista_doblemente_enlazada.dot" << std::endl;
}