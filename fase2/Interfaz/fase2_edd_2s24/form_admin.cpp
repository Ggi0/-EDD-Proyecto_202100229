#include "form_admin.h"
#include "ui_form_admin.h"

Form_admin::Form_admin(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::Form_admin)
{
    ui->setupUi(this);
}

Form_admin::~Form_admin()
{
    delete ui;
}
