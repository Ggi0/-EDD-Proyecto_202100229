/********************************************************************************
** Form generated from reading UI file 'form_admin.ui'
**
** Created by: Qt User Interface Compiler version 5.15.2
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_FORM_ADMIN_H
#define UI_FORM_ADMIN_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QComboBox>
#include <QtWidgets/QFrame>
#include <QtWidgets/QGraphicsView>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QStackedWidget>
#include <QtWidgets/QTableView>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_Form_admin
{
public:
    QLabel *label;
    QFrame *frame;
    QPushButton *btt_buscar;
    QPushButton *btt_cargarAr;
    QPushButton *btt_reportes;
    QStackedWidget *stackedWidget;
    QWidget *page_white;
    QWidget *page_buscar;
    QLabel *label_2;
    QLineEdit *txt_BusacarUser;
    QPushButton *btt_buscar2;
    QLabel *label_5;
    QComboBox *cbx_orden;
    QTableView *tableView_buscar;
    QPushButton *btt_eliminarUser;
    QWidget *page_cargaAr;
    QLabel *label_3;
    QFrame *frame_2;
    QPushButton *btt_cUsuarios;
    QLabel *label_6;
    QFrame *frame_3;
    QPushButton *btt_cSolicitudes;
    QLabel *label_7;
    QFrame *frame_4;
    QPushButton *btt_cPublicaciones;
    QLabel *label_8;
    QWidget *page_reportes;
    QLabel *label_4;
    QPushButton *btt_generarReportes;
    QGraphicsView *gView_AVL;
    QGraphicsView *gView_ListaPubli;
    QPushButton *btt_cerrarSesion;

    void setupUi(QWidget *Form_admin)
    {
        if (Form_admin->objectName().isEmpty())
            Form_admin->setObjectName(QString::fromUtf8("Form_admin"));
        Form_admin->resize(810, 579);
        Form_admin->setStyleSheet(QString::fromUtf8("QWidget#Form_admin{\n"
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
        label = new QLabel(Form_admin);
        label->setObjectName(QString::fromUtf8("label"));
        label->setGeometry(QRect(20, 10, 431, 61));
        QFont font;
        font.setFamily(QString::fromUtf8("Kohinoor Devanagari"));
        font.setPointSize(60);
        font.setBold(true);
        font.setWeight(75);
        label->setFont(font);
        frame = new QFrame(Form_admin);
        frame->setObjectName(QString::fromUtf8("frame"));
        frame->setGeometry(QRect(10, 80, 791, 491));
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
        btt_cargarAr = new QPushButton(frame);
        btt_cargarAr->setObjectName(QString::fromUtf8("btt_cargarAr"));
        btt_cargarAr->setGeometry(QRect(110, 10, 141, 41));
        btt_cargarAr->setFont(font1);
        btt_cargarAr->setStyleSheet(QString::fromUtf8("QPushButton#btt_cargarAr{\n"
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
"QPushButton#btt_cargarAr:hover {\n"
"    background-color: #2980B9; \n"
"    border-color: #1F618D; \n"
"}\n"
"\n"
"QPushButton#btt_cargarAr:pressed {\n"
"    background-color: #2980B9; /* Color m\303\241s oscuro cuando se presiona */\n"
"    border-color: #1F618D; /* Borde m\303\241s oscuro cuando se presiona"
                        " */\n"
