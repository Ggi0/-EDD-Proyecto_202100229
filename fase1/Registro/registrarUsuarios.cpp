#include "registrarUsuarios.h"

// ----- CONSTRUCTOR ------

GestorUsuarios::GestorUsuarios(){}

GestorUsuarios::GestorUsuarios(arrayList_us listaUsuarios){
    this -> listaUsuarios = listaUsuarios;
}

GestorUsuarios::~GestorUsuarios(){}

arrayList_us& GestorUsuarios::getListaUsuarios(){
    return listaUsuarios;
}
void GestorUsuarios::setListaUsuarios(arrayList_us listaUsuarios){
    this->listaUsuarios = listaUsuarios;

}

// ----- MÉTODOS -----

// Agregar Usuario
std::string GestorUsuarios::agregarUsuario(Usuarios nuevoUsuario) {
    std::string correo_nuevo = nuevoUsuario.getCorreo();

    // Si la lista está vacía, agregar el nuevo usuario directamente
    if (listaUsuarios.size() == 0) {
        listaUsuarios.append(nuevoUsuario);
        return "Usuario agregado exitosamente";
    }

    // Recorrer la lista para verificar si el correo ya existe
    usuarios_Nodo *actual = listaUsuarios.getPrimero();
    while (actual != nullptr) {
        if (actual->getDato().getCorreo() == correo_nuevo) {
            return "Este usuario YA existe, cambiar de correo";
        }
        actual = actual->getSig();
    }

    // Si no se encontró un correo duplicado, agregar el nuevo usuario
    listaUsuarios.append(nuevoUsuario);
    return "Usuario agregado exitosamente";
}