
#include "registroUsuarioOficial.h"

arrayList_us listaGlobal_usuarios; 

//arrayList_us listaGlobal_usuarios;

int verificarCorreo(std::string nombres, std::string apellidos, std::string fechaN, std::string correo, std::string contrasenia) {
    // Verificar si la lista está vacía
    if (listaGlobal_usuarios.size() == 0) {
        // Crear y agregar el nuevo usuario si la lista está vacía
        Usuarios nuevoUsuario(nombres, apellidos, fechaN, correo, contrasenia);
        listaGlobal_usuarios.append(nuevoUsuario);
        std::cout<< "Usuario agregado exitosamente"<< std::endl;
        return 1;  // Usuario agregado exitosamente
    }

    // Comienza desde el primer nodo de la lista
    usuarios_Nodo* actual = listaGlobal_usuarios.getPrimero();

    // Recorrer la lista para verificar si el correo ya existe
    while (actual != nullptr) {
        if (actual->getDato().getCorreo() == correo) {
            std::cout<< "Correo electronico ya existente en el sistema"<< std::endl;
            return 0;  // El correo ya pertenece a un usuario en la lista
        }
        actual = actual->getSig();  // Avanzar al siguiente nodo
    }

    // Si no se encontró un correo duplicado, crear y agregar el nuevo usuario
    Usuarios nuevoUsuario(nombres, apellidos, fechaN, correo, contrasenia);
    listaGlobal_usuarios.append(nuevoUsuario);
    std::cout<< "Usuario agregado exitosamente"<< std::endl;
    return 1;  // Usuario agregado exitosamente
}



int iniciarSesion(std::string correo, std::string contrasenia) {
    // Iniciando sesión como ADMIN
    if (correo == "admin@gmail.com" && contrasenia == "EDD2S2024") {
        std::cout << "ADMINISTRACIÓN" << std::endl;
        return 2;  // Código para acceso de administrador
    }

    // Verificar si la lista está vacía
    if (listaGlobal_usuarios.size() == 0) {
        std::cout << "La lista de usuarios está vacía. No hay usuarios registrados." << std::endl;
        return 0;  // Código para lista vacía o error de inicio de sesión
    }

    // Comienza desde el primer nodo de la lista
    usuarios_Nodo* actual = listaGlobal_usuarios.getPrimero();

    // Recorrer la lista para verificar las credenciales de usuario
    while (actual != nullptr) {
        if (actual->getDato().getCorreo() == correo && actual->getDato().getContrasenia() == contrasenia) {
            std::cout << "Inicio de sesión exitoso para el usuario: " << correo << std::endl;
            return 1;  // Código para acceso de usuario normal
        }
        actual = actual->getSig();  // Avanzar al siguiente nodo
    }

    // Si no se encontró un usuario con las credenciales proporcionadas
    std::cout << "Error: Correo o contraseña incorrectos." << std::endl;
    return 0;  // Código para error de inicio de sesión
}

void verListaGlobal(){
    listaGlobal_usuarios.printAll();
}

