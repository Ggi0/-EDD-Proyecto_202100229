#include "arrayListUs.h"

// Constructor
arrayList_us::arrayList_us(){
    primero = nullptr;
    ultimo = nullptr;
}

// Destructor
arrayList_us::~arrayList_us() {
    Nodo *tempo = primero;
    Nodo *aux;
    while (tempo != nullptr) {
        aux = tempo->getSig();
        delete tempo;
        tempo = aux;
    }
}

// Insertar un nodo al inicio de la lista
void arrayList_us::push(Usuarios usuario) {
    Nodo *nuevo_Nodo = new Nodo(usuario);
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
    Nodo *nuevo_Nodo = new Nodo(usuario);
    if (primero == nullptr) {
        primero = nuevo_Nodo;
        ultimo = nuevo_Nodo;
    } else {
        ultimo->setSig(nuevo_Nodo);
        ultimo = nuevo_Nodo;
    }
}
