
#include "listaEnlazada/listaSimpleEnlazada.h"

int main(int argc, char const *argv[]){
    listaSimpleEnlazada list;
    list.push(12);
    list.push(4);
    list.push(23);
    list.push(3);
    list.push(78);
    list.push(47);

    list.append(500);
    list.insert(3, 999);

    list.print();

    return 0;

}