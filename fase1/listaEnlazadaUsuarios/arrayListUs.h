#include "NodoUs.h"

class arrayList_us{
    private:
        Nodo *primero;
        Nodo *ultimo;

    public:
        // ----- CONSTRUCTOR ------
        arrayList_us();

        // ------ DESTRUCTOR ------
        ~arrayList_us();

        // ------- METODOS --------
        void push(Usuarios usuario);
        void append(Usuarios usuario);
};