#include "Usuarios.h"  // Incluir el archivo de cabecera de la clase Usuarios
#include <iostream>    // Incluir iostream para usar std::cout y std::endl

/*    Atributos:
        ID
        Nombres
        Apellidos
        Fecha de nacimiento
        Correo electrónico
        Contrasenia*/

// ---- CONSTRUCTOR -----
Usuarios::Usuarios(){
    nombres = "";
    apellidos = "";
    fechaN = "";
    correo = "";
    contrasenia = "";
}

Usuarios::Usuarios(std::string nombres, std::string apellidos, std::string fechaN, std::string correo, std::string contrasenia){
    this -> nombres = nombres;
    this -> apellidos = apellidos;
    this -> fechaN = fechaN; 
    this -> correo = correo; 
    this -> contrasenia = contrasenia;
}

// ----- DESTRUCTOR ------
Usuarios::~Usuarios() {
}

// Getters
std::string Usuarios::getNombres(){ return nombres;}
std::string Usuarios::getApellidos(){ return apellidos; }
std::string Usuarios::getFechaN(){ return fechaN; }
std::string Usuarios::getCorreo(){ return correo; }
std::string Usuarios::getContrasenia(){ return contrasenia; }

// Setters
void Usuarios::setNombres(std::string nombre) { this->nombres = nombres; }
void Usuarios::setApellidos(std::string apellidos) { this->apellidos = apellidos; }
void Usuarios::setFechaN(std::string fecha) { this->fechaN = fechaN; }
void Usuarios::setCorreo(std::string correo) { this->correo = correo; }
void Usuarios::setContrasenia(std::string contrasena) { this->contrasenia = contrasenia; }


// ----- METODO printUsuario -----
void Usuarios::printUsuario(){
    std::cout << "desde el metodo del objeto" << std::endl;
    std::cout << "===== Informacion del Usuario =====" << std::endl;
    std::cout << "Nombre: " << getNombres() << std::endl;
    std::cout << "Apellidos: " << getApellidos() << std::endl;
    std::cout << "Fecha de Nacimiento: " << getFechaN() << std::endl;
    std::cout << "Correo Electronico: " << getCorreo() << std::endl;
    std::cout << "Contrasena: " << getContrasenia() << std::endl; // Nota: Esto solo es un ejemplo; en un caso real, la contraseña no debería imprimirse así.
}
