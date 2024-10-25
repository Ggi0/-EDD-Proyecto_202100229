#ifndef V_NODO_H
#define V_NODO_H

#include "enodo.h"
#include <iostream>

#include "../../usuarios/usuario.h"
class Usuarios; // Declaración adelantada

/*
    Representa los vértices/nodos del grafo
    Cada vértice tiene:

    data (nombre del vértice)
    destinos (puntero a lista de aristas/enodo)
    siguiente (puntero al siguiente vértice)


    Maneja la inserción de destinos y la graficación
*/
class vnodo{
    private:
        Usuarios data;
        vnodo *siguiente;
        enodo *destinos;

    public:
        vnodo();
        ~vnodo();

        void insertarDestino(Usuarios);
        void graficarAristas(std::ofstream&);
        void graficarListaDestinos(std::ofstream&);

        // ------- GETTERS ---------
        Usuarios getData();
        vnodo* getSiguiente();
        enodo* getDestinos();

        // ------- SETTERS ---------
        void setData(Usuarios);
        void setSiguiente(vnodo*);
        void setDestinos(enodo*);
};

#endif // V_NODO_H