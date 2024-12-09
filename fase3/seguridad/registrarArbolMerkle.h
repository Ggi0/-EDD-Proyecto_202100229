#ifndef REGISTRAR_ARBOL_MERKLE_H
#define REGISTRAR_ARBOL_MERKLE_H

#include "../publicaciones/listaDobleEnlazada/listaD_enlazadaP.h"
#include "../publicaciones/global_data_publicaciones.h"
#include "merkle/merkleTree.h"
#include <iostream>
#include <string>
#include <sstream>

std::string registroArbolMerkle();
std::string escaparJson(const std::string& json);

#endif //REGISTRAR_ARBOL_MERKLE_H
