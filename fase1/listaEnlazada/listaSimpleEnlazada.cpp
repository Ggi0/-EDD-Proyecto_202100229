#include "listaSimpleEnlazada.h"

// Class::constructo/metodo/funcion
listaSimpleEnlazada::listaSimpleEnlazada(){
    primero = nullptr;
    ultimo = nullptr;
}

listaSimpleEnlazada::~listaSimpleEnlazada(){
    Nodo *tempo = primero; // puntero temporal que apunte a la cabeza
    Nodo *aux;

    // delete --> borra una direccione de memoria (deja de usarla)
    // Elimiar todos los nodos que se encuentren en la lista
    while(tempo != nullptr){
        aux = tempo -> getSig();  // 1) Guarda la dirección del siguiente nodo
        delete tempo;             // 2) Libera la memoria del nodo actual
        tempo = aux;              // 3) Avanza al siguiente nodo
    }
}

// insertar en la cabeza de la lista
void listaSimpleEnlazada::push(int valor){
    // new --> nueva direccion de memoria, que tendra el valor (parametro)
    Nodo *nuevo_Nodo = new Nodo(valor);

    // SI la lista esta vacia
    if(primero == nullptr){
        // el primero y ultimo apuntaran a la mismo nodo
        primero = nuevo_Nodo;
        ultimo = nuevo_Nodo;
    }else{
        // nuevo_Nodo ahora tendra la información por el setSig(que tenia el primero )
        nuevo_Nodo -> setSig(primero);

        // Entonces el primero (la cabeza) sera el nuevo nodo
        primero = nuevo_Nodo;
    }
}

void listaSimpleEnlazada::append(int valor){
    Nodo *nuevo_Nodo = new Nodo(valor);

    if(primero == nullptr){
        primero = nuevo_Nodo;
        ultimo = nuevo_Nodo;
    }else{
        ultimo -> setSig(nuevo_Nodo);
        ultimo = nuevo_Nodo;
    }
}

void listaSimpleEnlazada::print(){
    Nodo *tempo = primero;

    while(tempo != nullptr){
        std::cout <<tempo->getData() << ", ";
        tempo = tempo -> getSig();
    }
    std::cout<< std::endl;
}
