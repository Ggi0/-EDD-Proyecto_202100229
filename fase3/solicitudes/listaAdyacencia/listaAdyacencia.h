#ifndef LISTA_ADYACENCIA_H
#define LISTA_ADYACENCIA_H

#include "vnodo.h"
#include "../../usuarios/usuario.h"
#include "sugerenciaAmistad/listaSugerencias.h"
#include <iostream>
#include <set>

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

        // sugerir amistad:
        listaSugerencias* sugerirAmistades(std::string correo);
        void graficoPersonal(std::string correo);
};

#endif // 