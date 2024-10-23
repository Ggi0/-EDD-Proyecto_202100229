#include "mainwindow.h"
#include "ui_mainwindow.h"

#include "form_admin.h"
#include "form_registrarusuarios.h"
#include "form_usuario.h"

#include "../../publicaciones/arbolBinario/bst_publi.h"
#include "../../publicaciones/comentario/listaComentarios/lista_comentarios.h"
#include "../../publicaciones/comentario/comentario.h"
//#include "../../publicaciones/comentario/arbolB/arbolB.h"
#include "../../usuarios/usuario.h"

#include "../../usuarios/global_usuariosAVL.h"

#include "../../publicaciones/publicacion.h"
#include "../../publicaciones/comentario/listaComentarios/lista_comentarios.h"
#include "../../publicaciones/registroPublicaciones.h"

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);

}


MainWindow::~MainWindow()
{
    delete ui;
}


// ------------ BOTON LOGIN -----------------
void MainWindow::on_btt_login_clicked()
{
    std::string loginUser_global;


    // Obtén los textos de los QLineEdit
    QString username = ui->txt_user->text();    // usuario
    QString password = ui->txt_pasword->text(); // contrasenia

    // Validar los campos, que no esten vacios
    if(username.isEmpty() || password.isEmpty()) {
        QMessageBox::warning(this, "Error", "Todos los campos deben estar completos.");
        return;
    }

    // Convertir de QString a std::string
    std::string username_str = username.toStdString();
    std::string password_str = password.toStdString();

    // Llamar la funcion para verficar el LOGIN
    int resultado = iniciarSesion(username_str, password_str);

    if (resultado == 0){ // error login
        QMessageBox::warning(this, "Login fallido", "Usuario o contraseña incorrectos.");
    }else if (resultado == 1) { // acceso usuarios

        /*   // probando si se puede graficar por fecha. (si se puede)
        NodoAVL* usue_preuba = arbolGlobal_usuarios.buscarPorCorreo(username_str);
        Usuarios& usuario = usue_preuba->getData();
        usuario.graficar_fecha("22/08/2024");
        */

        // Crear una instancia de la nueva ventana
        Form_usuario *formUser = new Form_usuario(); // Ahora utiliza Form_usuario
        formUser->show(); // Muestra la ventana form_usuario
        // Cierra la ventana actual (login)
        this->close();

    }else if (resultado == 2){
        // Crear una instancia de la nueva ventana
        Form_admin *formAdmin = new Form_admin(); // Ahora utiliza Form_admin (ventana de ADMIN)
        formAdmin->show(); // Muestra la ventana form_admin
        // Cierra la ventana actual (login)
        this->close();

    }

    if (username == "gio" && password == "gio") {
                // Crear una instancia de la nueva ventana
                Form_usuario *formUser = new Form_usuario(); // Ahora utiliza Form_admin
                formUser->show(); // Muestra la ventana form_admin

                // Cierra la ventana actual (login)
                this->close();
    }


}




void MainWindow::on_btt_registro_clicked()
{
    // Crear una instancia de la nueva ventana
    Form_registrarUsuarios *formRegistroUsuarios = new Form_registrarUsuarios(); // Ahora utiliza Form_admin
    formRegistroUsuarios->show(); // Muestra la ventana form_admin

    // Cierra la ventana actual (login)
    this->close();

}

