#ifndef ARRAYLISTSOLI_H
#define ARRAYLISTSOLI_H

#include "solicitud_Nodo.h"
#include <functional>
#include <fstream>

class arrayList_soli {
    private:
        solicitud_Nodo *primero;
        solicitud_Nodo *ultimo;

        // Método auxiliar para copiar lista
        void copiarLista(const arrayList_soli& otra);

    public:
        // Constructor
        arrayList_soli();

        // Destructor
        // Constructor de copia
        arrayList_soli(const arrayList_soli& otra);
        // Operador de asignación
        arrayList_soli& operator=(const arrayList_soli& otra);
        // Destructor
        ~arrayList_soli();

        // Métodos

        // Getters y setters
        solicitud_Nodo* getPrimero();
        void setPrimero(solicitud_Nodo* nuevoPrimero);

        void push(Solicitud solicitud);
        void append(Solicitud solicitud);
        int size();
        void pop();
        void printAll();

        void removeIf(std::function<bool(const Solicitud&)> predicado);

        void grafica() const;

        void eliminarSolicitud(const std::string& emisor, const std::string& receptor);

};

#endif // ARRAYLIST_SOLI_H