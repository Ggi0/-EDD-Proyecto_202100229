#include "listaSugerencias.h"
#include <iostream>

listaSugerencias::listaSugerencias() {
    this->cabeza = nullptr;
}

listaSugerencias::~listaSugerencias() {
    sugerenciaAmistad* actual = cabeza;
    while (actual != nullptr) {
        sugerenciaAmistad* siguiente = actual->getSiguiente();
        delete actual;
        actual = siguiente;
    }
}

void listaSugerencias::insertarOrdenado(int id, std::string nombre, int amigosComun) {
    sugerenciaAmistad* nuevo = new sugerenciaAmistad(id, nombre, amigosComun);

    // Si la lista está vacía o el nuevo tiene más amigos en común que la cabeza
    if (cabeza == nullptr || amigosComun > cabeza->getAmigosEnComun()) {
        nuevo->setSiguiente(cabeza);
        cabeza = nuevo;
        return;
    }

    // Buscar la posición correcta
    sugerenciaAmistad* actual = cabeza;
    while (actual->getSiguiente() != nullptr && 
           actual->getSiguiente()->getAmigosEnComun() >= amigosComun) {
        actual = actual->getSiguiente();
    }

    nuevo->setSiguiente(actual->getSiguiente());
    actual->setSiguiente(nuevo);
}

void listaSugerencias::mostrarSugerencias() {
    sugerenciaAmistad* actual = cabeza;
    while (actual != nullptr) {
        std::cout << actual->getNombre() << " - " 
                 << actual->getAmigosEnComun() << " amigos en común" << std::endl;
        actual = actual->getSiguiente();
    }
}