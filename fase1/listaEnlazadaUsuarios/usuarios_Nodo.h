#ifndef NODOUS_H
#define NODOUS_H

#include "../Registro/Usuarios.h"
#include <iostream>

class usuarios_Nodo {
    private:
        Usuarios dato;
        usuarios_Nodo *sig; // puntero a otro nodo

    public:
        // --- contructor ----
        usuarios_Nodo();
        usuarios_Nodo(Usuarios valor);
        
        // Getters y Setters
        void setSig(usuarios_Nodo* sig);
        void setDato(Usuarios valor);

        Usuarios getDato();
        usuarios_Nodo* getSig();
};
#endif // NODOUS_H
