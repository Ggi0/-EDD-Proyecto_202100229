#include "nodo_arbolB.h"

Nodo_b::Nodo_b(bool esHoja) : claves(), hijos(), esHoja(esHoja) {}

// Destructor que libera todos los hijos del nodo actual
Nodo_b::~Nodo_b() {
    for (Nodo_b* hijo : hijos) {
        delete hijo; // Elimina cada hijo recursivamente
    }
    hijos.clear();
}


// Getters
std::vector<Comentario>& Nodo_b::getClaves() { return claves; }
std::vector<Nodo_b*>& Nodo_b::getHijos() { return hijos; }
bool Nodo_b::getEsHoja() const { return esHoja; }

// Setters
void Nodo_b::setClaves(const std::vector<Comentario>& claves) { this->claves = claves; }
void Nodo_b::setHijos(const std::vector<Nodo_b*>& hijos) { this->hijos = hijos; }
void Nodo_b::setEsHoja(bool esHoja) { this->esHoja = esHoja; }