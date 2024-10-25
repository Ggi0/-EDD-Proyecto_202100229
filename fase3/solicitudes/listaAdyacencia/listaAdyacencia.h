#ifndef LISTA_ADYACENCIA_H
#define LISTA_ADYACENCIA_H

#include "vnodo.h"
#include "../../usuarios/usuario.h"

class Usuarios; // Declaración adelantada
class listaAdyacencia{
    private:
        vnodo *cabeza;

    public:
        listaAdyacencia();
        ~listaAdyacencia();

        void insert(Usuarios);
        void crearConexion(Usuarios, Usuarios);
        void crearGrafo();
        void crearGrafoLista();
};

#endif // 