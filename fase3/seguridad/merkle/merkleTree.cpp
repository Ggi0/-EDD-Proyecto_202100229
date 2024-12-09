#include "merkleTree.h"
#include "../sha256.h"
#include "globales_merkle.h"

merkle::merkle(){
    topHash = nullptr;
    primeroData = nullptr;
    ultimoData = nullptr;
    dot = "";
    pos = 0;
}

merkle::~merkle(){
    postOrder(this->topHash);
}

void merkle::agregar(std::string val){
    nodoData *nuevo = new nodoData();
    nuevo->setValor(val);
    nuevo->setUid(globales::uid);
    globales::uid++;

    if(primeroData == nullptr){
        primeroData = nuevo;
        ultimoData = nuevo;

    }else{
        ultimoData->setSig(nuevo);
        ultimoData = nuevo;
    }
}

void merkle::generar(){
    std::string val = "-1";
    int expo = 1, i, pow;

    //Obtener un exponente X
    //tal que el resultado de 2^X sea mayor o igual que el largo de mi lista de data

    while(std::pow(2, expo) < this->largoListaData()){
        expo++;
    }

    pow = std::pow(2, expo);
    this->pos = pow;
    i = this->largoListaData();

    while(i < pow){
        this->agregar(val);
        i++;
    }

    this->topHash = new nodoHash();
    this->crearArbol(this->topHash, expo);
    this->generarHash(this->topHash, pow);
}

void merkle::crearArbol(nodoHash* top, int expo){
    top->setUid(globales::uid);
    globales::uid++;

    if(expo > 0){
        top->setDrcha(new nodoHash());
        top->setIzq(new nodoHash());

        this->crearArbol(top->getIzq(), expo - 1);
        this->crearArbol(top->getDrcha(), expo - 1);  
    }
}

void merkle::generarHash(nodoHash *top, int pow){
    if(top != nullptr){
        this->generarHash(top->getIzq(), pow);
        this->generarHash(top->getDrcha(), pow);
        
        if(top->getDrcha() == nullptr && top->getIzq() == nullptr){
            int temp = pow - this->pos;
            top->setData(this->obtenerData(temp));
            this->pos = this->pos - 1;
            std::string hash = top->getData()->getValor();
            top->setHash(sha256(hash));
        
        }else{
            std::string hash = top->getIzq()->getHash() + top->getDrcha()->getHash();
            top->setHash(sha256(hash));
        }
    }
}

void merkle::generarDot(){
    // Ruta donde deseas guardar el archivo .dot y .png
    std::string outputDir = "/Users/gio/Desktop/Edd_2s24/lab_edd_2s24/-EDD-Proyecto_202100229/fase3/usuarios/reportes/";

    std::ofstream outfile (outputDir + "merkleTree.dot");
    outfile << "graph {" << std::endl;

    this->generarDotRec(this->topHash, outfile);

    outfile << "}" << std::endl;
    outfile.close();

    // Comando para generar el archivo .png usando dot, especificando la ruta completa
    std::string dotCommand = "/opt/local/bin/dot -Tpng " + outputDir + "merkleTree.dot -o " + outputDir + "merkleTree.png";

    // Ejecutar el comando
    int returnCode = system(dotCommand.c_str());

    if(returnCode == 0){std::cout << "(arbol merkle) Command executed successfully." << std::endl;}
    else{std::cout << "(arbol merkle) Command execution failed or returned non-zero: " << returnCode << std::endl;}  
}


void merkle::generarDotRec(nodoHash *top, std::ofstream &f) {
    if (top == nullptr) return;

    // Añadimos estilo al nodo que contiene el hash.
    f << std::to_string(top->getUid()) + "[label = \"" + top->getHash() + "\" style=filled fillcolor=lightblue shape=ellipse];" << std::endl;

    // Si el nodo tiene un hijo izquierdo, se conecta
    if (top->getIzq() != nullptr) {
        f << std::to_string(top->getUid()) + " -- " + std::to_string(top->getIzq()->getUid()) + ";" << std::endl;
    }

    // Si el nodo tiene un hijo derecho, se conecta
    if (top->getDrcha() != nullptr) {
        f << std::to_string(top->getUid()) + " -- " + std::to_string(top->getDrcha()->getUid()) + ";" << std::endl;
    }

    // Llamada recursiva para hijos izquierdo y derecho
    this->generarDotRec(top->getIzq(), f);
    this->generarDotRec(top->getDrcha(), f);

    // Si el nodo contiene datos adicionales (JSON)
    if (top->getData() != nullptr) {
        // Escapar el contenido del JSON para que sea visualmente agradable
        std::string valor = top->getData()->getValor();
        std::string jsonFormateado;
        int nivel = 0;

        for (char c : valor) {
            if (c == '{' || c == '[') {
                jsonFormateado += c;
                jsonFormateado += "\\l";  // Salto de línea para Graphviz
                nivel++;
                jsonFormateado += std::string(nivel * 4, ' '); // Sangría de 4 espacios por nivel
            } else if (c == '}' || c == ']') {
                jsonFormateado += "\\l";
                nivel--;
                jsonFormateado += std::string(nivel * 4, ' ');
                jsonFormateado += c;
            } else if (c == ',') {
                jsonFormateado += c;
                jsonFormateado += "\\l";
                jsonFormateado += std::string(nivel * 4, ' ');
            } else {
                jsonFormateado += c;
            }
        }

        // Añadir el nodo de datos al archivo .dot con estilo y color pastel
        f << std::to_string(top->getData()->getUid()) + "[label = \"" + jsonFormateado + "\" style=filled fillcolor=lightyellow shape=rect];" << std::endl;
        f << std::to_string(top->getUid()) + " -- " + std::to_string(top->getData()->getUid()) + ";" << std::endl;
    }
}


int merkle::largoListaData(){
    int len = 0;
    nodoData *aux = primeroData;

    while(aux != nullptr){
        len++;
        aux = aux->getSig();
    }
    return len;
}

nodoData* merkle::obtenerData(int pos){
    nodoData *aux = this->primeroData;

    while(aux != nullptr){
        if(pos == 0) return aux;
        pos = pos - 1;
        aux = aux->getSig();
    }
    return aux;
}

void merkle::postOrder(nodoHash *top){
    if(top != nullptr){
        postOrder(top->getIzq());
        postOrder(top->getDrcha());
        delete top;
    }
}

std::string merkle::getTopHash() const {
    if (this->topHash != nullptr) {
        return this->topHash->getHash(); // Devuelve el hash del nodo raíz
    } else {
        return ""; // Retorna una cadena vacía si el topHash no está inicializado
    }
}