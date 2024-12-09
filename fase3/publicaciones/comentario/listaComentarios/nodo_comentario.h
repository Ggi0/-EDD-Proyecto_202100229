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
        //Nodo_com *primero = Nodo_com(); //---> Invocar a nodo y que devuelva un tipo de nodo 
        // Constructores y Destructor
        Nodo_com();
        Nodo_com(Comentario valor);
        Nodo_com(const Nodo_com& other); // Constructor de copia
        Nodo_com& operator=(const Nodo_com& other); // Operador de asignación
        ~Nodo_com(); // Destructor

        // ---------- Getters and Setters ---------
        void setData(Comentario valor); // Define el valor de del nodo
        void setSig(Nodo_com* sig); // Define el siguiente del nodo
        
        Comentario& getData(); // Devuelve la Data entera
        Nodo_com* getSig(); // Devuelve el siguiente del nodo, retorna un puntero ya que es un puntero 
};
#endif // NODO_COMENTARIO
