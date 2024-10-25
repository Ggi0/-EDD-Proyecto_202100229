#ifndef BST_PUBLI_H
#define BST_PUBLI_H
#include "nodoBST_publi.h"
#include <sstream>
#include <iostream>

class BST{
    private:
        NodoBST *raiz;

        //NodoBST* insert(NodoBST *raiz, const std::string& fechaID);
        // Método privado para insertar recursivamente
        //NodoBST* insert(NodoBST *raiz, const std::string& fechaID);
        void postOrden(NodoBST *raiz, bool accion);
        void preOrden(NodoBST *raiz);
        void inOrden(NodoBST *raiz);
        void graph(NodoBST *raiz, std::ofstream &f);

        // Método auxiliar para insertar recursivamente
        NodoBST* insertAndGetNodeHelper(NodoBST* nodo, const std::string& fechaID);
    
        void graphHelper(NodoBST *raiz, std::ofstream &f) const; // Método auxiliar para la visualización

        void destruirArbol(NodoBST* nodo);  // Método auxiliar para el destructor


        

    public:
        BST();
        ~BST();

        // Nuevo método para obtener la raíz
        NodoBST* getRaiz() const;
        
        //void insert(std::string fechaID);
         // Método público para insertar
        //void insert(const std::string& fechaID);
        // Método público para insertar y obtener el nodo
        NodoBST* insertAndGetNode(const std::string& fechaID);


        // Método auxiliar para comparar fechas
        int compareFechas(const std::string& fecha1, const std::string& fecha2);

        void preOrden();
        void inOrden();
        void postOrden();
        void graph() const;
        bool estaVacio() const; // Nuevo método para verificar si el árbol está vacío

        // Método para buscar un nodo por fecha
        NodoBST* buscarNodoPorFecha(const std::string& fecha);

};
#endif // BST_PUBLI_H