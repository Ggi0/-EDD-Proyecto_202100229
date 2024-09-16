#ifndef FORM_ADMIN_H
#define FORM_ADMIN_H

#include <QWidget>
#include <QStackedWidget>
#include <QPushButton>

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

private:
    Ui::Form_admin *ui;
};

#endif // FORM_ADMIN_H
