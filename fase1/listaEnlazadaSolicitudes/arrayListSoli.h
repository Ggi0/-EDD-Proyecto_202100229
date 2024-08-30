#ifndef ARRAYLISTSOLI_H
#define ARRAYLISTSOLI_H

#include "solicitud_Nodo.h"
#include <functional>
#include <fstream>

class arrayList_soli {
    private:
        solicitud_Nodo *primero;
        solicitud_Nodo *ultimo;

    public:
        // Constructor
        arrayList_soli();

        // Destructor
        ~arrayList_soli();

        // Métodos
        void push(Solicitud solicitud);
        void append(Solicitud solicitud);
        int size();
        void pop();
        void printAll();

        solicitud_Nodo* getPrimero();
        void setPrimero(solicitud_Nodo* nuevoPrimero);

        void removeIf(std::function<bool(const Solicitud&)> predicado);

        void grafica() const;
};

#endif // ARRAYLIST_SOLI_H