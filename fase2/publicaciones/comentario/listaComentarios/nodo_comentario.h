#ifndef NODO_COMENTARIO_H
#define NODO_COMENTARIO_H

#include <iostream>
#include "../comentario.h"
class Comentario; // Declaración adelantada

class Nodo_com{
    private:
        Comentario data;
        Nodo_com *sig; // puntero a otro nodo
    
    public:
        // --------- CONSTRUCTORES
        // Nodo *primero = Nodo() ---> Invocar a nodo y que devuelva un tipo de nodo 
        Nodo_com();
        // Nodo *primero = Nodo(data = 5) -----> Este pasara la información
        // un nodo que de info tenga 5
        Nodo_com(Comentario valor);

        // ---------- Getters and Setters ---------
        void setData(Comentario valor); // Define el valor de del nodo
        void setSig(Nodo_com* sig); // Define el siguiente del nodo
        
        Comentario& getData(); // Devuelve la Data entera
        Nodo_com* getSig(); // Devuelve el siguiente del nodo, retorna un puntero ya que es un puntero 
};
#endif // NODO_COMENTARIO
