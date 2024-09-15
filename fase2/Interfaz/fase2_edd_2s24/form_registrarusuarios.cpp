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
