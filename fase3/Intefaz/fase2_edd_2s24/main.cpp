#include "mainwindow.h"

#include <QApplication>

#include "../../seguridad/seguridad.h"
#include "../../seguridad/bloques/registrarBlock.h"

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    MainWindow w;

    descomprimirUsuarios();
    //leerbpBlockchain();
    //leerBackup_Usuarios();

    w.show();
    return a.exec();
}
