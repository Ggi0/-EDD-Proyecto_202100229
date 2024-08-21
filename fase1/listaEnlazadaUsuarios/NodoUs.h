#include "../Registro/Usuarios.h"
#include <iostream>

class Nodo {
    private:
        Usuarios dato;
        Nodo *sig; // puntero a otro nodo

    public:
        // --- contructor ----
        Nodo();
        Nodo(Usuarios valor);
        
        // Getters y Setters
        void setSig(Nodo* sig);
        void setDato(Usuarios valor);

        Usuarios getDato();
        Nodo* getSig();
};
