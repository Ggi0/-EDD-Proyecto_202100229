#ifndef ARBOLB_H
#define ARBOLB_H

#include "nodo_arbolB.h"
#include <string>
#include <fstream>

class ArbolB {
private:
    Nodo_b* raiz;
    int t;  // Grado mínimo del árbol B (t = 3 para un árbol de orden 5)

    Nodo_b* copiarNodo(Nodo_b* nodo) const;
    void dividirHijo(Nodo_b* padre, int indice, Nodo_b* hijo);
    void insertarNoLleno(Nodo_b* nodo, const Comentario& clave);
    Comentario* buscarRecursivo(Nodo_b* nodo, const Comentario& clave);
    void borrarDe(Nodo_b* nodo, const Comentario& clave);
    int encontrarClave(Nodo_b* nodo, const Comentario& clave);
    void borrarDeHoja(Nodo_b* nodo, int indice);
    void borrarDeNoHoja(Nodo_b* nodo, int indice);
    Comentario obtenerPredecesor(Nodo_b* nodo, int indice);
    Comentario obtenerSucesor(Nodo_b* nodo, int indice);
    void llenar(Nodo_b* nodo, int indice);
    void prestarDelAnterior(Nodo_b* nodo, int indice);
    void prestarDelSiguiente(Nodo_b* nodo, int indice);
    void fusionar(Nodo_b* nodo, int indice);
    void recorridoInordenAux(Nodo_b* nodo) const;
    void borrarRecursivo(Nodo_b* nodo);

    
    // Métodos auxiliares para graficar
    void grafoAux(Nodo_b* nodo, std::ofstream& outfile);
    //void conexionesAux(Nodo_b* nodo, std::ofstream& outfile);

    // Método auxiliar para comparar dos comentarios
    int compararComentarios(const Comentario& c1, const Comentario& c2) const;
    std::string escaparCaracteres(const std::string& str);

    void imprimirEstadoRecursivo(Nodo_b* nodo, int nivel) const;
    int contarNodosRecursivo(Nodo_b* nodo) const;

public:
    ArbolB(); // Constructor
    ArbolB(const ArbolB& other); // Constructor de copia
    ArbolB& operator=(const ArbolB& other); // Operador de asignación
    ~ArbolB(); // Destructor

    void insertar(const Comentario& clave);
    void borrar(const Comentario& clave);
    Comentario* buscar(const Comentario& clave);
    void recorridoInorden() const;
    void graficar();

    static int compareFechas(const std::string& fecha1, const std::string& fecha2);
    static int compareHoras(const std::string& hora1, const std::string& hora2);

    bool estaVacio() const;
    void imprimirEstado() const;
    int contarNodos() const;

    std::string obtenerComentariosJson() const;
    void obtenerComentariosJsonRecursivo(Nodo_b* nodo, std::ostringstream& jsonStream, bool& primerComentario) const;

};

#endif // ARBOLB_H