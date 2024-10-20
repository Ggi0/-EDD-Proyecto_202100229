#include "bst_publi.h"

BST::BST() : raiz(nullptr) {}

BST::~BST() {
    try {
        destruirArbol(raiz);
        raiz = nullptr;
    } catch (...) {
        std::cerr << "Error durante la destrucción del árbol" << std::endl;
    }
}

// Constructor de copia
BST::BST(const BST& other) : raiz(nullptr) {
    try {
        if (other.raiz != nullptr) {
            raiz = copiarArbol(other.raiz);
        }
    } catch (...) {
        destruirArbol(raiz);
        raiz = nullptr;
        throw;
    }
}

// Constructor de movimiento
BST::BST(BST&& other) noexcept : raiz(other.raiz) {
    other.raiz = nullptr;
}

// Operador de asignación
BST& BST::operator=(const BST& other) {
    if (this != &other) {
        BST temp(other);  // Copia temporal
        *this = std::move(temp);  // Movemos la copia temporal
    }
    return *this;
}

// Operador de movimiento
BST& BST::operator=(BST&& other) noexcept {
    if (this != &other) {
        destruirArbol(raiz);
        raiz = other.raiz;
        other.raiz = nullptr;
    }
    return *this;
}

// Método auxiliar para copiar el árbol
NodoBST* BST::copiarArbol(NodoBST* nodo) {
    if (nodo == nullptr) return nullptr;
    
    try {
        NodoBST* nuevoNodo = new NodoBST(nodo->getFechaID());
        nuevoNodo->setListaPublicaciones(nodo->getListaPublicaciones());
        
        if (nodo->getIzq()) {
            nuevoNodo->setIzq(copiarArbol(nodo->getIzq()));
        }
        if (nodo->getDrcha()) {
            nuevoNodo->setDrcha(copiarArbol(nodo->getDrcha()));
        }
        
        return nuevoNodo;
    } catch (...) {
        delete nodo;
        throw;
    }
}

void BST::destruirArbol(NodoBST* nodo) {
    if (nodo != nullptr) {
        NodoBST* izq = nodo->getIzq();
        NodoBST* der = nodo->getDrcha();
        
        // Desvinculamos los hijos antes de eliminar
        nodo->setIzq(nullptr);
        nodo->setDrcha(nullptr);
        
        destruirArbol(izq);
        destruirArbol(der);
        delete nodo;
    }
}




NodoBST* BST::getRaiz() const {
    return raiz;
}

// Método público para insertar y obtener el nodo
NodoBST* BST::insertAndGetNode(const std::string& fechaID) {
    raiz = insertAndGetNodeHelper(raiz, fechaID);
    std::cout << "Fecha " << fechaID << " procesada exitosamente" << std::endl;
    return raiz; // Devuelve el nodo raíz después de la inserción
}

// Método auxiliar para insertar recursivamente
NodoBST* BST::insertAndGetNodeHelper(NodoBST* nodo, const std::string& fechaID) {
    if (nodo == nullptr) {
        return new NodoBST(fechaID);
    }

    int comparacion = compareFechas(fechaID, nodo->getFechaID());

    if (comparacion < 0) {
        nodo->setIzq(insertAndGetNodeHelper(nodo->getIzq(), fechaID));
    } else if (comparacion > 0) {
        nodo->setDrcha(insertAndGetNodeHelper(nodo->getDrcha(), fechaID));
    }
    // Si la fecha ya existe, devolvemos el nodo existente
    return nodo;
}

bool BST::estaVacio() const {
    return raiz == nullptr;
}

void BST::preOrden(){
    preOrden(this->raiz);
}

void BST::inOrden(){
    inOrden(this->raiz);
}

void BST::postOrden(){
    postOrden(this->raiz, 0);
}


/*
void BST::graph() {
    // Ruta donde deseas guardar el archivo .dot y .png
    std::string outputDir = "/Users/gio/Desktop/Edd_2s24/lab_edd_2s24/-EDD-Proyecto_202100229/fase2/usuarios/reportes/";

    // Crear el archivo .dot en la ruta especificada
    std::ofstream outfile(outputDir + "bst.dot");
    outfile << "digraph G {" << std::endl;

    if (raiz != nullptr) {
        graph(raiz, outfile);
    }

    outfile << "}" << std::endl;
    outfile.close();

    // Comando para generar el archivo .png usando dot, especificando la ruta completa
    std::string dotCommand = "/opt/local/bin/dot -Tpng " + outputDir + "bst.dot -o " + outputDir + "bst.png";

    // Ejecutar el comando
    int returnCode = system(dotCommand.c_str());

    if (returnCode == 0) {
        std::cout << "Command executed successfully. BST" << std::endl;
    } else {
        std::cout << "(BST)Command execution failed or returned non-zero: " << returnCode << std::endl;
    }
}

*/

