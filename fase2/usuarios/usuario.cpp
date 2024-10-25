#include "usuario.h"  // Incluir el archivo de cabecera de la clase Usuarios


// Inicializar el contador de ID
int Usuarios::contadorID = 0;

// ---- CONSTRUCTOR -----
Usuarios::Usuarios(){
    ID = 0;
    nombres = "";
    apellidos = "";
    fechaN = "";
    correo = "";
    contrasenia = "";
}

Usuarios::Usuarios(std::string nombres, std::string apellidos, std::string fechaN, std::string correo, std::string contrasenia){
    this -> ID = ++contadorID;
    this -> nombres = nombres;
    this -> apellidos = apellidos;
    this -> fechaN = fechaN; 
    this -> correo = correo; 
    this -> contrasenia = contrasenia;
}

// ----- DESTRUCTOR ------
Usuarios::~Usuarios() {
}

// Getters
int Usuarios::getID()const{ return ID;}
std::string Usuarios::getNombres(){ return nombres;}
std::string Usuarios::getApellidos(){ return apellidos; }
std::string Usuarios::getFechaN(){ return fechaN; }
std::string Usuarios::getCorreo(){ return correo; }
std::string Usuarios::getContrasenia(){ return contrasenia; }

arrayList_soli& Usuarios::getListaSolicitudes() { return listaSolicitudes; }
solicitud_pila& Usuarios::getPilaSolicitudes() { return pilaSolicitudes; }
listaSimpleEnlazada& Usuarios::getLista_amigos() { return lista_amigos; }
BST& Usuarios::getBST_feedPublicaciones(){ return bst_feedPublicaciones;}

// Setters
void Usuarios::setID(int ID) { this->ID = ID; }
void Usuarios::setNombres(std::string& nombre) { this->nombres = nombre; }
void Usuarios::setApellidos(std::string& apellidos) { this->apellidos = apellidos; }
void Usuarios::setFechaN(std::string& fecha) { this->fechaN = fecha; }
void Usuarios::setCorreo(std::string& correo) { this->correo = correo; }
void Usuarios::setContrasenia(std::string& contrasena) { this->contrasenia = contrasena; }

void Usuarios::setListaSolicitudes(const arrayList_soli& listaSolicitudes) {
    this->listaSolicitudes = listaSolicitudes;
}

void Usuarios::setPilaSolicitudes(const solicitud_pila& pilaSolicitudes) {
    this->pilaSolicitudes = pilaSolicitudes;
}

void Usuarios::setLista_amigos(const listaSimpleEnlazada& lista_amigos) {
    this->lista_amigos = lista_amigos;
}

void Usuarios::setBST_feedPublicaciones(const BST& bst_feedPublicaciones){
    this->bst_feedPublicaciones = bst_feedPublicaciones;
}

// ----- METODOS -----
void Usuarios::printUsuario(){
    std::cout << "===== Informacion del Usuario =====" << std::endl;
    std::cout << "ID: " << getID() << std::endl;
    std::cout << "Nombre: " << getNombres() << std::endl;
    std::cout << "Apellidos: " << getApellidos() << std::endl;
    std::cout << "Fecha de Nacimiento: " << getFechaN() << std::endl;
    std::cout << "Correo Electronico: " << getCorreo() << std::endl;
    std::cout << "Contrasena: " << getContrasenia() << std::endl; 
    std::cout << "Numero de solicitudes enviadas (lista): " << listaSolicitudes.size() << std::endl;
    std::cout << "Numero de solicitudes recibidas (pila): " << pilaSolicitudes.size() << std::endl;
    std::cout << "Numero de amigos: " << lista_amigos.size() << std::endl;
    std::cout << "===== ======================= =====" << std::endl<< std::endl;
}



// ----------- SOLICITUDES A PILA -----------------
void Usuarios::agregarSolicitud(const Solicitud& solicitud) {
    listaSolicitudes.append(solicitud);
}

void Usuarios::agregarSolicitudPila(const Solicitud& solicitud) {
    pilaSolicitudes.push(solicitud);
}


// ------------- LISTA AMIGOS -------------
void Usuarios::agregarAmigo(int idAmigo) {
    lista_amigos.append(idAmigo);
}

void Usuarios::eliminarAmigo(int idAmigo) {
    int index = lista_amigos.findIndex(idAmigo);
    if (index != -1) {
        lista_amigos.removeAt(index);
    }
}

bool Usuarios::esAmigo(int idAmigo) const {
    return lista_amigos.findIndex(idAmigo) != -1;
}

void Usuarios::imprimirAmigos() {
    //std::cout << "Lista de amigos (IDs): ";
    lista_amigos.print();
}

