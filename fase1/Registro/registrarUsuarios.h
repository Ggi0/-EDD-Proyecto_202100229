#include "../listaEnlazadaUsuarios/arrayListUs.h"

/* 
    Agregar usuario a la lista
    verificar que no se repita el correo
        -> eliminar el objeto si repite el usuario

*/
class GestorUsuarios {
    private:
        arrayList_us listaUsuarios;

    public:
        // ---- CONSTRUCTOR -----
        GestorUsuarios();
        GestorUsuarios(arrayList_us listaUsuarios);
        
        // ----- DESTRUCTOR ------
        ~GestorUsuarios();

        // ----- GETTERS -------
        arrayList_us& getListaUsuarios();

        // ----- SETTERS -------
        void setListaUsuarios(arrayList_us listaUsuarios);

        // ----- METODOS -----
        std::string agregarUsuario(Usuarios nuevoUsuario);
};



/*

void agregarUsuario(Usuarios nuevoUsuario) {
            listaUsuarios.append(nuevoUsuario);
        }
        void mostrarUsuarios(){
            listaUsuarios.printAll();
        }
*/