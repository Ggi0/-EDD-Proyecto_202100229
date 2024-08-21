#include <string>
/*
    clase para los Nuevos Usuarios
    Atributos:
        ID
        nombres
        apellidos
        Fecha de nacimiento
        correo electrónico
        contrasenia
*/
class Usuarios{
    private:
        int ID;
        std::string nombres;
        std::string apellidos;
        std::string fechaN;
        std::string correo;
        std::string contrasenia;
    
    public:
        // ---- CONSTRUCTOR -----
        Usuarios();
        Usuarios(std::string nombres, 
                std::string apellidos, 
                std::string fechaN, 
                std::string correo, 
                std::string contrasenia);

        // ----- DESTRUCTOR ------
        ~Usuarios();

         // ----- GETTERS -------
        int getID();
        std::string getNombres();
        std::string getApellidos();
        std::string getFechaN();
        std::string getCorreo();
        std::string getContrasenia();

        // ----- SETTERS -------
        void setID(int ID);
        void setNombres(std::string nombre);
        void setApellidos(std::string apellidos);
        void setFechaN(std::string fecha);
        void setCorreo(std::string correo);
        void setContrasenia(std::string contrasena);

        // ---- METODOS -----
        void printUsuario();
        void asignarID();
        void guardarUsuario();
        void graficarUsuario();

};