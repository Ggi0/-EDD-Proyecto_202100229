#ifndef AVL_USUARIO_H
#define AVL_USUARIO_H

#include "nodoAVL_usuario.h"

class AVL{
    private:
        NodoAVL *raiz;

        NodoAVL* insert(NodoAVL *raiz, Usuarios data);
        NodoAVL* del(NodoAVL *raiz, Usuarios data);
        NodoAVL* rotacionIzquierda(NodoAVL *raiz);
        NodoAVL* rotacionDerecha(NodoAVL *raiz);
        NodoAVL* obtenerMayorDeMenores(NodoAVL *raiz);

        // Método privado auxiliar para la búsqueda recursiva
        NodoAVL* buscarPorCorreoRecursivo(NodoAVL* nodo, const std::string& correo) const;
        NodoAVL* buscarPorIDRecursivo(NodoAVL* nodo, int ID) const;

        int alturaMaxima(int izq, int drch);
        int obtenerAltura(NodoAVL *raiz);
        int obtenerBalance(NodoAVL *raiz);

        void postOrden(NodoAVL *raiz, bool accion);
        void preOrden(NodoAVL *raiz);
        void inOrden(NodoAVL *raiz);
        void graph(NodoAVL *raiz, std::ofstream &f);

        NodoAVL* delPorCorreo(NodoAVL* raiz, std::string correo);

    public:
        AVL();
        ~AVL();

        void insert(Usuarios data);
        void del(Usuarios data);

        void preOrden();
        void inOrden();
        void postOrden();
        void graph();

        // Nuevo método para obtener la raíz del árbol
        NodoAVL* getRaiz() const;

        // Nuevo método para buscar un usuario por correo
        NodoAVL* buscarPorCorreo(const std::string& correo) const;
        NodoAVL* buscarPorID(int ID) const;

        void delPorCorreo(std::string correo);
};

#endif // AVL_USUARIO_H