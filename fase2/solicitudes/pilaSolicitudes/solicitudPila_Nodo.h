#ifndef SOLICITUDPILA_NODO_H
#define SOLICITUDPILA_NODO_H

#include "../solicitud.h"

class solicitudPila_Nodo {
    private:
        Solicitud dato;
        solicitudPila_Nodo* siguiente;

    public:
        solicitudPila_Nodo(const Solicitud& solicitud);
        // -------- GETTERS ----------
        Solicitud getDato() const;
        solicitudPila_Nodo* getSiguiente() const;

        // -------- SETTERS ------------
        void setSiguiente(solicitudPila_Nodo* nodo);
};

#endif // SOLICITUDPILA_NODO_H