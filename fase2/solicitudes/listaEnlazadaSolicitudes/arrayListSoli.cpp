#include "arrayListSoli.h"

// Constructor
arrayList_soli::arrayList_soli(){
    primero = nullptr;
    ultimo = nullptr;
}

// Destructor
arrayList_soli::~arrayList_soli() {
    solicitud_Nodo *tempo = primero;
    solicitud_Nodo *aux;
    while (tempo != nullptr) {
        aux = tempo->getSig();
        delete tempo;
        tempo = aux;
    }
}

solicitud_Nodo* arrayList_soli::getPrimero() {
    return primero;
}

void arrayList_soli::setPrimero(solicitud_Nodo* nuevoPrimero) {
    primero = nuevoPrimero;
    if (ultimo == nullptr) {
        ultimo = nuevoPrimero;
    }
}

// Métodos

void arrayList_soli::push(Solicitud solicitud) {
    solicitud_Nodo *nuevo_Nodo = new solicitud_Nodo(solicitud);
    if (primero == nullptr) {
        primero = nuevo_Nodo;
        ultimo = nuevo_Nodo;
    } else {
        nuevo_Nodo->setSig(primero);
        primero = nuevo_Nodo;
    }
}

void arrayList_soli::append(Solicitud solicitud) {
    solicitud_Nodo *nuevo_Nodo = new solicitud_Nodo(solicitud);
    if (primero == nullptr) {
        primero = nuevo_Nodo;
        ultimo = nuevo_Nodo;
    } else {
        ultimo->setSig(nuevo_Nodo);
        ultimo = nuevo_Nodo;
    }
}

int arrayList_soli::size() {
    int count = 0;
    solicitud_Nodo *actual = primero;
    
    while (actual != nullptr) {
        count++;
        actual = actual->getSig();
    }
    
    return count;
}

void arrayList_soli::pop() {
    if (primero == nullptr) {
        return;
    }
    
    if (primero == ultimo) {
        delete primero;
        primero = nullptr;
        ultimo = nullptr;
    } else {
        solicitud_Nodo *actual = primero;
        
        while (actual->getSig() != ultimo) {
            actual = actual->getSig();
        }
        
        delete ultimo;
        ultimo = actual;
        ultimo->setSig(nullptr);
    }
}

void arrayList_soli::printAll() {
    solicitud_Nodo *actual = primero;

    while (actual != nullptr) {
        const Solicitud& solicitud = actual->getDato();
        std::cout << "Emisor: " << solicitud.getEmisor() 
                  << ", Receptor: " << solicitud.getReceptor()
                  << ", Estado: " << solicitud.getEstado() << std::endl;
        actual = actual->getSig();
    }
}

void arrayList_soli::removeIf(std::function<bool(const Solicitud&)> predicado) {
    solicitud_Nodo* actual = primero;
    solicitud_Nodo* anterior = nullptr;

    while (actual != nullptr) {
        if (predicado(actual->getDato())) {
            if (anterior == nullptr) {
                primero = actual->getSig();
                delete actual;
                actual = primero;
            } else {
                anterior->setSig(actual->getSig());
                if (actual == ultimo) {
                    ultimo = anterior;
                }
                delete actual;
                actual = anterior->getSig();
            }
        } else {
            anterior = actual;
            actual = actual->getSig();
        }
    }
}

void arrayList_soli::grafica() const {
    if (primero != nullptr) {

        // Ruta donde deseas guardar el archivo .dot y .png
        std::string outputDir = "/Users/gio/Desktop/Edd_2s24/lab_edd_2s24/-EDD-Proyecto_202100229/fase2/usuarios/reportes/";

        std::ofstream archivo(outputDir + "listaSolicitudes.dot");
        archivo << "digraph G {" << std::endl;
        archivo << "    rankdir=LR;" << std::endl; // Configuración para colocar nodos de izquierda a derecha
        archivo << "    node [shape=record];" << std::endl;

        solicitud_Nodo* actual = primero;
        int contador = 0;

        // Generar nodos con su contenido
        while (actual != nullptr) {
            archivo << "    node" << contador << " [label=\"{" 
                    << "Emisor: " << actual->getDato().getEmisor() << "\\n"
                    << "Receptor: " << actual->getDato().getReceptor() << "\\n"
                    << "Estado: " << actual->getDato().getEstado() << "}\"];" << std::endl;
            if (actual->getSig() != nullptr) {
                archivo << "    node" << contador << " -> node" << contador + 1 << ";" << std::endl;
            }
            actual = actual->getSig();
            contador++;
        }

        archivo << "}" << std::endl;
        archivo.close();

        // Comando para generar la imagen a partir del archivo .dot
        system("/opt/local/bin/dot -Tpng listaSolicitudes.dot -o listaSolicitudes.png");
    } else {
        std::cout << "La lista está vacía. No se puede generar la gráfica." << std::endl;
    }
}

void arrayList_soli::eliminarSolicitud(const std::string& emisor, const std::string& receptor) {
    solicitud_Nodo* actual = primero;
    solicitud_Nodo* anterior = nullptr;

    while (actual != nullptr) {
        if (actual->getDato().getEmisor() == emisor && actual->getDato().getReceptor() == receptor) {
            if (anterior == nullptr) {
                primero = actual->getSig();
            } else {
                anterior->setSig(actual->getSig());
            }
            delete actual;
            std::cout << "Solicitud eliminada de la lista del emisor original" << std::endl;
            return;
        }
        anterior = actual;
        actual = actual->getSig();
    }

    std::cout << "No se encontró la solicitud en la lista del emisor original" << std::endl;
}