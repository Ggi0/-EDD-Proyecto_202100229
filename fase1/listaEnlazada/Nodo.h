#include <iostream>

class Nodo{
    private:
        int data;
        Nodo *sig; // puntero a otro nodo
    
    public:
        // --------- CONSTRUCTORES
        // Nodo *primero = Nodo() ---> Invocar a nodo y que devuelva un tipo de nodo 
        Nodo();
        // Nodo *primero = Nodo(data = 5) -----> Este pasara la información
        // un nodo que de info tenga 5
        Nodo(int data);

        // ---------- Getters and Setters ---------
        void setData(int valor); // Define el valor de del nodo
        void setSig(Nodo* sig); // Define el siguiente del nodo
        
        int getData(); // Devuelve la Data entera
        Nodo* getSig(); // Devuelve el siguiente del nodo, retorna un puntero ya que es un puntero 
        
        


};