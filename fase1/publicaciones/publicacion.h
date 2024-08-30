#ifndef PUBLICACION_H
#define PUBLICACION_H
#include <string>

/*
    clase para las PUBLICACIONES    
    
    ATRIBUTOS:
        correo
        contenido
        fecha
        hora

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
        std::string correoP;
        std::string contenido;
        std::string fecha;
        std::string hora;

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
        std::string getCorreoP() const;
        std::string getContenido() const;
        std::string getFecha() const;
        std::string getHora() const;

        // ------ SETTERS ----------
        void setCorreoP(const std::string& correoP);
        void setContenido(const std::string& contenido);
        void setFecha(const std::string& fecha);
        void setHora(const std::string& hora);
        
        // ------ METODOS ----------
        void printPublicacion() const;


};

#endif // PUBLICACION_H