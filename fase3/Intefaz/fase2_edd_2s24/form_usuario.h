#ifndef FORM_USUARIO_H
#define FORM_USUARIO_H

#include <QWidget>
#include <QStackedWidget>

#include <QString>
#include <QLabel>
#include <string>
#include <QLineEdit>
#include <iostream>
#include <string>
#include <QDebug>

#include <QGraphicsPixmapItem>
#include <QGraphicsScene>
#include <QPixmap>

#include "../../solicitudes/registroSolicitudes.h"
#include "../../solicitudes/global_relacionesAmistad.h"
#include "../../usuarios/global_usuariosAVL.h"
#include "../../usuarios/perfilUsuario.h"
#include "../modelosTablas/modeloEnviarSoli/UsuariosTableModel.h"
#include "../modelosTablas/modeloPila/SoliRecividasTableModel.h"
#include "../modelosTablas/modeloLista/listaEnvTableModel.h"


namespace Ui {
class Form_usuario;
}

class Form_usuario : public QWidget
{
    Q_OBJECT

public:
    explicit Form_usuario(QWidget *parent = nullptr);
    ~Form_usuario();

private slots:
    void on_btt_cerrarSesion_clicked();

    void on_btt_buscar_clicked();

    void on_btt_publicaciones_clicked();

    void on_btt_solicitudes_clicked(); // solicitudes

    void on_btt_reportes_clicked();

    void on_btt_perfil_clicked();

    void on_btt_buscar2_clicked();

    void on_btt_publicar_clicked();

    void on_btt_hacerPubli_clicked();

    void on_btt_modificarDatos_clicked();

    void on_btt_modificarDatos_2_clicked();

    void actualizar_panelTexto();

    void on_btt_eliminarDatos_clicked();

    void procesarClickTabla(const QModelIndex &index);  // Nuevo slot para manejar clicks
    void procesarClickTablaSolicitudes(const QModelIndex &index);  // Slot para manejar acciones en la tabla
    void procesarClickTablaSolicitudesEnviadas(const QModelIndex &index);  // Slot para manejar la acción de cancelar



private:
    Ui::Form_usuario *ui;
    UsuariosTableModel *modeloTabla;
    SoliRecividasTableModel *modeloTablaSolicitudes;  // Modelo de tabla para solicitudes recibidas
    listaEnvTableModel *modeloTablaSolicitudesEnviadas;  // Modelo de tabla para solicitudes enviadas


    std::string correoSeleccionado;  // Variable para guardar el correo seleccionado

};

#endif // FORM_USUARIO_H
