/********************************************************************************
** Form generated from reading UI file 'form_registrarusuarios.ui'
**
** Created by: Qt User Interface Compiler version 5.15.2
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_FORM_REGISTRARUSUARIOS_H
#define UI_FORM_REGISTRARUSUARIOS_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QFrame>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_Form_registrarUsuarios
{
public:
    QFrame *frame;
    QLineEdit *txt_nombres;
    QLineEdit *txt_apellidos;
    QLineEdit *txt_fechaNac;
    QLineEdit *txt_correo;
    QLineEdit *txt_contrasenia;
    QLabel *label_2;
    QLabel *label_3;
    QLabel *label_4;
    QLabel *label_5;
    QLabel *label_6;
    QLabel *label_7;
    QPushButton *btt_registrar;
    QPushButton *btt_exit;
    QLabel *label;

    void setupUi(QWidget *Form_registrarUsuarios)
    {
        if (Form_registrarUsuarios->objectName().isEmpty())
            Form_registrarUsuarios->setObjectName(QString::fromUtf8("Form_registrarUsuarios"));
        Form_registrarUsuarios->resize(638, 533);
        Form_registrarUsuarios->setStyleSheet(QString::fromUtf8("QWidget#Form_registrarUsuarios {\n"
"    background: qlineargradient(\n"
"        spread: pad, \n"
"        x1: 0, y1: 0, \n"
"        x2: 1, y2: 1, \n"
"        stop: 0 #A1C4FD, \n"
"        stop: 1 #C2E9FB\n"
"    ); /* Degradado de azul suave a azul pastel */\n"
"    padding: 10px;\n"
"}\n"
""));
        frame = new QFrame(Form_registrarUsuarios);
        frame->setObjectName(QString::fromUtf8("frame"));
        frame->setGeometry(QRect(80, 90, 471, 401));
        frame->setStyleSheet(QString::fromUtf8("QFrame#frame {\n"
"    background-color: #E0F7FA; /* Azul claro con un toque vibrante */\n"
"    border: 2px solid #00796B; /* Borde en verde azulado para un contraste atractivo */\n"
"    border-radius: 5px; /* Bordes redondeados para suavidad */\n"
"    padding: 15px; /* Espacio interno mayor para mejor estructura */\n"
"    \n"
"\n"
"\n"
"    /* Agregar un degradado sutil para darle m\303\241s dimensi\303\263n */\n"
"    background: qlineargradient(\n"
"        spread: pad, \n"
"        x1: 0, y1: 0, \n"
"        x2: 1, y2: 1, \n"
"        stop: 0 #E0F7FA, \n"
"        stop: 1 #B2EBF2\n"
"    ); /* Degradado azul claro a un tono m\303\241s fresco */\n"
"}\n"
""));
        frame->setFrameShape(QFrame::StyledPanel);
        frame->setFrameShadow(QFrame::Raised);
        txt_nombres = new QLineEdit(frame);
        txt_nombres->setObjectName(QString::fromUtf8("txt_nombres"));
        txt_nombres->setGeometry(QRect(220, 70, 231, 31));
        QFont font;
        font.setFamily(QString::fromUtf8("Kohinoor Devanagari"));
        font.setPointSize(16);
        txt_nombres->setFont(font);
        txt_nombres->setEchoMode(QLineEdit::Normal);
        txt_apellidos = new QLineEdit(frame);
        txt_apellidos->setObjectName(QString::fromUtf8("txt_apellidos"));
        txt_apellidos->setGeometry(QRect(220, 120, 231, 31));
        txt_apellidos->setFont(font);
        txt_apellidos->setEchoMode(QLineEdit::Normal);
        txt_fechaNac = new QLineEdit(frame);
        txt_fechaNac->setObjectName(QString::fromUtf8("txt_fechaNac"));
        txt_fechaNac->setGeometry(QRect(220, 170, 231, 31));
        txt_fechaNac->setFont(font);
        txt_fechaNac->setEchoMode(QLineEdit::Normal);
        txt_correo = new QLineEdit(frame);
        txt_correo->setObjectName(QString::fromUtf8("txt_correo"));
        txt_correo->setGeometry(QRect(220, 220, 231, 31));
        txt_correo->setFont(font);
        txt_correo->setEchoMode(QLineEdit::Normal);
        txt_contrasenia = new QLineEdit(frame);
        txt_contrasenia->setObjectName(QString::fromUtf8("txt_contrasenia"));
        txt_contrasenia->setGeometry(QRect(220, 270, 231, 31));
        txt_contrasenia->setFont(font);
        txt_contrasenia->setEchoMode(QLineEdit::Normal);
        label_2 = new QLabel(frame);
        label_2->setObjectName(QString::fromUtf8("label_2"));
        label_2->setGeometry(QRect(10, 20, 361, 31));
        QFont font1;
        font1.setFamily(QString::fromUtf8("Kohinoor Devanagari"));
        font1.setPointSize(30);
        font1.setBold(true);
        font1.setWeight(75);
        label_2->setFont(font1);
        label_3 = new QLabel(frame);
        label_3->setObjectName(QString::fromUtf8("label_3"));
        label_3->setGeometry(QRect(10, 70, 91, 31));
        QFont font2;
        font2.setFamily(QString::fromUtf8("Kohinoor Devanagari"));
        font2.setPointSize(20);
        font2.setBold(false);
        font2.setWeight(50);
        label_3->setFont(font2);
        label_4 = new QLabel(frame);
        label_4->setObjectName(QString::fromUtf8("label_4"));
        label_4->setGeometry(QRect(10, 120, 91, 31));
        label_4->setFont(font2);
        label_5 = new QLabel(frame);
        label_5->setObjectName(QString::fromUtf8("label_5"));
        label_5->setGeometry(QRect(10, 270, 121, 31));
        label_5->setFont(font2);
        label_6 = new QLabel(frame);
        label_6->setObjectName(QString::fromUtf8("label_6"));
        label_6->setGeometry(QRect(10, 170, 201, 31));
        label_6->setFont(font2);
        label_7 = new QLabel(frame);
        label_7->setObjectName(QString::fromUtf8("label_7"));
        label_7->setGeometry(QRect(10, 220, 201, 31));
        label_7->setFont(font2);
        btt_registrar = new QPushButton(frame);
        btt_registrar->setObjectName(QString::fromUtf8("btt_registrar"));
        btt_registrar->setGeometry(QRect(200, 330, 112, 41));
        QFont font3;
        font3.setFamily(QString::fromUtf8("Kohinoor Devanagari"));
        btt_registrar->setFont(font3);
        btt_registrar->setStyleSheet(QString::fromUtf8("QPushButton#btt_registrar {\n"
"background: qlineargradient(\n"
"    spread: pad, \n"
"    x1: 0, y1: 0, \n"
"    x2: 1, y2: 1, \n"
"    stop: 0 #5DADE2, /* Azul m\303\241s claro */\n"
"    stop: 1 #85C1E9  /* Azul a\303\272n m\303\241s claro */\n"
"); /* Degradado de azul claro a azul m\303\241s claro */\n"
"\n"
"    color: #FFFFFF; /* Texto blanco para buen contraste */\n"
"    border: 2px solid #3498DB; /* Borde m\303\241s oscuro para definici\303\263n */\n"
"    border-radius: 5px; /* Bordes redondeados para suavidad */\n"
"    padding: 10px 20px; /* Espacio interno para mejor tama\303\261o del bot\303\263n */\n"
"    font-size: 16px; /* Tama\303\261o de fuente para legibilidad */\n"
"  \n"
"}\n"
"\n"
"QPushButton#btt_registrar:hover {\n"
"    background-color: #2980B9; \n"
"    border-color: #1F618D; \n"
"}\n"
"\n"
"QPushButton#btt_registrar:pressed {\n"
"    background-color: #2980B9; /* Color m\303\241s oscuro cuando se presiona */\n"
"    border-color: #1F618D; /* Borde m\303\241s oscuro cuando se pres"
                        "iona */\n"
"}"));
        btt_exit = new QPushButton(frame);
        btt_exit->setObjectName(QString::fromUtf8("btt_exit"));
        btt_exit->setGeometry(QRect(400, 10, 51, 41));
        btt_exit->setFont(font3);
        btt_exit->setStyleSheet(QString::fromUtf8("QPushButton#btt_exit {\n"
"    background: qlineargradient(\n"
"        spread: pad, \n"
"        x1: 0, y1: 0, \n"
"        x2: 1, y2: 1, \n"
"        stop: 0 #E74C3C, /* Rojo m\303\241s claro */\n"
"        stop: 1 #F1948A  /* Rojo a\303\272n m\303\241s claro */\n"
"    ); /* Degradado de rojo claro a rojo m\303\241s claro */\n"
"\n"
"    color: #FFFFFF; /* Texto blanco para buen contraste */\n"
"    border: 2px solid #C0392B; /* Borde m\303\241s oscuro para definici\303\263n */\n"
"    border-radius: 5px; /* Bordes redondeados para suavidad */\n"
"    padding: 10px 20px; /* Espacio interno para mejor tama\303\261o del bot\303\263n */\n"
"    font-size: 16px; /* Tama\303\261o de fuente para legibilidad */\n"
"}\n"
"\n"
"QPushButton#btt_exit:hover {\n"
"    background-color: #CB4335; \n"
"    border-color: #922B21; \n"
"}\n"
"\n"
"QPushButton#btt_exit:pressed {\n"
"    background-color: #922B21; /* Color m\303\241s oscuro cuando se presiona */\n"
"    border-color: #641E16; /* Borde m\303\241s oscuro cuando s"
                        "e presiona */\n"
"}\n"
""));
        label = new QLabel(Form_registrarUsuarios);
        label->setObjectName(QString::fromUtf8("label"));
        label->setGeometry(QRect(20, 0, 631, 81));
        QFont font4;
        font4.setFamily(QString::fromUtf8("Kohinoor Devanagari"));
        font4.setPointSize(60);
        font4.setBold(true);
        font4.setWeight(75);
        label->setFont(font4);

        retranslateUi(Form_registrarUsuarios);

        QMetaObject::connectSlotsByName(Form_registrarUsuarios);
    } // setupUi

    void retranslateUi(QWidget *Form_registrarUsuarios)
    {
        Form_registrarUsuarios->setWindowTitle(QCoreApplication::translate("Form_registrarUsuarios", "Form", nullptr));
        txt_nombres->setText(QString());
        txt_apellidos->setText(QString());
        txt_fechaNac->setText(QString());
        txt_correo->setText(QString());
        txt_contrasenia->setText(QString());
        label_2->setText(QCoreApplication::translate("Form_registrarUsuarios", "Datos del nuevo usuario", nullptr));
        label_3->setText(QCoreApplication::translate("Form_registrarUsuarios", "Nombres:", nullptr));
        label_4->setText(QCoreApplication::translate("Form_registrarUsuarios", "Apellidos:", nullptr));
        label_5->setText(QCoreApplication::translate("Form_registrarUsuarios", "Contrase\303\261a:", nullptr));
        label_6->setText(QCoreApplication::translate("Form_registrarUsuarios", "Fecha de Nacimiento:", nullptr));
        label_7->setText(QCoreApplication::translate("Form_registrarUsuarios", "Correo electronico:", nullptr));
        btt_registrar->setText(QCoreApplication::translate("Form_registrarUsuarios", "Registrar", nullptr));
        btt_exit->setText(QCoreApplication::translate("Form_registrarUsuarios", "x", nullptr));
        label->setText(QCoreApplication::translate("Form_registrarUsuarios", "Registro de usuarios:", nullptr));
    } // retranslateUi

};

namespace Ui {
    class Form_registrarUsuarios: public Ui_Form_registrarUsuarios {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_FORM_REGISTRARUSUARIOS_H
