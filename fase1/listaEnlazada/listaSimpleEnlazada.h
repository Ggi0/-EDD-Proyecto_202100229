
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
        void insert(int indice, int valor); //insertar en un lugar especifico
        void print();
        void graph();
};
