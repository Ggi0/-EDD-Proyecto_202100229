#include "sugerenciaAmistad.h"

sugerenciaAmistad::sugerenciaAmistad() {
    this->siguiente = nullptr;
    this->amigosEnComun = 0;
}

sugerenciaAmistad::sugerenciaAmistad(int id, std::string nombre, int amigosComun) {
    this->idUsuario = id;
    this->nombre = nombre;
    this->amigosEnComun = amigosComun;
    this->siguiente = nullptr;
}

// Implementación de getters
int sugerenciaAmistad::getIdUsuario() const { return idUsuario; }
std::string sugerenciaAmistad::getNombre() const { return nombre; }
int sugerenciaAmistad::getAmigosEnComun() const { return amigosEnComun; }
sugerenciaAmistad* sugerenciaAmistad::getSiguiente() const { return siguiente; }

// Implementación de setters
void sugerenciaAmistad::setIdUsuario(int id) { this->idUsuario = id; }
void sugerenciaAmistad::setNombre(std::string nombre) { this->nombre = nombre; }
void sugerenciaAmistad::setAmigosEnComun(int amigos) { this->amigosEnComun = amigos; }
void sugerenciaAmistad::setSiguiente(sugerenciaAmistad* sig) { this->siguiente = sig; }