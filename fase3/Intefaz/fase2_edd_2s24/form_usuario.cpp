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


}


void Form_usuario::on_btt_reportes_clicked()
{
    ui->stackedWidget->setCurrentWidget(ui->page_reportes);

}


void Form_usuario::on_btt_perfil_clicked()
{
    ui->stackedWidget->setCurrentWidget(ui->page_perfil);

    actualizar_panelTexto();

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


void Form_usuario::on_btt_modificarDatos_clicked()
{
    ui->stackedWidget->setCurrentWidget(ui->page_edtiPerfil);
    std::string correoActual;
    correoActual = loginUser_global;
    NodoAVL* usuarioActual = arbolGlobal_usuarios.buscarPorCorreo(correoActual);

    // obtener la informacion del usuario
    std::string nombre = usuarioActual->getData().getNombres();
    std::string apellido = usuarioActual->getData().getApellidos();
    std::string contrasenia = usuarioActual->getData().getContrasenia();
    std::string fecha = usuarioActual->getData().getFechaN();
    std::string correo = usuarioActual->getData().getCorreo();

    //cambiar de string a QString
    QString viewNombre = QString::fromStdString(nombre);
    QString viewApellido = QString::fromStdString(apellido);
    QString viewContra = QString::fromStdString(contrasenia);
    QString viewFecha = QString::fromStdString(fecha);
    QString viewCorreo = QString::fromStdString(correo);


    // para hacer no editable el panel de texto
    ui->txt_correo_2->setReadOnly(true);

    // colocar la información del usuario en el pantalla

    ui->txt_nombres_2->setText(viewNombre);
    ui->txt_apellidos_2->setText(viewApellido);
    ui->txt_contrasenia_2->setText(viewContra);
    ui->txt_fechaNac_2->setText(viewFecha);
    ui->txt_correo_2->setText(viewCorreo);

}


void Form_usuario::on_btt_modificarDatos_2_clicked()
{
    // Obtener los valores de los QLineEdit
    QString nombresE = ui->txt_nombres_2->text();
    QString apellidosE = ui->txt_apellidos_2->text();
    QString fechaNacE = ui->txt_fechaNac_2->text();
    QString contraseniaE = ui->txt_contrasenia_2->text();

    // Validar los campos, que no esten vacios
    if(nombresE.isEmpty() || apellidosE.isEmpty() || fechaNacE.isEmpty() || contraseniaE.isEmpty()) {
        QMessageBox::warning(this, "Error", "Todos los campos deben estar completos.");
        return;
    }

    // Convertir de QString a std::string
    std::string nombre_edit = nombresE.toStdString();
    std::string apellido_edit = apellidosE.toStdString();
    std::string fechaN_edit = fechaNacE.toStdString();
    std::string contrasena_edit = contraseniaE.toStdString();

    std::string correoActual;
    correoActual = loginUser_global;
    NodoAVL* usuarioActual = arbolGlobal_usuarios.buscarPorCorreo(correoActual);

    usuarioActual->getData().modificarDatos(nombre_edit, apellido_edit, contrasena_edit, fechaN_edit);
    actualizar_panelTexto();
    ui->stackedWidget->setCurrentWidget(ui->page_perfil);
    QMessageBox::information(this, "Estado", "Actualización de datos exitosa!");

}

void Form_usuario::actualizar_panelTexto()
{
    // Crear una nueva escena
    QGraphicsScene* scene = new QGraphicsScene(this);

    // Cargar la imagen desde la ruta que conoces
    QPixmap image("/Users/gio/Desktop/Edd_2s24/lab_edd_2s24/-EDD-Proyecto_202100229/fase3/imagenes/image_user.png");

    // Verificar si la imagen se cargó correctamente
    if (!image.isNull()) {
        // Obtener el tamaño del QGraphicsView
        QSize viewSize = ui->view_grphUser->size();

        // Ajustar la imagen exactamente al tamaño del QGraphicsView sin mantener la proporción
        QPixmap scaledImage = image.scaled(viewSize, Qt::IgnoreAspectRatio, Qt::SmoothTransformation);

        // Crear un item gráfico con la imagen ajustada y agregarlo a la escena
        QGraphicsPixmapItem* item = new QGraphicsPixmapItem(scaledImage);
        scene->addItem(item);

        // Establecer la escena en el QGraphicsView
        ui->view_grphUser->setScene(scene);

        // Asegurar que la imagen se ajuste al tamaño del QGraphicsView
        ui->view_grphUser->fitInView(item, Qt::IgnoreAspectRatio);

    } else {
        // Mostrar un mensaje de error si la imagen no se pudo cargar
        qDebug() << "Error: No se pudo cargar la imagen.";
    }



    std::string correoActual;
    correoActual = loginUser_global;
    NodoAVL* usuarioActual = arbolGlobal_usuarios.buscarPorCorreo(correoActual);

    // obtener la informacion del usuario
    std::string nombre = usuarioActual->getData().getNombres();
    std::string apellido = usuarioActual->getData().getApellidos();
    std::string contrasenia = usuarioActual->getData().getContrasenia();
    std::string fecha = usuarioActual->getData().getFechaN();
    std::string correo = usuarioActual->getData().getCorreo();

    //cambiar de string a QString
    QString viewNombre = QString::fromStdString(nombre);
    QString viewApellido = QString::fromStdString(apellido);
    QString viewContra = QString::fromStdString(contrasenia);
    QString viewFecha = QString::fromStdString(fecha);
    QString viewCorreo = QString::fromStdString(correo);


    // para hacer no editable el panel de texto
    ui->txt_nombres->setReadOnly(true);
    ui->txt_apellidos->setReadOnly(true);
    ui->txt_contrasenia->setReadOnly(true);
    ui->txt_fechaNac->setReadOnly(true);
    ui->txt_correo->setReadOnly(true);

    // colocar la información del usuario en el pantalla

    ui->txt_nombres->setText(viewNombre);
    ui->txt_apellidos->setText(viewApellido);
    ui->txt_contrasenia->setText(viewContra);
    ui->txt_fechaNac->setText(viewFecha);
    ui->txt_correo->setText(viewCorreo);
}


void Form_usuario::on_btt_eliminarDatos_clicked()
{
    std::string correoActual;
    correoActual = loginUser_global;

    QMessageBox::StandardButton reply;
    reply = QMessageBox::question(this, "Confirmación", "¿Estás seguro de eliminar tu cuenta??",
                                  QMessageBox::Yes | QMessageBox::No);

    if (reply == QMessageBox::Yes) {
        // Acción si el usuario selecciona "Sí"
        arbolGlobal_usuarios.delPorCorreo(correoActual);
        std::cout << "Cuenta eliminada exitosamente"<< std::endl;

        // mandar al login:
        // Crear una instancia de la nueva ventana
        MainWindow *formLogin = new MainWindow();
        formLogin->show(); // regresa al login

        // Cierra la ventana actual (form_admin)
        this->close();

    } else {
        // Acción si el usuario selecciona "No"
        std::cout << "Se cancelo la elimininación de la cuenta"<< std::endl;
    }


}

