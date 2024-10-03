#include "leerJson.h"

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

        std::cerr << "Archivo JSON leido correctamente." << std::endl;


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

/*
void leerPublicaciones(const std::string& pathDelArchivo) {
    try {
        nlohmann::json jsonData;
        std::ifstream archivo(pathDelArchivo);
        
        if (!archivo.is_open()) {
            std::cerr << "No se pudo abrir el archivo JSON." << std::endl;
            return;
        }
        
        archivo >> jsonData;
        archivo.close();
        
        for (const auto& publicacion : jsonData) {
            lista_comentarios lista_com;
            
            // Procesar comentarios de manera más segura
            if (publicacion.contains("comentarios") && !publicacion["comentarios"].empty()) {
                for (const auto& comentario : publicacion["comentarios"]) {
                    try {
                        std::string correo = comentario["correo"].get<std::string>();
                        std::string contenido = comentario["comentario"].get<std::string>();
                        std::string fecha = comentario["fecha"].get<std::string>();
                        std::string hora = comentario["hora"].get<std::string>();
                        
                        lista_com.append(Comentario(correo, contenido, fecha, hora));
                    } catch (const std::exception& e) {
                        std::cerr << "Error al procesar comentario: " << e.what() << std::endl;
                        continue;
                    }
                }
            }
            
            try {
                lista_com.graficar();
                std::string correo = publicacion["correo"].get<std::string>();
                std::string contenido = publicacion["contenido"].get<std::string>();
                std::string fecha = publicacion["fecha"].get<std::string>();
                std::string hora = publicacion["hora"].get<std::string>();
                
                verificarCorreo_publicacion(correo, contenido, fecha, hora, lista_com);
            } catch (const std::exception& e) {
                std::cerr << "Error al procesar publicación: " << e.what() << std::endl;
                continue;
            }
        }
        
    } catch (const std::exception& e) {
        std::cerr << "Error al procesar el archivo JSON: " << e.what() << std::endl;
    }
}
*/



void leerPublicaciones(const std::string& pathDelArchivo) {
    try {
        nlohmann::json jsonData;
        std::ifstream archivo(pathDelArchivo);

        if (!archivo.is_open()) {
            std::cerr << "No se pudo abrir el archivo JSON." << std::endl;
            return;
        }

        archivo >> jsonData;
        archivo.close();

        for (const auto& publicacion : jsonData) {
            // Creamos una lista de comentarios vacía
            lista_comentarios lista_com;

            try {
                std::string correo = publicacion["correo"].get<std::string>();
                std::string contenido = publicacion["contenido"].get<std::string>();
                std::string fecha = publicacion["fecha"].get<std::string>();
                std::string hora = publicacion["hora"].get<std::string>();

                // Pasamos la lista vacía a la función
                verificarCorreo_publicacion(correo, contenido, fecha, hora, lista_com);
            } catch (const std::exception& e) {
                std::cerr << "Error al procesar publicación: " << e.what() << std::endl;
                continue;
            }
        }

    } catch (const std::exception& e) {
        std::cerr << "Error al procesar el archivo JSON: " << e.what() << std::endl;
    }
}
