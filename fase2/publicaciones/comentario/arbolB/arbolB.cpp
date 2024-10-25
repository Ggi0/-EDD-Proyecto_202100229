#include "arbolB.h"
#include <iostream>
#include <sstream>
#include <fstream>
#include <cstdlib>

ArbolB::ArbolB() : raiz(nullptr), t(3) {}  // t = 3 para un árbol de orden 5

// 1. Modificar el destructor de ArbolB para manejar correctamente la memoria
ArbolB::~ArbolB() {
    if (raiz != nullptr) {
        delete raiz;
        raiz = nullptr;
    }
}

void ArbolB::insertar(const Comentario& clave) {
    if (raiz == nullptr) {
        raiz = new Nodo_b(true);
        raiz->getClaves().push_back(clave);
    } else {
        // Si la raíz está llena, crear nuevo nodo
        if (raiz->getClaves().size() == 2*t - 1) {
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
        if (j + t < hijo->getClaves().size()) {
            nuevoNodo->getClaves().push_back(hijo->getClaves()[j+t]);
        }
    }
    
    // Si no es hoja, copiar los hijos correspondientes
    if (!hijo->getEsHoja()) {
        for (int j = 0; j < t; j++) {
            if (j + t < hijo->getHijos().size()) {
                nuevoNodo->getHijos().push_back(hijo->getHijos()[j+t]);
            }
        }
    }
    
    // Insertar la clave mediana en el padre
    if (!hijo->getClaves().empty() && t-1 < hijo->getClaves().size()) {
        padre->getClaves().insert(
            padre->getClaves().begin() + indice,
            hijo->getClaves()[t-1]
        );
    }
    
    // Insertar el nuevo nodo en la posición correcta
    if (indice + 1 <= padre->getHijos().size()) {
        padre->getHijos().insert(
            padre->getHijos().begin() + indice + 1,
            nuevoNodo
        );
    }
    
    // Redimensionar el hijo original
    if (t-1 < hijo->getClaves().size()) {
        hijo->getClaves().resize(t-1);
    }
    if (!hijo->getEsHoja() && t < hijo->getHijos().size()) {
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
        if (nodo->getHijos()[i]->getClaves().size() == 2*t - 1) {
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
    try {
        std::string outputDir = "/Users/gio/Desktop/Edd_2s24/lab_edd_2s24/-EDD-Proyecto_202100229/fase2/usuarios/reportes/";
        std::ofstream outfile(outputDir + "ArbolB.dot");
        
        if (!outfile.is_open()) {
            std::cerr << "No se pudo abrir el archivo para escribir el grafo" << std::endl;
            return;
        }
        
        outfile << "digraph G {" << std::endl;
        outfile << "node [shape=record];" << std::endl;

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
        outfile << "nodo" << nodo << " [label=\"";
        
        // Añadir el primer puerto para el hijo izquierdo
        outfile << "<f0> |";
        
        for (size_t i = 0; i < nodo->getClaves().size(); ++i) {
            const Comentario& com = nodo->getClaves()[i];
            outfile << "{Usuario: " << escaparCaracteres(com.getCorreoC()) << "\\n"
                    << "Comentario: " << escaparCaracteres(com.getComment()) << "\\n"
                    << "Fecha: " << com.getFecha() << "\\n"
                    << "Hora: " << com.getHora() 
                    << "}";
            
            // Añadir un puerto entre cada clave, excepto después de la última
            if (i < nodo->getClaves().size() - 1) {
                outfile << "| <f" << i+1 << "> |";
            }
        }
        
        // Añadir el último puerto para el hijo derecho
        outfile << "| <f" << nodo->getClaves().size() << ">";
        
        outfile << "\"];" << std::endl;

        // Dibujar las conexiones a los hijos y procesar los hijos recursivamente
        for (size_t i = 0; i < nodo->getHijos().size(); ++i) {
            if (nodo->getHijos()[i] != nullptr) {
                outfile << "nodo" << nodo << ":f" << i << " -> nodo" << nodo->getHijos()[i] << ";" << std::endl;
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