#include "Usuarios.h"  // Incluir el archivo de cabecera de la clase Usuarios
#include <iostream>    // Incluir iostream para usar std::cout y std::endl

// Inicializar el contador de ID
int Usuarios::contadorID = 0;

// ---- CONSTRUCTOR -----
Usuarios::Usuarios(){
    ID = 0;
    nombres = "";
    apellidos = "";
    fechaN = "";
    correo = "";
    contrasenia = "";
}

Usuarios::Usuarios(std::string nombres, std::string apellidos, std::string fechaN, std::string correo, std::string contrasenia){
    this -> ID = ++contadorID;
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
int Usuarios::getID(){ return ID;}
std::string Usuarios::getNombres(){ return nombres;}
std::string Usuarios::getApellidos(){ return apellidos; }
std::string Usuarios::getFechaN(){ return fechaN; }
std::string Usuarios::getCorreo(){ return correo; }
std::string Usuarios::getContrasenia(){ return contrasenia; }

// Setters
void Usuarios::setID(int ID) { this->ID = ID; }
void Usuarios::setNombres(std::string& nombre) { this->nombres = nombres; }
void Usuarios::setApellidos(std::string& apellidos) { this->apellidos = apellidos; }
void Usuarios::setFechaN(std::string& fecha) { this->fechaN = fechaN; }
void Usuarios::setCorreo(std::string& correo) { this->correo = correo; }
void Usuarios::setContrasenia(std::string& contrasena) { this->contrasenia = contrasenia; }


// ----- METODO printUsuario -----
void Usuarios::printUsuario(){
    std::cout << "desde el metodo del objeto" << std::endl;
    std::cout << "===== Informacion del Usuario =====" << std::endl;
    std::cout << "ID: " << getID() << std::endl;
    std::cout << "Nombre: " << getNombres() << std::endl;
    std::cout << "Apellidos: " << getApellidos() << std::endl;
    std::cout << "Fecha de Nacimiento: " << getFechaN() << std::endl;
    std::cout << "Correo Electronico: " << getCorreo() << std::endl;
    std::cout << "Contrasena: " << getContrasenia() << std::endl; 
}
