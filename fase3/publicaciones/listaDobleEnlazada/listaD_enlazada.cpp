#include "listaD_enlazadaP.h"


// Constructor
ListaDoblementeEnlazadaP::ListaDoblementeEnlazadaP() : primero(nullptr), ultimo(nullptr) {}

// Destructor
// Constructor de copia
ListaDoblementeEnlazadaP::ListaDoblementeEnlazadaP(const ListaDoblementeEnlazadaP& other) : primero(nullptr), ultimo(nullptr) {
    copiarNodos(other);
}

// Operador de asignación
ListaDoblementeEnlazadaP& ListaDoblementeEnlazadaP::operator=(const ListaDoblementeEnlazadaP& other) {
    if (this != &other) {  // Evitar auto-asignación
        liberarMemoria();   // Liberar memoria actual
        copiarNodos(other); // Copiar nodos de other
    }
    return *this;
}

// Destructor
ListaDoblementeEnlazadaP::~ListaDoblementeEnlazadaP() {
    liberarMemoria();
}

// Método auxiliar para liberar memoria
void ListaDoblementeEnlazadaP::liberarMemoria() {
    PublicacionNodo* actual = primero;
    while (actual != nullptr) {
        PublicacionNodo* siguiente = actual->getSig();
        delete actual;
        actual = siguiente;
    }
    primero = nullptr;
    ultimo = nullptr;
}

// Método auxiliar para copiar nodos
void ListaDoblementeEnlazadaP::copiarNodos(const ListaDoblementeEnlazadaP& other) {
    PublicacionNodo* actual = other.primero;
    while (actual != nullptr) {
        append(actual->getData());
        actual = actual->getSig();
    }
}



PublicacionNodo* ListaDoblementeEnlazadaP::getPrimero() const {
    return primero;
}

// Inserta una nueva publicación al inicio de la lista
void ListaDoblementeEnlazadaP::push(const Publicacion& data) {
    PublicacionNodo* nuevo = new PublicacionNodo(data);

    if (primero == nullptr) {
        // Si la lista está vacía, el nuevo nodo es tanto el primero como el último
        primero = nuevo;
        ultimo = nuevo;
    } else {
        // Si la lista no está vacía, insertamos al inicio
        nuevo->setSig(primero);
        primero->setPrev(nuevo);
        primero = nuevo;
    }
}

// Inserta una nueva publicación al final de la lista
void ListaDoblementeEnlazadaP::append(const Publicacion& data) {
    PublicacionNodo* nuevo = new PublicacionNodo(data);

    if (primero == nullptr) {
        // Si la lista está vacía, el nuevo nodo es tanto el primero como el último
        primero = nuevo;
        ultimo = nuevo;
    } else {
        // Si la lista no está vacía, insertamos al final
        nuevo->setPrev(ultimo);
        ultimo->setSig(nuevo);
        ultimo = nuevo;
    }
}

// Inserta una nueva publicación en una posición específica
void ListaDoblementeEnlazadaP::insert(int indice, const Publicacion& data) {
    PublicacionNodo* nuevo = new PublicacionNodo(data);
    PublicacionNodo* actual = primero;

    if (primero == nullptr || indice == 0) {
        // Si la lista está vacía o se inserta al inicio, usamos push
        push(data);
        return;
    }

    int i = 0;
    while (actual->getSig() != nullptr && i < indice - 1) {
        actual = actual->getSig();
        i++;
    }

    if (i < indice - 1) {
        // Si el índice es mayor que el tamaño de la lista, insertamos al final
        append(data);
        return;
    }

    // Insertamos el nuevo nodo en la posición correcta
    nuevo->setSig(actual->getSig());
    nuevo->setPrev(actual);
    if (actual->getSig() != nullptr) {
        actual->getSig()->setPrev(nuevo);
    } else {
        ultimo = nuevo;
    }
    actual->setSig(nuevo);
}

// Imprime la lista de inicio a fin
void ListaDoblementeEnlazadaP::print() const {
    PublicacionNodo* temp = primero;
    std::cout<<"lista global de publicaciones (desde el metodo): "<<std::endl;
    while (temp != nullptr) {
        temp->getData().printPublicacion();  // Imprime los datos de la publicación
        std::cout << " -> "<<std::endl;
        temp = temp->getSig();
    }
    std::cout << "nullptr" << std::endl;
}