/*
void Usuarios::graficaAmigos() const {
    if (lista_amigos.getPrimero() != nullptr) {
        std::ofstream archivo("listaAmigos.dot");
        archivo << "digraph G {" << std::endl;
        archivo << "    rankdir=LR;" << std::endl; // Configuración para colocar nodos de izquierda a derecha
        archivo << "    node [shape=record];" << std::endl;

        Nodo* actual = lista_amigos.getPrimero();
        int contador = 0;

        while (actual != nullptr) {
            int amigoID = actual->getData();
            Usuarios* amigo = listaGlobal_usuarios.buscarUsuarioPorID(amigoID);

            if (amigo != nullptr) {
                archivo << "    node" << contador << " [label=\"{" 
                        << "ID: " << amigo->getID() << "\\n"
                        << "Nombre: " << amigo->getNombres() << " " << amigo->getApellidos() << "\\n"
                        << "Correo: " << amigo->getCorreo() << "}\"];" << std::endl;
            }

            if (actual->getSig() != nullptr) {
                archivo << "    node" << contador << " -> node" << contador + 1 << ";" << std::endl;
            }

            actual = actual->getSig();
            contador++;
        }

        archivo << "}" << std::endl;
        archivo.close();

        // Comando para generar la imagen a partir del archivo .dot
        system("dot -Tpng listaAmigos.dot -o listaAmigos.png");
    } else {
        std::cout << "La lista de amigos está vacía. No se puede generar la gráfica." << std::endl;
    }
}

*/


// Operador de comparación para ordenar usuarios por correo
bool Usuarios::operator<(const Usuarios& otro) const {
    return this->correo < otro.correo;
}

void Usuarios::graficar_fecha(const std::string& fecha) const {
    // Ruta donde se guardarán los archivos
    std::string outputDir = "/Users/gio/Desktop/Edd_2s24/lab_edd_2s24/-EDD-Proyecto_202100229/fase2/usuarios/reportes/";

    std::ofstream archivo(outputDir + "feed_publicaciones.dot");
    if (!archivo.is_open()) {
        std::cout << "Error al abrir el archivo para escritura" << std::endl;
        return;
    }

    // Iniciar el grafo
    archivo << "digraph G {\n";
    archivo << "    rankdir=TB;\n";  // Top to Bottom direction
    archivo << "    node [shape=record];\n\n";
    
    // Graficar el BST y la lista de publicaciones
    if (bst_feedPublicaciones.getRaiz() != nullptr) {
        graficar_bst_recursivo(bst_feedPublicaciones.getRaiz(), fecha, archivo);
    } else {
        archivo << "    empty[label=\"BST Vacío\"];\n";
    }
    
    archivo << "}\n";
    archivo.close();
    
    // Generar el PNG
    std::string cmd = "/opt/local/bin/dot -Tpng " + outputDir + "feed_publicaciones.dot -o " + outputDir + "feed_publicaciones.png";
    int returnCode = system(cmd.c_str());
    if (returnCode == 0) {
        std::cout << "Gráfico generado exitosamente: feed_publicaciones.png" << std::endl;
    } else {
        std::cout << "Error al generar el gráfico. Código: " << returnCode << std::endl;
    }
}

void Usuarios::graficar_bst_recursivo(NodoBST* nodo, const std::string& fecha_buscada, std::ofstream& archivo) const {
    if (nodo == nullptr) return;

    // Generar un ID único para el nodo usando su dirección de memoria
    std::string nodeId = "node_" + std::to_string(reinterpret_cast<uintptr_t>(nodo));
    
    // Configurar el color del nodo si coincide con la fecha buscada
    std::string color = (nodo->getFechaID() == fecha_buscada) ? "style=filled,fillcolor=lightblue" : "";
    
    // Crear el nodo en el grafo
    archivo << "    " << nodeId << "[label=\"{Fecha: " << nodo->getFechaID() << "}\", " << color << "];\n";

    // Enlaces a los hijos
    if (nodo->getIzq() != nullptr) {
        std::string leftId = "node_" + std::to_string(reinterpret_cast<uintptr_t>(nodo->getIzq()));
        archivo << "    " << nodeId << " -> " << leftId << " [label=\"Izq\"];\n";
        graficar_bst_recursivo(nodo->getIzq(), fecha_buscada, archivo);
    }

    if (nodo->getDrcha() != nullptr) {
        std::string rightId = "node_" + std::to_string(reinterpret_cast<uintptr_t>(nodo->getDrcha()));
        archivo << "    " << nodeId << " -> " << rightId << " [label=\"Der\"];\n";
        graficar_bst_recursivo(nodo->getDrcha(), fecha_buscada, archivo);
    }

    // Si es el nodo con la fecha buscada, graficar su lista de publicaciones
    if (nodo->getFechaID() == fecha_buscada) {
        graficar_lista_publicaciones(nodo, nodeId, archivo);
    }
}

