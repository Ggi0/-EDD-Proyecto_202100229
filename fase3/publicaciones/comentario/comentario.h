#ifndef COMENTARIO_H
#define COMENTARIO_H
#include <string>

/*
    clase para los COMENTARIOS    
    
    ATRIBUTOS:
        correo
        comment
        fecha (DD/MM/YYYY)
        hora (24:00)

    formato en JSON:
    {
      "correo": "maria.lopez@example.com",
      "comentario": "Felicidades.",
      "fecha": "11/08/2024",
      "hora": "09:45"
    }

*/
class Comentario{
    private:
        std::string correoC;
        std::string comment;
        std::string fecha;
        std::string hora;

    public:
        // ------ CONSTRUCCIOR ------
        Comentario();
        Comentario(std::string correoC, 
                    std::string comment,
                    std::string fecha,
                    std::string hora);

        // ------ DESTRUCTOR -------
        ~Comentario();

        // ------ GETTERS ----------
        std::string getCorreoC() const;
        std::string getComment() const;
        std::string getFecha() const;
        std::string getHora() const;

        // ------ SETTERS ----------
        void setCorreoC(const std::string& correoC);
        void setComment(const std::string& comment);
        void setFecha(const std::string& fecha);
        void setHora(const std::string& hora);
        
        // ------ METODOS ----------
        void printComentario() const;


};

#endif // PUBLICACION_H