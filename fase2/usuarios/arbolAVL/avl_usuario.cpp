#include "avl_usuario.h"

AVL::AVL(){
    this->raiz = nullptr;
}

AVL::~AVL(){
    postOrden(this->raiz, 1);
}

void AVL::insert(Usuarios data){
    this->raiz = insert(this->raiz, data);
}

void AVL::del(Usuarios data){
    this->raiz = del(this->raiz, data);
}

void AVL::preOrden(){
    preOrden(this->raiz);
}

void AVL::inOrden(){
    inOrden(this->raiz);
}

void AVL::postOrden(){
    postOrden(this->raiz, 0);
}

void AVL::graph(){
    // Ruta donde deseas guardar el archivo .dot y .png
    std::string outputDir = "/Users/gio/Desktop/Edd_2s24/lab_edd_2s24/-EDD-Proyecto_202100229/fase2/usuarios/reportes/";

    // Crear el archivo .dot en la ruta especificada
    std::ofstream outfile(outputDir + "AVL.dot");
    outfile << "digraph G {" << std::endl;

    if(raiz != nullptr){
        graph(raiz, outfile);
    }

    outfile << "}" << std::endl;
    outfile.close();

    // Comando para generar el archivo .png usando dot, especificando la ruta completa
    std::string dotCommand = "/opt/local/bin/dot -Tpng " + outputDir + "AVL.dot -o " + outputDir + "AVL.png";

    // Ejecutar el comando
    int returnCode = system(dotCommand.c_str());

    if(returnCode == 0){
        std::cout << "(AVL) Command executed successfully." << std::endl;
        }
    else{
        std::cout << "(AVL) Command execution failed or returned non-zero: " << returnCode << std::endl;
    }
}

void AVL::graph(NodoAVL *raiz, std::ofstream &f){
    if(raiz != nullptr){
        std::stringstream oss;
        oss << raiz;
        std::string nombre = oss.str();

        f << "Nodo" + nombre + "[label = \"" + raiz->getData().getCorreo() + "\"]" << std::endl;
    
        if(raiz->getIzq() != nullptr){
            oss.str("");
            oss << raiz->getIzq();
            std::string izquierda = oss.str();
            f << "Nodo" << nombre + "->Nodo" + izquierda << std::endl;
            //Nodo<nombre_raiz>->Nodo<izquierda>;
        }

        if(raiz->getDrcha() != nullptr){
            oss.str("");
            oss << raiz->getDrcha();
            std::string derecha = oss.str();
            f << "Nodo" << nombre + "->Nodo" + derecha << std::endl;
            //Nodo<nombre_raiz>->Nodo<derecha>;
        }

        this->graph(raiz->getIzq(), f);
        this->graph(raiz->getDrcha(), f);
    }
}

// ---------- PRE ORDEN ------------------
void AVL::preOrden(NodoAVL *raiz){
    if(raiz != nullptr){
        std::cout << raiz->getData().getCorreo() << ", ";
        preOrden(raiz->getIzq());
        preOrden(raiz->getDrcha());
    }
}

// ---------- IN ORDEN ------------------
void AVL::inOrden(NodoAVL *raiz){
    if(raiz != nullptr){
        preOrden(raiz->getIzq());
        std::cout << raiz->getData().getCorreo() << ", ";
        preOrden(raiz->getDrcha());
    }
}

// ---------- POST ORDEN ------------------
void AVL::postOrden(NodoAVL *raiz, bool accion){
    if(raiz != nullptr){
        postOrden(raiz->getIzq(), accion);
        postOrden(raiz->getDrcha(), accion);
        if(!accion){std::cout << raiz->getData().getCorreo() << ", ";}
        else{delete raiz;}
    }
}

NodoAVL* AVL::insert(NodoAVL *raiz, Usuarios data){
    if(raiz == nullptr){
        raiz = new NodoAVL(data);
    }
    else if(data.getCorreo() < raiz->getData().getCorreo()){
        raiz->setIzq(insert(raiz->getIzq(), data));
    }
    else if(data.getCorreo() > raiz->getData().getCorreo()){
        raiz->setDrcha(insert(raiz->getDrcha(), data));
    }

    raiz->setAltura(alturaMaxima(obtenerAltura(raiz->getIzq()), obtenerAltura(raiz->getDrcha())) + 1);

    if(obtenerBalance(raiz) > 1){
        if(obtenerBalance(raiz->getDrcha()) < 0){
            raiz->setDrcha(rotacionDerecha(raiz->getDrcha()));
            raiz = rotacionIzquierda(raiz);
        } else {
            raiz = rotacionIzquierda(raiz);
        }
    }

    if(obtenerBalance(raiz) < -1){
        if(obtenerBalance(raiz->getIzq()) > 0){
            raiz->setIzq(rotacionIzquierda(raiz->getIzq()));
            raiz = rotacionDerecha(raiz);
        }else{
            raiz = rotacionDerecha(raiz);
        }
    }
    return raiz;
}

