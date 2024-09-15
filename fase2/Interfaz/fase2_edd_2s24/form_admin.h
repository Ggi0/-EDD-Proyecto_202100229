#ifndef FORM_ADMIN_H
#define FORM_ADMIN_H

#include <QWidget>

namespace Ui {
class Form_admin;
}

class Form_admin : public QWidget
{
    Q_OBJECT

public:
    explicit Form_admin(QWidget *parent = nullptr);
    ~Form_admin();

private:
    Ui::Form_admin *ui;
};

#endif // FORM_ADMIN_H
