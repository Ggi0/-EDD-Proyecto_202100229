#ifndef FORM_REGISTRARUSUARIOS_H
#define FORM_REGISTRARUSUARIOS_H

#include <QWidget>
#include <iostream>
#include "mainwindow.h"
#include "../../usuarios/arbolAVL/avl_usuario.h"
#include "../../usuarios/registroUsuarios.h"
#include "../../usuarios/global_usuariosAVL.h"

namespace Ui {
class Form_registrarUsuarios;
}

class Form_registrarUsuarios : public QWidget
{
    Q_OBJECT

public:
    explicit Form_registrarUsuarios(QWidget *parent = nullptr);
    ~Form_registrarUsuarios();

private slots:
    void on_btt_exit_clicked();

    void on_btt_registrar_clicked();

private:
    Ui::Form_registrarUsuarios *ui;

};

#endif // FORM_REGISTRARUSUARIOS_H
