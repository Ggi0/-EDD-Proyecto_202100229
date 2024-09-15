#include "form_usuario.h"
#include "ui_form_usuario.h"

Form_USUARIO::Form_USUARIO(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::Form_USUARIO)
{
    ui->setupUi(this);
}

Form_USUARIO::~Form_USUARIO()
{
    delete ui;
}
