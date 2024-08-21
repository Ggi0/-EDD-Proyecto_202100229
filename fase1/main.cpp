
#include "listaEnlazada/listaSimpleEnlazada.h"
#include <string>


void enter() {
    std::cout << "Presiona Enter para continuar..." << std::endl;
    std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n'); // Ignora cualquier entrada previa hasta encontrar un salto de línea
    std::cin.get(); // Espera a que el usuario presione Enter
}

int main(int argc, char const *argv[]){

    int opcion;
    std::string correo;
    std::string contrasena;

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
                std::getline(std::cin >> std::ws, contrasena);  // Leer la contraseña ingresada por el usuario

                std::cout <<"su correo es: "<< correo<<std::endl; 
                std::cout <<"su contrasenia es: "<< contrasena<<std::endl;
                enter(); 
                std::cout<< std::endl<< std::endl;
                break;

            case 2:
                std::cout << "2) REGISTRARSE"<< std::endl;
                std::cout << "- - - - - - - - - - - - - - - -"<< std::endl<< std::endl;
                // registrar a un usuario nuevo
                std::cout<< std::endl<< std::endl;
                break;

            case 3:
                std::cout << "3) INFORMACION"<< std::endl;
                std::cout << "- - - - - - - - - - - - - - - -"<< std::endl<< std::endl;
                std::cout << "Giovanni Concohá"<< std::endl<<"       202100229"<< std::endl<<std::endl;
                enter();
                std::cout << std::endl;
                break;

            case 4: 
                std::cout << "... adio"<<std::endl;
                break;

            default:
                std::cout << "opcion NO valida. Seleccione una de la 4 opciones";
                std::cout << "... presione ENTER para continuar..."<<std::endl;
                enter();
        }




    } while (opcion != 4);
    
    //prueba de lista enlazada
    /*
    listaSimpleEnlazada list;
    list.push(12);
    list.push(4);
    list.push(23);
    list.push(3);
    list.push(78);
    list.push(47);

    list.append(500);
    list.insert(3, 999);

    list.print();
    */


    return 0;

}