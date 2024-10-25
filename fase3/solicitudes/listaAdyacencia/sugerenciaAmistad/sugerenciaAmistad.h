#ifndef SUGERENCIAAMISTAD_H
#define SUGERENCIAAMISTAD_H

#include <string>

class sugerenciaAmistad {
private:
    int idUsuario;         // ID del usuario sugerido
    std::string nombre;    // Nombre del usuario sugerido
    int amigosEnComun;     // Cantidad de amigos en común
    sugerenciaAmistad* siguiente;

public:
    sugerenciaAmistad();
    sugerenciaAmistad(int id, std::string nombre, int amigosComun);
    
    // Getters
    int getIdUsuario() const;
    std::string getNombre() const;
    int getAmigosEnComun() const;
    sugerenciaAmistad* getSiguiente() const;
    
    // Setters
    void setIdUsuario(int id);
    void setNombre(std::string nombre);
    void setAmigosEnComun(int amigos);
    void setSiguiente(sugerenciaAmistad* sig);
};

#endif