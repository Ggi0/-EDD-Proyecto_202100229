#ifndef SOLICITUD_NODO_H
#define SOLICITUD_NODO_H

#include "../solicitud.h"
#include <iostream>

class solicitud_Nodo {
    private:
        Solicitud dato;
        solicitud_Nodo *sig; // puntero a otro nodo

    public:
        // Constructores
        solicitud_Nodo();
        //solicitud_Nodo(Solicitud valor);

        explicit solicitud_Nodo(Solicitud valor);
        // Constructor de copia
        solicitud_Nodo(const solicitud_Nodo& otro);
        // Operador de asignación
        solicitud_Nodo& operator=(const solicitud_Nodo& otro);
        // Destructor
        ~solicitud_Nodo();
        
        // Getters y Setters
        void setSig(solicitud_Nodo* sig);
        void setDato(Solicitud valor);

        Solicitud& getDato(); // Cambiado para devolver una referencia
        const Solicitud& getDato() const; // Versión const

        solicitud_Nodo* getSig();
};
#endif // SOLICITUD_NODO_H