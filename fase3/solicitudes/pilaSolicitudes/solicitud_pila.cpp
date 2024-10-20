#include "solicitud_pila.h" // Incluir la cabecera de la clase solicitud_pila


// Constructor de la clase solicitud_pila
// Inicializa el puntero tope a nullptr y el tamaño a 0
solicitud_pila::solicitud_pila() : tope(nullptr), tamano(0) {}

// Constructor de copia - Realiza una copia profunda de la pila
solicitud_pila::solicitud_pila(const solicitud_pila& otra) : tope(nullptr), tamano(0) {
    if (otra.tope != nullptr) {
        // Usamos una pila temporal para mantener el orden correcto
        solicitudPila_Nodo* actual = otra.tope;
        solicitudPila_Nodo* ultimo = nullptr;
        
        while (actual != nullptr) {
            solicitudPila_Nodo* nuevo = new solicitudPila_Nodo(actual->getDato());
            if (tope == nullptr) {
                tope = nuevo;
            } else {
                ultimo->setSiguiente(nuevo);
            }
            ultimo = nuevo;
            actual = actual->getSiguiente();
            tamano++;
        }
    }
}

// Operador de asignación - Realiza una copia profunda
solicitud_pila& solicitud_pila::operator=(const solicitud_pila& otra) {
    if (this != &otra) {  // Evitar auto-asignación
        // Primero limpiamos la pila actual
        while (!estaVacia()) {
            pop();
        }
        
        // Luego copiamos los elementos de la otra pila
        solicitudPila_Nodo* actual = otra.tope;
        solicitudPila_Nodo* ultimo = nullptr;
        
        while (actual != nullptr) {
            solicitudPila_Nodo* nuevo = new solicitudPila_Nodo(actual->getDato());
            if (tope == nullptr) {
                tope = nuevo;
            } else {
                ultimo->setSiguiente(nuevo);
            }
            ultimo = nuevo;
            actual = actual->getSiguiente();
            tamano++;
        }
    }
    return *this;
}

// Destructor mejorado
solicitud_pila::~solicitud_pila() {
    while (tope != nullptr) {
        solicitudPila_Nodo* temp = tope;
        tope = tope->getSiguiente();
        delete temp;
    }
    tamano = 0;
}

// Función para agregar una solicitud a la pila (push)
// Recibe un objeto Solicitud por referencia constante
void solicitud_pila::push(const Solicitud& solicitud) {
    try {
        solicitudPila_Nodo* nuevoNodo = new solicitudPila_Nodo(solicitud);
        nuevoNodo->setSiguiente(tope);
        tope = nuevoNodo;
        tamano++;
    } catch (const std::bad_alloc& e) {
        throw std::runtime_error("Error al asignar memoria para el nuevo nodo");
    }
}

// Función para eliminar la solicitud en la parte superior de la pila (pop)
void solicitud_pila::pop() {
    if (!estaVacia()) {
        solicitudPila_Nodo* temp = tope;
        tope = tope->getSiguiente();
        delete temp;
        tamano--;
        return; // Agregamos return aquí para evitar el mensaje de error innecesario
    }
    // Solo mostramos el mensaje si la pila está vacía
    std::cout << "Error: La pila está vacía" << std::endl;
}


// Función para obtener la solicitud en la parte superior de la pila (top)
// Retorna una copia del objeto Solicitud en el tope de la pila
Solicitud solicitud_pila::top() const {
    if (estaVacia()) {
        throw std::runtime_error("Error: La pila está vacía");
    }
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
        // Ruta donde deseas guardar el archivo .dot y .png
        std::string outputDir = "/Users/gio/Desktop/Edd_2s24/lab_edd_2s24/-EDD-Proyecto_202100229/fase2/usuarios/reportes/";

        std::ofstream archivo(outputDir + "pilaSolicitudes.dot");
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
        system("/opt/local/bin/dot -Tpng pilaSolicitudes.dot -o pilaSolicitudes.png");
    } else {
        std::cout << "La pila está vacía. No se puede generar la gráfica." << std::endl;
    }
}