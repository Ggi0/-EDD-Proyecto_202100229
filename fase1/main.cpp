// para menuAdmin
#include "Administrador/menuAdmin.h"

// para menuAdmin
#include "ModuloUsuario/menuUsuario.h"

// Funciones para verificar usuarios
#include "Registro/registroUsuarioOficial.h"

#include <string>

#include "Registro/global_data.h"
#include "publicaciones/global_data_publicaciones.h"

// metodo para registrar solicitudes
#include "Solicitudes/registroSolicitudes.h"

//registrar publicaciones
#include "publicaciones/registroPublicaciones.h"

#include "Herramientas/enter.h"

int main(int argc, char const *argv[]){

    int opcion;
    std::string nombres;
    std::string apellidos;
    std::string fechaN;
    std::string correo;
    std::string contrasenia;
    std::string msj = "";
    int valorInicioSesion = 0;

    std::string emisor = "";
    std::string receptor = "";
    std::string estado = "";

    std::string correo_p = "";
    std::string contenido_p ="";
    std::string fecha_p ="";
    std::string hora_p="";

    do{
        //system("cls"); // limpiar consola win 
        //system("clear"); // limpiar consola macOS
        // ----- MENU ------
        std::cout <<std::endl<<"-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-"<< std::endl;
        std::cout << "             MENU                "<< std::endl;
        std::cout << "- - - - - - - - - - - - - - - -"<< std::endl;
        std::cout << "1) INICIAR SESION"<< std::endl;
        std::cout << "2) REGISTRARSE"<< std::endl;
        std::cout << "3) INFORMACION"<< std::endl;
        std::cout << "4) SALIR"<< std::endl<<std::endl;

        // capturar la entrada
        std::cout<<"Seleccione una opcion: ";
        std::cin >> opcion;

        // Verificar si la entrada es válida
        if (std::cin.fail()) {
            std::cin.clear(); // Limpiar el estado de error
            std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n'); // Descartar la entrada inválida
            opcion = 0; // Asignar un valor inválido para que el switch maneje la opción por defecto
        }

        std::cout <<"-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-"<< std::endl<< std::endl<<std::endl;
        // clasificar opcion
        switch(opcion){
            case 1:
                std::cout << "1) INICIAR SESION"<< std::endl;
                std::cout << "- - - - - - - - - - - - - - - -"<< std::endl;
                // iniciar seción para un usuario
                // Solicitar correo
                std::cout << "Correo electronico: ";
                std::getline(std::cin >> std::ws, correo);  // Leer el correo ingresado por el usuario
                // Solicitar contraseña
                std::cout << "Contrasena: ";
                std::getline(std::cin >> std::ws, contrasenia);  // Leer la contraseña ingresada por el usuario
                std::cout<< std::endl<< std::endl;

                valorInicioSesion = iniciarSesion(correo, contrasenia);
                if (valorInicioSesion == 2){
                    menuAdmin();
                }else if (valorInicioSesion == 1){
                    menuUsuario(correo);
                }

                enter(); 
                break;

            case 2:
                std::cout << "2) REGISTRARSE"<< std::endl;
                std::cout << "- - - - - - - - - - - - - - - -"<< std::endl<< std::endl;
                // REGISTRAR a un usuario nuevo
                // Nombres
                std::cout << "Nombres: ";
                std::getline(std::cin >> std::ws, nombres);

                // Apellidos
                std::cout << "Apellidos: ";
                std::getline(std::cin >> std::ws, apellidos);

                // Fecha de nacimiento
                std::cout << "Fecha de Nacimiento (DD/MM/AA): ";
                std::getline(std::cin >> std::ws, fechaN);
                
                // Correo Electronico
                std::cout << "correo electronico: ";
                std::getline(std::cin >> std::ws, correo);

                // Contrasenia
                std::cout << "contrasenia: ";
                std::getline(std::cin >> std::ws, contrasenia);
                std::cout<< std::endl<< std::endl;

                verificarCorreo(nombres, apellidos, fechaN, correo, contrasenia);
                break;

            case 3:
                std::cout << "3) INFORMACION"<< std::endl;
                std::cout << "- - - - - - - - - - - - - - - -"<< std::endl<< std::endl;
                std::cout << "Giovanni Concohá"<< std::endl<<"       202100229"<< std::endl<<std::endl;

                verListaGlobal();
                enter();
                std::cout << std::endl;
                break;

            case 4: 
                std::cout << "... adio"<<std::endl;
                break;

            case 5: 
                std::cout << "... viendo si jala la lista global"<<std::endl;
                listaGlobal_usuarios.printAll();
                break;

            case 6: 
                std::cout << "... validadndo solicitudes"<<std::endl;

                std::cout << "--------------------------"<<std::endl;
                std::cout << "(gio2/gio1/PEN)"<<std::endl;
                emisor = "gio2";
                receptor = "gio1";
                estado = "PENDIENTE";
                registroSolicitudes(emisor, receptor, estado);
                std::cout << "--------------------------"<<std::endl<<std::endl;

                std::cout << "--------------------------"<<std::endl;
                std::cout << "(gio3/gio1/PEN)"<<std::endl;
                emisor = "gio3";
                receptor = "gio1";
                estado = "PENDIENTE";
                registroSolicitudes(emisor, receptor, estado);
                std::cout << "--------------------------"<<std::endl<<std::endl;

                std::cout << "--------------------------"<<std::endl;
                std::cout << "(gio4/gio1/Ac)"<<std::endl;
                emisor = "gio4";
                receptor = "gio1";
                estado = "ACEPTADA";
                registroSolicitudes(emisor, receptor, estado);
                std::cout << "--------------------------"<<std::endl<<std::endl;

                std::cout << "--------------------------"<<std::endl;
                std::cout << "(gio1/gio3/ACEP)"<<std::endl;
                emisor = "gio1";
                receptor = "gio3";
                estado = "ACEPTADA";
                registroSolicitudes(emisor, receptor, estado);
                std::cout << "--------------------------"<<std::endl<<std::endl;

                std::cout << "--------------------------"<<std::endl;
                std::cout << "(gio7/gio2/PEN)"<<std::endl;
                emisor = "gio7";
                receptor = "gio2";
                estado = "PENDIENTE";
                registroSolicitudes(emisor, receptor, estado);
                std::cout << "--------------------------"<<std::endl<<std::endl;

                std::cout << "--------------------------"<<std::endl;
                std::cout << "(gio2/gio7/ACEP)"<<std::endl;
                emisor = "gio2";
                receptor = "gio7";
                estado = "ACEPTADA";
                registroSolicitudes(emisor, receptor, estado);
                std::cout << "--------------------------"<<std::endl<<std::endl;
                
                std::cout << "--------------------------"<<std::endl;
                std::cout << "(gio1/gio2/ACEP)"<<std::endl;
                emisor = "gio1";
                receptor = "gio2";
                estado = "ACEPTADA";
                registroSolicitudes(emisor, receptor, estado);
                std::cout << "--------------------------"<<std::endl<<std::endl;
                break;

            case 7:
                std::cout << "--------------------------"<<std::endl;
                std::cout << "(publicacion 1)"<<std::endl;
                correo_p = "gio1";
                contenido_p ="hola publicacion 1 de gio1";
                fecha_p ="hoy";
                hora_p="6 pm";
                verificarCorreo_publicacion(correo_p, contenido_p, fecha_p,hora_p);
                std::cout << "--------------------------"<<std::endl<<std::endl;

                std::cout << "--------------------------"<<std::endl;
                std::cout << "(publicacion 2)"<<std::endl;
                correo_p = "gio1";
                contenido_p ="hola publicacion 2 de gio1";
                fecha_p ="hoy";
                hora_p="7 pm";
                verificarCorreo_publicacion(correo_p, contenido_p, fecha_p, hora_p);
                std::cout << "--------------------------"<<std::endl<<std::endl;

                std::cout << "--------------------------"<<std::endl;
                std::cout << "(publicacion 3)"<<std::endl;
                correo_p = "gio7";
                contenido_p ="hola publicacion 1 de gio7";
                fecha_p ="hoy";
                hora_p="9 pm";
                verificarCorreo_publicacion(correo_p, contenido_p, fecha_p, hora_p);
                std::cout << "--------------------------"<<std::endl<<std::endl;

                std::cout << "--------------------------"<<std::endl;
                std::cout << "(publicacion 4)"<<std::endl;
                correo_p = "gio5";
                contenido_p ="hola publicacion 1 de gio5";
                fecha_p ="hoy";
                hora_p="3 pm";
                verificarCorreo_publicacion(correo_p, contenido_p, fecha_p, hora_p);
                std::cout << "--------------------------"<<std::endl<<std::endl;
                break;

            case 8:
                std::cout << "todas las publicaciones: "<<std::endl;
                listaGlobal_publicaciones.print();
                break;

            default:
                std::cout << "opcion NO valida. Seleccione una de la 4 opciones";
                enter();
        }
    } while (opcion != 4);
    return 0;

}