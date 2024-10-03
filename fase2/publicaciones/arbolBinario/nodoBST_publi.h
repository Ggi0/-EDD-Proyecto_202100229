#ifndef NODO_BST_PUBLI_H
#define NODO_BST_PUBLI_H
#include <iostream>
#include <fstream>
#include <sstream>
#include "../listaDobleEnlazada/listaD_enlazadaP.h"

class NodoBST{
    private:
        std::string fechaID; // Clave del nodo (en formato "DD/MM/YYYY")
        
        ListaDoblementeEnlazadaP listaPublicaciones;// Lista de publicaciones en esta fecha
        
        NodoBST *drcha;
        NodoBST *izq;


    public:
        NodoBST(std::string fechaID);
        // --------- GETTERS ------------
        std::string getFechaID();
        NodoBST* getDrcha();
        NodoBST* getIzq();
        ListaDoblementeEnlazadaP& getListaPublicaciones();

        // ----------- SETTERES --------------
        void setFechaID(std::string fechaID);
        void setDrcha(NodoBST *drcha);
        void setIzq(NodoBST *Izq);
        void setListaPublicaciones(const ListaDoblementeEnlazadaP& getListaPublicaciones);

};
#endif // NODO_BST_PUBLI_H