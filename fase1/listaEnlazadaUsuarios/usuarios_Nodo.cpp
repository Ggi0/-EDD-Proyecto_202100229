#include "usuarios_Nodo.h"

// ------- CONSTRUCTORES --------
// Constructor por defecto
usuarios_Nodo::usuarios_Nodo() : dato(), sig(nullptr) {
    // Inicializa dato si es necesario
}

// Constructor que inicializa con un valor de Usuarios
usuarios_Nodo::usuarios_Nodo(Usuarios valor) : dato(valor), sig(nullptr) {
    // Los valores ya están inicializados en la lista de inicialización
}

// GETTER AND SETTER
void usuarios_Nodo::setDato(Usuarios dato){
    this-> dato = dato;
}

void usuarios_Nodo::setSig(usuarios_Nodo *sig){
    this->sig = sig;
}

Usuarios& usuarios_Nodo::getDato() {
    return dato;
}

usuarios_Nodo* usuarios_Nodo::getSig(){
    return sig;
}
