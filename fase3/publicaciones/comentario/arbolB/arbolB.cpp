#include "arbolB.h"
#include <iostream>
#include <sstream>
#include <fstream>
#include <cstdlib>

// Constructor: t = 3 para un árbol de orden 5
ArbolB::ArbolB() : raiz(nullptr), t(3) {}  

Nodo_b* ArbolB::copiarNodo(Nodo_b* nodo) const {
    if (!nodo) return nullptr;

    Nodo_b* nuevoNodo = new Nodo_b(nodo->getEsHoja());
    nuevoNodo->setClaves(nodo->getClaves()); // Copia las claves

    // Copia recursivamente los hijos
    for (Nodo_b* hijo : nodo->getHijos()) {
        nuevoNodo->getHijos().push_back(copiarNodo(hijo));
    }

    return nuevoNodo;
}

ArbolB::ArbolB(const ArbolB& other) : raiz(nullptr), t(other.t) {
    if (other.raiz) {
        raiz = copiarNodo(other.raiz);
    }
}

ArbolB& ArbolB::operator=(const ArbolB& other) {
    if (this != &other) {
        // Limpia el árbol actual
        borrarRecursivo(raiz);
        raiz = nullptr;

        // Copia el árbol nuevo
        t = other.t;
        if (other.raiz) {
            raiz = copiarNodo(other.raiz);
        }
    }
    return *this;
}

// Destructor que limpia la memoria del árbol recursivamente
ArbolB::~ArbolB() {
    borrarRecursivo(raiz); // Elimina todos los nodos recursivamente
    raiz = nullptr;
}

// Método recursivo para liberar todos los nodos
void ArbolB::borrarRecursivo(Nodo_b* nodo) {
    if (nodo) {
        for (Nodo_b* hijo : nodo->getHijos()) {
            borrarRecursivo(hijo); // Llama recursivamente a cada hijo
        }
        delete nodo; // Elimina el nodo actual
    }
}

void ArbolB::insertar(const Comentario& clave) {
    if (raiz == nullptr) {
        raiz = new Nodo_b(true);
        raiz->getClaves().push_back(clave);
    } else {
        // Si la raíz está llena, crear nuevo nodo
        if (static_cast<int>(raiz->getClaves().size()) == 2 * t - 1) {
            Nodo_b* nuevoNodo = new Nodo_b(false);
            nuevoNodo->getHijos().push_back(raiz);
            dividirHijo(nuevoNodo, 0, raiz);
            
            int i = 0;
            if (compararComentarios(nuevoNodo->getClaves()[0], clave) < 0) {
                i++;
            }
            insertarNoLleno(nuevoNodo->getHijos()[i], clave);
            raiz = nuevoNodo;
        } else {
            insertarNoLleno(raiz, clave);
        }
    }
}

void ArbolB::dividirHijo(Nodo_b* padre, int indice, Nodo_b* hijo) {
    if (padre == nullptr || hijo == nullptr) return;
    
    Nodo_b* nuevoNodo = new Nodo_b(hijo->getEsHoja());
    
    // Copiar las claves al nuevo nodo
    for (int j = 0; j < t-1; j++) {
        if (j + t < static_cast<int>(hijo->getClaves().size())) {
            nuevoNodo->getClaves().push_back(hijo->getClaves()[j+t]);
        }
    }
    
    // Si no es hoja, copiar los hijos correspondientes
    if (!hijo->getEsHoja()) {
        for (int j = 0; j < t; j++) {
            if (j + t < static_cast<int>(hijo->getHijos().size())) {
                nuevoNodo->getHijos().push_back(hijo->getHijos()[j+t]);
            }
        }
    }
    
    // Insertar la clave mediana en el padre
    if (!hijo->getClaves().empty() && t - 1 < static_cast<int>(hijo->getClaves().size())) {
        padre->getClaves().insert(
            padre->getClaves().begin() + indice,
            hijo->getClaves()[t-1]
        );
    }
    
    // Insertar el nuevo nodo en la posición correcta
    if (indice + 1 <= static_cast<int>(padre->getHijos().size())) {
        padre->getHijos().insert(
            padre->getHijos().begin() + indice + 1,
            nuevoNodo
        );
    }
    
    // Redimensionar el hijo original
    if (t - 1 < static_cast<int>(hijo->getClaves().size())) {
        hijo->getClaves().resize(t-1);
    }
    if (!hijo->getEsHoja() && t < static_cast<int>(hijo->getHijos().size())) {
        hijo->getHijos().resize(t);
    }
}

