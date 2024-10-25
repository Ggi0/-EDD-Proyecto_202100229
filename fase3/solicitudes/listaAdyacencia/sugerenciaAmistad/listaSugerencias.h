#ifndef LISTASUGERENCIAS_H
#define LISTASUGERENCIAS_H

#include "sugerenciaAmistad.h"

class listaSugerencias {
private:
    sugerenciaAmistad* cabeza;

public:
    listaSugerencias();
    ~listaSugerencias();
    
    // Inserta ordenadamente por cantidad de amigos en común (descendente)
    void insertarOrdenado(int id, std::string nombre, int amigosComun);
    // Muestra las sugerencias
    void mostrarSugerencias();
};

#endif
