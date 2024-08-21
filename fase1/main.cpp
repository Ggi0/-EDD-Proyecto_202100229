
#include "listaEnlazada/listaSimpleEnlazada.h"

int main(int argc, char const *argv[]){
    listaSimpleEnlazada list;
    list.push(12);
    list.push(4);
    list.push(23);

    list.print();

    return 0;

}