#ifndef MENU_USUARIO_H
#define MENU_USUARIO_H
#include <string>
#include <iostream>
#include <iomanip>
#include <ctime>
#include <sstream>
#include "../Solicitudes/registroSolicitudes.h"

void menuUsuario(std::string correo);

void verPerfil(std::string correo);
void eliminarCuenta(std::string correo);

void verSolicitud(std::string correo);
void enviarSolicitud(std::string correo);

void verPublicaciones(std::string correo);
void hacerPublicacion(std::string correo);

std::string obtenerFechaActual();
std::string obtenerHoraActual();

void imprimirReportes(std::string correo);


#endif // MENU_USUARIO_H