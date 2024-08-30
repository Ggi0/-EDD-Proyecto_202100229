#ifndef SOLICITUD_PILA_H
#define SOLICITUD_PILA_H

#include "solicitudPila_Nodo.h"
#include <fstream> 

class solicitud_pila {
    private:
        solicitudPila_Nodo* tope;
        int tamano;

    public:
        solicitud_pila();
        ~solicitud_pila();

        void push(const Solicitud& solicitud);
        void pop();
        Solicitud top() const;
        bool estaVacia() const;
        int size() const;
        void imprimir() const;

        void grafica() const;
};

#endif // SOLICITUD_PILA_H