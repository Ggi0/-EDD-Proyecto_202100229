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
    //this->close();

    // Crear una instancia de la nueva ventana
    MainWindow *formLogin = new MainWindow();
    formLogin->show(); // regresa al login

    arbolGlobal_usuarios.graph();

    // Cierra la ventana actual (form_registrarusuarios)
    this->close();
}


void Form_registrarUsuarios::on_btt_registrar_clicked()
{
    // Obtener los valores de los QLineEdit
    QString nombres = ui->txt_nombres->text();
    QString apellidos = ui->txt_apellidos->text();
    QString fechaNac = ui->txt_fechaNac->text();
    QString correo = ui->txt_correo->text();
    QString contrasenia = ui->txt_contrasenia->text();

    // Validar los campos, que no esten vacios
    if(nombres.isEmpty() || apellidos.isEmpty() || fechaNac.isEmpty() ||  correo.isEmpty() || contrasenia.isEmpty()) {
        QMessageBox::warning(this, "Error", "Todos los campos deben estar completos.");
        return;
    }

    // Convertir de QString a std::string
    std::string nombre_str = nombres.toStdString();
    std::string apellido_str = apellidos.toStdString();
    std::string fechaN_str = fechaNac.toStdString();
    std::string correo_str = correo.toStdString();
    std::string contrasena_str = contrasenia.toStdString();

    // Guardar la información llamando a la función verficarCorreo(atributos)

    // Llamar a la función verificarCorreo pasando std::string
    int resultado = verificarCorreo(nombre_str, apellido_str, fechaN_str, correo_str, contrasena_str);

    if (resultado == 1){
        QMessageBox::information(this, "Estado", "Usuario agregado exitosamente");
    }else if (resultado == 0) {
        QMessageBox::warning(this, "Estado", "Correo electrónico ya existente en el sistema");
    }else{
        QMessageBox::warning(this, "Error", "Inconsistene al ingresar el usuario");
    }

    // Limpiar los campos después de registrar
    ui->txt_nombres->clear();
    ui->txt_apellidos->clear();
    ui->txt_fechaNac->clear();
    ui->txt_correo->clear();
    ui->txt_contrasenia->clear();

}

