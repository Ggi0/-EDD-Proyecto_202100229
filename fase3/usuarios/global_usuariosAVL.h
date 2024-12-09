
#ifndef GLOBAL_USUARIOS_AVL_H
#define GLOBAL_USUARIOS_AVL_H

#include "arbolAVL/avl_usuario.h" 
#include "../solicitudes/listaEnlazadaSolicitudes/arrayListSoli.h"
#include <string>


// Arbol AVL global en donde almacenar todos los usuarios.
extern AVL arbolGlobal_usuarios;

// Declaración de la variable global (sin definirla)
extern std::string loginUser_global;

// Declaración de la lista de solicitudes globlaes (som definir)
extern arrayList_soli listaGlobal_solicitudes;
#endif 