#include "enodo.h"

enodo::enodo(){
    this->siguiente = nullptr;
}
Usuarios enodo::getDestino(){
    return destino;
}

enodo* enodo::getSiguiente(){
    return siguiente;
}

void enodo::setDestino(Usuarios destino){
    this->destino = destino;
}

void enodo::setSiguiente(enodo* siguiente){
    this->siguiente = siguiente;
}