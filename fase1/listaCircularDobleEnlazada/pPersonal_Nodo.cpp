#include "pPersonal_Nodo.h"

// Implementación de la clase pPersonal_Nodo

// CONSTRUCTOR que inicializa el nodo con una publicación. Los apuntadores siguiente y anterior se inicializan a nullptr.
pPersonal_Nodo::pPersonal_Nodo(const Publicacion& pub) : data(pub), siguiente(nullptr), anterior(nullptr) {}

// DESTRUCTOR. No es necesario liberar los apuntadores siguiente o anterior aquí, ya que eso se manejará en la clase de la lista.
pPersonal_Nodo::~pPersonal_Nodo() {}


// ------- GETTERS -------------

Publicacion pPersonal_Nodo::getData() const { return data; }
pPersonal_Nodo* pPersonal_Nodo::getSiguiente() const { return siguiente; }
pPersonal_Nodo* pPersonal_Nodo::getAnterior() const { return anterior; }

// ------- SETTERS ----------
void pPersonal_Nodo::setData(const Publicacion& pub) { data = pub; }
void pPersonal_Nodo::setSiguiente(pPersonal_Nodo* sig) { siguiente = sig; }
void pPersonal_Nodo::setAnterior(pPersonal_Nodo* ant) { anterior = ant; }
