#ifndef FORM_USUARIO_H
#define FORM_USUARIO_H

#include <QWidget>

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

private:
    Ui::Form_usuario *ui;
};

#endif // FORM_USUARIO_H
