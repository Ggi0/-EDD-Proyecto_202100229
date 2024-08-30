#include "leerJson.h"
#include "../Registro/registroUsuarioOficial.h"
#include "../publicaciones/registroPublicaciones.h"
#include "../Solicitudes/registroSolicitudes.h"

void leerUsuarios(const std::string& pathDelArchivo) {
    // Crear un objeto JSON
    nlohmann::json jsonData;

    // Abrir el archivo JSON
    std::ifstream archivo(pathDelArchivo);

    // Verificar si el archivo se abrió correctamente
    if (archivo.is_open()) {
        // Leer el archivo JSON en el objeto jsonData
        archivo >> jsonData;
        archivo.close();

        // Recorrer cada objeto en el array JSON
        for (const auto& usuario : jsonData) {
            // Capturar los valores en variables
            std::string nombres = usuario["nombres"];
            std::string apellidos = usuario["apellidos"];
            std::string fecha_de_nacimiento = usuario["fecha_de_nacimiento"];
            std::string correo = usuario["correo"];
            std::string contrasena = usuario["contraseña"];

            // Pasar los valores a la función procesarUsuario
            verificarCorreo(nombres, apellidos, fecha_de_nacimiento, correo, contrasena);
        }

    } else {
        std::cerr << "No se pudo abrir el archivo JSON en la ruta especificada." << std::endl;
    }
}

/*
    {
      "emisor": "carlos.gomez@example.com",
      "receptor": "maria.lopez@example.com",
      "estado": "ACEPTADA"
    }
*/
void leerSolicitudes(const std::string& pathDelArchivo) {
    // Crear un objeto JSON
    nlohmann::json jsonData;

    // Abrir el archivo JSON
    std::ifstream archivo(pathDelArchivo);

    // Verificar si el archivo se abrió correctamente
    if (archivo.is_open()) {
        // Leer el archivo JSON en el objeto jsonData
        archivo >> jsonData;
        archivo.close();

        // Recorrer cada objeto en el array JSON
        for (const auto& solicitud : jsonData) {
            // Capturar los valores en variables
            std::string emisor = solicitud["emisor"];
            std::string receptor = solicitud["receptor"];
            std::string estado = solicitud["estado"];

            // Pasar los valores a la función que procesa las solicitudes
            registroSolicitudes(emisor, receptor, estado);
        }

    } else {
        std::cerr << "No se pudo abrir el archivo JSON en la ruta especificada." << std::endl;
    }
}

void leerPublicaciones(const std::string& pathDelArchivo) {
    // Crear un objeto JSON
    nlohmann::json jsonData;

    // Abrir el archivo JSON
    std::ifstream archivo(pathDelArchivo);

    // Verificar si el archivo se abrió correctamente
    if (archivo.is_open()) {
        // Leer el archivo JSON en el objeto jsonData
        archivo >> jsonData;
        archivo.close();

        // Recorrer cada objeto en el array JSON
        for (const auto& publicacion : jsonData) {
            // Capturar los valores en variables
            std::string correo = publicacion["correo"];
            std::string contenido = publicacion["contenido"];
            std::string fecha = publicacion["fecha"];
            std::string hora = publicacion["hora"];

            // Pasar los valores a la función que procesa las publicaciones
            verificarCorreo_publicacion(correo, contenido, fecha, hora);
        }

    } else {
        std::cerr << "No se pudo abrir el archivo JSON en la ruta especificada." << std::endl;
    }
}