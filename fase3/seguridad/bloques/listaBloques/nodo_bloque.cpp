#include "nodo_bloque.h"

// Constructores
Bloque_Nodo::Bloque_Nodo() : dato(), sig(nullptr) {
}

Bloque_Nodo::Bloque_Nodo(Bloque valor) : dato(valor), sig(nullptr) {
}

// Constructor de copia
Bloque_Nodo::Bloque_Nodo(const Bloque_Nodo& otro) : dato(otro.dato), sig(nullptr) {
}

// Operador de asignación
Bloque_Nodo& Bloque_Nodo::operator=(const Bloque_Nodo& otro) {
    if (this != &otro) {
        dato = otro.dato;
        // No copiamos el puntero sig, eso lo maneja la lista
        // sig = nullptr;
    }
    return *this;
}

// Destructor
Bloque_Nodo::~Bloque_Nodo() {
    // No eliminamos sig aquí, eso lo maneja la lista
    sig = nullptr;
}

// Getters y Setters
void Bloque_Nodo::setDato(Bloque dato){
    this->dato = dato;
}

void Bloque_Nodo::setSig(Bloque_Nodo *sig){
    this->sig = sig;
}

Bloque& Bloque_Nodo::getDato() {
    return dato;
}

const Bloque& Bloque_Nodo::getDato() const {
    return dato;
}

Bloque_Nodo* Bloque_Nodo::getSig(){
    return sig;
}