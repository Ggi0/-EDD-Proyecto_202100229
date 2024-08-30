#include "listaSimpleEnlazada.h"

// Class::constructo/metodo/funcion
listaSimpleEnlazada::listaSimpleEnlazada(){
    primero = nullptr;
    ultimo = nullptr;
}

// Destructor
listaSimpleEnlazada::~listaSimpleEnlazada(){
    Nodo *tempo = primero; // puntero temporal que apunte a la cabeza
    Nodo *aux;

    // delete --> borra una direccione de memoria (deja de usarla)
    // Elimiar todos los nodos que se encuentren en la lista
    while(tempo != nullptr){
        aux = tempo -> getSig();  // 1) Guarda la dirección del siguiente nodo
        delete tempo;             // 2) Libera la memoria del nodo actual
        tempo = aux;              // 3) Avanza al siguiente nodo
    }
}

// insertar en la cabeza de la lista (inicio)
void listaSimpleEnlazada::push(int valor){
    // new --> nueva direccion de memoria, que tendra el valor (parametro)
    Nodo *nuevo_Nodo = new Nodo(valor);

    // SI la lista esta vacia
    if(primero == nullptr){
        // el primero y ultimo apuntaran a la mismo nodo
        primero = nuevo_Nodo;
        ultimo = nuevo_Nodo;
    }else{
        // nuevo_Nodo ahora tendra la información por el setSig(que tenia el primero )
        nuevo_Nodo -> setSig(primero);

        // Entonces el primero (la cabeza) sera el nuevo nodo
        primero = nuevo_Nodo;
    }
}

// insertar un nodo al final de la lista
void listaSimpleEnlazada::append(int valor){
    Nodo *nuevo_Nodo = new Nodo(valor);

    if(primero == nullptr){
        primero = nuevo_Nodo;
        ultimo = nuevo_Nodo;
    }else{
        ultimo -> setSig(nuevo_Nodo);
        ultimo = nuevo_Nodo;
        // esta solución es para utilizar un puntero menos, que a su vez es menos memoria utilizada
        //Nodo *temp = primero;
        // while(temp->getSig() != nullptr){
        //     temp = temp->getSig();
        // }
        // temp->setSig(nuevo_nodo);
    }
}

// Eliminar
/*
lista = [1, 2, 3, 4]
valor = lista.pop()  # valor = 4, lista = [1, 2, 3]
*/
int listaSimpleEnlazada::pop(){
    Nodo *temp;
    int ret;

    if(primero == nullptr){return -999;}

    temp = primero;
    ret = temp->getData();

    primero = primero->getSig();

    delete temp;
    return ret;
}

// Método para eliminar un nodo en un índice específico
void listaSimpleEnlazada::removeAt(int indice) {
    if (primero == nullptr) {  // La lista está vacía
        std::cerr << "La lista está vacía, no se puede eliminar." << std::endl;
        return;
    }

    if (indice == 0) {  // Eliminar el primer nodo
        Nodo *temp = primero;
        primero = primero->getSig();
        if (primero == nullptr) {  // Si la lista queda vacía
            ultimo = nullptr;
        }
        delete temp;
        return;
    }

    Nodo *temp = primero;
    Nodo *prev = nullptr;
    int i = 0;

    // Buscar el nodo en la posición especificada
    while (temp != nullptr && i < indice) {
        prev = temp;
        temp = temp->getSig();
        i++;
    }

    if (temp == nullptr) {  // El índice está fuera de rango
        std::cerr << "Índice fuera de rango, no se puede eliminar." << std::endl;
        return;
    }

    // Actualizar el siguiente nodo del nodo anterior
    prev->setSig(temp->getSig());
    if (temp->getSig() == nullptr) {  // Si se está eliminando el último nodo
        ultimo = prev;
    }
    delete temp;
}

/*
    -   Si el indice es mayor que el tamaño de la lista, lo inserta al final
        -> ya que estariamos buscando una posición de indice que no existe
    
    -   Si el índice es 0, es un push
        -> estamos agregando al inicio 
    -   0 significa el primer elemento
    ->  Los índices entonces, irán desde 0 hasta el tamaño - 1
 */
void listaSimpleEnlazada::insert(int indice, int valor){
    Nodo *nuevo_nodo = new Nodo(valor);
    Nodo *temp;
    int i = 0;

    temp = primero;

    // si la cabeza esta vacia O el indice es 0
    if (primero == nullptr || indice == 0){
        // metodo push()
        this->push(valor);
    }else{
        // 1) se llego al final de la lista
        // 2) se llego a la posición que se quiere insertar
        while(temp->getSig() != nullptr && i < indice - 1 ){
            temp = temp->getSig();
            i+=1;
        }
        
        // si se sale del while significa que podemos agregar el nodo
        // TEMPORAL es el nodo en el que nos encontramos donde agregaremos el nuevo NODO
        // el siguiente de nuevo_Nodo será el siguiente temporal
        // el siguiente de mi temporal apunta al nodo continuo
        // el puntero de temporal apuntara a nodo continuo
        nuevo_nodo->setSig(temp->getSig());

        // mi TEMPORAL sera el NUEVO
        temp->setSig(nuevo_nodo);
    }
}

// Método para encontrar el índice de un valor específico
int listaSimpleEnlazada::findIndex(int valor) {
    Nodo *temp = primero;
    int indice = 0;

    while (temp != nullptr) {
        if (temp->getData() == valor) {
            return indice;  // Retorna el índice si se encuentra el valor
        }
        temp = temp->getSig();
        indice++;
    }

    return -1;  // Retorna -1 si el valor no se encuentra en la lista
}


// para IMPRIMIR
void listaSimpleEnlazada::print(){
    Nodo *tempo = primero;

    while(tempo != nullptr){
        std::cout <<tempo->getData() << ", ";
        tempo = tempo -> getSig();
    }
    std::cout<< std::endl;
}



int listaSimpleEnlazada::size() {
    int contador = 0;
    Nodo *temp = primero;

    // Recorre la lista y cuenta cada nodo
    while (temp != nullptr) {
        contador++;
        temp = temp->getSig();
    }

    return contador;
}

Nodo* listaSimpleEnlazada::getPrimero() const {
    return primero;
}