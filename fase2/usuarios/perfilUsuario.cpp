#include "perfilUsuario.h"


// Obtener la fecha actual en formato DD/MM/YYYY
std::string obtenerFechaActual() {
    std::time_t tiempo = std::time(nullptr);
    std::tm* tm_local = std::localtime(&tiempo);

    std::ostringstream fecha;
    fecha << std::setw(2) << std::setfill('0') << tm_local->tm_mday << "/"
          << std::setw(2) << std::setfill('0') << (tm_local->tm_mon + 1) << "/"
          << (tm_local->tm_year + 1900);  // Año es tm_year + 1900
    return fecha.str();
}

// Obtener la hora actual en formato HH:MM (24 horas)
std::string obtenerHoraActual() {
    std::time_t tiempo = std::time(nullptr);
    std::tm* tm_local = std::localtime(&tiempo);

    std::ostringstream hora;
    hora << std::setw(2) << std::setfill('0') << tm_local->tm_hour << ":"  // 24 horas
         << std::setw(2) << std::setfill('0') << tm_local->tm_min;
    return hora.str();
}

// Método para hacer una publicación
void hacerPublicacion(const std::string& correo, const std::string& contenido) {
    std::string fecha = obtenerFechaActual();
    std::string hora = obtenerHoraActual();
    lista_comentarios lista_com;

    

    verificarCorreo_publicacion(correo, contenido, fecha, hora, lista_com);
}