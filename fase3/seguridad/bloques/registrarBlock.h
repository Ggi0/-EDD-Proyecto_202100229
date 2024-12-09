#ifndef REGISTRO_BLOCK_H
#define REGISTRO_BLOCK_H

// Arbol AVL globla de USUARIOS
#include "global_blockchain.h"
#include "../../publicaciones/global_data_publicaciones.h"
#include "../registrarArbolMerkle.h"
#include "../sha256.h"
#include <string>
#include <iostream>
#include <fstream>
#include <string>
#include <iomanip>  // Para el formato JSON

#include <filesystem>
#include <vector>
#include <algorithm>
#include "../../administracion/leerJson.h"




// ----- METODOS -----

// Guardar bloque en la lista de bloques global
void saveBlock();

std::string obtenerTimestamp();
std::pair<std::string, std::string> determinarNonce(const std::string& s);
std::string generarJsonPublicaciones();
std::string formatearJson(const std::string& json);

// Para iniciar sesion 
//std::string valorNonce(std::string hash);

// 
void escribirJsonBLOCKCHAIN();

void leerbpBlockchain();
std::string verficarRootMerkle(std::string&  data);

#endif // REGISTRO_USUARIOS_H