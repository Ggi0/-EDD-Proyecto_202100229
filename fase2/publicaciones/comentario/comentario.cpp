#include "comentario.h"
#include <iostream>

// ------ CONSTRUCTOR ------
Comentario::Comentario(){
    correoC = "";
    comment = "";
    fecha = "";
    hora = "";
}

Comentario::Comentario(std::string correoC, std::string comment, std::string fecha, std::string hora){
    this -> correoC = correoC;
    this -> comment = comment;
    this -> fecha = fecha;
    this -> hora = hora;            
}

// ------ DESTRUCTOR -------
Comentario::~Comentario() {}

// ------ GETTERS ----------
std::string Comentario::getCorreoC() const {
    return correoC;
}

std::string Comentario::getComment() const {
    return comment;
}

std::string Comentario::getFecha() const {
    return fecha;
}

std::string Comentario::getHora() const {
    return hora;
}

// ------ SETTERS ----------
void Comentario::setCorreoC(const std::string& correoC) {this->correoC = correoC;}
void Comentario::setComment(const std::string& comment) {this->comment = comment;}
void Comentario::setFecha(const std::string& fecha) {this->fecha = fecha;}
void Comentario::setHora(const std::string& hora) {this->hora = hora;}

// ------ METODOS ----------
void Comentario::printComentario() const {
    std::cout << "======= ~ Commentario ~ =======" << std::endl;
    std::cout << "Correo: " << correoC << std::endl;
    std::cout << "Contenido: " << comment << std::endl;
    std::cout << "Fecha: " << fecha << std::endl;
    std::cout << "Hora: " << hora << std::endl;
    std::cout << "======= ~ =========== ~ =======" << std::endl;
}