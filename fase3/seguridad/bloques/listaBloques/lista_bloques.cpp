#include "lista_bloques.h"

// Constructor
listaBloques::listaBloques(){
    primero = nullptr;
    ultimo = nullptr;
}

// Destructor
// Constructor de copia
listaBloques::listaBloques(const listaBloques& otra) : primero(nullptr), ultimo(nullptr) {
    copiarLista(otra);
}

// Operador de asignación
listaBloques& listaBloques::operator=(const listaBloques& otra) {
    if (this != &otra) {
        // Limpiamos la lista actual
        Bloque_Nodo* actual = primero;
        while (actual != nullptr) {
            Bloque_Nodo* siguiente = actual->getSig();
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
void listaBloques::copiarLista(const listaBloques& otra) {
    Bloque_Nodo* actual = otra.primero;
    while (actual != nullptr) {
        append(actual->getDato());
        actual = actual->getSig();
    }
}

// Destructor mejorado
listaBloques::~listaBloques() {
    Bloque_Nodo* actual = primero;
    while (actual != nullptr) {
        Bloque_Nodo* siguiente = actual->getSig();
        delete actual;
        actual = siguiente;
    }
    primero = nullptr;
    ultimo = nullptr;
}

Bloque_Nodo* listaBloques::getPrimero() {
    return primero;
}

void listaBloques::setPrimero(Bloque_Nodo* nuevoPrimero) {
    // No eliminamos los nodos existentes, solo actualizamos los punteros
    primero = nuevoPrimero;
    if (primero == nullptr) {
        ultimo = nullptr;
    } else {
        // Actualizar el último nodo
        Bloque_Nodo* actual = primero;
        while (actual->getSig() != nullptr) {
            actual = actual->getSig();
        }
        ultimo = actual;
    }
}

Bloque_Nodo* listaBloques::getUltimo() {
    // Si la lista está vacía, retornamos nullptr
    if (primero == nullptr) {
        return nullptr;
    }
    
    // Como mantenemos actualizado el puntero 'ultimo',
    // simplemente lo retornamos
    return ultimo;
}

void listaBloques::setUltimo(Bloque_Nodo* nuevoUltimo) {
    // Si la lista está vacía
    if (primero == nullptr) {
        primero = nuevoUltimo;
        ultimo = nuevoUltimo;
        if (nuevoUltimo != nullptr) {
            nuevoUltimo->setSig(nullptr);
        }
        return;
    }
    
    // Si no está vacía
    if (ultimo != nullptr) {
        ultimo->setSig(nuevoUltimo);
    }
    ultimo = nuevoUltimo;
    if (nuevoUltimo != nullptr) {
        nuevoUltimo->setSig(nullptr);
    }
}


// Métodos

void listaBloques::push(Bloque bloque) {
    Bloque_Nodo* nuevo_Nodo = new Bloque_Nodo(bloque);
    if (primero == nullptr) {
        primero = nuevo_Nodo;
        ultimo = nuevo_Nodo;
    } else {
        nuevo_Nodo->setSig(primero);
        primero = nuevo_Nodo;
    }
}

void listaBloques::append(Bloque bloque) {
    Bloque_Nodo* nuevo_Nodo = new Bloque_Nodo(bloque);
    if (primero == nullptr) {
        primero = nuevo_Nodo;
        ultimo = nuevo_Nodo;
    } else {
        ultimo->setSig(nuevo_Nodo);
        ultimo = nuevo_Nodo;
    }
    nuevo_Nodo->setSig(nullptr);
}


int listaBloques::size() {
    int count = 0;
    Bloque_Nodo *actual = primero;
    
    while (actual != nullptr) {
        count++;
        actual = actual->getSig();
    }
    
    return count;
}

void listaBloques::pop() {
    if (primero == nullptr) {
        return;
    }
    
    if (primero == ultimo) {
        delete primero;
        primero = nullptr;
        ultimo = nullptr;
        return;
    }
    
    Bloque_Nodo* actual = primero;
    while (actual->getSig() != ultimo) {
        actual = actual->getSig();
    }
    
    delete ultimo;
    ultimo = actual;
    ultimo->setSig(nullptr);
}

void listaBloques::printAll() {
    Bloque_Nodo *actual = primero;

    while (actual != nullptr) {
        Bloque& Bloque = actual->getDato();
        
        Bloque.printBloque();

        actual = actual->getSig();
    }
}

void listaBloques::removeIf(std::function<bool(const Bloque&)> predicado) {
    Bloque_Nodo* actual = primero;
    Bloque_Nodo* anterior = nullptr;

    while (actual != nullptr) {
        Bloque_Nodo* siguiente = actual->getSig();
        
        if (predicado(actual->getDato())) {
            if (anterior == nullptr) {
                primero = siguiente;
            } else {
                anterior->setSig(siguiente);
            }
            
            if (actual == ultimo) {
                ultimo = anterior;
                if (ultimo != nullptr) {
                    ultimo->setSig(nullptr);
                }
            }
            
            delete actual;
        } else {
            anterior = actual;
        }
        
        actual = siguiente;
    }
}


    

void listaBloques::grafica() const {
    // Ruta donde deseas guardar el archivo .dot y .png
    std::string outputDir = "/Users/gio/Desktop/Edd_2s24/lab_edd_2s24/-EDD-Proyecto_202100229/fase3/usuarios/reportes/";

    // Crear el archivo .dot en la ruta especificada
    std::ofstream dotFile(outputDir + "blockchain_graph.dot");
    if (!dotFile.is_open()) {
        std::cerr << "Error: Could not open file for writing." << std::endl;
        return;
    }

    // Start the DOT graph
    dotFile << "digraph BlockChain {\n";
    dotFile << "    node [shape=record, style=filled];\n";
    
    Bloque_Nodo* actual = primero;
    while (actual != nullptr) {
        Bloque& bloque = actual->getDato();
        
        // Determine color based on informacionValida
        std::string fillcolor = bloque.getInformacionValida() ? 
            "lightblue" : "lightsalmon";
        
        // Create node with block details
        dotFile << "    node" << bloque.getIndex() 
                << " [label=\"{Index: " << bloque.getIndex() 
                << "\\nTimestamp: " << bloque.getTimestamp() 
                << "\\nHash: " << bloque.getHash() 
                << "\\nPrev Hash: " << bloque.getPrev() 
                << "}\", fillcolor=\"" << fillcolor << "\"];\n";
        
        // Create edge to next node if exists
        if (actual->getSig() != nullptr) {
            Bloque& siguienteBloque = actual->getSig()->getDato();
            dotFile << "    node" << bloque.getIndex() 
                    << " -> node" << siguienteBloque.getIndex() << ";\n";
        }
        
        actual = actual->getSig();
    }
    
    dotFile << "}\n";
    dotFile.close();
        // Comando para generar el archivo .png usando dot, especificando la ruta completa
    std::string dotCommand = "/opt/local/bin/dot -Tpng " + outputDir + "blockchain_graph.dot -o" + outputDir + "blockchain_graph.png";

    // Ejecutar el comando
    int returnCode = system(dotCommand.c_str());

    if(returnCode == 0){
        std::cout << "(bloch - fase3) Command executed successfully." << std::endl;
        }
    else{
        std::cout << "(bloch - fase3) Command execution failed or returned non-zero: " << returnCode << std::endl;
    }
}

