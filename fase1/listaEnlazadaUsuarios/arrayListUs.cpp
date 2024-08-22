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



// Método para imprimir todos los usuarios en la lista
void arrayList_us::printAll() {
    usuarios_Nodo *actual = primero;  // Empezar desde el primer nodo

    // Recorrer toda la lista
    while (actual != nullptr) {
        actual->getDato().printUsuario();  // Llamar al método printUsuario de cada objeto Usuario
        actual = actual->getSig();  // Avanzar al siguiente nodo
    }
}

