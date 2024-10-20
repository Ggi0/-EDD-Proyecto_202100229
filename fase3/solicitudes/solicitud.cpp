#include "solicitud.h"  // Incluir el archivo de cabecera de la clase Usuarios
#include <iostream>    // Incluir iostream para usar std::cout y std::endl


// ---- CONSTRUCTOR -----
Solicitud::Solicitud(){
    std::string emisor = ""; //std::string emisors = "";
    std::string receptor="";
    std::string estado="";
}

Solicitud::Solicitud(std::string emisor, std::string receptor, std::string estado){
    this -> emisor = emisor;
    this -> receptor = receptor;
    this -> estado = estado;
}

// ----- DESTRUCTOR ------
Solicitud::~Solicitud() {
}

// ----- GETTERS -------
std::string Solicitud::getEmisor() const {
    return emisor;
}

std::string Solicitud::getReceptor() const {
    return receptor;
}

std::string Solicitud::getEstado() const {
    return estado;
}

// ----- SETTERS -------
void Solicitud::setEmisor(std::string& _emisor) {
    emisor = _emisor;
}

void Solicitud::setReceptor(std::string& _receptor) {
    receptor = _receptor;
}

void Solicitud::setEstado(std::string& _estado) {
    estado = _estado;
}