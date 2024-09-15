#ifndef FORM_USUARIO_H
#define FORM_USUARIO_H

#include <QWidget>

namespace Ui {
class Form_USUARIO;
}

class Form_USUARIO : public QWidget
{
    Q_OBJECT

public:
    explicit Form_USUARIO(QWidget *parent = nullptr);
    ~Form_USUARIO();

private:
    Ui::Form_USUARIO *ui;
};

#endif // FORM_USUARIO_H