NodoAVL* AVL::del(NodoAVL* raiz, Usuarios data){
    if(raiz == nullptr) return raiz;
    else if(data.getCorreo() < raiz->getData().getCorreo()){
        raiz->setIzq(del(raiz->getIzq(), data));
    }
    else if(data.getCorreo() > raiz->getData().getCorreo()){
        raiz->setDrcha(del(raiz->getDrcha(), data));
    }
    else{
        if(raiz->esHoja()){
            delete raiz;
            raiz = nullptr;
        
        }else if (raiz->tieneUnHijo()){
            raiz = raiz->obtenerHijoUnico();

        }else if (raiz->tieneDosHijos()){
            NodoAVL *temp = obtenerMayorDeMenores(raiz->getIzq());
            raiz->setData(temp->getData());
            raiz->setIzq(del(raiz->getIzq(), temp->getData()));
        }
    }

    if(raiz == nullptr){
        return raiz;
    }

    raiz->setAltura(alturaMaxima(obtenerAltura(raiz->getIzq()), obtenerAltura(raiz->getDrcha())) + 1);

    if(obtenerBalance(raiz) > 1){
        if(obtenerBalance(raiz->getDrcha()) < 0){
            raiz->setDrcha(rotacionDerecha(raiz->getDrcha()));
            raiz = rotacionIzquierda(raiz);
        
        }else{
            raiz = rotacionIzquierda(raiz);
        }
    } 

    if(obtenerBalance(raiz) < -1){
        if(obtenerBalance(raiz->getIzq()) > 0){
            raiz->setIzq(rotacionIzquierda(raiz->getIzq()));
            raiz = rotacionDerecha(raiz);
        }else{
            raiz = rotacionDerecha(raiz);
        }
    }

    return raiz; 
}

NodoAVL* AVL::rotacionIzquierda(NodoAVL *raiz){
    NodoAVL *raizDerecha = raiz->getDrcha();
    NodoAVL *temp = raizDerecha->getIzq();

    raizDerecha->setIzq(raiz);
    raiz->setDrcha(temp);

    raiz->setAltura(alturaMaxima(obtenerAltura(raiz->getIzq()), obtenerAltura(raiz->getDrcha())) + 1);
    raizDerecha->setAltura(alturaMaxima(obtenerAltura(raizDerecha->getIzq()), obtenerAltura(raizDerecha->getDrcha())) + 1);

    return raizDerecha;
}

NodoAVL* AVL::rotacionDerecha(NodoAVL *raiz){
    NodoAVL *raizIzquierda = raiz->getIzq();
    NodoAVL *temp = raizIzquierda->getDrcha();

    raizIzquierda->setDrcha(raiz);
    raiz->setIzq(temp);

    raiz->setAltura(alturaMaxima(obtenerAltura(raiz->getIzq()), obtenerAltura(raiz->getDrcha())) + 1);
    raizIzquierda->setAltura(alturaMaxima(obtenerAltura(raizIzquierda->getIzq()), obtenerAltura(raizIzquierda->getDrcha())) + 1);

    return raizIzquierda;
}

NodoAVL* AVL::obtenerMayorDeMenores(NodoAVL *raiz){
    while(raiz->getDrcha() != nullptr){
        raiz = raiz->getDrcha();
    }
    return raiz;
}

int AVL::obtenerAltura(NodoAVL *raiz){
    if(raiz == nullptr) return 0;
    return raiz->getAltura();
}

int AVL::alturaMaxima(int izq, int drcha){
    if(izq >= drcha) return izq;
    return drcha;
}

int AVL::obtenerBalance(NodoAVL *raiz){
    return obtenerAltura(raiz->getDrcha()) - obtenerAltura(raiz->getIzq());
}

// Método para obtener la raíz del árbol
NodoAVL* AVL::getRaiz() const {
    return raiz;
}

