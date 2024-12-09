#ifndef NODO_BLOQUES_H
#define NODO_BLOQUES_H

#include "../bloque.h"
#include <iostream>

class Bloque_Nodo {
    private:
        Bloque dato;
        Bloque_Nodo *sig; // puntero a otro nodo

    public:
        // Constructores
        Bloque_Nodo();
        //Bloque_Nodo(Bloque valor);

        explicit Bloque_Nodo(Bloque valor);
        // Constructor de copia
        Bloque_Nodo(const Bloque_Nodo& otro);
        // Operador de asignación
        Bloque_Nodo& operator=(const Bloque_Nodo& otro);
        // Destructor
        ~Bloque_Nodo();
        
        // Getters y Setters
        void setSig(Bloque_Nodo* sig);
        void setDato(Bloque valor);

        Bloque& getDato(); // Cambiado para devolver una referencia
        const Bloque& getDato() const; // Versión const

        Bloque_Nodo* getSig();
};
#endif // SOLICITUD_NODO_H