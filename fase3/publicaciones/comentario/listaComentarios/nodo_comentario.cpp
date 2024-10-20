#include "nodo_comentario.h"

// ------- CONSTRUCTORES --------
// Constructor por defecto
Nodo_com::Nodo_com() : data(), sig(nullptr) {
    // Inicializa dato si es necesario
}

// Constructor que inicializa con un valor de Usuarios
Nodo_com::Nodo_com(Comentario valor) : data(valor), sig(nullptr) {
    // Los valores ya están inicializados en la lista de inicialización
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