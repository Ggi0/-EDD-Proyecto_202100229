#include "Usuarios.h"  // Incluir el archivo de cabecera de la clase Usuarios
#include <iostream>    // Incluir iostream para usar std::cout y std::endl
#include "global_data.h"
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
int Usuarios::getID(){ return ID;}
std::string Usuarios::getNombres(){ return nombres;}
std::string Usuarios::getApellidos(){ return apellidos; }
std::string Usuarios::getFechaN(){ return fechaN; }
std::string Usuarios::getCorreo(){ return correo; }
std::string Usuarios::getContrasenia(){ return contrasenia; }

arrayList_soli& Usuarios::getListaSolicitudes() { return listaSolicitudes; }
solicitud_pila& Usuarios::getPilaSolicitudes() { return pilaSolicitudes; }
listaSimpleEnlazada& Usuarios::getLista_amigos() { return lista_amigos; }
ListaCircular_Dpp& Usuarios::getLista_publicacionesP() {return lista_publicacionesP;}

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

void Usuarios::setLista_publicacionesP(const ListaCircular_Dpp& lista_publicacionesP) {
    this->lista_publicacionesP = lista_publicacionesP;
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
    std::cout << "Numero de publicaciones: " << lista_publicacionesP.obtenerTamanio() << std::endl;
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

bool Usuarios::esAmigo(int idAmigo) {
    return lista_amigos.findIndex(idAmigo) != -1;
}

void Usuarios::imprimirAmigos() {
    //std::cout << "Lista de amigos (IDs): ";
    lista_amigos.print();
}

// ------- DOBLEMENTE CIRCULAR PUBLICACIONES ------------
// Método para agregar una publicación
void Usuarios::agregarPublicacion(const Publicacion& publicacion) {
    lista_publicacionesP.insertarFinal(publicacion);
}

// Método para eliminar una publicación
void Usuarios::eliminarPublicacion(const std::string& correo) {
    lista_publicacionesP.eliminarPublicacion(correo);
}

// Método para verificar si existe una publicación
bool Usuarios::tienePublicacion(const std::string& correo) const {
    return lista_publicacionesP.buscarPublicacion(correo) != nullptr;
}

// Método para imprimir todas las publicaciones
void Usuarios::imprimirPublicaciones() const {
    std::cout << "Publicaciones del usuario:" << std::endl;
    lista_publicacionesP.mostrarLista();
}




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
