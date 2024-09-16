#include "form_usuario.h"
#include "ui_form_usuario.h"
#include "mainwindow.h"

Form_usuario::Form_usuario(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::Form_usuario)
{
    ui->setupUi(this);
}

Form_usuario::~Form_usuario()
{
    delete ui;
}

void Form_usuario::on_btt_cerrarSesion_clicked()
{
    // Crear una instancia de la nueva ventana
    MainWindow *formLogin = new MainWindow();
    formLogin->show(); // regresa al login

    // Cierra la ventana actual (form_admin)
    this->close();

}