void ArbolB::insertarNoLleno(Nodo_b* nodo, const Comentario& clave) {
    int i = nodo->getClaves().size() - 1;

    if (nodo->getEsHoja()) {
        nodo->getClaves().push_back(clave);
        while (i >= 0 && compararComentarios(nodo->getClaves()[i], clave) > 0) {
            nodo->getClaves()[i+1] = nodo->getClaves()[i];
            i--;
        }
        nodo->getClaves()[i+1] = clave;
    } else {
        while (i >= 0 && compararComentarios(nodo->getClaves()[i], clave) > 0)
            i--;
        i++;
        if (static_cast<int>(nodo->getHijos()[i]->getClaves().size()) == 2 * t - 1) {
            dividirHijo(nodo, i, nodo->getHijos()[i]);
            if (compararComentarios(nodo->getClaves()[i], clave) < 0)
                i++;
        }
        insertarNoLleno(nodo->getHijos()[i], clave);
    }
}

int ArbolB::compararComentarios(const Comentario& c1, const Comentario& c2) const {
    int compFecha = compareFechas(c1.getFecha(), c2.getFecha());
    if (compFecha != 0) return compFecha;
    return compareHoras(c1.getHora(), c2.getHora());
}

void ArbolB::graficar() {
    if (estaVacio()) {
            std::cout << "Error: Intentando graficar un árbol vacío" << std::endl;
            return;
    }
    try {

        // Verificación adicional antes de graficar
        std::cout << "Verificando estado del árbol antes de graficar:" << std::endl;
        std::cout << "Número de claves en la raíz: " << raiz->getClaves().size() << std::endl;

        std::string outputDir = "/Users/gio/Desktop/Edd_2s24/lab_edd_2s24/-EDD-Proyecto_202100229/fase3/usuarios/reportes/";
        std::ofstream outfile(outputDir + "ArbolB.dot");
        
        if (!outfile.is_open()) {
            std::cerr << "No se pudo abrir el archivo para escribir el grafo en: " << outputDir << "ArbolB.dot" << std::endl;
            return;
        }
        
        outfile << "digraph G {" << std::endl;
        outfile << "rankdir=TB;" << std::endl;  // Top to Bottom direction
        outfile << "node [shape=record, height=0.1];" << std::endl;
        outfile << "splines=false;" << std::endl;  // Use straight lines

        if (raiz != nullptr) {
            grafoAux(raiz, outfile);
        }

        outfile << "}" << std::endl;
        outfile.close();


        std::string dotCommand = "/opt/local/bin/dot -Tpng " + outputDir + "ArbolB.dot -o " + outputDir + "ArbolB.png";
        int returnCode = system(dotCommand.c_str());

        if (returnCode == 0) {
            std::cout << "Gráfico del Árbol B generado exitosamente." << std::endl;
        } else {
            std::cerr << "Error al generar el gráfico del Árbol B." << std::endl;
        }
    } catch (const std::exception& e) {
        std::cerr << "Error durante la generación del gráfico: " << e.what() << std::endl;
    }
}

void ArbolB::grafoAux(Nodo_b* nodo, std::ofstream& outfile) {
    if (nodo != nullptr) {
        // Generar un ID único para el nodo basado en su dirección de memoria
        outfile << "nodo" << nodo << " [label=\"";
        
        // Añadir los puertos y las claves
        for (size_t i = 0; i < nodo->getClaves().size(); ++i) {
            if (i > 0) outfile << "|";
            outfile << "<f" << i << ">|";
            
            const Comentario& com = nodo->getClaves()[i];
            outfile << "{" << escaparCaracteres(com.getCorreoC()) << "\\n"
                   << escaparCaracteres(com.getComment()) << "\\n"
                   << com.getFecha() << " " << com.getHora() << "}";
            
            if (i == nodo->getClaves().size() - 1) {
                outfile << "|<f" << i + 1 << ">";
            }
        }
        
        outfile << "\"];" << std::endl;

        // Dibujar conexiones a los hijos
        for (size_t i = 0; i < nodo->getHijos().size(); ++i) {
            if (nodo->getHijos()[i] != nullptr) {
                // Dibujar la conexión al hijo
                outfile << "nodo" << nodo << ":f" << i 
                       << " -> nodo" << nodo->getHijos()[i] << ";" << std::endl;
                
                // Llamada recursiva para procesar el hijo
                grafoAux(nodo->getHijos()[i], outfile);
            }
        }
    }
}
/*
void ArbolB::conexionesAux(Nodo_b* nodo, std::ofstream& outfile) {
    if (nodo != nullptr) {
        for (size_t i = 0; i < nodo->getHijos().size(); ++i) {
            if (nodo->getHijos()[i] != nullptr) {
                // Dibuja solo una conexión por hijo
                outfile << "nodo" << nodo << ":f" << i << " -> nodo" << nodo->getHijos()[i] << ";" << std::endl;
                // Llamada recursiva para procesar los hijos
                conexionesAux(nodo->getHijos()[i], outfile);
            }
        }
    }
}*/

