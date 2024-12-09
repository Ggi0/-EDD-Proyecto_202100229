#include "publicacion.h"
#include <iostream>

int Publicacion::contadorID_publi = 0; // Inicialización del contador de ID

// Constructor por defecto
Publicacion::Publicacion() : ID_publi(++contadorID_publi), correoP(""), contenido(""), fecha(""), hora("") {}

// Constructor con parámetros
Publicacion::Publicacion(std::string correoP, std::string contenido, std::string fecha, std::string hora)
    : correoP(correoP), contenido(contenido), fecha(fecha), hora(hora), ID_publi(++contadorID_publi) {}

// Constructor de copia
Publicacion::Publicacion(const Publicacion& other)
    : ID_publi(other.ID_publi),
      correoP(other.correoP),
      contenido(other.contenido),
      fecha(other.fecha),
      hora(other.hora),
      arbolComentarios(other.arbolComentarios) {} // Copia de arbolComentarios

// Operador de asignación
Publicacion& Publicacion::operator=(const Publicacion& other) {
    if (this != &other) { // Evitar autoasignación
        ID_publi = other.ID_publi;
        correoP = other.correoP;
        contenido = other.contenido;
        fecha = other.fecha;
        hora = other.hora;
        arbolComentarios = other.arbolComentarios;
    }
    return *this;
}

// Destructor
Publicacion::~Publicacion() {
    // No es necesario liberar recursos manualmente ya que no se usa memoria dinámica aquí
}

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

// Versión const (ya existente)
const ArbolB& Publicacion::getArbolBComentarios() const {
    return arbolComentarios;
}

// Nueva versión no-const
ArbolB& Publicacion::getArbolBComentarios() {
    return arbolComentarios;
}

// ------ SETTERS ----------
void Publicacion::setID_publi(const int ID_publi) { this->ID_publi = ID_publi; }
void Publicacion::setCorreoP(const std::string& correoP) {this->correoP = correoP;}
void Publicacion::setContenido(const std::string& contenido) {this->contenido = contenido;}
void Publicacion::setFecha(const std::string& fecha) {this->fecha = fecha;}
void Publicacion::setHora(const std::string& hora) {this->hora = hora;}
void Publicacion::setArbolBComentarios(const ArbolB& arbolComentarios){this->arbolComentarios = arbolComentarios;}

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