void BST::graphHelper(NodoBST *nodo, std::ofstream &f) const {
    if (nodo != nullptr) {
        f << "  \"" << nodo->getFechaID() << "\" [label=\"" << nodo->getFechaID() << "\"];" << std::endl;
        
        if (nodo->getIzq() != nullptr) {
            f << "  \"" << nodo->getFechaID() << "\" -> \"" << nodo->getIzq()->getFechaID() << "\";" << std::endl;
            graphHelper(nodo->getIzq(), f);
        }
        
        if (nodo->getDrcha() != nullptr) {
            f << "  \"" << nodo->getFechaID() << "\" -> \"" << nodo->getDrcha()->getFechaID() << "\";" << std::endl;
            graphHelper(nodo->getDrcha(), f);
        }
    }
}

void BST::graph() const {
    std::string outputDir = "/Users/gio/Desktop/Edd_2s24/lab_edd_2s24/-EDD-Proyecto_202100229/fase3/usuarios/reportes";
    std::ofstream outfile(outputDir + "bst.dot");
    outfile << "digraph BST {" << std::endl;
    outfile << "  node [shape=circle];" << std::endl;

    if (!estaVacio()) {
        graphHelper(raiz, outfile);
    } else {
        outfile << "  empty [label=\"Árbol vacío\", shape=none];" << std::endl;
    }

    outfile << "}" << std::endl;
    outfile.close();

    std::string dotCommand = "/opt/local/bin/dot -Tpng " + outputDir + "bst.dot -o " + outputDir + "bst.png";
    int returnCode = system(dotCommand.c_str());

    if (returnCode == 0) {
        std::cout << "Gráfico del BST generado exitosamente." << std::endl;
    } else {
        std::cout << "Error al generar el gráfico del BST. Código de retorno: " << returnCode << std::endl;
    }
}

void BST::graph(NodoBST *raiz, std::ofstream &f) {
    if (raiz != nullptr) {
        std::stringstream oss;
        oss << raiz;
        std::string nombre = oss.str();

        f << "Nodo" << nombre << "[label = \"" << raiz->getFechaID() << "\"];" << std::endl;
    
        if (raiz->getIzq() != nullptr) {
            oss.str("");
            oss << raiz->getIzq();
            std::string izquierda = oss.str();
            f << "Nodo" << nombre << "->Nodo" << izquierda << ";" << std::endl;
            graph(raiz->getIzq(), f);
        }

        if (raiz->getDrcha() != nullptr) {
            oss.str("");
            oss << raiz->getDrcha();
            std::string derecha = oss.str();
            f << "Nodo" << nombre << "->Nodo" << derecha << ";" << std::endl;
            graph(raiz->getDrcha(), f);
        }
    }
}

void BST::preOrden(NodoBST *raiz){
    if(raiz != nullptr){
        std::cout << raiz->getFechaID() << ", ";
        preOrden(raiz->getIzq());
        preOrden(raiz->getDrcha());
    }
}

void BST::inOrden(NodoBST *raiz){
    if(raiz != nullptr){
        preOrden(raiz->getIzq());
        std::cout << raiz->getFechaID() << ", ";
        preOrden(raiz->getDrcha());
    }
}

void BST::postOrden(NodoBST *raiz, bool accion){
    if(raiz != nullptr){
        postOrden(raiz->getIzq(), accion);
        postOrden(raiz->getDrcha(), accion);
        if(!accion){std::cout << raiz->getFechaID() << ", ";}
        else{delete raiz;}
    }
}

// Implementación del método auxiliar para comparar fechas
int BST::compareFechas(const std::string& fecha1, const std::string& fecha2) {
    // Extraer día, mes y año de cada fecha
    int dia1, mes1, anio1, dia2, mes2, anio2;
    char delim;
    std::istringstream ss1(fecha1);
    std::istringstream ss2(fecha2);

    ss1 >> dia1 >> delim >> mes1 >> delim >> anio1;
    ss2 >> dia2 >> delim >> mes2 >> delim >> anio2;

    // Comparar año, luego mes, luego día
    if (anio1 != anio2) return anio1 - anio2;
    if (mes1 != mes2) return mes1 - mes2;
    return dia1 - dia2;
}

NodoBST* BST::buscarNodoPorFecha(const std::string& fecha) {
    NodoBST* actual = raiz;
    while (actual != nullptr) {
        int comparacion = compareFechas(fecha, actual->getFechaID());
        if (comparacion == 0) {
            return actual;  // Fecha encontrada
        } else if (comparacion < 0) {
            actual = actual->getIzq();
        } else {
            actual = actual->getDrcha();
        }
    }
    return nullptr;  // Fecha no encontrada
}

