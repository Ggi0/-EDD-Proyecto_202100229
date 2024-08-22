#ifndef ARRAYLIST_US_H
#define ARRAYLIST_US_H

#include "usuarios_Nodo.h"

class arrayList_us{
    private:
        usuarios_Nodo *primero;
        usuarios_Nodo *ultimo;

    public:
        // ----- CONSTRUCTOR ------
        arrayList_us();

        // ------ DESTRUCTOR ------
        ~arrayList_us();

        // ------- METODOS --------
        void push(Usuarios usuario);
        void append(Usuarios usuario);
        int size();
        void pop();
        void printAll();

        usuarios_Nodo* getPrimero();
};

#endif // ARRAYLIST_US_H