// Imprime la lista de fin a inicio
void ListaDoblementeEnlazadaP::revPrint() const {
    PublicacionNodo* temp = ultimo;

    while (temp != nullptr) {
        temp->getData().printPublicacion();  // Imprime los datos de la publicación
        std::cout << " -> ";
        temp = temp->getPrev();
    }
    std::cout << "nullptr" << std::endl;
}


void ListaDoblementeEnlazadaP::graficar() const {
    std::string outputDir = "/Users/gio/Desktop/Edd_2s24/lab_edd_2s24/-EDD-Proyecto_202100229/fase3/usuarios/reportes/";
    std::ofstream archivo(outputDir + "listaGlobal_publicaciones.dot");
    archivo << "digraph G {" << std::endl;
    archivo << "    node [shape=record];" << std::endl;
    
    PublicacionNodo* temp = primero;
    int i = 0;
    
    while (temp != nullptr) {
        archivo << "    node" << i << " [label=\"{";
        archivo << "Correo: " << temp->getData().getCorreoP() << "\\n";
        archivo << "Contenido: " << temp->getData().getContenido() << "\\n";
        archivo << "Fecha: " << temp->getData().getFecha() << "\\n";
        archivo << "Hora: " << temp->getData().getHora() << "}\"];" << std::endl;
        
        if (temp->getSig() != nullptr) {
            archivo << "    node" << i << " -> node" << i+1 << ";" << std::endl;
        }
        
        if (temp->getPrev() != nullptr) {
            archivo << "    node" << i << " -> node" << i-1 << ";" << std::endl;
        }
        
        temp = temp->getSig();
        i++;
    }
    
    archivo << "}" << std::endl;
    archivo.close();
    std::string dotCommand = "/opt/local/bin/dot -Tpng " + outputDir + "listaGlobal_publicaciones.dot -o " + outputDir + "listaGlobal_publicaciones.png";
    int returnCode = system(dotCommand.c_str());
    if (returnCode == 0) {
        std::cout << "Gráfico (lista D enlazada - publi) generado exitosamente." << std::endl;
    } else {
        std::cout << "Error al generar el gráfico (lista D enlazada - publi). Código de retorno: " << returnCode << std::endl;
    }
    
    std::cout << "Archivo DOT generado: listaGlobal_publicaciones.dot" << std::endl;
}

void ListaDoblementeEnlazadaP::graficarNodo(const std::string& nombreArchivo) const {
    std::string outputDir = "/Users/gio/Desktop/Edd_2s24/lab_edd_2s24/-EDD-Proyecto_202100229/fase2/usuarios/reportes/";
    std::string fullPath = outputDir + nombreArchivo + ".dot";
    std::ofstream archivo(fullPath);
    
    if (!archivo.is_open()) {
        std::cerr << "Error: No se pudo abrir el archivo para escribir: " << fullPath << std::endl;
        return;
    }
    
    archivo << "digraph G {" << std::endl;
    archivo << "    node [shape=record];" << std::endl;
    archivo << "    rankdir=LR;" << std::endl;
    
    PublicacionNodo* temp = primero;
    int i = 0;
    
    while (temp != nullptr) {
        archivo << "    node" << i << " [label=\"{";
        archivo << "Correo: " << temp->getData().getCorreoP() << "\\n";
        archivo << "Contenido: " << temp->getData().getContenido() << "\\n";
        archivo << "Fecha: " << temp->getData().getFecha() << "\\n";
        archivo << "Hora: " << temp->getData().getHora() << "}\"];" << std::endl;
        
        if (i > 0) {
            archivo << "    node" << i-1 << " -> node" << i << ";" << std::endl;
        }
        
        temp = temp->getSig();
        i++;
    }
    
    archivo << "}" << std::endl;
    archivo.close();
    
    std::string dotCommand = "/opt/local/bin/dot -Tpng " + fullPath + " -o " + outputDir + nombreArchivo + ".png";
    int returnCode = system(dotCommand.c_str());
    if (returnCode == 0) {
        std::cout << "Gráfico de publicaciones generado exitosamente: " << nombreArchivo << ".png" << std::endl;
    } else {
        std::cerr << "Error al generar el gráfico de publicaciones. Comando: " << dotCommand << std::endl;
        std::cerr << "Código de retorno: " << returnCode << std::endl;
    }
}