#ifndef USUARIOS_H
#define USUARIOS_H
#include <string>
#include <iostream>    // Incluir iostream para usar std::cout y std::endl


// lista solicitudes enviadas y pila solicitudes recibidas
#include "../solicitudes/listaEnlazadaSolicitudes/arrayListSoli.h"
#include "../solicitudes/pilaSolicitudes/solicitud_pila.h"

// para la lista de amigos -> para id de amigos
#include "listaEnlazadaInt/listaSimpleEnlazada.h"

// para el arbol binario (feed)
#include "../publicaciones/arbolBinario/bst_publi.h"


#include <fstream>
#include <sstream>

/*
    clase para los Usuarios:
    Atributos:
        ID
        nombres
        apellidos
        Fecha de nacimiento
        correo electrónico
        contrasenia

        lista simplemente enlazada de solicitudes enviadas
        pila de solicitudes recibidas

        lista simplemente enlazada de amigos (int id)

        arbol binario de busqueda (ABB - BST) -> publicaciones del usuario y amigos (feed)

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
        BST bst_feedPublicaciones;

        // Métodos auxiliares privados para la graficación
        void graficar_bst_recursivo(NodoBST* nodo, const std::string& fecha_buscada, std::ofstream& archivo) const;
        //void graficar_lista_publicaciones(NodoBST* nodo, std::ofstream& archivo) const;
        void graficar_lista_publicaciones(NodoBST* nodo, const std::string& nodeId, std::ofstream& archivo) const;

    
    public:
        // ---- CONSTRUCTOR -----
        // Constructores
        Usuarios();
        Usuarios(std::string nombres, std::string apellidos, std::string fechaN, 
                std::string correo, std::string contrasenia);
 

        // ----- DESTRUCTOR ------
        // Constructor de copia
        Usuarios(const Usuarios& other);
        
        // Operador de asignación
        Usuarios& operator=(const Usuarios& other);
        
        // Destructor
        ~Usuarios();

         // ----- GETTERS -------
        int getID() const;
        std::string getNombres();
        std::string getApellidos();
        std::string getFechaN();
        std::string getCorreo();
        std::string getContrasenia();

        arrayList_soli& getListaSolicitudes();
        solicitud_pila& getPilaSolicitudes();
        listaSimpleEnlazada& getLista_amigos();
        BST& getBST_feedPublicaciones();

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
        void setBST_feedPublicaciones(const BST& bst_feedPublicaciones);

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
        bool esAmigo(int idAmigo) const;
        void imprimirAmigos();
        void graficaAmigos() const;

        // Operador de comparación para ordenar usuarios por correo
        bool operator<(const Usuarios& otro) const;

        // Método para graficar el BST de feedPublicaciones, resaltando una fecha específica
        void graficar_fecha(const std::string& fecha) const;

        void generarGraficoBSTPersonal() const;


        


        
};

#endif // USUARIOS_H