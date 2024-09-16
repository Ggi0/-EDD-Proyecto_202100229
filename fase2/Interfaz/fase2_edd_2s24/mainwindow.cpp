#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "form_admin.h"
#include "form_registrarusuarios.h"
#include "form_usuario.h"

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
    // Obtén los textos de los QLineEdit
    QString username = ui->txt_user->text();
    QString password = ui->txt_pasword->text();

    // Verifica si coinciden con "admin" y "123"
    if (username == "admin" && password == "123") {
        // Crear una instancia de la nueva ventana
        Form_admin *formAdmin = new Form_admin(); // Ahora utiliza Form_admin
        formAdmin->show(); // Muestra la ventana form_admin

        // Cierra la ventana actual (login)
        this->close();
    }else if (username == "gio" && password == "gio") {
            // Crear una instancia de la nueva ventana
            Form_usuario *formUser = new Form_usuario(); // Ahora utiliza Form_admin
            formUser->show(); // Muestra la ventana form_admin

            // Cierra la ventana actual (login)
            this->close();

    } else {
        // Opcional: muestra un mensaje de error si las credenciales no coinciden
        QMessageBox::warning(this, "Login fallido", "Usuario o contraseña incorrectos.");
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

