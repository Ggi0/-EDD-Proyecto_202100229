#include "nodo_huff.h"

Nodo_huff::Nodo_huff(char c){
    this->c = c;
    n = 1;
    sig = nullptr;
    izq = nullptr;
    der = nullptr;
}