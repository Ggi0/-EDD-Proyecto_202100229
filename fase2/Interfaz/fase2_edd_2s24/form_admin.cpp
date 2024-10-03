#include "form_admin.h"
#include "ui_form_admin.h"
#include "mainwindow.h"


Form_admin::Form_admin(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::Form_admin),
    modeloTabla(new AVLTableModel(this))

{
    ui->setupUi(this);
    // Muestra la página vacía (page_white) al inicio
    ui->stackedWidget->setCurrentWidget(ui->page_white);

    // Configurar el modelo en la tabla
    ui->tableView_buscar->setModel(modeloTabla);

    // Ajustar el tamaño de las columnas automáticamente
    ui->tableView_buscar->horizontalHeader()->setSectionResizeMode(QHeaderView::Stretch);

    // Permitir ordenamiento
    ui->tableView_buscar->setSortingEnabled(true);

    cbx_orden = ui->cbx_orden; // Inicialización correcta



}

Form_admin::~Form_admin()
{
    delete ui;
}

void Form_admin::on_btt_buscar_clicked()
{
    ui->stackedWidget->setCurrentWidget(ui->page_buscar);
    // Actualizar los datos de la tabla
    modeloTabla->actualizarDatosDesdeAVL(arbolGlobal_usuarios);

    // Ajustar el tamaño de las filas
    ui->tableView_buscar->resizeRowsToContents();
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


void Form_admin::on_btt_cUsuarios_clicked()
{
    // Abrir un diálogo de archivo para seleccionar un archivo .json
    QString qRutaArchivo = QFileDialog::getOpenFileName(this,
                                     tr("Abrir archivo JSON"),
                                     "",
                                     tr("Archivos JSON (*.json)"));  // Filtro para archivos JSON

    // Verificar si se seleccionó un archivo
    if (!qRutaArchivo.isEmpty()) {
        // Convertir la ruta de QString a std::string
        std::string rutaArchivo = qRutaArchivo.toStdString();

        // Remover comillas dobles si las hay
        rutaArchivo.erase(std::remove(rutaArchivo.begin(), rutaArchivo.end(), '\"'), rutaArchivo.end());

        // Llamar a la función leerUsuarios() pasando la ruta del archivo
        leerUsuarios(rutaArchivo);
        arbolGlobal_usuarios.graph();
    } else {
        // No se seleccionó ningún archivo, puedes mostrar un mensaje de error o advertencia
        qDebug() << "No se seleccionó ningún archivo.";
    }

}


void Form_admin::on_btt_cSolicitudes_clicked()
{
    // Abrir un diálogo de archivo para seleccionar un archivo .json
    QString qRutaArchivo = QFileDialog::getOpenFileName(this,
                                     tr("Abrir archivo JSON"),
                                     "",
                                     tr("Archivos JSON (*.json)"));  // Filtro para archivos JSON

    // Verificar si se seleccionó un archivo
    if (!qRutaArchivo.isEmpty()) {
        // Convertir la ruta de QString a std::string
        std::string rutaArchivo = qRutaArchivo.toStdString();

        // Remover comillas dobles si las hay
        rutaArchivo.erase(std::remove(rutaArchivo.begin(), rutaArchivo.end(), '\"'), rutaArchivo.end());

        // Llamar a la función leerUsuarios() pasando la ruta del archivo
        leerSolicitudes(rutaArchivo);
    } else {
        // No se seleccionó ningún archivo, puedes mostrar un mensaje de error o advertencia
        qDebug() << "No se seleccionó ningún archivo.";
    }


}


void Form_admin::on_btt_cPublicaciones_clicked()
{
    // Abrir un diálogo de archivo para seleccionar un archivo .json
    QString qRutaArchivo = QFileDialog::getOpenFileName(this,
                                     tr("Abrir archivo JSON"),
                                     "",
                                     tr("Archivos JSON (*.json)"));  // Filtro para archivos JSON

    // Verificar si se seleccionó un archivo
    if (!qRutaArchivo.isEmpty()) {
        // Convertir la ruta de QString a std::string
        std::string rutaArchivo = qRutaArchivo.toStdString();

        // Remover comillas dobles si las hay
        rutaArchivo.erase(std::remove(rutaArchivo.begin(), rutaArchivo.end(), '\"'), rutaArchivo.end());

        // Llamar a la función leerUsuarios() pasando la ruta del archivo
        leerPublicaciones(rutaArchivo);
    } else {
        // No se seleccionó ningún archivo, puedes mostrar un mensaje de error o advertencia
        qDebug() << "No se seleccionó ningún archivo.";
    }

}


void Form_admin::on_btt_buscar2_clicked()
{
    // Obtén los textos de los QLineEdit
    QString buscarUser = ui->txt_BusacarUser->text();    // usuario

    // Validar los campos, que no esten vacios
    if(buscarUser.isEmpty()) {
        QMessageBox::warning(this, "Error", "Agrega un usuariario para buscar");
        return;
    }

    // Convertir de QString a std::string
    std::string buscarUser_str = buscarUser.toStdString();
    // Llamar al método de búsqueda en el modelo
    modeloTabla->buscarYPosicionarUsuario(arbolGlobal_usuarios, buscarUser_str);
}


void Form_admin::on_cbx_orden_currentIndexChanged(int index)
{
    if (cbx_orden != nullptr) {
        QString selectedText = cbx_orden->itemText(index);
        qDebug() << "Índice seleccionado:" << index << ", Texto seleccionado:" << selectedText;

        // Actualizar la tabla según el recorrido seleccionado
        switch(index) {
            case 1: // PreOrden
                modeloTabla->actualizarDatosPreOrden(arbolGlobal_usuarios);
                break;
            case 2: // InOrden
                modeloTabla->actualizarDatosInOrden(arbolGlobal_usuarios);
                break;
            case 3: // PostOrden
                modeloTabla->actualizarDatosPostOrden(arbolGlobal_usuarios);
                break;
            case 0: // Orden por defecto
            default:
                modeloTabla->actualizarDatosDesdeAVL(arbolGlobal_usuarios);
                break;
        }

        // Ajustar el tamaño de las filas después de actualizar los datos
        ui->tableView_buscar->resizeRowsToContents();
    } else {
        qDebug() << "cbx_orden es nullptr";
    }
}


void Form_admin::on_btt_eliminarUser_clicked()
{
    // Obtén los textos de los QLineEdit
    QString buscarUser = ui->txt_BusacarUser->text();

    // Validar los campos, que no esten vacios
    if(buscarUser.isEmpty()) {
        QMessageBox::warning(this, "Error", "Agrega un usuariario para buscar");
        return;
    }

    // Convertir de QString a std::string
    std::string buscarUser_str = buscarUser.toStdString();
    // Llamar al método de búsqueda en el modelo
    modeloTabla->eliminarUsuario(arbolGlobal_usuarios, buscarUser_str);
    arbolGlobal_usuarios.graph();
}


void Form_admin::on_btt_generarReportes_clicked()
{
    arbolGlobal_usuarios.graph();
    // Crear una nueva escena
    QGraphicsScene* scene = new QGraphicsScene(this);

    // Cargar la imagen desde la ruta que conoces
    QPixmap image("/Users/gio/Desktop/Edd_2s24/lab_edd_2s24/-EDD-Proyecto_202100229/fase2/usuarios/reportes/AVL.png");

    // Verificar si la imagen se cargó correctamente
    if (!image.isNull()) {
        // Crear un item gráfico y agregarlo a la escena
        QGraphicsPixmapItem* item = new QGraphicsPixmapItem(image);
        scene->addItem(item);

        // Establecer la escena en el QGraphicsView
        ui->gView_AVL->setScene(scene);
    } else {
        // Mostrar un mensaje de error si la imagen no se pudo cargar
        qDebug() << "Error: No se pudo cargar la imagen.";
    }

    listaGlobal_publicaciones.graficar();
    // Crear una nueva escena
    QGraphicsScene* scene1 = new QGraphicsScene(this);

    // Cargar la imagen desde la ruta que conoces
    QPixmap listaGlobal_publicaciones("/Users/gio/Desktop/Edd_2s24/lab_edd_2s24/-EDD-Proyecto_202100229/fase2/usuarios/reportes/listaGlobal_publicaciones.png");

    // Verificar si la imagen se cargó correctamente
    if (!listaGlobal_publicaciones.isNull()) {
        // Crear un item gráfico y agregarlo a la escena
        QGraphicsPixmapItem* item = new QGraphicsPixmapItem(listaGlobal_publicaciones);
        scene1->addItem(item);

        // Establecer la escena en el QGraphicsView
        ui->gView_ListaPubli->setScene(scene1);
    } else {
        // Mostrar un mensaje de error si la imagen no se pudo cargar
        qDebug() << "Error: No se pudo cargar la imagen.";
    }


}

