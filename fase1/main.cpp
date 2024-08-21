
#include "listaEnlazada/listaSimpleEnlazada.h"

// LISTA DE USUARIOS
#include "listaEnlazadaUsuarios/arrayListUs.h"

// OBJETOS USUARIOS
#include "Registro/Usuarios.h"
// para que cin solo acepte int
#include <limits>
#include <string>


void enter() {
    std::cout << "Presiona Enter para continuar..." << std::endl;
    std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n'); // Ignora cualquier entrada previa hasta encontrar un salto de línea
    std::cin.get(); // Espera a que el usuario presione Enter
}

int main(int argc, char const *argv[]){

    int opcion;
    std::string nombres;
    std::string apellidos;
    std::string fechaN;
    std::string correo;
    std::string contrasenia;

    arrayList_us listaUsuarios;

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
        Usuarios usuario_nuevo;
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

                std::cout <<"su correo es: "<< correo<<std::endl; 
                std::cout <<"su contrasenia es: "<< contrasenia<<std::endl;
                enter(); 
                std::cout<< std::endl<< std::endl;
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

                // Crear un nuevo objeto usuario con los datos ingresados
                usuario_nuevo = Usuarios(nombres, apellidos, fechaN, correo, contrasenia);
                usuario_nuevo.printUsuario();
                listaUsuarios.append(usuario_nuevo);
                break;

            case 3:
                std::cout << "3) INFORMACION"<< std::endl;
                std::cout << "- - - - - - - - - - - - - - - -"<< std::endl<< std::endl;
                std::cout << "Giovanni Concohá"<< std::endl<<"       202100229"<< std::endl<<std::endl;
                enter();
                std::cout << std::endl;
                break;

            case 4: 
                listaUsuarios.printAll();
                std::cout << "... adio"<<std::endl;
                break;

            default:
                std::cout << "opcion NO valida. Seleccione una de la 4 opciones";
                std::cout << "... presione ENTER para continuar..."<<std::endl;
                enter();
        }




    } while (opcion != 4);


    return 0;

}