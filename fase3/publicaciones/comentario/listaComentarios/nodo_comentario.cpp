#include "nodo_comentario.h"

// ------- CONSTRUCTORES --------
// Constructor por defecto
Nodo_com::Nodo_com() : data(), sig(nullptr) {}

// Constructor con valor de `Comentario`
Nodo_com::Nodo_com(Comentario valor) : data(valor), sig(nullptr) {}

// Constructor de copia
Nodo_com::Nodo_com(const Nodo_com& other) : data(other.data), sig(nullptr) {}

// Operador de asignación
Nodo_com& Nodo_com::operator=(const Nodo_com& other) {
    if (this != &other) {
        data = other.data;
        sig = nullptr;
    }
    return *this;
}

// Destructor
Nodo_com::~Nodo_com() {
    sig = nullptr; // Asegurarse de no intentar liberar `sig` aquí, ya que la lista lo maneja
}

// GETTER AND SETTER
void Nodo_com::setData(Comentario data){
    this-> data = data;
}

void Nodo_com::setSig(Nodo_com *sig){
    this->sig = sig;
}

Comentario& Nodo_com::getData() {
    return data;
}

Nodo_com* Nodo_com::getSig(){
    return sig;
}