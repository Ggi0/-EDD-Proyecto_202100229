#include "../Registro/Usuarios.h"
#include <iostream>

class Nodo {
private:
    Usuarios dato;
    Nodo *sig;

public:
    Nodo(Usuarios valor);
    
    // Getters y Setters
    Usuarios getDato() const;
    void setDato(Usuarios valor);
    Nodo* getSig() const;
    void setSig(Nodo* siguiente);
};
