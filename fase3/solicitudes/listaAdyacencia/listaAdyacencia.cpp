#include "listaAdyacencia.h"

listaAdyacencia::listaAdyacencia(){
    this->cabeza = nullptr;
}

listaAdyacencia::~listaAdyacencia(){
    vnodo *aux = this->cabeza;
    vnodo *temp;

    while(aux != nullptr){
        temp = aux->getSiguiente();
        delete aux;
        aux = temp;
    }
}

void listaAdyacencia::insert(Usuarios vertice){
    if(this->cabeza == nullptr){
        this->cabeza = new vnodo();
        this->cabeza->setData(vertice);

    }else{
        vnodo *nuevo = new vnodo();
        nuevo->setData(vertice);

        if(vertice.getID() < this->cabeza->getData().getID()){
            nuevo->setSiguiente(cabeza);
            this->cabeza = nuevo;
        
        }else{
            vnodo *aux = this->cabeza;
            while(aux->getSiguiente() != nullptr){
                if(vertice.getID() < aux->getSiguiente()->getData().getID()){
                    nuevo->setSiguiente(aux->getSiguiente());
                    aux->setSiguiente(nuevo);
                    break;
                } 
                aux = aux->getSiguiente();
            }

            if(aux->getSiguiente() == nullptr){
                aux->setSiguiente(nuevo);
            }
        }
    }
}

void listaAdyacencia::crearConexion(Usuarios origen, Usuarios destino){
    vnodo *aux = this->cabeza;
    while(aux != nullptr){
        if(aux->getData().getID() == origen.getID()){
            aux->insertarDestino(destino);
            break;
        }
        aux = aux->getSiguiente();
    }
}

void listaAdyacencia::crearGrafo(){
    std::ofstream outfile ("grafo.dot");
    outfile << "digraph G {" << std::endl;

    vnodo *aux = this->cabeza;
    while(aux != nullptr){
        std::string valor = std::to_string(aux->getData().getID());
        std::string dec_nodo  = "Nodo" + valor + "[label = \"" + valor + "\"];";
        outfile << dec_nodo << std::endl;
        aux->graficarAristas(outfile);
        aux = aux->getSiguiente();
    }

    outfile << "}" << std::endl;
    outfile.close();

    int returnCode = system("/opt/local/bin/dot -Tpng ./grafo.dot -o ./grafo.png");

    if(returnCode == 0){std::cout << "(Grafico grafo) Command executed successfully." << std::endl;}
    else{std::cout << "(Grafico grafo) Command execution failed or returned non-zero: " << returnCode << std::endl;}
}

void listaAdyacencia::crearGrafoLista(){
    std::ofstream outfile ("grafoLista.dot");
    outfile << "digraph G {" << std::endl;
    outfile << "node[shape = \"box\" style = \"filled\"]" << std::endl;

    vnodo *aux = this->cabeza;
    while(aux != nullptr){
        std::string valor = std::to_string(aux->getData().getID());
        std::string nombre = "Nodo" + valor + "[label = \"" + valor + "\" group = \"1\" fillcolor=\"lightgray\"];";
        outfile << nombre << std::endl;

        if(aux->getSiguiente() != nullptr){
            outfile << "Nodo" + valor + "->Nodo" + std::to_string(aux->getSiguiente()->getData().getID()) + "[dir = none];";
        }

        aux->graficarListaDestinos(outfile);
        aux = aux->getSiguiente();
    }

    outfile << "}" << std::endl;
    outfile.close();

    int returnCode = system("/opt/local/bin/dot -Tpng ./grafoLista.dot -o ./grafoLista.png");

    if(returnCode == 0){std::cout << "(Grafico lista) Command executed successfully." << std::endl;}
    else{std::cout << "(Grafico lista) Command execution failed or returned non-zero: " << returnCode << std::endl;}  
}