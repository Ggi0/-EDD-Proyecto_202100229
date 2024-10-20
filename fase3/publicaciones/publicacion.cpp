#include "publicacion.h"
#include <iostream>

// Inicializar el contador de ID
int Publicacion::contadorID_publi = 0;

// ------ CONSTRUCTOR ------
Publicacion::Publicacion(){
    ID_publi = 0;
    correoP = "";
    contenido = "";
    fecha = "";
    hora = "";
}

Publicacion::Publicacion(std::string correoP, std::string contenido, std::string fecha, std::string hora){
    this -> ID_publi = ++contadorID_publi;
    this -> correoP = correoP;
    this -> contenido = contenido;
    this -> fecha = fecha;
    this -> hora = hora;            
}

// ------ DESTRUCTOR -------
Publicacion::~Publicacion() {}

// ------ GETTERS ----------
int Publicacion::getID_publi() const { 
    return ID_publi;
}

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
/*
ArbolB Publicacion::getArbolB_comentarios() const{
    return arbolB_comentarios;
}*/

// ------ SETTERS ----------
void Publicacion::setID_publi(const int ID_publi) { this->ID_publi = ID_publi; }
void Publicacion::setCorreoP(const std::string& correoP) {this->correoP = correoP;}
void Publicacion::setContenido(const std::string& contenido) {this->contenido = contenido;}
void Publicacion::setFecha(const std::string& fecha) {this->fecha = fecha;}
void Publicacion::setHora(const std::string& hora) {this->hora = hora;}
//void Publicacion::setArbolB_comentarios(const ArbolB& arbolB_comentarios){this->arbolB_comentarios = arbolB_comentarios;}

// ------ METODOS ----------
void Publicacion::printPublicacion() const {
    std::cout << "======= ~ PUBLICACION ~ =======" << std::endl;
    std::cout << "ID: " << getID_publi() << std::endl;
    std::cout << "Correo: " << getCorreoP() << std::endl;
    std::cout << "Contenido: " << getContenido() << std::endl;
    std::cout << "Fecha: " << getFecha() << std::endl;
    std::cout << "Hora: " << getHora() << std::endl;
    std::cout << "Comentarios: " << std::endl;
    std::cout << "======= ~ =========== ~ =======" << std::endl;
}