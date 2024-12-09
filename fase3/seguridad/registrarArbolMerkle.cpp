
#include "registrarArbolMerkle.h"


// Función para escapar las comillas dobles en el JSON
std::string escaparJson(const std::string& json) {
    std::ostringstream escapedJson;
    for (char c : json) {
        if (c == '"') {
            escapedJson << "\\\"";  // Escapar las comillas dobles
        } else {
            escapedJson << c;
        }
    }
    return escapedJson.str();
}

std::string registroArbolMerkle() {
    std::cout << "---------------DENTRO DEL METODO PARA REGISTRAR EL ARBOL MERKLE -------------------" << std::endl;
    merkle arbol;
    // Iterar sobre la lista global de publicaciones
    PublicacionNodo* actual = listaGlobal_publicaciones.getPrimero();
    while (actual != nullptr) {
        std::ostringstream jsonStream;
        
        const Publicacion& pub = actual->getData();
        jsonStream << "[{"
                   << "\"correo\":\"" << pub.getCorreoP() << "\","
                   << "\"contenido\":\"" << pub.getContenido() << "\","
                   << "\"fecha\":\"" << pub.getFecha() << "\","
                   << "\"hora\":\"" << pub.getHora() << "\","
                   << "\"comentarios\":" << pub.getArbolBComentarios().obtenerComentariosJson()
                   << "}]";
        
        // Escapar el JSON para evitar errores en el archivo .dot
        std::string jsonMerkle = escaparJson(jsonStream.str());
        
        std::cout << "----------------------------------" << std::endl;
        std::cout << jsonMerkle << std::endl;
        std::cout << "----------------------------------" << std::endl;
        
        // Agregar JSON escapado al árbol Merkle
        
        arbol.agregar(jsonMerkle);
        
        actual = actual->getSig();
    }
    arbol.generar();
    arbol.generarDot();

    // Obtener el topHash como cadena
    std::string ultimoHash = arbol.getTopHash();
    std::cout << "Top Hash del árbol Merkle: " << ultimoHash << std::endl;
    return ultimoHash;
}