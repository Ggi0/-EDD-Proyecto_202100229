#ifndef USUARIOS_H
#define USUARIOS_H
#include <string>
#include "../listaEnlazadaSolicitudes/arrayListSoli.h"
#include "../pilaSolicitudes/solicitud_pila.h"

// para la lista de amigos
#include "../listaEnlazadaInt/listaSimpleEnlazada.h"

// para publicaciones
#include "../listaCircularDobleEnlazada/listaCircular_DEpp.h"

#include <fstream>

/*
    clase para los Nuevos Usuarios
    Atributos:
        ID
        nombres
        apellidos
        Fecha de nacimiento
        correo electrónico
        contrasenia

        lista simplemente enlazada de solicitudes
        pila de solicitudes
        lista simplemente enlazada de amigos (int id)
*/
class Usuarios{
    private:
        int ID;
        static int contadorID;
        std::string nombres;
        std::string apellidos;
        std::string fechaN;
        std::string correo;
        std::string contrasenia;

        arrayList_soli listaSolicitudes;
        solicitud_pila pilaSolicitudes;
        listaSimpleEnlazada lista_amigos;
        ListaCircular_Dpp lista_publicacionesP;

    
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

        arrayList_soli& getListaSolicitudes();
        solicitud_pila& getPilaSolicitudes();
        listaSimpleEnlazada& getLista_amigos();
        ListaCircular_Dpp& getLista_publicacionesP();

        // ----- SETTERS -------
        void setID(int ID);
        void setNombres(std::string& nombre);
        void setApellidos(std::string& apellidos);
        void setFechaN(std::string& fecha);
        void setCorreo(std::string& correo);
        void setContrasenia(std::string& contrasena);

        void setListaSolicitudes(const arrayList_soli& listaSolicitudes);
        void setPilaSolicitudes(const solicitud_pila& pilaSolicitudes);
        void setLista_amigos(const listaSimpleEnlazada& lista_amigos);
        void setLista_publicacionesP(const ListaCircular_Dpp& lista_publicacionesP);

        // ---- METODOS -----
        void printUsuario();
        void asignarID();
        void guardarUsuario();
        void graficarUsuario();

            // Nuevos métodos para manejar las estructuras de datos
        void agregarSolicitud(const Solicitud& solicitud);
        void agregarSolicitudPila(const Solicitud& solicitud);

        // metodos para lista amigos:
        void agregarAmigo(int idAmigo);
        void eliminarAmigo(int idAmigo);
        bool esAmigo(int idAmigo);
        void imprimirAmigos();


        // Nuevos métodos para manejar publicaciones
        void agregarPublicacion(const Publicacion& publicacion);
        void eliminarPublicacion(const std::string& correo);
        bool tienePublicacion(const std::string& correo) const;
        void imprimirPublicaciones() const;

        void graficaAmigos() const;


        
};

#endif // USUARIOS_H