std::string ArbolB::escaparCaracteres(const std::string& str) {
    std::string resultado;
    for (char c : str) {
        if (c == '"' || c == '\\') {
            resultado += '\\';
        }
        resultado += c;
    }
    return resultado;
}

int ArbolB::compareFechas(const std::string& fecha1, const std::string& fecha2) {
    int dia1, mes1, anio1, dia2, mes2, anio2;
    char delim;
    std::istringstream ss1(fecha1);
    std::istringstream ss2(fecha2);

    ss1 >> dia1 >> delim >> mes1 >> delim >> anio1;
    ss2 >> dia2 >> delim >> mes2 >> delim >> anio2;

    if (anio1 != anio2) return anio1 - anio2;
    if (mes1 != mes2) return mes1 - mes2;
    return dia1 - dia2;
}

int ArbolB::compareHoras(const std::string& hora1, const std::string& hora2) {
    int h1, m1, h2, m2;
    char delim;
    std::istringstream ss1(hora1);
    std::istringstream ss2(hora2);

    ss1 >> h1 >> delim >> m1;
    ss2 >> h2 >> delim >> m2;

    if (h1 != h2) return h1 - h2;
    return m1 - m2;
}

// Implementar los demás métodos (borrar, buscar, recorridoInorden, etc.) siguiendo la misma lógica


bool ArbolB::estaVacio() const {
    return raiz == nullptr;
}

void ArbolB::imprimirEstado() const {
    if (estaVacio()) {
        std::cout << "Árbol B vacío" << std::endl;
        return;
    }
    std::cout << "Estado del Árbol B:" << std::endl;
    imprimirEstadoRecursivo(raiz, 0);
}

void ArbolB::imprimirEstadoRecursivo(Nodo_b* nodo, int nivel) const {
    if (nodo == nullptr) return;
    
    std::string indentacion(nivel * 4, ' ');
    std::cout << indentacion << "Nivel " << nivel << ": ";
    
    for (const auto& clave : nodo->getClaves()) {
        std::cout << "[" << clave.getCorreoC() << " " 
                 << clave.getFecha() << " " << clave.getHora() << "] ";
    }
    std::cout << std::endl;
    
    if (!nodo->getEsHoja()) {
        for (auto hijo : nodo->getHijos()) {
            imprimirEstadoRecursivo(hijo, nivel + 1);
        }
    }
}

int ArbolB::contarNodos() const {
    return contarNodosRecursivo(raiz);
}

int ArbolB::contarNodosRecursivo(Nodo_b* nodo) const {
    if (nodo == nullptr) return 0;
    
    int count = 1;
    for (auto hijo : nodo->getHijos()) {
        count += contarNodosRecursivo(hijo);
    }
    return count;
}

// para merkle 

std::string ArbolB::obtenerComentariosJson() const {
    std::ostringstream jsonStream;
    bool primerComentario = true;
    
    if (raiz == nullptr) {
        return "[]"; // Retorna un array vacío si no hay comentarios
    }
    
    jsonStream << "[";
    obtenerComentariosJsonRecursivo(raiz, jsonStream, primerComentario);
    jsonStream << "]";
    
    return jsonStream.str();
}

void ArbolB::obtenerComentariosJsonRecursivo(Nodo_b* nodo, std::ostringstream& jsonStream, bool& primerComentario) const {
    if (nodo == nullptr) return;
    
    // Procesar los primeros hijos
    if (!nodo->getEsHoja() && !nodo->getHijos().empty()) {
        obtenerComentariosJsonRecursivo(nodo->getHijos()[0], jsonStream, primerComentario);
    }
    
    // Procesar las claves del nodo actual
    for (size_t i = 0; i < nodo->getClaves().size(); i++) {
        if (!primerComentario) {
            jsonStream << ",";
        }
        primerComentario = false;
        
        const Comentario& com = nodo->getClaves()[i];
        jsonStream << "{"
                  << "\"correo\":\"" << com.getCorreoC() << "\","
                  << "\"comentario\":\"" << com.getComment() << "\","
                  << "\"fecha\":\"" << com.getFecha() << "\","
                  << "\"hora\":\"" << com.getHora() << "\""
                  << "}";
        
        // Procesar el siguiente hijo si existe
        if (!nodo->getEsHoja() && i + 1 < nodo->getHijos().size()) {
            obtenerComentariosJsonRecursivo(nodo->getHijos()[i + 1], jsonStream, primerComentario);
        }
    }
}