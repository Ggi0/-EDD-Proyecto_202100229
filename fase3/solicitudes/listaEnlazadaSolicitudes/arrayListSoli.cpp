#include "arrayListSoli.h"

// Constructor
arrayList_soli::arrayList_soli(){
    primero = nullptr;
    ultimo = nullptr;
}

// Destructor
// Constructor de copia
arrayList_soli::arrayList_soli(const arrayList_soli& otra) : primero(nullptr), ultimo(nullptr) {
    copiarLista(otra);
}

// Operador de asignación
arrayList_soli& arrayList_soli::operator=(const arrayList_soli& otra) {
    if (this != &otra) {
        // Limpiamos la lista actual
        solicitud_Nodo* actual = primero;
        while (actual != nullptr) {
            solicitud_Nodo* siguiente = actual->getSig();
            delete actual;
            actual = siguiente;
        }
        primero = nullptr;
        ultimo = nullptr;
        
        // Copiamos la otra lista
        copiarLista(otra);
    }
    return *this;
}

// Método auxiliar para copiar lista
void arrayList_soli::copiarLista(const arrayList_soli& otra) {
    solicitud_Nodo* actual = otra.primero;
    while (actual != nullptr) {
        append(actual->getDato());
        actual = actual->getSig();
    }
}

// Destructor mejorado
arrayList_soli::~arrayList_soli() {
    solicitud_Nodo* actual = primero;
    while (actual != nullptr) {
        solicitud_Nodo* siguiente = actual->getSig();
        delete actual;
        actual = siguiente;
    }
    primero = nullptr;
    ultimo = nullptr;
}

solicitud_Nodo* arrayList_soli::getPrimero() {
    return primero;
}

void arrayList_soli::setPrimero(solicitud_Nodo* nuevoPrimero) {
    // No eliminamos los nodos existentes, solo actualizamos los punteros
    primero = nuevoPrimero;
    if (primero == nullptr) {
        ultimo = nullptr;
    } else {
        // Actualizar el último nodo
        solicitud_Nodo* actual = primero;
        while (actual->getSig() != nullptr) {
            actual = actual->getSig();
        }
        ultimo = actual;
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
        solicitud_Nodo* actual = primero;
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
        solicitud_Nodo* siguiente = actual->getSig();
        
        if (predicado(actual->getDato())) {
            if (anterior == nullptr) {
                primero = siguiente;
            } else {
                anterior->setSig(siguiente);
            }
            
            if (actual == ultimo) {
                ultimo = anterior;
            }
            
            delete actual;
        } else {
            anterior = actual;
        }
        
        actual = siguiente;
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
    if (primero == nullptr) return;

    solicitud_Nodo* actual = primero;
    solicitud_Nodo* anterior = nullptr;

    while (actual != nullptr) {
        if (actual->getDato().getEmisor() == emisor && 
            actual->getDato().getReceptor() == receptor) {
            
            if (anterior == nullptr) {
                // Es el primer nodo
                primero = actual->getSig();
                if (primero == nullptr) {
                    ultimo = nullptr;
                }
            } else {
                anterior->setSig(actual->getSig());
                if (actual == ultimo) {
                    ultimo = anterior;
                }
            }
            
            delete actual;
            return;
        }
        anterior = actual;
        actual = actual->getSig();
    }
}
