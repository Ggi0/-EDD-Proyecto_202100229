#ifndef LISTA_CIRCULAR_DEPP_H
#define LISTA_CIRCULAR_DEPP_H

#include "pPersonal_Nodo.h"
#include <fstream>

// Clase que representa una lista circular doblemente enlazada de publicaciones personales.
class ListaCircular_Dpp {
private:
    pPersonal_Nodo* primero;  // Apuntador al primer nodo de la lista circular.
    int tamanio;             // Variable que almacena el tamaño actual de la lista.
    

public:
    // ---------- CONSTRUCTOR ----------
    ListaCircular_Dpp();

    // ---------- DESTRUCTOR ------------
    ~ListaCircular_Dpp();

    // -------- METODOS ----------- 
    // Inserta una nueva publicación al inicio de la lista.
    void insertarInicio(const Publicacion& pub);

    // Inserta una nueva publicación al final de la lista.
    void insertarFinal(const Publicacion& pub);

    // Elimina el primer nodo de la lista.
    void eliminarInicio();

    // Elimina el último nodo de la lista.
    void eliminarFinal();

    // Elimina el nodo que contiene la publicación con el correo especificado.
    void eliminarPublicacion(const std::string& correo);

    // Busca un nodo en la lista que contenga una publicación con el correo especificado.
    pPersonal_Nodo* buscarPublicacion(const std::string& correo) const;

    // Muestra todas las publicaciones en la lista.
    void mostrarLista() const;

    // Verifica si la lista está vacía.
    bool estaVacia() const;

    // Obtiene el número de nodos en la lista.
    int obtenerTamanio() const;

    // Libera toda la memoria ocupada por los nodos en la lista.
    void limpiarLista();

    pPersonal_Nodo* getPrimero() const;

    // Dentro de la clase ListaCircular_Dpp
    void grafica() const;
};

#endif // LISTA_CIRCULAR_DEPP_H