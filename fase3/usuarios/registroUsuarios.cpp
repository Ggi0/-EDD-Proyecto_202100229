#include "registroUsuarios.h"

// llamando al arbol global para almacenar los usuarios
AVL arbolGlobal_usuarios; 
std::string loginUser_global;



/*
    verificar si el arbol esta vacio, si lo esta crear y agregar el nuevo usuario al arbolGlobal_usuarios.
    si no esta vacia, tomar el parametro correo que entra a la funcion y verificar si a algun objeto Usuarios dentro del arbolGlobal_usuarios ya le perteneces el correo. si el correo le pertenece a un usuario retornar 0
    si no se encontró un correo duplicado, crear y agregar el nuevo usuario al arbolGlobal_usuarios
*/
int verificarCorreo(std::string nombres, std::string apellidos, std::string fechaN, std::string correo, std::string contrasenia) {
    // Crear un usuario temporal para la búsqueda
    Usuarios usuarioTemp(nombres, apellidos, fechaN, correo, contrasenia);
    
    // Verificar si el árbol está vacío
    if (arbolGlobal_usuarios.getRaiz() == nullptr) {
        // Insertar el nuevo usuario si el árbol está vacío
        arbolGlobal_usuarios.insert(usuarioTemp);
        std::cout << "Usuario agregado exitosamente" << std::endl;
        return 1;  // Usuario agregado exitosamente
    }
    
    // Buscar si el correo ya existe en el árbol
    NodoAVL* resultado = arbolGlobal_usuarios.buscarPorCorreo(correo);
    
    if (resultado != nullptr) {
        std::cout << "Correo electrónico ya existente en el sistema" << std::endl;
        return 0;  // El correo ya pertenece a un usuario en el árbol
    }
    
    // Si no se encontró un correo duplicado, insertar el nuevo usuario
    arbolGlobal_usuarios.insert(usuarioTemp);
    std::cout << "Usuario agregado exitosamente" << std::endl;
    return 1;  // Usuario agregado exitosamente
}


/*
    retorna 0 -> para arbol vacio o "correo o contrasenia incorrectos"
    retorna 1 -> para el accesos de usuarios normales
    retorna 2 -> para el acceso del administrador
*/
int iniciarSesion(std::string correo, std::string contrasenia) {
    // Iniciando sesión como ADMIN
    if (correo == "admin" && contrasenia == "123") {
        std::cout << "ADMINISTRACIÓN" << std::endl;
        return 2;  // Código para acceso de administrador
    }

    // Verificar si el árbol está vacío
    if (arbolGlobal_usuarios.getRaiz() == nullptr) {
        std::cout << "El árbol de usuarios está vacío. No hay usuarios registrados." << std::endl;
        return 0;  // Código para árbol vacío o error de inicio de sesión
    }

    // Buscar el usuario por correo en el árbol AVL
    NodoAVL* usuarioEncontrado = arbolGlobal_usuarios.buscarPorCorreo(correo);

    // Verificar las credenciales del usuario
    if (usuarioEncontrado != nullptr && usuarioEncontrado->getData().getContrasenia() == contrasenia) {
        std::cout << "Inicio de sesión exitoso para el usuario: " << correo << std::endl;
        loginUser_global = correo;

        return 1;  // Código para acceso de usuario normal
    }

    // Si no se encontró un usuario con las credenciales proporcionadas
    std::cout << "Error: Correo o contraseña incorrectos." << std::endl;
    return 0;  // Código para error de inicio de sesión
}


void verListaGlobal(){
    //listaGlobal_usuarios.printAll();
}
