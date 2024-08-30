#ifndef PUBLICACION_NODO_H
#define PUBLICACION_NODO_H

#include "../publicaciones/publicacion.h"

class PublicacionNodo {
private:
    Publicacion data;
    PublicacionNodo* prev;
    PublicacionNodo* sig;

public:
    PublicacionNodo(const Publicacion& publicacion);

    void setData(const Publicacion& publicacion);
    void setSig(PublicacionNodo* sig);
    void setPrev(PublicacionNodo* prev);

    Publicacion getData() const;
    PublicacionNodo* getPrev() const;   
    PublicacionNodo* getSig() const;    
};

#endif // PUBLICACION_NODO_H