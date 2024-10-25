#ifndef E_NODO_H
#define E_NODO_H

#include <iostream>
#include <fstream>
#include <sstream>
#include "../../usuarios/usuario.h"


class Usuarios; // Declaración adelantada

/*
  Representa las conexiones/aristas entre los vértices del grafo
  Cada nodo tiene un destino (usuarios) y un puntero al siguiente nodo
  Es básicamente una lista enlazada que guarda los destinos de cada vértice
*/
class enodo{
    private:
      Usuarios destino;
      enodo *siguiente;

    public:
        enodo();

        // ----- GETTERS ---------
        Usuarios getDestino();
        enodo* getSiguiente();

        // ------ SETTERS --------
        void setDestino(Usuarios); 
        void setSiguiente(enodo*); 
};

#endif // E_NODO_H