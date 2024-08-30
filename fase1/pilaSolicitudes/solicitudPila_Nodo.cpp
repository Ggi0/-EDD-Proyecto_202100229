#include "solicitudPila_Nodo.h"

solicitudPila_Nodo::solicitudPila_Nodo(const Solicitud& solicitud) : dato(solicitud), siguiente(nullptr) {}

Solicitud solicitudPila_Nodo::getDato() const {
    return dato;
}

solicitudPila_Nodo* solicitudPila_Nodo::getSiguiente() const {
    return siguiente;
}

void solicitudPila_Nodo::setSiguiente(solicitudPila_Nodo* nodo) {
    siguiente = nodo;
}