#ifndef MERKLE_TREE_H
#define MERKLE_TREE_H
#include "nodos_merkle.h"
#include <iomanip> 

class merkle{
    private:
        nodoHash *topHash;
        nodoData *primeroData;
        nodoData *ultimoData;
        std::string dot;
        int pos;

        void postOrder(nodoHash*);
        void crearArbol(nodoHash*, int);
        void generarHash(nodoHash*, int);
        void generarDotRec(nodoHash*, std::ofstream&);

        int largoListaData();
        nodoData* obtenerData(int);

    public:
        merkle();
        ~merkle();

        void agregar(std::string);
        void generar();
        void generarDot();
        std::string getTopHash() const;
};

#endif // MERKLE_TREE_H
