#include "nodoAVL_usuario.h"

NodoAVL::NodoAVL(Usuarios data) : 
    data(data), 
    drcha(nullptr), 
    izq(nullptr), 
    altura(1) {}

// Constructor de copia
NodoAVL::NodoAVL(const NodoAVL& other) : 
    data(other.data),
    drcha(nullptr),
    izq(nullptr),
    altura(other.altura) {}

// Operador de asignación
NodoAVL& NodoAVL::operator=(const NodoAVL& other) {
    if (this != &other) {
        data = other.data;
        altura = other.altura;
        // No copiamos los punteros, eso lo maneja el árbol
    }
    return *this;
}


bool NodoAVL::esHoja(){
    return drcha == nullptr && izq == nullptr;
}

bool NodoAVL::tieneUnHijo(){
    return (drcha == nullptr && izq != nullptr) || (drcha != nullptr || izq == nullptr);
}

bool NodoAVL::tieneDosHijos(){
    return drcha != nullptr && izq != nullptr;
}

NodoAVL* NodoAVL::obtenerHijoUnico(){
    if(this->tieneUnHijo()){
        return (this->drcha != nullptr) ? this->drcha : this->izq;
    }  
    return nullptr;
}

// Devuelve una referencia modificable al objeto Usuarios
Usuarios& NodoAVL::getData() {
    return data;
}

// Devuelve una referencia constante al objeto Usuarios (para casos const)
const Usuarios& NodoAVL::getData() const {
    return data;
}

int NodoAVL::getAltura(){
    return altura;
}

NodoAVL* NodoAVL::getDrcha(){
    return drcha;
}

NodoAVL* NodoAVL::getIzq(){
    return izq;
}

void NodoAVL::setData(Usuarios data){
    this->data = data;
}

void NodoAVL::setAltura(int altura){
    this->altura = altura;
}

void NodoAVL::setDrcha(NodoAVL *drcha){
    this->drcha = drcha;
}

void NodoAVL::setIzq(NodoAVL *izq){
    this->izq = izq;
}