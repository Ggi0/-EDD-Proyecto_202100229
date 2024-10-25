#include "vnodo.h"

vnodo::vnodo(){
    this->destinos = nullptr;
    this->siguiente = nullptr;
}

vnodo::~vnodo(){
    enodo *aux = this->destinos;
    enodo *temp;

    while(aux != nullptr){
        temp = aux->getSiguiente();
        delete aux;
        aux = temp;
    }
}

// --------- getters ----------
Usuarios vnodo::getData(){
    return this->data;
}

enodo* vnodo::getDestinos(){
    return this->destinos;
}

vnodo* vnodo::getSiguiente(){
    return this->siguiente;
}

// -------- setters ----------
void vnodo::setData(Usuarios data){
    this->data = data;
}

void vnodo::setDestinos(enodo *destinos){
    this->destinos = destinos;
}

void vnodo::setSiguiente(vnodo *siguiente){
    this->siguiente = siguiente;
}

// ----------- metodos ---------------

void vnodo::insertarDestino(Usuarios destino){
    enodo *nuevo = new enodo();
    nuevo->setDestino(destino);

    // lista de destinos esta vacia 
    if(this->destinos == nullptr){
        this->destinos = nuevo;
    
    }else{
        enodo *aux = this->destinos;
        // getSiguiente porque estamos asignando info
        while(aux->getSiguiente() != nullptr){
            if(aux->getDestino().getID() == destino.getID()){
                return;
            }
            aux = aux->getSiguiente();
        }

        if(aux->getDestino().getID() != destino.getID()){
            aux->setSiguiente(nuevo);
        }
    }
}

void vnodo::graficarAristas(std::ofstream &f){
    enodo *aux = this->destinos;

    std::string nombre_origen = "Nodo" + std::to_string(this->data.getID());
    while(aux != nullptr){
        if(this->data.getID() < aux->getDestino().getID()){
            std::string nombre_destino = "Nodo" + std::to_string(aux->getDestino().getID());
            f << nombre_origen + "->" + nombre_destino + "[dir = both];" << std::endl;
        }
        aux = aux->getSiguiente();
    }
}

void vnodo::graficarListaDestinos(std::ofstream &f){
    enodo  *aux = this->destinos;
    std::ostringstream oss;
    std::string valor = std::to_string(this->data.getID());
    std::string nombre_origen = "Nodo" + valor;
    std::string rank = "{rank=same;" + nombre_origen;

    oss << this->destinos;
    std::string nombre = oss.str();

    f << nombre_origen + "->Nodo" + nombre + ";" << std::endl;

    while(aux != nullptr){
        oss.str("");
        oss << aux;
        std::string nombre = oss.str();

        std::string nombre_destino = "Nodo" + nombre;
        f << nombre_destino + "[label = \"" + std::to_string(aux->getDestino().getID()) + "\" fillcolor = \"white\"];" << std::endl;
        rank+=";" + nombre_destino;

        if(aux->getSiguiente() != nullptr){
            oss.str("");
            oss << aux->getSiguiente();
            std::string nombre = oss.str();
            f << nombre_destino + "->Nodo" + nombre + ";" << std::endl;
        }
        aux = aux->getSiguiente();
    }
    rank+= "}";
    f << rank << std::endl;
}