// Método público para iniciar la búsqueda por correo
NodoAVL* AVL::buscarPorCorreo(const std::string& correo) const {
    return buscarPorCorreoRecursivo(raiz, correo);
}

// Método privado para la búsqueda recursiva por correo
NodoAVL* AVL::buscarPorCorreoRecursivo(NodoAVL* nodo, const std::string& correo) const {
    if (nodo == nullptr || nodo->getData().getCorreo() == correo) {
        return nodo;
    }
    
    if (correo < nodo->getData().getCorreo()) {
        return buscarPorCorreoRecursivo(nodo->getIzq(), correo);
    } else {
        return buscarPorCorreoRecursivo(nodo->getDrcha(), correo);
    }
}

// buscar usuarios por ID 
NodoAVL* AVL::buscarPorID(int ID) const {
    return buscarPorIDRecursivo(raiz, ID);
}

NodoAVL* AVL::buscarPorIDRecursivo(NodoAVL* nodo, int ID) const {
    if (nodo == nullptr || nodo->getData().getID() == ID) {
        return nodo;
    }
    
    if (ID < nodo->getData().getID()) {
        return buscarPorIDRecursivo(nodo->getIzq(), ID);
    } else {
        return buscarPorIDRecursivo(nodo->getDrcha(), ID);
    }
}


// Método público para eliminar un nodo a partir del correo
void AVL::delPorCorreo(std::string correo) {
    NodoAVL* nodoAEliminar = buscarPorCorreo(correo);
    if (nodoAEliminar == nullptr) {
        std::cout << "No se encontró el usuario con el correo: " << correo << std::endl;
        return;
    }
    this->raiz = delPorCorreo(this->raiz, correo);
}

// Método privado que realiza la eliminación del nodo basado en el correo
NodoAVL* AVL::delPorCorreo(NodoAVL* raiz, std::string correo) {
    // Caso base: si el nodo es nulo
    if (raiz == nullptr) return nullptr;

    // Buscar el nodo a eliminar
    std::string correoActual = raiz->getData().getCorreo();
    
    if (correo < correoActual) {
        raiz->setIzq(delPorCorreo(raiz->getIzq(), correo));
    }
    else if (correo > correoActual) {
        raiz->setDrcha(delPorCorreo(raiz->getDrcha(), correo));
    }
    else { // Encontramos el nodo a eliminar
        
        // Caso 1: Nodo hoja
        if (raiz->getIzq() == nullptr && raiz->getDrcha() == nullptr) {
            delete raiz;
            return nullptr;
        }
        
        // Caso 2: Nodo con un hijo
        if (raiz->getIzq() == nullptr) {
            NodoAVL* temp = raiz->getDrcha();
            delete raiz;
            return temp;
        }
        if (raiz->getDrcha() == nullptr) {
            NodoAVL* temp = raiz->getIzq();
            delete raiz;
            return temp;
        }
        
        // Caso 3: Nodo con dos hijos
        NodoAVL* sucesor = obtenerMayorDeMenores(raiz->getIzq());
        // Copiamos los datos del sucesor al nodo actual
        raiz->setData(sucesor->getData());
        // Eliminamos el sucesor (que ahora está duplicado)
        raiz->setIzq(delPorCorreo(raiz->getIzq(), sucesor->getData().getCorreo()));
    }

    // Si el árbol quedó vacío después de la eliminación
    if (raiz == nullptr) return raiz;

    // Actualizar altura
    raiz->setAltura(alturaMaxima(obtenerAltura(raiz->getIzq()), obtenerAltura(raiz->getDrcha())) + 1);

    // Obtener el factor de balance
    int balance = obtenerBalance(raiz);

    // Casos de balanceo
    // Izquierda Izquierda
    if (balance < -1 && obtenerBalance(raiz->getIzq()) <= 0) {
        return rotacionDerecha(raiz);
    }

    // Izquierda Derecha
    if (balance < -1 && obtenerBalance(raiz->getIzq()) > 0) {
        raiz->setIzq(rotacionIzquierda(raiz->getIzq()));
        return rotacionDerecha(raiz);
    }

    // Derecha Derecha
    if (balance > 1 && obtenerBalance(raiz->getDrcha()) >= 0) {
        return rotacionIzquierda(raiz);
    }

    // Derecha Izquierda
    if (balance > 1 && obtenerBalance(raiz->getDrcha()) < 0) {
        raiz->setDrcha(rotacionDerecha(raiz->getDrcha()));
        return rotacionIzquierda(raiz);
    }

    return raiz;
}