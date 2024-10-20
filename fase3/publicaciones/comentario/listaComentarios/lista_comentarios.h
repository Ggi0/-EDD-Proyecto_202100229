#ifndef LISTA_COMENTARIOS_H
#define LISTA_COMENTARIOS_H

#include "nodo_comentario.h"

#include <fstream>  // Para manejar archivos
#include <iostream>

#include <algorithm>
#include <vector>
#include <fstream>

class Comentario; 


class lista_comentarios{
    private:
        Nodo_com *primero;
        Nodo_com *ultimo;

    public:
        // ----- CONSTRUCTOR ------
        lista_comentarios();

        // ------ DESTRUCTOR ------
        ~lista_comentarios();

        // ------- METODOS --------
        void push(Comentario comentario);

        void append(Comentario comentario);
        int size();
        void pop();
        void printAll();
        void removeIf(bool (*condition)(const Comentario&));
        
        // Método para graficar la lista usando Graphviz
        void graficar() const; 

        // Métodos para acceder y modificar los nodos primero y último
        Nodo_com* getPrimero();
        void setPrimero(Nodo_com* nuevoPrimero);

        Nodo_com* getUltimo();
        void setUltimo(Nodo_com* nuevoUltimo);

        Comentario* buscarPorCorreo(const std::string& correo);
        void eliminarUsuario(const std::string& correo);
};

#endif // ARRAYLIST_US_H