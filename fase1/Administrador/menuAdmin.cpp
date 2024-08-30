#include "menuAdmin.h"
#include <iostream>
#include "../Herramientas/enter.h"
#include "leerJson.h"
#include "../ModuloUsuario/menuUsuario.h"
#include "../Registro/global_data.h"
#include "../publicaciones/global_data_publicaciones.h"
/*
    Interfas que en la que interactuara el ADMINISTRADOR luego de iniciar sesion
    
    En donde tendra opciones para:
    * carga de usuarios
    * carga de reportes
    * carga de publicaciones
    * gestionar usuarios
       -> elimanar usuarios
    * reportes
    * salir

*/
void menuAdmin(){
    int opcion = 0;
    int opcion2 = 0;
    std::string ruta="";
    std::string correoEliminar = "";
    
    do{
        // ----- MENU ADMINISTRACION ------
        std::cout <<std::endl<<"-!-!-!-!-!-!-!-!-!-!-!-!-!-!-!-"<< std::endl;
        std::cout << "     ADMINISTRACION"<< std::endl;
        std::cout << "- - - - - - - - - - - - - - - -"<< std::endl;
        std::cout << "1) Carga de usuarios"<< std::endl;
        std::cout << "2) Carga de relaciones"<< std::endl;
        std::cout << "3) Carga de publicaciones"<< std::endl;
        std::cout << "4) Gestionar usuarios"<< std::endl;
        std::cout << "5) Reportes "<< std::endl;
        std::cout << "6) Salir"<< std::endl<<std::endl;

        // capturar la entrada
        std::cout<<"Seleccione una opcion: ";
        std::cin >> opcion;

        // Verificar si la entrada es válida
        if (std::cin.fail()) {
            std::cin.clear(); // Limpiar el estado de error
            std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n'); // Descartar la entrada inválida
            opcion = 0; // Asignar un valor inválido para que el switch maneje la opción por defecto
        }
        std::cout <<"-¡-¡-¡-¡-¡-¡-¡-¡-¡-¡-¡-¡-¡-¡-¡-"<< std::endl<< std::endl<<std::endl;
        
        switch(opcion){
            case 1:
                std::cout << "1) Carga de usuarios: "<< std::endl;
                std::cout << "- - - - - - - - - - - - - - - -"<< std::endl;
                std::cout<<"Ingrese la ruta del documento: ";
                // Usar std::getline para leer la ruta con espacios
                std::getline(std::cin >> std::ws, ruta);

                // Remover comillas dobles si las hay
                ruta.erase(std::remove(ruta.begin(), ruta.end(), '\"'), ruta.end());
                leerUsuarios(ruta);
                break;

            case 2:
                std::cout << "2) Carga de relaciones: "<< std::endl;
                std::cout << "- - - - - - - - - - - - - - - -"<< std::endl;
                std::cout<<"Ingrese la ruta del documento: ";
                // Usar std::getline para leer la ruta con espacios
                std::getline(std::cin >> std::ws, ruta);

                // Remover comillas dobles si las hay
                ruta.erase(std::remove(ruta.begin(), ruta.end(), '\"'), ruta.end());
                leerSolicitudes(ruta);
                break;

            case 3:
                std::cout << "3) Carga de publicaciones: "<< std::endl;
                std::cout << "- - - - - - - - - - - - - - - -"<< std::endl;
                std::cout<<"Ingrese la ruta del documento: ";
                // Usar std::getline para leer la ruta con espacios
                std::getline(std::cin >> std::ws, ruta);

                // Remover comillas dobles si las hay
                ruta.erase(std::remove(ruta.begin(), ruta.end(), '\"'), ruta.end());
                leerPublicaciones(ruta);
                break;

            case 4:
                std::cout << "4) Gestionar usuarios: "<< std::endl;
                std::cout << "- - - - - - - - - - - - - - - -"<< std::endl<<std::endl;
                std::cout << "      1) Eliminar usuarios "<< std::endl;
                std::cout << "      2) Regresar "<< std::endl;
                std::cout<<"Seleccione una opcion: ";
                std::cin >> opcion2;
                // Verificar si la entrada es válida
                if (std::cin.fail()) {
                    std::cin.clear(); // Limpiar el estado de error
                    std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n'); // Descartar la entrada inválida
                    opcion2 = 0; // Asignar un valor inválido para que el switch maneje la opción por defecto
                }
                std::cout << "- - - - - - - - - - - - - - - -"<< std::endl<<std::endl;
                switch(opcion2){
                    case 1:
                        std::cout << "1) Eliminar usuarios: "<< std::endl;
                        std::cout << "- - - - - - - - - - - - - - - -"<< std::endl;
                        std::cout <<std::endl << "por favor, Ingrese correo electrónico: ";
                        std::getline(std::cin >> std::ws, correoEliminar);
                        eliminarCuenta(correoEliminar);
                        break;

                    case 2:
                        std::cout << "2) Regresar: "<< std::endl;
                        std::cout << "- - - - - - - - - - - - - - - -"<< std::endl;
                        std::cout << "... volviendo al menú"<< std::endl;
                        break;
                }
                break;

            case 5:
                std::cout << "5) Reportes: "<< std::endl;
                std::cout << "- - - - - - - - - - - - - - - -"<< std::endl;
                listaGlobal_usuarios.graficar();
                listaGlobal_publicaciones.graficar();

                listaGlobal_usuarios.graficarTop5ConMasPublicaciones();
                listaGlobal_usuarios.graficarTop5ConMenosAmigos();
                
                break;

            case 6:
                std::cout << "6) Salir: "<< std::endl;
                std::cout << "- - - - - - - - - - - - - - - -"<< std::endl;
                std::cout << "Regresando al menu principal ... "<< std::endl;
                break;

            default:
                std::cout << "opcion NO valida. Seleccione una de la 4 opciones";
                std::cout << "... presione ENTER para continuar..."<<std::endl;
                enter();
        }

    }while(opcion != 6);

}