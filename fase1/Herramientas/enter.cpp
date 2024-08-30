// para que cin solo acepte int
#include "enter.h"
#include <limits>
#include <iostream>


void enter() {
    std::cout << "Presiona Enter para continuar..." << std::endl;
    std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n'); // Ignora cualquier entrada previa hasta encontrar un salto de línea
    std::cin.get(); // Espera a que el usuario presione Enter
}