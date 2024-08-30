#ifndef LISTAD_ENLAZADAP_H
#define LISTAD_ENLAZADAP_H

#include "publicacion_Nodo.h"
#include <fstream>
#include <iostream>

class ListaDoblementeEnlazadaP {
private:
    PublicacionNodo* primero;  // Puntero al primer nodo de la lista
    PublicacionNodo* ultimo;   // Puntero al último nodo de la lista

public:
    // Constructor
    ListaDoblementeEnlazadaP();

    // Destructor
    ~ListaDoblementeEnlazadaP();

    // Métodos para insertar elementos
    void push(const Publicacion& data);    // Inserta al inicio
    void append(const Publicacion& data);  // Inserta al final
    void insert(int indice, const Publicacion& data);  // Inserta en una posición específica

    // Métodos para imprimir la lista
    void print() const;    // Imprime de inicio a fin
    void revPrint() const; // Imprime de fin a inicio

    // Método para graficar la lista usando Graphviz
    void graficar() const;
};

#endif // LISTAD_ENLAZADAP_H