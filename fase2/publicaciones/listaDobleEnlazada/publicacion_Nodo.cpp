#include "publicacion_Nodo.h"

// Constructor
PublicacionNodo::PublicacionNodo(const Publicacion& publicacion) : data(publicacion), prev(nullptr), sig(nullptr) {}

// Getters y setters
Publicacion PublicacionNodo::getData() const {
    return data;
}

PublicacionNodo* PublicacionNodo::getPrev() const {
    return prev;
}

PublicacionNodo* PublicacionNodo::getSig() const {
    return sig;
}

void PublicacionNodo::setData(const Publicacion& publicacion) {
    this->data = publicacion;
}

void PublicacionNodo::setPrev(PublicacionNodo* prev) {
    this->prev = prev;
}

void PublicacionNodo::setSig(PublicacionNodo* sig) {
    this->sig = sig;
}