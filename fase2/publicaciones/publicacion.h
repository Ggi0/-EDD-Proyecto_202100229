#ifndef PUBLICACION_H
#define PUBLICACION_H
#include <string>
#include "comentario/arbolB/arbolB.h"

/*
    clase para las PUBLICACIONES    
    
    ATRIBUTOS:
        ID
        correo
        contenido
        fecha
        hora
        arbolB -> comentarios

    formato en JSON:
    {
      "correo": "maria.lopez@example.com",
      "contenido": "Hoy aprendí algo nuevo, siempre es bueno salir de la zona de confort.",
      "fecha": "11/08/2024",
      "hora": "09:45"
    }

*/
class Publicacion{
    private:
        int ID_publi;
        static int contadorID_publi;
        std::string correoP;
        std::string contenido;
        std::string fecha;
        std::string hora;

        // arbolB arbolComentarios
        ArbolB arbolB_comentarios;

    public:
        // ------ CONSTRUCCIOR ------
        Publicacion();
        Publicacion(std::string correoP, 
                    std::string contenido,
                    std::string fecha,
                    std::string hora);

        // ------ DESTRUCTOR -------
        ~Publicacion();

        // ------ GETTERS ----------
        int getID_publi() const;
        std::string getCorreoP() const;
        std::string getContenido() const;
        std::string getFecha() const;
        std::string getHora() const;
        ArbolB getArbolB_comentarios() const;

        // ------ SETTERS ----------
        void setID_publi(const int ID_publi);
        void setCorreoP(const std::string& correoP);
        void setContenido(const std::string& contenido);
        void setFecha(const std::string& fecha);
        void setHora(const std::string& hora);
        void setArbolB_comentarios(const ArbolB& arbolB_comentarios);
        
        // ------ METODOS ----------
        void printPublicacion() const;


};

#endif // PUBLICACION_H