#ifndef FORM_ADMIN_H
#define FORM_ADMIN_H

#include <QWidget>
#include <QStackedWidget>
#include <QFileDialog>
#include <QString>
#include <string>
#include <QDebug>
#include <QComboBox>

#include <QGraphicsPixmapItem>
#include <QGraphicsScene>
#include <QPixmap>

#include <QMessageBox>
#include <algorithm> // para usar std::remove
#include "../../administracion/leerJson.h"
#include "../../usuarios/global_usuariosAVL.h"
#include "../../publicaciones/global_data_publicaciones.h"

#include "../../usuarios/arbolAVL/AVLTableModel.h"

namespace Ui {
class Form_admin;
}

class Form_admin : public QWidget
{
    Q_OBJECT

public:
    explicit Form_admin(QWidget *parent = nullptr);
    ~Form_admin();

private slots:
    void on_btt_buscar_clicked();

    void on_btt_cargarAr_clicked();

    void on_btt_reportes_clicked();

    void on_btt_cerrarSesion_clicked();

    void on_btt_cUsuarios_clicked();

    void on_btt_cSolicitudes_clicked();

    void on_btt_cPublicaciones_clicked();

    void on_btt_buscar2_clicked();

    void on_cbx_orden_currentIndexChanged(int index);

    void on_btt_eliminarUser_clicked();

    void on_btt_generarReportes_clicked();

private:
    Ui::Form_admin *ui;
    AVLTableModel *modeloTabla;
    QComboBox *cbx_orden;



};

#endif // FORM_ADMIN_H
