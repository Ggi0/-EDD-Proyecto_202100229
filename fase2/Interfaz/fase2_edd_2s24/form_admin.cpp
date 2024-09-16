#include "form_admin.h"
#include "ui_form_admin.h"
#include "mainwindow.h"


Form_admin::Form_admin(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::Form_admin)
{
    ui->setupUi(this);
    // Muestra la página vacía (page_white) al inicio
    ui->stackedWidget->setCurrentWidget(ui->page_white);
}

Form_admin::~Form_admin()
{
    delete ui;
}

void Form_admin::on_btt_buscar_clicked()
{
    ui->stackedWidget->setCurrentWidget(ui->page_buscar);
}


void Form_admin::on_btt_cargarAr_clicked()
{
    ui->stackedWidget->setCurrentWidget(ui->page_cargaAr);
}


void Form_admin::on_btt_reportes_clicked()
{
    ui->stackedWidget->setCurrentWidget(ui->page_reportes);
}


void Form_admin::on_btt_cerrarSesion_clicked()
{
    // Crear una instancia de la nueva ventana
    MainWindow *formLogin = new MainWindow();
    formLogin->show(); // regresa al login

    // Cierra la ventana actual (form_admin)
    this->close();
}

