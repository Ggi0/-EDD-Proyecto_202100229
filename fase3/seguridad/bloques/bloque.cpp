#include "bloque.h"  // Incluir el archivo de cabecera de la clase Usuarios


// ---- CONSTRUCTOR -----
Bloque::Bloque(){
    index = 0;
    timestamp = "";
    data = "";
    nonce = "";
    prev = "";
    hash = "";
    rootMerkle = "";
}

Bloque::Bloque(int index, std::string timestamp, std::string data, std::string nonce, std::string prev, std::string hash, std::string rootMerkle){
    this -> index = index;
    this -> timestamp = timestamp;
    this -> data = data;
    this -> nonce = nonce; 
    this -> prev = prev; 
    this -> hash = hash;
    this -> rootMerkle = rootMerkle;
}

// ----- DESTRUCTOR ------
// Constructor de copia
Bloque::Bloque(const Bloque& other) {
    index = other.index;
    timestamp = other.timestamp;
    data = other.data;
    nonce = other.nonce;
    prev = other.prev;
    hash = other.hash;
    rootMerkle = other.rootMerkle;
}

    // Operador de asignación
    Bloque& Bloque::operator=(const Bloque& other) {
        if (this != &other) {
            index = other.index;
            timestamp = other.timestamp;
            data = other.data;
            nonce = other.nonce;
            prev = other.prev;
            hash = other.hash;
            rootMerkle = other.rootMerkle;
            
        }
        return *this;
    }

// Destructor
Bloque::~Bloque() {
    // No necesitas liberar explícitamente `lista_amigos`, ya que el destructor se llama automáticamente
}


// Getters
    int Bloque::getIndex()const{ return index;}
    std::string Bloque::getTimestamp(){ return timestamp;}
    std::string Bloque::getData(){ return data; }
    std::string Bloque::getNonce(){ return nonce; }
    std::string Bloque::getPrev(){ return prev; }
    std::string Bloque::getHash(){ return hash; }
    std::string Bloque::getRootMerkle(){ return rootMerkle; }
    bool Bloque::getInformacionValida() const {
        return informacionValida;
    }



// Setters
    void Bloque::setIndex(int index) { this->index = index; }
    void Bloque::setTimestamp(std::string& timestamp) { this->timestamp = timestamp; }
    void Bloque::setData(std::string& data) { this->data = data; }
    void Bloque::setNonce(std::string& nonce) { this->nonce = nonce; }
    void Bloque::setPrev(std::string& prev) { this->prev = prev; }
    void Bloque::setHash(std::string& hash) { this->hash = hash; }
    void Bloque::setRootMerkle(std::string& rootMerkle) { this->rootMerkle = rootMerkle; }
    void Bloque::setInformacionValida(bool valor) {
        informacionValida = valor;
    }

// ----- METODOS -----
void Bloque::printBloque(){
    std::cout << "===== Informacion del BLOQUE =====" << std::endl;
    std::cout << "index: " << getIndex() << std::endl;
    std::cout << "timeStamp: " << getTimestamp() << std::endl;
    std::cout << "Data: " << getData() << std::endl;
    std::cout << "Nonce: " << getNonce() << std::endl;
    std::cout << "PreviosHash: " << getPrev() << std::endl;
    std::cout << "Hash: " << getHash() << std::endl;
    std::cout << "===== ======================= =====" << std::endl<< std::endl;
}

