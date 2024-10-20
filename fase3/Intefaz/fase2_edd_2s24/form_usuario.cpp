#include "form_usuario.h"
#include "ui_form_usuario.h"
#include "mainwindow.h"

Form_usuario::Form_usuario(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::Form_usuario)
{
    ui->setupUi(this);
    // Muestra la página vacía (page_white) al inicio
    ui->stackedWidget->setCurrentWidget(ui->page_white);

    //cambiar name:
    QString texto_ap = QString::fromStdString(loginUser_global);
    // Asignar el texto al QLabel
    ui->lbl_tituloUser->setText(texto_ap);

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

void Form_usuario::on_btt_buscar_clicked()
{
    ui->stackedWidget->setCurrentWidget(ui->page_buscar);
    std::cout<< "valor del string global: "<< loginUser_global<< std::endl;
}


void Form_usuario::on_btt_publicaciones_clicked()
{
    ui->stackedWidget->setCurrentWidget(ui->page_publi);

}


void Form_usuario::on_btt_solicitudes_clicked()
{
    ui->stackedWidget->setCurrentWidget(ui->page_soli);

    /*// logica para manejar las solicitudes
    std::cout<<"--------------------------------"<< std::endl;
    registroSolicitudes("gio1", "gio4", "PENDIENTE");
    std::cout<<"--------------------------------"<< std::endl;
    registroSolicitudes("gio3", "gio6", "ACEPTADA");
    std::cout<<"--------------------------------"<< std::endl;
    registroSolicitudes("gio1", "gio4", "PENDIENTE");
    std::cout<<"--------------------------------"<< std::endl;
    registroSolicitudes("gio4", "gio1", "PENDIENTE");


    std::cout<<"--------------------------------"<< std::endl;
    registroSolicitudes("gio4", "gio1", "ACEPTADA");
    std::cout<<"--------------------------------"<< std::endl;
    registroSolicitudes("gio4", "gio1", "ACEPTADA");


    std::cout<<"--------------------------------"<< std::endl;
    registroSolicitudes("gio2", "gio4", "PENDIENTE");
    std::cout<<"--------------------------------"<< std::endl;
    registroSolicitudes("gio4", "gio2", "RECHAZADA");

    //std::cout<<"esta retornando: "<< result<< std::endl;*/

}


void Form_usuario::on_btt_reportes_clicked()
{
    ui->stackedWidget->setCurrentWidget(ui->page_reportes);

}


void Form_usuario::on_btt_perfil_clicked()
{
    ui->stackedWidget->setCurrentWidget(ui->page_perfil);
}


void Form_usuario::on_btt_buscar2_clicked()
{
    // Obtén los textos de los QLineEdit
    QString buscarUser = ui->txt_buscarUser->text();    // usuario

    // Validar los campos, que no esten vacios
    if(buscarUser.isEmpty()) {
        QMessageBox::warning(this, "Error", "Agrega un usuariario para buscar");
        return;
    }

    // Convertir de QString a std::string
    std::string buscarUser_str = buscarUser.toStdString();
    // Llamar al método de búsqueda en el modelo
    NodoAVL* usuarioEncontrado = arbolGlobal_usuarios.buscarPorCorreo(buscarUser_str);
    if (usuarioEncontrado != nullptr) {
        // ------ NOMBRE -----------
        std::string nombre_find = usuarioEncontrado->getData().getNombres();
        QString texto_nombre = QString::fromStdString(nombre_find);
        // Asignar el texto al QLabel
        ui->lbl_nombreUserfind->setText(texto_nombre);

        // ------ APELLIDO -----------
        std::string apellido_find = usuarioEncontrado->getData().getApellidos();
        QString texto_ap = QString::fromStdString(apellido_find);
        // Asignar el texto al QLabel
        ui->lbl_apellidoUserfind->setText(texto_ap);

        // ------ CORREO -----------
        std::string c_find = usuarioEncontrado->getData().getCorreo();
        QString texto_c = QString::fromStdString(c_find);
        // Asignar el texto al QLabel
        ui->lbl_correoUserfind->setText(texto_c);

        // ------ FECHA DE NACIMIENTO -----------
        std::string date_find = usuarioEncontrado->getData().getFechaN();
        QString texto_date = QString::fromStdString(date_find);
        // Asignar el texto al QLabel
        ui->lbl_dateUserfind->setText(texto_date);
    }else {
        QMessageBox::warning(this, "Error", "El correo ingresado no coincide con ningun USUARIO");
        ui->lbl_nombreUserfind->setText("");
        ui->lbl_apellidoUserfind->setText("");
        ui->lbl_correoUserfind->setText("");
        ui->lbl_dateUserfind->setText("");

    }
}


void Form_usuario::on_btt_publicar_clicked()
{
    // Obtén los textos de los QLineEdit
    QString contenido_publi = ui->txt_hacerPubli->text();    // usuario

    // Validar los campos, que no esten vacios
    if(contenido_publi.isEmpty()) {
        QMessageBox::warning(this, "Error", "Agrega algo para comentar");
        return;
    }

    // Convertir de QString a std::string
    std::string contenido_str = contenido_publi.toStdString();

    std::string correoActual = loginUser_global;

    hacerPublicacion(correoActual, contenido_str);

    ui->stackedWidget->setCurrentWidget(ui->page_publi);


}


void Form_usuario::on_btt_hacerPubli_clicked()
{
    ui->stackedWidget->setCurrentWidget(ui->page_hacerPubli);

}

