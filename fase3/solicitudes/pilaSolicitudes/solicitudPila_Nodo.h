#ifndef SOLICITUDPILA_NODO_H
#define SOLICITUDPILA_NODO_H

#include "../solicitud.h"

class solicitudPila_Nodo {
    private:
        Solicitud dato;
        solicitudPila_Nodo* siguiente;

    public:

        explicit solicitudPila_Nodo(const Solicitud& solicitud);
        // Constructor de copia
        solicitudPila_Nodo(const solicitudPila_Nodo& otro);

        //solicitudPila_Nodo(const Solicitud& solicitud);
        // -------- GETTERS ----------
        Solicitud getDato() const;
        solicitudPila_Nodo* getSiguiente() const;

        // -------- SETTERS ------------
        void setSiguiente(solicitudPila_Nodo* nodo);
};

#endif // SOLICITUDPILA_NODO_H