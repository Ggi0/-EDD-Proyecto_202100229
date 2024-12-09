#ifndef NODO_ARBOLB_H
#define NODO_ARBOLB_H

#include <vector>
#include "../comentario.h"

class Nodo_b {
private:
    std::vector<Comentario> claves;  // Vector de claves (comentarios)
    std::vector<Nodo_b*> hijos;      // Vector de punteros a hijos
    bool esHoja;                     // Indica si el nodo es una hoja

public:
    Nodo_b(bool esHoja = true);
    ~Nodo_b();

    // Getters
    std::vector<Comentario>& getClaves();
    std::vector<Nodo_b*>& getHijos();
    bool getEsHoja() const;

    // Setters
    void setClaves(const std::vector<Comentario>& claves);
    void setHijos(const std::vector<Nodo_b*>& hijos);
    void setEsHoja(bool esHoja);
};

#endif // NODO_ARBOLB_H