void Usuarios::graficar_lista_publicaciones(NodoBST* nodo, const std::string& nodeId, std::ofstream& archivo) const {
    const ListaDoblementeEnlazadaP& lista = nodo->getListaPublicaciones();
    PublicacionNodo* actual = lista.getPrimero();
    
    if (actual == nullptr) {
        return; // No hay publicaciones que mostrar
    }

    // Crear un subgrafo para las publicaciones
    archivo << "\n    // Subgrafo para las publicaciones\n";
    archivo << "    subgraph cluster_publications {\n";
    archivo << "        style=dashed;\n";
    archivo << "        label=\"Publicaciones\";\n";

    // Graficar cada publicación
    int i = 0;
    PublicacionNodo* temp = actual;
    while (temp != nullptr) {
        std::string pubId = "pub_" + std::to_string(i);
        
        // Crear el nodo de publicación
        archivo << "        " << pubId << " [shape=record, label=\"{";
        archivo << "ID: " << temp->getData().getID_publi() << "\\n";
        archivo << "Correo: " << temp->getData().getCorreoP() << "\\n";
        archivo << "Contenido: " << temp->getData().getContenido() << "\\n";
        archivo << "Fecha: " << temp->getData().getFecha() << "\\n";
        archivo << "Hora: " << temp->getData().getHora() << "}\"];\n";

        // Crear enlace con el siguiente nodo
        if (temp->getSig() != nullptr) {
            archivo << "        " << pubId << " -> pub_" << (i + 1) << ";\n";
        }

        temp = temp->getSig();
        i++;
    }
    
    archivo << "    }\n\n";
    
    // Crear enlace desde el nodo BST a la primera publicación
    archivo << "    " << nodeId << " -> pub_0 [color=red, label=\"Publicaciones\"];\n";
}




void Usuarios::generarGraficoBSTPersonal() const {
    bst_feedPublicaciones.graph();
}


/*
// version estable

void Usuarios::graficar_fecha(const std::string& fecha) const {


    // Ruta donde deseas guardar el archivo .dot y .png
    std::string outputDir = "/Users/gio/Desktop/Edd_2s24/lab_edd_2s24/-EDD-Proyecto_202100229/fase2/usuarios/reportes/";

    std::ofstream archivo(outputDir + "feed_publicaciones.dot");
    archivo << "digraph G {" << std::endl;
    archivo << "    node [shape=record];" << std::endl;
    
    // Llamada a función auxiliar para graficar el BST
    graficar_bst_recursivo(bst_feedPublicaciones.getRaiz(), fecha, archivo);
    
    archivo << "}" << std::endl;
    archivo.close();
    
    // Generar imagen PNG a partir del archivo DOT
    std::string cmd = "/opt/local/bin/dot -Tpng " + outputDir + "feed_publicaciones.dot -o" + outputDir + "feed_publicaciones.png";
    int returnCode = system(cmd.c_str());
    if(returnCode == 0){
        std::cout << "Command executed successfully. (BST - fecha)" << std::endl;
        std::cout << "Gráfico generado: feed_publicaciones_" << this->ID << ".png" << std::endl;

        }
    else{
        std::cout << "Command execution failed or returned non-zero: " << returnCode << std::endl;
    }
    
}

void Usuarios::graficar_bst_recursivo(NodoBST* nodo, const std::string& fecha_buscada, std::ofstream& archivo) const {
    if (nodo == nullptr) return;

    std::string color = (nodo->getFechaID() == fecha_buscada) ? "style=filled,fillcolor=lightblue" : "";
    
    archivo << "    node" << nodo << " [label=\"{Fecha: " << nodo->getFechaID() << "}\", " << color << "];" << std::endl;

    if (nodo->getIzq() != nullptr) {
        archivo << "    node" << nodo << " -> node" << nodo->getIzq() << " [label=\"Izq\"];" << std::endl;
        graficar_bst_recursivo(nodo->getIzq(), fecha_buscada, archivo);
    }

    if (nodo->getDrcha() != nullptr) {
        archivo << "    node" << nodo << " -> node" << nodo->getDrcha() << " [label=\"Der\"];" << std::endl;
        graficar_bst_recursivo(nodo->getDrcha(), fecha_buscada, archivo);
    }

    // Si es el nodo buscado, graficar su lista de publicaciones
    if (nodo->getFechaID() == fecha_buscada) {
        graficar_lista_publicaciones(nodo, archivo);
    }
}

void Usuarios::graficar_lista_publicaciones(NodoBST* nodo, std::ofstream& archivo) const {
    const ListaDoblementeEnlazadaP& lista = nodo->getListaPublicaciones();
    PublicacionNodo* pubNodo = lista.getPrimero();
    int i = 0;

    while (pubNodo != nullptr) {
        std::string pubId = "pub" + std::to_string(reinterpret_cast<long>(pubNodo));
        archivo << "    " << pubId << " [shape=record, label=\"{";
        archivo << "ID: " << pubNodo->getData().getID_publi() << "\\n";
        archivo << "Correo: " << pubNodo->getData().getCorreoP() << "\\n";
        archivo << "Contenido: " << pubNodo->getData().getContenido() << "\\n";
        archivo << "Fecha: " << pubNodo->getData().getFecha() << "\\n";
        archivo << "Hora: " << pubNodo->getData().getHora() << "}\"];" << std::endl;

        if (i == 0) {
            archivo << "    node" << nodo << " -> " << pubId << " [label=\"Publicaciones\", color=red];" << std::endl;
        } else {
            std::string prevPubId = "pub" + std::to_string(reinterpret_cast<long>(pubNodo->getPrev()));
            archivo << "    " << prevPubId << " -> " << pubId << ";" << std::endl;
        }

        pubNodo = pubNodo->getSig();
        i++;
    }
}


*/