#ifndef SOLICITUD_H
#define SOLICITUD_H
#include <string>
/*
    clase para las SOLICITUDES
    Atributos:
        string emisor (correo)
        string receptor (correo)
        string estado (ACEPTADA/PENDIENTE/RECHAZADA)
*/
class Solicitud{
    private:
        std::string emisor;
        std::string receptor;
        std::string estado;
    
    public:
        // ---- CONSTRUCTOR -----
        Solicitud();
        Solicitud(std::string emisor, 
                std::string receptor, 
                std::string estado);

        // ----- DESTRUCTOR ------
        ~Solicitud();

         // ----- GETTERS -------
        int getID();
        std::string getEmisor() const;
        std::string getReceptor() const;
        std::string getEstado() const;

        // ----- SETTERS -------
        void setEmisor(std::string& _emisor);
        void setReceptor(std::string& _receptor);
        void setEstado(std::string& _estado);

        // ---- METODOS -----
        void printSolicitud();
        void guardarSolicitud();

        void eliminarSolicitud();

        void aceptarSolicitud();
        void rechazarSolicitud();

};

#endif // USUARIOS_H