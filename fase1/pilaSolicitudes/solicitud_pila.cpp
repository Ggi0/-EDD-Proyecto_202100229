#include "solicitud_pila.h" // Incluir la cabecera de la clase solicitud_pila
#include <iostream> // Incluir la biblioteca para la entrada y salida estándar

// Constructor de la clase solicitud_pila
// Inicializa el puntero tope a nullptr y el tamaño a 0
solicitud_pila::solicitud_pila() : tope(nullptr), tamano(0) {}

// Destructor de la clase solicitud_pila
// Elimina todos los nodos de la pila para liberar la memoria
solicitud_pila::~solicitud_pila() {
    while (!estaVacia()) { // Mientras la pila no esté vacía
        pop(); // Llama a la función pop para eliminar el nodo superior
    }
}

// Función para agregar una solicitud a la pila (push)
// Recibe un objeto Solicitud por referencia constante
void solicitud_pila::push(const Solicitud& solicitud) {
    // Crea un nuevo nodo con la solicitud proporcionada
    solicitudPila_Nodo* nuevoNodo = new solicitudPila_Nodo(solicitud);
    // Establece el siguiente nodo del nuevo nodo como el tope actual
    nuevoNodo->setSiguiente(tope);
    // El nuevo nodo se convierte en el nuevo tope de la pila
    tope = nuevoNodo;
    // Incrementa el tamaño de la pila
    tamano++;
}

// Función para eliminar la solicitud en la parte superior de la pila (pop)
void solicitud_pila::pop() {
    // Verifica si la pila está vacía antes de intentar eliminar un nodo
    if (estaVacia()) {
        std::cout << "Error: La pila está vacía" << std::endl;
        return;
    }
    // Apunta a nodoEliminar al nodo que se encuentra en el tope
    solicitudPila_Nodo* nodoEliminar = tope;
    // Mueve el tope al siguiente nodo en la pila
    tope = tope->getSiguiente();
    // Elimina el nodo que estaba en el tope
    delete nodoEliminar;
    // Decrementa el tamaño de la pila
    tamano--;
}

// Función para obtener la solicitud en la parte superior de la pila (top)
// Retorna una copia del objeto Solicitud en el tope de la pila
Solicitud solicitud_pila::top() const {
    // Verifica si la pila está vacía antes de intentar acceder al tope
    if (estaVacia()) {
        std::cout << "Error: La pila está vacía" << std::endl;
        return Solicitud(); // Retorna un objeto Solicitud vacío en caso de error
    }
    // Retorna la solicitud que se encuentra en el tope
    return tope->getDato();
}

// Función para verificar si la pila está vacía
// Retorna true si el tope es nullptr, lo que significa que la pila está vacía
bool solicitud_pila::estaVacia() const {
    return tope == nullptr;
}

// Función para obtener el tamaño de la pila
// Retorna el número de elementos en la pila
int solicitud_pila::size() const {
    return tamano;
}

// Función para imprimir todas las solicitudes en la pila
void solicitud_pila::imprimir() const {
    // Verifica si la pila está vacía antes de intentar imprimir
    if (estaVacia()) {
        std::cout << "La pila está vacía" << std::endl;
        return;
    }

    // Apunta al nodo actual comenzando desde el tope
    solicitudPila_Nodo* actual = tope;
    // Recorre todos los nodos en la pila
    while (actual != nullptr) {
        // Imprime los atributos de la solicitud en el nodo actual
        std::cout << "Emisor: " << actual->getDato().getEmisor() 
                  << ", Receptor: " << actual->getDato().getReceptor()
                  << ", Estado: " << actual->getDato().getEstado() << std::endl;
        // Avanza al siguiente nodo en la pila
        actual = actual->getSiguiente();
    }
}


void solicitud_pila::grafica() const {
    if (!estaVacia()) {
        std::ofstream archivo("pilaSolicitudes.dot");
        archivo << "digraph G {" << std::endl;
        archivo << "    rankdir=TB;" << std::endl; // Configuración para colocar nodos uno encima del otro
        archivo << "    node [shape=record];" << std::endl;

        solicitudPila_Nodo* actual = tope;
        int contador = 0;

        // Generar nodos con su contenido
        while (actual != nullptr) {
            archivo << "    node" << contador << " [label=\"{" 
                    << "Emisor: " << actual->getDato().getEmisor() << "\\n"
                    << "Receptor: " << actual->getDato().getReceptor() << "\\n"
                    << "Estado: " << actual->getDato().getEstado() << "}\"];" << std::endl;
            if (actual->getSiguiente() != nullptr) {
                archivo << "    node" << contador << " -> node" << contador + 1 << ";" << std::endl;
            }
            actual = actual->getSiguiente();
            contador++;
        }

        archivo << "}" << std::endl;
        archivo.close();

        // Comando para generar la imagen a partir del archivo .dot
        system("dot -Tpng pilaSolicitudes.dot -o pilaSolicitudes.png");
    } else {
        std::cout << "La pila está vacía. No se puede generar la gráfica." << std::endl;
    }
}