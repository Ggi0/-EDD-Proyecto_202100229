#include "huffman.h"

Huffman::Huffman(){
    raiz = nullptr;

    for(int i = 0; i < 256; i++){
        this->codigos[i] = "";
    }
}

Huffman::~Huffman(){
    eliminar(this->raiz);
}

std::string Huffman::comprimir(std::string texto){
    std::string comprimido = "";

    for(char c: texto){
        comprimido+=codigos[(unsigned char)c];
    }
    return comprimido;
}

std::string Huffman::descomprimir(std::string comprimido) {
    if(raiz == nullptr) {
        std::cerr << "Error: Árbol no inicializado" << std::endl;
        return "";
    }

    std::string texto = "";
    Nodo_huff *actual = this->raiz;

    for(char c: comprimido) {
        if(actual == nullptr) {
            std::cerr << "Error: Nodo nulo encontrado durante la descompresión" << std::endl;
            return texto;
        }

        if(c == '0') {
            actual = actual->izq;
        } else {
            actual = actual->der;
        }

        if(actual != nullptr && actual->izq == nullptr && actual->der == nullptr) {
            texto += actual->c;
            actual = this->raiz;
        }
    }

    return texto;
}

void Huffman::crearArbol(std::string s){
    //Construyendo lista simplemente enlazada
    while(s != ""){
        Nodo_huff *nuevo = new Nodo_huff(s[0]);
        nuevo->n = std::count(s.begin(), s.end(), nuevo->c);
        this->insertarCaracter(nuevo);
        s.erase(std::remove(s.begin(), s.end(), nuevo->c), s.end());
    }

    while(this->raiz->sig != nullptr){
        Nodo_huff *derecha = this->raiz;
        Nodo_huff *izquierda = this->raiz->sig;

        this->raiz = izquierda->sig;

        Nodo_huff *nueva_raiz = new Nodo_huff('~');
        nueva_raiz->n = izquierda->n + derecha->n;
        nueva_raiz->izq = izquierda;
        nueva_raiz->der = derecha;

        insertarCaracter(nueva_raiz);
    }
}

void Huffman::insertarCaracter(Nodo_huff *nuevo){
    //Insertando caracter en lista simplemente enlazada
    if(this->raiz == nullptr){
        this->raiz = nuevo;
    
    }else{
        Nodo_huff *aux = this->raiz;
        while(aux->sig != nullptr){
            if((nuevo->n < aux->sig->n) || 
            (nuevo->n == aux->sig->n && nuevo->c < aux->sig->c)){
                nuevo->sig = aux->sig;
                aux->sig = nuevo;
                break;
            }
            aux = aux->sig;
        }

        if(aux->sig == nullptr){
            aux->sig = nuevo;
        }
    }
}

void Huffman::crearCodigosHuffman(Nodo_huff *raiz, std::string codigo){
    if(raiz == nullptr) return;

    if(raiz->izq == nullptr && raiz->der == nullptr){
        codigos[(unsigned char)raiz->c] = codigo;
    }

   crearCodigosHuffman(raiz->izq, codigo + "0");
   crearCodigosHuffman(raiz->der, codigo + "1"); 
}

void Huffman::graficar(){
    // Ruta donde deseas guardar el archivo .dot y .png
    std::string outputDir = "/Users/gio/Desktop/Edd_2s24/lab_edd_2s24/-EDD-Proyecto_202100229/fase3/usuarios/reportes/";
    std::ofstream outfile (outputDir + "huffman.dot");
    outfile << "digraph G {" << std::endl;

    if(raiz != nullptr){
        graficar(raiz, outfile);
    }

    outfile << "}" << std::endl;
    outfile.close();
    std::string dotCommand = "/opt/local/bin/dot -Tpng " + outputDir + "huffman.dot -o" + outputDir + "huffman.png";

    // Ejecutar el comando
    int returnCode = system(dotCommand.c_str());

    if(returnCode == 0){std::cout << "(Huffman) Command executed successfully." << std::endl;}
    else{std::cout << "(huffman) Command execution failed or returned non-zero: " << returnCode << std::endl;}
}

void Huffman::imprimirCodigos(){
    for(int i = 0; i < 256; i++){
        if(codigos[i] != ""){
            std::cout << char(i) << ": " << codigos[i] << '\n';
        }
    }
}

// Función auxiliar para escapar caracteres especiales en DOT
std::string Huffman::escaparCaracterDOT(const std::string& str) const {
    std::string resultado;
    for (char c : str) {
        if (c == '"') {
            resultado += "\\\"";
        } else {
            resultado += c;
        }
    }
    return resultado;
}

// Modificar el método graficar para usar la función de escape
void Huffman::graficar(Nodo_huff *raiz, std::ofstream &f) {
    if(raiz != nullptr) {
        std::ostringstream oss;
        oss << raiz;
        std::string nombre = oss.str();
        
        // Escapar el carácter para el label
        std::string caracterEscapado = escaparCaracterDOT(std::string(1, raiz->c));
                                                                                                                                                                    // "                                                    
        f << "Nodo" + nombre + "[label = \"" + caracterEscapado + "(" 
          + std::to_string(raiz->n) + ")" + "\"]" << std::endl;
        
        if(raiz->izq != nullptr) {
            oss.str("");
            oss << raiz->izq;
            std::string izquierda = oss.str();
            f << "Nodo" + nombre + "->Nodo" + izquierda + "[label = \"0\"];" << std::endl;
        }
        
        if(raiz->der != nullptr) {
            oss.str("");
            oss << raiz->der;
            std::string derecha = oss.str();
            f << "Nodo" + nombre + "->Nodo" + derecha + "[label = \"1\"];" << std::endl;
        }
        
        this->graficar(raiz->izq, f);
        this->graficar(raiz->der, f);
    }
}


void Huffman::eliminar(Nodo_huff *raiz){
    if(raiz != nullptr){
        eliminar(raiz->izq);
        eliminar(raiz->der);
        delete raiz; 
    }
}

Nodo_huff* Huffman::getRaiz(){
    return raiz;
}



void Huffman::reconstruirArbol() {
    raiz = new Nodo_huff('~');
    
    for(int i = 0; i < 256; i++) {
        if(codigos[i] != "") {
            Nodo_huff* actual = raiz;
            std::string codigo = codigos[i];
            
            // Recorrer el código bit por bit
            for(size_t j = 0; j < codigo.length(); j++) {
                if(codigo[j] == '0') {
                    if(actual->izq == nullptr) {
                        actual->izq = new Nodo_huff('~');
                    }
                    actual = actual->izq;
                } else {
                    if(actual->der == nullptr) {
                        actual->der = new Nodo_huff('~');
                    }
                    actual = actual->der;
                }
                
                // Si es el último bit, asignar el carácter
                if(j == codigo.length() - 1) {
                    actual->c = (char)i;
                }
            }
        }
    }
}