#include "publicacion.h"
#include <iostream>

// ------ CONSTRUCTOR ------
Publicacion::Publicacion(){
    correoP = "";
    contenido = "";
    fecha = "";
    hora = "";
}

Publicacion::Publicacion(std::string correoP, std::string contenido, std::string fecha, std::string hora){
    this -> correoP = correoP;
    this -> contenido = contenido;
    this -> fecha = fecha;
    this -> hora = hora;            
}

// ------ DESTRUCTOR -------
Publicacion::~Publicacion() {}

// ------ GETTERS ----------
std::string Publicacion::getCorreoP() const {
    return correoP;
}

std::string Publicacion::getContenido() const {
    return contenido;
}

std::string Publicacion::getFecha() const {
    return fecha;
}

std::string Publicacion::getHora() const {
    return hora;
}

// ------ SETTERS ----------
void Publicacion::setCorreoP(const std::string& correoP) {this->correoP = correoP;}
void Publicacion::setContenido(const std::string& contenido) {this->contenido = contenido;}
void Publicacion::setFecha(const std::string& fecha) {this->fecha = fecha;}
void Publicacion::setHora(const std::string& hora) {this->hora = hora;}

// ------ METODOS ----------
void Publicacion::printPublicacion() const {
    std::cout << "======= ~ PUBLICACION ~ =======" << std::endl;
    std::cout << "Correo: " << correoP << std::endl;
    std::cout << "Contenido: " << contenido << std::endl;
    std::cout << "Fecha: " << fecha << std::endl;
    std::cout << "Hora: " << hora << std::endl;
    std::cout << "======= ~ =========== ~ =======" << std::endl;
}