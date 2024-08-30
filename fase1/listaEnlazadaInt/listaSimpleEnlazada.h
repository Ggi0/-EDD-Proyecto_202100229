#ifndef LISTA_SIMPLE_ENLAZADA
#define LISTA_SIMPLE_ENLAZADA

#include "Nodo.h"

class listaSimpleEnlazada{
    private:
        Nodo *primero; // puntero al tipo nodo
        Nodo *ultimo;

    public:
        // ---- CONSTRUCTOR -----
        listaSimpleEnlazada();

        // ----- DESTRUCTOR ------
        ~listaSimpleEnlazada();

        // ----- METODOS -------
        void push(int valor); // agregar al inicio de la lista
        void append(int valor); // agregar al final de la lista
        int pop();
        void insert(int indice, int valor); //insertar en un lugar especifico
        void print();
        void removeAt(int indice); // elimina en un indice espcifico
        int findIndex(int valor); // encuentra el indice de un valor concreto
        void graph();
        int size();

        Nodo* getPrimero() const;
};
#endif // LISTA_SIMPLE_ENLAZADA
