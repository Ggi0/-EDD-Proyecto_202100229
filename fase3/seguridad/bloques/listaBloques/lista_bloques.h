#ifndef LISTA_BLOQUES_H
#define LISTA_BLOQUES_H

#include "nodo_bloque.h"
#include <functional>
#include <fstream>
#include <iostream>

class listaBloques {
    private:
        Bloque_Nodo *primero;
        Bloque_Nodo *ultimo;

        // Método auxiliar para copiar lista
        void copiarLista(const listaBloques& otra);

    public:
        // Constructor
        listaBloques();

        // Destructor
        // Constructor de copia
        listaBloques(const listaBloques& otra);
        // Operador de asignación
        listaBloques& operator=(const listaBloques& otra);
        // Destructor
        ~listaBloques();

        // Métodos

        // Getters y setters
        Bloque_Nodo* getPrimero();
        void setPrimero(Bloque_Nodo* nuevoPrimero);

        Bloque_Nodo* getUltimo();  // Nuevo método
        void setUltimo(Bloque_Nodo* nuevoUltimo);  // Nuevo método // Método para añadir un nodo al final de la lista


        void push(Bloque bloque);
        void append(Bloque bloque);
        int size();
        void pop();
        void printAll();

        void removeIf(std::function<bool(const Bloque&)> predicado);

        void grafica() const;
        

};

#endif // ARRAYLIST_SOLI_H