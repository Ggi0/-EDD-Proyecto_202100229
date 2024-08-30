#include "solicitud_Nodo.h"

// Constructores
solicitud_Nodo::solicitud_Nodo() : dato(), sig(nullptr) {
}

solicitud_Nodo::solicitud_Nodo(Solicitud valor) : dato(valor), sig(nullptr) {
}

// Getters y Setters
void solicitud_Nodo::setDato(Solicitud dato){
    this->dato = dato;
}

void solicitud_Nodo::setSig(solicitud_Nodo *sig){
    this->sig = sig;
}

Solicitud& solicitud_Nodo::getDato() {
    return dato;
}

const Solicitud& solicitud_Nodo::getDato() const {
    return dato;
}

solicitud_Nodo* solicitud_Nodo::getSig(){
    return sig;
}