"}"));
        btt_reportes = new QPushButton(frame);
        btt_reportes->setObjectName(QString::fromUtf8("btt_reportes"));
        btt_reportes->setGeometry(QRect(260, 10, 112, 41));
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
        stackedWidget = new QStackedWidget(frame);
        stackedWidget->setObjectName(QString::fromUtf8("stackedWidget"));
        stackedWidget->setGeometry(QRect(10, 60, 771, 421));
        stackedWidget->setStyleSheet(QString::fromUtf8("QWidget#page_white {\n"
"    background-color: #E0F7FA; /* Azul claro con un toque vibrante */\n"
"    border: 0px solid #00796B; /* Borde en verde azulado para un contraste atractivo */\n"
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
        page_white = new QWidget();
        page_white->setObjectName(QString::fromUtf8("page_white"));
        stackedWidget->addWidget(page_white);
        page_buscar = new QWidget();
        page_buscar->setObjectName(QString::fromUtf8("page_buscar"));
        label_2 = new QLabel(page_buscar);
        label_2->setObjectName(QString::fromUtf8("label_2"));
        label_2->setGeometry(QRect(0, 0, 111, 41));
        QFont font2;
        font2.setFamily(QString::fromUtf8("Kohinoor Devanagari"));
        font2.setPointSize(30);
        font2.setBold(true);
        font2.setWeight(75);
        label_2->setFont(font2);
        txt_BusacarUser = new QLineEdit(page_buscar);
        txt_BusacarUser->setObjectName(QString::fromUtf8("txt_BusacarUser"));
        txt_BusacarUser->setGeometry(QRect(110, 10, 231, 31));
        QFont font3;
        font3.setFamily(QString::fromUtf8("Kohinoor Devanagari"));
        font3.setPointSize(16);
        txt_BusacarUser->setFont(font3);
        txt_BusacarUser->setEchoMode(QLineEdit::Normal);
        btt_buscar2 = new QPushButton(page_buscar);
        btt_buscar2->setObjectName(QString::fromUtf8("btt_buscar2"));
        btt_buscar2->setGeometry(QRect(350, 10, 31, 31));
        btt_buscar2->setFont(font1);
        btt_buscar2->setStyleSheet(QString::fromUtf8("QPushButton#btt_buscar2 {\n"
"background: qlineargradient(\n"
"    spread: pad, \n"
"    x1: 0, y1: 0, \n"
"    x2: 1, y2: 1, \n"
"    stop: 0 #5DADE2, /* Azul m\303\241s claro */\n"
"    stop: 1 #85C1E9  /* Azul a\303\272n m\303\241s claro */\n"
"); /* Degradado de azul claro a azul m\303\241s claro */\n"
"\n"
"\n"
"    border: 0px solid #3498DB; /* Borde m\303\241s oscuro para definici\303\263n */\n"
"}\n"
"\n"
"QPushButton#btt_buscar2:hover {\n"
"    background-color: #2980B9; \n"
"    border-color: #1F618D; \n"
"}\n"
"\n"
"QPushButton#btt_buscar2:pressed {\n"
"    background-color: #2980B9; /* Color m\303\241s oscuro cuando se presiona */\n"
"    border-color: #1F618D; /* Borde m\303\241s oscuro cuando se presiona */\n"
"}"));
        label_5 = new QLabel(page_buscar);
        label_5->setObjectName(QString::fromUtf8("label_5"));
        label_5->setGeometry(QRect(400, 0, 61, 41));
        QFont font4;
        font4.setFamily(QString::fromUtf8("Kohinoor Devanagari"));
        font4.setPointSize(20);
        font4.setBold(false);
        font4.setWeight(50);
        label_5->setFont(font4);
        cbx_orden = new QComboBox(page_buscar);
        cbx_orden->addItem(QString());
        cbx_orden->addItem(QString());
        cbx_orden->addItem(QString());
        cbx_orden->addItem(QString());
        cbx_orden->setObjectName(QString::fromUtf8("cbx_orden"));
        cbx_orden->setGeometry(QRect(460, 10, 121, 21));
        cbx_orden->setFont(font3);
        tableView_buscar = new QTableView(page_buscar);
        tableView_buscar->setObjectName(QString::fromUtf8("tableView_buscar"));
        tableView_buscar->setGeometry(QRect(10, 50, 751, 361));
        tableView_buscar->setFont(font1);
        btt_eliminarUser = new QPushButton(page_buscar);
        btt_eliminarUser->setObjectName(QString::fromUtf8("btt_eliminarUser"));
        btt_eliminarUser->setGeometry(QRect(660, 10, 81, 31));
        btt_eliminarUser->setFont(font1);
        btt_eliminarUser->setStyleSheet(QString::fromUtf8("QPushButton#btt_eliminarUser {\n"
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
"    border-radius: 2px; /* Bordes redondeados para suavidad */\n"
"    font-size: 10 px; /* Tama\303\261o de fuente para legibilidad */\n"
"}\n"
"\n"
"QPushButton#btt_eliminarUser:hover {\n"
"    background-color: #CB4335; \n"
"    border-color: #922B21; \n"
"}\n"
"\n"
"QPushButton#btt_eliminarUser:pressed {\n"
"    background-color: #922B21; /* Color m\303\241s oscuro cuando se presiona */\n"
"    border-color: #641E16; /* Borde m\303\241s oscuro cuando se presiona */\n"
"}\n"
""));
        stackedWidget->addWidget(page_buscar);
        page_cargaAr = new QWidget();
        page_cargaAr->setObjectName(QString::fromUtf8("page_cargaAr"));
        label_3 = new QLabel(page_cargaAr);
        label_3->setObjectName(QString::fromUtf8("label_3"));
        label_3->setGeometry(QRect(10, 0, 211, 41));
        label_3->setFont(font2);
        frame_2 = new QFrame(page_cargaAr);
        frame_2->setObjectName(QString::fromUtf8("frame_2"));
        frame_2->setGeometry(QRect(10, 50, 231, 361));
        frame_2->setStyleSheet(QString::fromUtf8("QFrame#frame_2{\n"
"    background: qlineargradient(\n"
"        spread: pad, \n"
"        x1: 0, y1: 0, \n"
"        x2: 1, y2: 1, \n"
"        stop: 0 #d3877d, \n"
"        stop: 1 #f6e1dd\n"
"    ); /* Degradado de #566e71 a un tono m\303\241s fresco */\n"
"    padding: 15px; /* Espacio interno mayor para mejor estructura */\n"
"    border: 3px solid #944038; /* Borde en verde azulado para un contraste atractivo */\n"
"    border-radius: 5px; /* Bordes redondeados para suavidad */\n"
"}\n"
""));
        frame_2->setFrameShape(QFrame::StyledPanel);
        frame_2->setFrameShadow(QFrame::Raised);
        btt_cUsuarios = new QPushButton(frame_2);
        btt_cUsuarios->setObjectName(QString::fromUtf8("btt_cUsuarios"));
        btt_cUsuarios->setGeometry(QRect(30, 160, 161, 41));
        btt_cUsuarios->setFont(font1);
        btt_cUsuarios->setStyleSheet(QString::fromUtf8("QPushButton#btt_cUsuarios {\n"
"background: qlineargradient(\n"
"    spread: pad, \n"
"    x1: 0, y1: 0, \n"
"    x2: 1, y2: 1, \n"
"    stop: 0 #b44c43, /* Azul m\303\241s claro */\n"
"    stop: 1 #944038  /* Azul a\303\272n m\303\241s claro */\n"
"); /* Degradado de azul claro a azul m\303\241s claro */\n"
"\n"
"    color: #FFFFFF; /* Texto blanco para buen contraste */\n"
"    border: 2px solid #582924; /* Borde m\303\241s oscuro para definici\303\263n */\n"
"    border-radius: 5px; /* Bordes redondeados para suavidad */\n"
"    padding: 10px 20px; /* Espacio interno para mejor tama\303\261o del bot\303\263n */\n"
"    font-size: 16px; /* Tama\303\261o de fuente para legibilidad */\n"
"  \n"
"}\n"
"\n"
"QPushButton#btt_cUsuarios:hover {\n"
"    background-color: #582924; \n"
"    border-color: #3c1e1b; \n"
"}\n"
"\n"
"QPushButton#btt_cUsuarios:press {\n"
"    background-color: #2980B9; /* Color m\303\241s oscuro cuando se presiona */\n"
"    border-color: #3c1e1b; /* Borde m\303\241s oscuro cuando se presio"
                        "na */\n"
"}"));
        label_6 = new QLabel(frame_2);
        label_6->setObjectName(QString::fromUtf8("label_6"));
        label_6->setGeometry(QRect(10, 10, 111, 41));
        QFont font5;
        font5.setFamily(QString::fromUtf8("Kohinoor Devanagari"));
        font5.setPointSize(25);
        font5.setBold(true);
        font5.setWeight(75);
        label_6->setFont(font5);
        frame_3 = new QFrame(page_cargaAr);
        frame_3->setObjectName(QString::fromUtf8("frame_3"));
        frame_3->setGeometry(QRect(270, 50, 231, 361));
        frame_3->setStyleSheet(QString::fromUtf8("QFrame#frame_3{\n"
"    background: qlineargradient(\n"
"        spread: pad, \n"
"        x1: 0, y1: 0, \n"
"        x2: 1, y2: 1, \n"
"        stop: 0 #d3877d, \n"
"        stop: 1 #f6e1dd\n"
"    ); /* Degradado de #566e71 a un tono m\303\241s fresco */\n"
"    padding: 15px; /* Espacio interno mayor para mejor estructura */\n"
"    border: 3px solid #944038; /* Borde en verde azulado para un contraste atractivo */\n"
"    border-radius: 5px; /* Bordes redondeados para suavidad */\n"
"}\n"
""));
        frame_3->setFrameShape(QFrame::StyledPanel);
        frame_3->setFrameShadow(QFrame::Raised);
        btt_cSolicitudes = new QPushButton(frame_3);
        btt_cSolicitudes->setObjectName(QString::fromUtf8("btt_cSolicitudes"));
        btt_cSolicitudes->setGeometry(QRect(30, 160, 171, 41));
        btt_cSolicitudes->setFont(font1);
        btt_cSolicitudes->setStyleSheet(QString::fromUtf8("QPushButton#btt_cSolicitudes {\n"
"background: qlineargradient(\n"
"    spread: pad, \n"
"    x1: 0, y1: 0, \n"
"    x2: 1, y2: 1, \n"
"    stop: 0 #b44c43, /* Azul m\303\241s claro */\n"
"    stop: 1 #944038  /* Azul a\303\272n m\303\241s claro */\n"
"); /* Degradado de azul claro a azul m\303\241s claro */\n"
"\n"
"    color: #FFFFFF; /* Texto blanco para buen contraste */\n"
"    border: 2px solid #582924; /* Borde m\303\241s oscuro para definici\303\263n */\n"
"    border-radius: 5px; /* Bordes redondeados para suavidad */\n"
"    padding: 10px 20px; /* Espacio interno para mejor tama\303\261o del bot\303\263n */\n"
"    font-size: 16px; /* Tama\303\261o de fuente para legibilidad */\n"
"  \n"
"}\n"
"\n"
"QPushButton#btt_cSolicitudes:hover {\n"
"    background-color: #582924; \n"
"    border-color: #3c1e1b; \n"
"}\n"
"\n"
"QPushButton#btt_cSolicitudes:press {\n"
"    background-color: #2980B9; /* Color m\303\241s oscuro cuando se presiona */\n"
"    border-color: #3c1e1b; /* Borde m\303\241s oscuro cuando "
                        "se presiona */\n"
"}"));
        label_7 = new QLabel(frame_3);
        label_7->setObjectName(QString::fromUtf8("label_7"));
        label_7->setGeometry(QRect(20, 10, 141, 41));
        label_7->setFont(font5);
        frame_4 = new QFrame(page_cargaAr);
        frame_4->setObjectName(QString::fromUtf8("frame_4"));
        frame_4->setGeometry(QRect(530, 50, 231, 361));
        frame_4->setStyleSheet(QString::fromUtf8("QFrame#frame_4{\n"
"    background: qlineargradient(\n"
"        spread: pad, \n"
"        x1: 0, y1: 0, \n"
"        x2: 1, y2: 1, \n"
"        stop: 0 #d3877d, \n"
"        stop: 1 #f6e1dd\n"
"    ); /* Degradado de #566e71 a un tono m\303\241s fresco */\n"
"    padding: 15px; /* Espacio interno mayor para mejor estructura */\n"
"    border: 3px solid #944038; /* Borde en verde azulado para un contraste atractivo */\n"
"    border-radius: 5px; /* Bordes redondeados para suavidad */\n"
"}\n"
""));
        frame_4->setFrameShape(QFrame::StyledPanel);
        frame_4->setFrameShadow(QFrame::Raised);
        btt_cPublicaciones = new QPushButton(frame_4);
        btt_cPublicaciones->setObjectName(QString::fromUtf8("btt_cPublicaciones"));
        btt_cPublicaciones->setGeometry(QRect(20, 160, 201, 41));
        btt_cPublicaciones->setFont(font1);
        btt_cPublicaciones->setStyleSheet(QString::fromUtf8("QPushButton#btt_cPublicaciones {\n"
"background: qlineargradient(\n"
"    spread: pad, \n"
"    x1: 0, y1: 0, \n"
"    x2: 1, y2: 1, \n"
"    stop: 0 #b44c43, /* Azul m\303\241s claro */\n"
"    stop: 1 #944038  /* Azul a\303\272n m\303\241s claro */\n"
"); /* Degradado de azul claro a azul m\303\241s claro */\n"
"\n"
"    color: #FFFFFF; /* Texto blanco para buen contraste */\n"
"    border: 2px solid #582924; /* Borde m\303\241s oscuro para definici\303\263n */\n"
"    border-radius: 5px; /* Bordes redondeados para suavidad */\n"
"    padding: 10px 20px; /* Espacio interno para mejor tama\303\261o del bot\303\263n */\n"
"    font-size: 16px; /* Tama\303\261o de fuente para legibilidad */\n"
"  \n"
"}\n"
"\n"
"QPushButton#btt_cPublicaciones:hover {\n"
"    background-color: #582924; \n"
"    border-color: #3c1e1b; \n"
"}\n"
"\n"
"QPushButton#btt_cPublicaciones:press {\n"
"    background-color: #2980B9; /* Color m\303\241s oscuro cuando se presiona */\n"
"    border-color: #3c1e1b; /* Borde m\303\241s oscuro c"
                        "uando se presiona */\n"
"}"));
        label_8 = new QLabel(frame_4);
        label_8->setObjectName(QString::fromUtf8("label_8"));
        label_8->setGeometry(QRect(20, 10, 171, 41));
        label_8->setFont(font5);
        stackedWidget->addWidget(page_cargaAr);
        page_reportes = new QWidget();
        page_reportes->setObjectName(QString::fromUtf8("page_reportes"));
        label_4 = new QLabel(page_reportes);
        label_4->setObjectName(QString::fromUtf8("label_4"));
        label_4->setGeometry(QRect(10, 0, 141, 41));
        label_4->setFont(font2);
        btt_generarReportes = new QPushButton(page_reportes);
        btt_generarReportes->setObjectName(QString::fromUtf8("btt_generarReportes"));
        btt_generarReportes->setGeometry(QRect(320, 380, 141, 41));
        btt_generarReportes->setFont(font1);
        btt_generarReportes->setStyleSheet(QString::fromUtf8("QPushButton#btt_generarReportes {\n"
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
"    font-size: 13px; /* Tama\303\261o de fuente para legibilidad */\n"
"  \n"
"}\n"
"\n"
"QPushButton#btt_generarReportes:hover {\n"
"    background-color: #2980B9; \n"
"    border-color: #1F618D; \n"
"}\n"
"\n"
"QPushButton#btt_generarReportes:pressed {\n"
"    background-color: #2980B9; /* Color m\303\241s oscuro cuando se presiona */\n"
"    border-color: #1F618D; /* Borde m\303\241s oscuro cuando se presiona */\n"
"}"));
        gView_AVL = new QGraphicsView(page_reportes);
        gView_AVL->setObjectName(QString::fromUtf8("gView_AVL"));
        gView_AVL->setGeometry(QRect(10, 40, 371, 311));
        gView_ListaPubli = new QGraphicsView(page_reportes);
        gView_ListaPubli->setObjectName(QString::fromUtf8("gView_ListaPubli"));
        gView_ListaPubli->setGeometry(QRect(390, 40, 371, 311));
        stackedWidget->addWidget(page_reportes);
        btt_cerrarSesion = new QPushButton(frame);
        btt_cerrarSesion->setObjectName(QString::fromUtf8("btt_cerrarSesion"));
        btt_cerrarSesion->setGeometry(QRect(630, 10, 141, 41));
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

        retranslateUi(Form_admin);

        stackedWidget->setCurrentIndex(1);


        QMetaObject::connectSlotsByName(Form_admin);
    } // setupUi

    void retranslateUi(QWidget *Form_admin)
    {
        Form_admin->setWindowTitle(QCoreApplication::translate("Form_admin", "Form", nullptr));
        label->setText(QCoreApplication::translate("Form_admin", "Administraci\303\263n", nullptr));
        btt_buscar->setText(QCoreApplication::translate("Form_admin", "Buscar", nullptr));
        btt_cargarAr->setText(QCoreApplication::translate("Form_admin", "Carga Masiva", nullptr));
        btt_reportes->setText(QCoreApplication::translate("Form_admin", "Reportes", nullptr));
        label_2->setText(QCoreApplication::translate("Form_admin", "Buscar:", nullptr));
        txt_BusacarUser->setText(QString());
        btt_buscar2->setText(QCoreApplication::translate("Form_admin", "\360\237\224\215\357\270\216", nullptr));
        label_5->setText(QCoreApplication::translate("Form_admin", "Orden", nullptr));
        cbx_orden->setItemText(0, QString());
        cbx_orden->setItemText(1, QCoreApplication::translate("Form_admin", "PreOrden", nullptr));
        cbx_orden->setItemText(2, QCoreApplication::translate("Form_admin", "InOrden", nullptr));
        cbx_orden->setItemText(3, QCoreApplication::translate("Form_admin", "PostOrden", nullptr));

        btt_eliminarUser->setText(QCoreApplication::translate("Form_admin", "Eliminar", nullptr));
        label_3->setText(QCoreApplication::translate("Form_admin", "Carga Masiva:", nullptr));
        btt_cUsuarios->setText(QCoreApplication::translate("Form_admin", "Cargar usuarios", nullptr));
        label_6->setText(QCoreApplication::translate("Form_admin", "Usuarios", nullptr));
        btt_cSolicitudes->setText(QCoreApplication::translate("Form_admin", "Cargar solicitudes", nullptr));
        label_7->setText(QCoreApplication::translate("Form_admin", "Solicitudes", nullptr));
        btt_cPublicaciones->setText(QCoreApplication::translate("Form_admin", "Cargar publicaciones", nullptr));
        label_8->setText(QCoreApplication::translate("Form_admin", "Publicaciones", nullptr));
        label_4->setText(QCoreApplication::translate("Form_admin", "Reportes:", nullptr));
        btt_generarReportes->setText(QCoreApplication::translate("Form_admin", "Generar repotes", nullptr));
        btt_cerrarSesion->setText(QCoreApplication::translate("Form_admin", "Cerrar sesi\303\263n", nullptr));
    } // retranslateUi

};

namespace Ui {
    class Form_admin: public Ui_Form_admin {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_FORM_ADMIN_H
