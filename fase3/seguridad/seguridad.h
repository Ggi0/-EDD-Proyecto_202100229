#ifndef SEGURIDAD_H
#define SEGURIDAD_H

#include "huffman/huffman.h"
#include "../usuarios/global_usuariosAVL.h"
#include "../administracion/leerJson.h"

#include <string>
#include <fstream>
#include <sstream>

// para comprimir la informacion del arbol AVL de usuarios
    // Función principal para comprimir usuarios
    void comprimirUsuarios();

    // Funciones auxiliares para la generación del JSON
    std::string generarJSONUsuarios(AVL& arbol);
    void recorrerArbolJSON(NodoAVL* nodo, std::stringstream& ss, bool& esElPrimero);
    std::string usuarioToJSON(Usuarios& usuario);

// para comprimir la infomación de la lista de solicitudes general.
    // funcion para comprimir solicitudes.
    void comprimirSolicitudes();
    std::string generarJSONSolicitudes(arrayList_soli& listaSolicitudes);

// metodos para descomprimir el texto en el programa.
    void descomprimirUsuarios();
    void leerBackup_Usuarios();

    void descomprimirSolicitudes();
    void leerBackup_solicitudes();



#endif // SEGURIDAD_H