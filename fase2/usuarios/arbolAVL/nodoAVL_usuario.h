#ifndef NODO_AVL_USUARIO_H
#define NODO_AVL_USUARIO_H

#include <iostream>
#include <fstream>
#include <sstream>
#include "../usuario.h"


class Usuarios; // Declaración adelantada


class NodoAVL{
    private:
        // data es la informacion que va tener el nodo, un usuario
        Usuarios data;
        int altura;

        // apuntadores hacia derecha e izquieda
        NodoAVL *drcha;
        NodoAVL *izq;

    public:
        NodoAVL(Usuarios value);

        // -------- GETTERS ------------
        Usuarios& getData();
        const Usuarios& getData() const;
        NodoAVL* getDrcha();
        NodoAVL* getIzq();
        NodoAVL* obtenerHijoUnico();
        int getAltura();

        bool esHoja();
        bool tieneUnHijo();
        bool tieneDosHijos();

        // -------- SETTERS ------------
        void setData(Usuarios data);
        void setDrcha(NodoAVL *drcha);
        void setIzq(NodoAVL *Izq);
        void setAltura(int altura);
};

#endif // USUARIOS_NODO_H