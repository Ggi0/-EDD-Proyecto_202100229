#include "NodoUs.h"

// ------- CONSTRUCTORES --------
Nodo::Nodo(){
    dato;
    sig = nullptr;
}

Nodo::Nodo(Usuarios valor){
    this -> dato = dato;
    sig = nullptr;
}

// GETTER AND SETTER
void Nodo::setDato(Usuarios dato){
    this-> dato = dato;
}

void Nodo::setSig(Nodo *sig){
    this->sig = sig;
}

Usuarios Nodo::getDato(){
    return dato;
}

Nodo* Nodo::getSig(){
    return sig;
}
