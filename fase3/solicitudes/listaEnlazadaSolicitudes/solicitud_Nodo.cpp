#include "solicitud_Nodo.h"

// Constructores
solicitud_Nodo::solicitud_Nodo() : dato(), sig(nullptr) {
}

solicitud_Nodo::solicitud_Nodo(Solicitud valor) : dato(valor), sig(nullptr) {
}

// Constructor de copia
solicitud_Nodo::solicitud_Nodo(const solicitud_Nodo& otro) : dato(otro.dato), sig(nullptr) {
}

// Operador de asignación
solicitud_Nodo& solicitud_Nodo::operator=(const solicitud_Nodo& otro) {
    if (this != &otro) {
        dato = otro.dato;
        // No copiamos el puntero sig, eso lo maneja la lista
        // sig = nullptr;
    }
    return *this;
}

// Destructor
solicitud_Nodo::~solicitud_Nodo() {
    // No eliminamos sig aquí, eso lo maneja la lista
    sig = nullptr;
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