#include "nodoBST_publi.h"

NodoBST::NodoBST(std::string fechaID){
    this->fechaID = fechaID;
    drcha = nullptr;
    izq = nullptr;
}

// -------- GETTERS -------------
std::string NodoBST::getFechaID(){
    return fechaID;
}

NodoBST* NodoBST::getDrcha(){
    return drcha;
}

NodoBST* NodoBST::getIzq(){
    return izq;
}

ListaDoblementeEnlazadaP& NodoBST::getListaPublicaciones(){
    return listaPublicaciones;
}


// -------- SETTERS ------------
void NodoBST::setFechaID(std::string fechaID){
    this->fechaID = fechaID;
}

void NodoBST::setDrcha(NodoBST *drcha){
    this->drcha = drcha;
}

void NodoBST::setIzq(NodoBST *izq){
    this->izq = izq;
}

void NodoBST::setListaPublicaciones(const ListaDoblementeEnlazadaP& listaPublicaciones){
    this -> listaPublicaciones = listaPublicaciones;
}
