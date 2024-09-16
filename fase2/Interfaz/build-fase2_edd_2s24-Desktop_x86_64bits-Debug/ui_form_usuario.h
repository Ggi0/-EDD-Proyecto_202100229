/********************************************************************************
** Form generated from reading UI file 'form_usuario.ui'
**
** Created by: Qt User Interface Compiler version 5.15.2
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_FORM_USUARIO_H
#define UI_FORM_USUARIO_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QFrame>
#include <QtWidgets/QLabel>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QStackedWidget>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_Form_usuario
{
public:
    QLabel *label;
    QFrame *frame;
    QPushButton *btt_buscar;
    QPushButton *btt_publicaciones;
    QPushButton *btt_solicitudes;
    QPushButton *btt_reportes;
    QPushButton *btt_perfil;
    QPushButton *btt_cerrarSesion;
    QStackedWidget *stackedWidget;
    QWidget *page_buscar;
    QWidget *page_publi;
    QWidget *page_soli;
    QWidget *page_reportes;
    QWidget *page_perfil;

    void setupUi(QWidget *Form_usuario)
    {
        if (Form_usuario->objectName().isEmpty())
            Form_usuario->setObjectName(QString::fromUtf8("Form_usuario"));
        Form_usuario->resize(828, 551);
        Form_usuario->setStyleSheet(QString::fromUtf8("QWidget#Form_usuario{\n"
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
        label = new QLabel(Form_usuario);
        label->setObjectName(QString::fromUtf8("label"));
        label->setGeometry(QRect(10, 10, 471, 61));
        QFont font;
        font.setFamily(QString::fromUtf8("Kohinoor Devanagari"));
        font.setPointSize(60);
        font.setBold(true);
        font.setWeight(75);
        label->setFont(font);
        frame = new QFrame(Form_usuario);
        frame->setObjectName(QString::fromUtf8("frame"));
        frame->setGeometry(QRect(10, 80, 811, 461));
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
        btt_buscar = new QPushButton(frame);
        btt_buscar->setObjectName(QString::fromUtf8("btt_buscar"));
        btt_buscar->setGeometry(QRect(10, 10, 91, 41));
        QFont font1;
        font1.setFamily(QString::fromUtf8("Kohinoor Devanagari"));
        btt_buscar->setFont(font1);
        btt_buscar->setStyleSheet(QString::fromUtf8("QPushButton#btt_buscar {\n"
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
"QPushButton#btt_buscar:hover {\n"
"    background-color: #2980B9; \n"
"    border-color: #1F618D; \n"
"}\n"
"\n"
"QPushButton#btt_buscar:pressed {\n"
"    background-color: #2980B9; /* Color m\303\241s oscuro cuando se presiona */\n"
"    border-color: #1F618D; /* Borde m\303\241s oscuro cuando se presiona */\n"
""
                        "}"));
        btt_publicaciones = new QPushButton(frame);
        btt_publicaciones->setObjectName(QString::fromUtf8("btt_publicaciones"));
        btt_publicaciones->setGeometry(QRect(110, 10, 141, 41));
        btt_publicaciones->setFont(font1);
        btt_publicaciones->setStyleSheet(QString::fromUtf8("QPushButton#btt_publicaciones{\n"
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
"QPushButton#btt_publicaciones:hover {\n"
"    background-color: #2980B9; \n"
"    border-color: #1F618D; \n"
"}\n"
"\n"
"QPushButton#btt_publicaciones:pressed {\n"
"    background-color: #2980B9; /* Color m\303\241s oscuro cuando se presiona */\n"
"    border-color: #1F618D; /* Borde m\303\241s oscuro cua"
                        "ndo se presiona */\n"
"}"));
        btt_solicitudes = new QPushButton(frame);
        btt_solicitudes->setObjectName(QString::fromUtf8("btt_solicitudes"));
        btt_solicitudes->setGeometry(QRect(260, 10, 121, 41));
        btt_solicitudes->setFont(font1);
        btt_solicitudes->setStyleSheet(QString::fromUtf8("QPushButton#btt_solicitudes {\n"
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
"QPushButton#btt_solicitudes:hover {\n"
"    background-color: #2980B9; \n"
"    border-color: #1F618D; \n"
"}\n"
"\n"
"QPushButton#btt_solicitudes:pressed {\n"
"    background-color: #2980B9; /* Color m\303\241s oscuro cuando se presiona */\n"
"    border-color: #1F618D; /* Borde m\303\241s oscuro cuando s"
                        "e presiona */\n"
"}"));
        btt_reportes = new QPushButton(frame);
        btt_reportes->setObjectName(QString::fromUtf8("btt_reportes"));
        btt_reportes->setGeometry(QRect(390, 10, 111, 41));
        btt_reportes->setFont(font1);
        btt_reportes->setStyleSheet(QString::fromUtf8("QPushButton#btt_reportes {\n"
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
"QPushButton#btt_reportes:hover {\n"
"    background-color: #2980B9; \n"
"    border-color: #1F618D; \n"
"}\n"
"\n"
"QPushButton#btt_reportes:pressed {\n"
"    background-color: #2980B9; /* Color m\303\241s oscuro cuando se presiona */\n"
"    border-color: #1F618D; /* Borde m\303\241s oscuro cuando se presion"
                        "a */\n"
"}"));
        btt_perfil = new QPushButton(frame);
        btt_perfil->setObjectName(QString::fromUtf8("btt_perfil"));
        btt_perfil->setGeometry(QRect(510, 10, 81, 41));
        btt_perfil->setFont(font1);
        btt_perfil->setStyleSheet(QString::fromUtf8("QPushButton#btt_perfil{\n"
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
"QPushButton#btt_perfil:hover {\n"
"    background-color: #2980B9; \n"
"    border-color: #1F618D; \n"
"}\n"
"\n"
"QPushButton#btt_perfil:pressed {\n"
"    background-color: #2980B9; /* Color m\303\241s oscuro cuando se presiona */\n"
"    border-color: #1F618D; /* Borde m\303\241s oscuro cuando se presiona */\n"
""
                        "}"));
        btt_cerrarSesion = new QPushButton(frame);
        btt_cerrarSesion->setObjectName(QString::fromUtf8("btt_cerrarSesion"));
        btt_cerrarSesion->setGeometry(QRect(660, 10, 141, 41));
        btt_cerrarSesion->setFont(font1);
        btt_cerrarSesion->setStyleSheet(QString::fromUtf8("QPushButton#btt_cerrarSesion {\n"
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
"QPushButton#btt_cerrarSesion:hover {\n"
"    background-color: #CB4335; \n"
"    border-color: #922B21; \n"
"}\n"
"\n"
"QPushButton#btt_cerrarSesion:pressed {\n"
"    background-color: #922B21; /* Color m\303\241s oscuro cuando se presiona */\n"
"    border-color: #641E16; /* Borde m\303"
                        "\241s oscuro cuando se presiona */\n"
"}\n"
""));
        stackedWidget = new QStackedWidget(frame);
        stackedWidget->setObjectName(QString::fromUtf8("stackedWidget"));
        stackedWidget->setGeometry(QRect(10, 60, 791, 391));
        page_buscar = new QWidget();
        page_buscar->setObjectName(QString::fromUtf8("page_buscar"));
        stackedWidget->addWidget(page_buscar);
        page_publi = new QWidget();
        page_publi->setObjectName(QString::fromUtf8("page_publi"));
        stackedWidget->addWidget(page_publi);
        page_soli = new QWidget();
        page_soli->setObjectName(QString::fromUtf8("page_soli"));
        stackedWidget->addWidget(page_soli);
        page_reportes = new QWidget();
        page_reportes->setObjectName(QString::fromUtf8("page_reportes"));
        stackedWidget->addWidget(page_reportes);
        page_perfil = new QWidget();
        page_perfil->setObjectName(QString::fromUtf8("page_perfil"));
        stackedWidget->addWidget(page_perfil);

        retranslateUi(Form_usuario);

        QMetaObject::connectSlotsByName(Form_usuario);
    } // setupUi

    void retranslateUi(QWidget *Form_usuario)
    {
        Form_usuario->setWindowTitle(QCoreApplication::translate("Form_usuario", "Form", nullptr));
        label->setText(QCoreApplication::translate("Form_usuario", "Social Structure", nullptr));
        btt_buscar->setText(QCoreApplication::translate("Form_usuario", "Buscar", nullptr));
        btt_publicaciones->setText(QCoreApplication::translate("Form_usuario", "Publicaciones", nullptr));
        btt_solicitudes->setText(QCoreApplication::translate("Form_usuario", "Solicitudes", nullptr));
        btt_reportes->setText(QCoreApplication::translate("Form_usuario", "Reportes", nullptr));
        btt_perfil->setText(QCoreApplication::translate("Form_usuario", "Perfil", nullptr));
        btt_cerrarSesion->setText(QCoreApplication::translate("Form_usuario", "Cerrar sesi\303\263n", nullptr));
    } // retranslateUi

};

namespace Ui {
    class Form_usuario: public Ui_Form_usuario {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_FORM_USUARIO_H
