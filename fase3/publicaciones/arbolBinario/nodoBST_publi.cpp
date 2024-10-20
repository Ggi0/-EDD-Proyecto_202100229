#include "nodoBST_publi.h"

// Constructor
NodoBST::NodoBST(const std::string& fechaID) 
    : fechaID(fechaID), izq(nullptr), drcha(nullptr) {}

// Constructor de copia
NodoBST::NodoBST(const NodoBST& other)
    : fechaID(other.fechaID)
    , listaPublicaciones(other.listaPublicaciones)
    , izq(nullptr)
    , drcha(nullptr) 
{
    // Copia profunda de los subárboles
    if (other.izq) {
        izq = new NodoBST(*other.izq);
    }
    if (other.drcha) {
        drcha = new NodoBST(*other.drcha);
    }
}

// Operador de asignación
NodoBST& NodoBST::operator=(const NodoBST& other) {
    if (this != &other) {
        // Crear copias temporales
        NodoBST* nuevoIzq = other.izq ? new NodoBST(*other.izq) : nullptr;
        NodoBST* nuevoDrcha = other.drcha ? new NodoBST(*other.drcha) : nullptr;
        
        // Liberar memoria antigua
        delete izq;
        delete drcha;
        
        // Asignar nuevos valores
        fechaID = other.fechaID;
        listaPublicaciones = other.listaPublicaciones;
        izq = nuevoIzq;
        drcha = nuevoDrcha;
    }
    return *this;
}

// Destructor
NodoBST::~NodoBST() {
    if (izq) {
        delete izq;
        izq = nullptr;
    }
    if (drcha) {
        delete drcha;
        drcha = nullptr;
    }
}

// Getters
std::string NodoBST::getFechaID() const {
    return fechaID;
}

NodoBST* NodoBST::getDrcha() const {
    return drcha;
}

NodoBST* NodoBST::getIzq() const {
    return izq;
}

ListaDoblementeEnlazadaP& NodoBST::getListaPublicaciones() {
    return listaPublicaciones;
}

const ListaDoblementeEnlazadaP& NodoBST::getListaPublicaciones() const {
    return listaPublicaciones;
}


// -------- SETTERS ------------
void NodoBST::setFechaID(const std::string& fechaID) {
    this->fechaID = fechaID;
}

void NodoBST::setDrcha(NodoBST* drcha) {
    this->drcha = drcha;
}

void NodoBST::setIzq(NodoBST* izq) {
    this->izq = izq;
}

void NodoBST::setListaPublicaciones(const ListaDoblementeEnlazadaP& listaPublicaciones) {
    this->listaPublicaciones = listaPublicaciones;
}