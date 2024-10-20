#ifndef SOLICITUD_PILA_H
#define SOLICITUD_PILA_H

#include "solicitudPila_Nodo.h"
#include <fstream> 
#include <stdexcept>
#include <iostream> // Incluir la biblioteca para la entrada y salida estándar

class solicitud_pila {
    private:
        solicitudPila_Nodo* tope;
        int tamano;

    public:
        solicitud_pila();
        solicitud_pila(const solicitud_pila& otra);         // Constructor de copia
        ~solicitud_pila();                                  // Destructor
        // Operador de asignación
        solicitud_pila& operator=(const solicitud_pila& otra);

        void push(const Solicitud& solicitud);
        void pop();
        Solicitud top() const;
        bool estaVacia() const;
        int size() const;
        void imprimir() const;

        void grafica() const;
};

#endif // SOLICITUD_PILA_H