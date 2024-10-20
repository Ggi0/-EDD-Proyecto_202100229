#include "solicitudPila_Nodo.h"

/*
    Constructor de la clase solicitudPila_Nodo que inicializa el dato con el objeto solicitud 
    y establece el puntero siguiente a nullptr.
*/
solicitudPila_Nodo::solicitudPila_Nodo(const Solicitud& solicitud) : dato(solicitud), siguiente(nullptr) {}


// Constructor de copia
solicitudPila_Nodo::solicitudPila_Nodo(const solicitudPila_Nodo& otro)
    : dato(otro.dato), siguiente(nullptr) {}


// Método getter que devuelve el dato almacenado en el nodo.
Solicitud solicitudPila_Nodo::getDato() const {return dato;}

// Método getter que devuelve el puntero al siguiente nodo en la pila.
solicitudPila_Nodo* solicitudPila_Nodo::getSiguiente() const {return siguiente;}

// Método setter que establece el puntero al siguiente nodo en la pila.
void solicitudPila_Nodo::setSiguiente(solicitudPila_Nodo* nodo) {siguiente = nodo;}