#ifndef BLOQUES_H
#define BLOQUES_H
#include <string>
#include <iostream>    // Incluir iostream para usar std::cout y std::endl
#include <fstream>
#include <sstream>

/*
    clase para los Usuarios:
    Atributos:
        index
        timestamp
        data
        nonce
        prev
        hash
*/
class Bloque{
    private:
        int index;
        std::string timestamp;
        std::string data;
        std::string nonce;
        std::string prev;
        std::string hash;
        std::string rootMerkle;

        bool informacionValida = true;  //atributo par asaber si la información fue modificada.


    public:
        // ---- CONSTRUCTOR -----
        // Constructores
        Bloque();
        Bloque(int index, std::string timestamp, 
               std::string data, std::string nonce, 
               std::string prev, std::string hash, std::string rootMerkle);
 

        // ----- DESTRUCTOR ------
        // Constructor de copia
        Bloque(const Bloque& other);
        
        // Operador de asignación
        Bloque& operator=(const Bloque& other);
        
        // Destructor
        ~Bloque();

         // ----- GETTERS -------
        int getIndex() const;
        std::string getTimestamp();
        std::string getData();
        std::string getNonce();
        std::string getPrev();
        std::string getHash();
        std::string getRootMerkle();

        bool getInformacionValida() const;  // Getter para informacionValida



        // ----- SETTERS -------
        void setIndex(int index);
        void setTimestamp(std::string& timestamp);
        void setData(std::string& data);
        void setNonce(std::string& nonce);
        void setPrev(std::string& prev);
        void setHash(std::string& hash);
        void setRootMerkle(std::string& rootMerkle);

        void setInformacionValida(bool valor);  // Setter para informacionValida


        // ---- METODOS -----
        void printBloque();   
};

#endif // BLOQUES_H