#ifndef ARRAYLISTUS_H
#define ARRAYLISTUS_H

#include "usuarios_Nodo.h"

#include <fstream>  // Para manejar archivos
#include <iostream>

#include <algorithm>
#include <vector>
#include <fstream>

class Usuarios; 


class arrayList_us{
    private:
        usuarios_Nodo *primero;
        usuarios_Nodo *ultimo;

    public:
        // ----- CONSTRUCTOR ------
        arrayList_us();

        // ------ DESTRUCTOR ------
        ~arrayList_us();

        // ------- METODOS --------
        void push(Usuarios usuario);
        void append(Usuarios usuario);
        int size();
        void pop();
        void printAll();
        void removeIf(bool (*condition)(const Usuarios&));
        
        // Método para graficar la lista usando Graphviz
        void graficar() const; 

        // Métodos para acceder y modificar los nodos primero y último
        usuarios_Nodo* getPrimero();
        void setPrimero(usuarios_Nodo* nuevoPrimero);

        usuarios_Nodo* getUltimo();
        void setUltimo(usuarios_Nodo* nuevoUltimo);

        Usuarios* buscarPorCorreo(const std::string& correo);
        Usuarios* buscarPorID(int id);
        void eliminarUsuario(const std::string& correo);


        // Método para obtener los 5 usuarios con más publicaciones
        std::vector<Usuarios*> top5UsuariosConMasPublicaciones();

        // Método para obtener los 5 usuarios con menos amigos
        std::vector<Usuarios*> top5UsuariosConMenosAmigos();

        // Método para graficar los 5 usuarios con más publicaciones
        void graficarTop5ConMasPublicaciones();

        // Método para graficar los 5 usuarios con menos amigos
        void graficarTop5ConMenosAmigos();

        Usuarios* buscarUsuarioPorID(int id) const;
};

#endif // ARRAYLIST_US_H