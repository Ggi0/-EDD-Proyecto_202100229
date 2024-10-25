#ifndef FORM_USUARIO_H
#define FORM_USUARIO_H

#include <QWidget>
#include <QStackedWidget>

#include <QString>
#include <QLabel>
#include <string>

#include "../../solicitudes/registroSolicitudes.h"
#include "../../usuarios/global_usuariosAVL.h"
#include "../../usuarios/perfilUsuario.h"

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

    void on_btt_solicitudes_clicked();

    void on_btt_reportes_clicked();

    void on_btt_perfil_clicked();

    void on_btt_buscar2_clicked();

    void on_btt_publicar_clicked();

    void on_btt_hacerPubli_clicked();

private:
    Ui::Form_usuario *ui;
};

#endif // FORM_USUARIO_H
