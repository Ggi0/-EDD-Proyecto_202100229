#include "form_registrarusuarios.h"
#include "ui_form_registrarusuarios.h"

Form_registrarUsuarios::Form_registrarUsuarios(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::Form_registrarUsuarios)
{
    ui->setupUi(this);
}

Form_registrarUsuarios::~Form_registrarUsuarios()
{
    delete ui;
}

void Form_registrarUsuarios::on_btt_exit_clicked()
{
    // Cierra la ventana actual (Registro de usuarios)
    this->close();
}

