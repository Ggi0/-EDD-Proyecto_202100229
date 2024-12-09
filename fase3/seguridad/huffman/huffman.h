#include "nodo_huff.h"

class Huffman{
    private:
        Nodo_huff *raiz;

        void insertarCaracter(Nodo_huff*);
        void graficar(Nodo_huff*, std::ofstream&);
        void eliminar(Nodo_huff*);
        // Función auxiliar para escapar caracteres especiales en DOT
    std::string escaparCaracterDOT(const std::string& str) const;

    public:
        Huffman();
        ~Huffman();

        std::string codigos[256];


        void crearArbol(std::string);
        void crearCodigosHuffman(Nodo_huff*, std::string);
        void graficar();
        void imprimirCodigos();

        std::string comprimir(std::string);
        std::string descomprimir(std::string);

        Nodo_huff* getRaiz();

        void reconstruirArbol();

        void setRaiz(Nodo_huff* r) { raiz = r; }

};