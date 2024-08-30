#ifndef PPERSONAL_NODO_H
#define PPERSONAL_NODO_H

#include <string>
#include "../publicaciones/publicacion.h"

// Clase que representa un nodo en una lista doblemente enlazada para publicaciones personales.
class pPersonal_Nodo {
    private:
        Publicacion data;                  // Datos de la publicación almacenados en el nodo.
        pPersonal_Nodo* siguiente;         // Apuntador al siguiente nodo en la lista.
        pPersonal_Nodo* anterior;          // Apuntador al nodo anterior en la lista.

    public:
        // Constructor que inicializa el nodo con una publicación y apunta a nullptr para siguiente y anterior.
        pPersonal_Nodo(const Publicacion& pub);

        // Destructor para liberar recursos asociados con el nodo.
        ~pPersonal_Nodo();

        // ------ GETTERS ---------
        Publicacion getData() const;
        pPersonal_Nodo* getSiguiente() const;
        pPersonal_Nodo* getAnterior() const;

        // ------ SETTERS --------- 
        void setData(const Publicacion& pub);
        void setSiguiente(pPersonal_Nodo* sig);
        void setAnterior(pPersonal_Nodo* ant);
};

#endif // PPERSONAL_NODO_H