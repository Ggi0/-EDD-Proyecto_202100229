#include "lista_comentarios.h"

// Constructor
lista_comentarios::lista_comentarios(){
    primero = nullptr;
    ultimo = nullptr;
}

// Destructor
lista_comentarios::~lista_comentarios() {
    Nodo_com *tempo = primero;
    Nodo_com *aux;
    while (tempo != nullptr) {
        aux = tempo->getSig();
        delete tempo;
        tempo = aux;
    }
}

Nodo_com* lista_comentarios::getPrimero() {
    return primero;
}

// ----------- METODOS ----------------

// Insertar un nodo al inicio de la lista
void lista_comentarios::push(Comentario comentario) {
    Nodo_com *nuevo_Nodo = new Nodo_com(comentario);
    if (primero == nullptr) {
        primero = nuevo_Nodo;
        ultimo = nuevo_Nodo;
    } else {
        nuevo_Nodo->setSig(primero);
        primero = nuevo_Nodo;
    }
}

// Insertar un nodo al final de la lista
void lista_comentarios::append(Comentario comentario) {
    Nodo_com *nuevo_Nodo = new Nodo_com(comentario);
    if (primero == nullptr) {
        primero = nuevo_Nodo;
        ultimo = nuevo_Nodo;
    } else {
        ultimo->setSig(nuevo_Nodo);
        ultimo = nuevo_Nodo;
    }
}

// Método para obtener el tamaño de la lista
int lista_comentarios::size() {
    int count = 0;
    Nodo_com *actual = primero;
    
    while (actual != nullptr) {
        count++;
        actual = actual->getSig();
    }
    
    return count;
}

// Método para eliminar el último elemento de la lista
void lista_comentarios::pop() {
    if (primero == nullptr) {
        // La lista está vacía, no hay nada que eliminar
        return;
    }
    
    if (primero == ultimo) {
        // Solo hay un elemento en la lista
        delete primero;
        primero = nullptr;
        ultimo = nullptr;
    } else {
        // Hay más de un elemento en la lista
        Nodo_com *actual = primero;
        
        // Recorrer la lista hasta el penúltimo nodo
        while (actual->getSig() != ultimo) {
            actual = actual->getSig();
        }
        
        // Eliminar el último nodo
        delete ultimo;
        ultimo = actual;
        ultimo->setSig(nullptr);
    }
}

void lista_comentarios::removeIf(bool (*condition)(const Comentario&)) {
    Nodo_com *actual = primero;
    Nodo_com *anterior = nullptr;

    while (actual != nullptr) {
        if (condition(actual->getData())) {
            // El nodo actual debe ser eliminado
            if (anterior == nullptr) {
                // Estamos eliminando el primer nodo
                primero = actual->getSig();
                delete actual;
                actual = primero;
            } else {
                // Estamos eliminando un nodo intermedio o el último
                anterior->setSig(actual->getSig());
                if (actual == ultimo) {
                    ultimo = anterior;
                }
                delete actual;
                actual = anterior->getSig();
            }
        } else {
            // Mover al siguiente nodo
            anterior = actual;
            actual = actual->getSig();
        }
    }
}


// Método para imprimir todos los usuarios en la lista
void lista_comentarios::printAll() {
    Nodo_com *actual = primero;  // Empezar desde el primer nodo

    // Recorrer toda la lista
    while (actual != nullptr) {
        actual->getData().printComentario();  // Llamar al método printUsuario de cada objeto Usuario
        actual = actual->getSig();  // Avanzar al siguiente nodo
    }
}

Comentario* lista_comentarios::buscarPorCorreo(const std::string& correo) {
    Nodo_com* actual = primero;
    while (actual != nullptr) {
        if (actual->getData().getCorreoC() == correo) {
            return &(actual->getData());
        }
        actual = actual->getSig();
    }
    return nullptr;
}


void lista_comentarios::eliminarUsuario(const std::string& correo) {
    Nodo_com* actual = primero;
    Nodo_com* anterior = nullptr;

    while (actual != nullptr) {
        if (actual->getData().getCorreoC() == correo) {
            if (anterior == nullptr) {
                primero = actual->getSig();
            } else {
                anterior->setSig(actual->getSig());
            }
            if (actual == ultimo) {
                ultimo = anterior;
            }
            delete actual;
            return;
        }
        anterior = actual;
        actual = actual->getSig();
    }
}


// ----- SETTER DE PRIMERO -----
void lista_comentarios::setPrimero(Nodo_com* nuevoPrimero) {
    primero = nuevoPrimero;
    if (primero == nullptr) {
        ultimo = nullptr; // Si la lista queda vacía, también actualizamos el último a nullptr
    }
}

// ----- GETTER DE ULTIMO -----
Nodo_com* lista_comentarios::getUltimo() {
    return ultimo;
}

// ----- SETTER DE ULTIMO -----
void lista_comentarios::setUltimo(Nodo_com* nuevoUltimo) {
    ultimo = nuevoUltimo;
    if (ultimo == nullptr) {
        primero = nullptr; // Si la lista queda vacía, también actualizamos el primero a nullptr
    }
}

void lista_comentarios::graficar() const {
    // Ruta donde deseas guardar el archivo .dot y .png
    std::string outputDir = "/Users/gio/Desktop/Edd_2s24/lab_edd_2s24/-EDD-Proyecto_202100229/fase2/usuarios/reportes/";
    std::ofstream archivo(outputDir + "lista_comentarios.dot");
    if (!archivo.is_open()) {
        std::cerr << "No se pudo crear el archivo .dot" << std::endl;
        return;
    }

    archivo << "digraph G {" << std::endl;
    archivo << "  rankdir=LR;" << std::endl;

    int contador = 0;
    Nodo_com* actual = primero;
    while (actual != nullptr) {
        archivo << "  nodo" << contador << " [label=\"Correo: " 
                << actual->getData().getCorreoC() << "\\nComentario: " 
                << actual->getData().getComment() << "\\nFecha: " 
                << actual->getData().getFecha() << "\\nHora: " 
                << actual->getData().getHora() << "\"];" << std::endl;

        if (actual->getSig() != nullptr) {
            archivo << "  nodo" << contador << " -> nodo" << contador + 1 << ";" << std::endl;
        }

        actual = actual->getSig();
        contador++;
    }

    archivo << "}" << std::endl;
    archivo.close();// Cerrar el archivo

        // Comando para generar el archivo .png usando dot, especificando la ruta completa
    std::string dotCommand = "/opt/local/bin/dot -Tpng " + outputDir + "lista_comentarios.dot -o " + outputDir + "lista_comentarios.png";

    // Ejecutar el comando
    int returnCode = system(dotCommand.c_str());

    if(returnCode == 0){
        std::cout << "Command executed successfully." << std::endl;
        }
    else{
        std::cout << "Command execution failed or returned non-zero: " << returnCode << std::endl;
    }
}

