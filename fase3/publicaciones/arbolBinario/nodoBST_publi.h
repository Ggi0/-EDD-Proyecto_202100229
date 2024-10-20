#ifndef NODO_BST_PUBLI_H
#define NODO_BST_PUBLI_H
#include <iostream>
#include <fstream>
#include <sstream>
#pragma once
#include "../listaDobleEnlazada/listaD_enlazadaP.h"

class NodoBST{
    private:
        std::string fechaID; // Clave del nodo (en formato "DD/MM/YYYY")
        
        ListaDoblementeEnlazadaP listaPublicaciones;// Lista de publicaciones en esta fecha
        
        NodoBST *drcha;
        NodoBST *izq;


    public:
        // Constructor y destructor
        explicit NodoBST(const std::string& fechaID);
        virtual ~NodoBST();
        
        // Constructor de copia
        NodoBST(const NodoBST& other);
        
        // Operador de asignación
        NodoBST& operator=(const NodoBST& other);

        // --------- GETTERS ------------
        std::string getFechaID() const;
        NodoBST* getDrcha() const;
        NodoBST* getIzq() const;
        ListaDoblementeEnlazadaP& getListaPublicaciones();
        const ListaDoblementeEnlazadaP& getListaPublicaciones() const;

        // ----------- SETTERES --------------
        void setFechaID(const std::string& fechaID);
        void setDrcha(NodoBST* drcha);
        void setIzq(NodoBST* izq);
        void setListaPublicaciones(const ListaDoblementeEnlazadaP& listaPublicaciones);

};
#endif // NODO_BST_PUBLI_H