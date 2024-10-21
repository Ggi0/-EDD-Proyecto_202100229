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

class Ui_Form_usuario
{
public:
    QLabel *label;
    QFrame *frame;
    QPushButton *btt_buscar;
    QPushButton *btt_solicitudes;
    QPushButton *btt_reportes;
    QPushButton *btt_perfil;
    QPushButton *btt_cerrarSesion;
    QStackedWidget *stackedWidget;
    QWidget *page_buscar;
    QLineEdit *txt_buscarUser;
    QLabel *label_2;
    QPushButton *btt_buscar2;
    QFrame *frame_9;
    QLabel *label_10;
    QLabel *label_11;
    QLabel *label_12;
    QLabel *label_13;
    QLabel *lbl_nombreUserfind;
    QLabel *lbl_apellidoUserfind;
    QLabel *lbl_correoUserfind;
    QLabel *lbl_dateUserfind;
    QWidget *page_publi;
    QLabel *label_3;
    QFrame *frame_2;
    QFrame *frame_3;
    QPushButton *btt_hacerPubli;
    QWidget *page_soli;
    QTableView *tableV_usuarios;
    QTableView *tableV_soliRec;
    QTableView *tableV_soliEnv;
    QWidget *page_reportes;
    QFrame *frame_4;
    QTableView *tableView;
    QLabel *label_14;
    QFrame *frame_5;
    QTableView *tableView_2;
    QLabel *label_15;
    QFrame *frame_6;
    QComboBox *comboBox;
    QWidget *page_hacerPubli;
    QLabel *label_16;
    QLineEdit *txt_hacerPubli;
    QPushButton *btt_publicar;
    QWidget *page_white;
    QWidget *page_perfil;
    QFrame *frame_7;
    QLabel *label_4;
    QLabel *label_5;
    QLabel *label_6;
    QLabel *label_7;
    QLabel *label_8;
    QLineEdit *txt_nombres;
    QLineEdit *txt_apellidos;
    QLineEdit *txt_correo;
    QLineEdit *txt_contrasenia;
    QLineEdit *txt_fechaNac;
    QPushButton *btt_modificarDatos;
    QPushButton *btt_eliminarDatos;
    QFrame *frame_8;
    QGraphicsView *view_grphUser;
    QWidget *page_edtiPerfil;
    QFrame *frame_10;
    QLabel *label_9;
    QLabel *label_17;
    QLabel *label_18;
    QLabel *label_19;
    QLabel *label_20;
    QLineEdit *txt_nombres_2;
    QLineEdit *txt_apellidos_2;
    QLineEdit *txt_correo_2;
    QLineEdit *txt_contrasenia_2;
    QLineEdit *txt_fechaNac_2;
    QPushButton *btt_modificarDatos_2;
    QPushButton *btt_publicaciones;
    QLabel *lbl_tituloUser;

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
        txt_buscarUser = new QLineEdit(page_buscar);
        txt_buscarUser->setObjectName(QString::fromUtf8("txt_buscarUser"));
        txt_buscarUser->setGeometry(QRect(120, 10, 231, 31));
        QFont font2;
        font2.setFamily(QString::fromUtf8("Kohinoor Devanagari"));
        font2.setPointSize(16);
        txt_buscarUser->setFont(font2);
        txt_buscarUser->setEchoMode(QLineEdit::Normal);
        label_2 = new QLabel(page_buscar);
        label_2->setObjectName(QString::fromUtf8("label_2"));
        label_2->setGeometry(QRect(10, 0, 111, 41));
        QFont font3;
        font3.setFamily(QString::fromUtf8("Kohinoor Devanagari"));
        font3.setPointSize(30);
        font3.setBold(true);
        font3.setWeight(75);
        label_2->setFont(font3);
        btt_buscar2 = new QPushButton(page_buscar);
        btt_buscar2->setObjectName(QString::fromUtf8("btt_buscar2"));
        btt_buscar2->setGeometry(QRect(360, 10, 31, 31));
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
        frame_9 = new QFrame(page_buscar);
        frame_9->setObjectName(QString::fromUtf8("frame_9"));
        frame_9->setGeometry(QRect(120, 50, 531, 331));
        frame_9->setStyleSheet(QString::fromUtf8("QFrame#frame_9 {\n"
"    border: 2px solid #00796B; /* Borde en verde azulado para un contraste atractivo */\n"
"    border-radius: 5px; /* Bordes redondeados para suavidad */\n"
"    \n"
"}\n"
""));
        frame_9->setFrameShape(QFrame::StyledPanel);
        frame_9->setFrameShadow(QFrame::Raised);
        label_10 = new QLabel(frame_9);
        label_10->setObjectName(QString::fromUtf8("label_10"));
        label_10->setGeometry(QRect(20, 10, 101, 41));
        QFont font4;
        font4.setFamily(QString::fromUtf8("Kohinoor Devanagari"));
        font4.setPointSize(20);
        font4.setBold(true);
        font4.setWeight(75);
        label_10->setFont(font4);
        label_11 = new QLabel(frame_9);
        label_11->setObjectName(QString::fromUtf8("label_11"));
        label_11->setGeometry(QRect(20, 80, 101, 41));
        label_11->setFont(font4);
        label_12 = new QLabel(frame_9);
        label_12->setObjectName(QString::fromUtf8("label_12"));
        label_12->setGeometry(QRect(20, 160, 101, 41));
        label_12->setFont(font4);
        label_13 = new QLabel(frame_9);
        label_13->setObjectName(QString::fromUtf8("label_13"));
        label_13->setGeometry(QRect(20, 230, 221, 41));
        label_13->setFont(font4);
        lbl_nombreUserfind = new QLabel(frame_9);
        lbl_nombreUserfind->setObjectName(QString::fromUtf8("lbl_nombreUserfind"));
        lbl_nombreUserfind->setGeometry(QRect(110, 40, 401, 41));
        QFont font5;
        font5.setFamily(QString::fromUtf8("Kohinoor Devanagari"));
        font5.setPointSize(20);
        font5.setBold(false);
        font5.setWeight(50);
        lbl_nombreUserfind->setFont(font5);
        lbl_apellidoUserfind = new QLabel(frame_9);
        lbl_apellidoUserfind->setObjectName(QString::fromUtf8("lbl_apellidoUserfind"));
        lbl_apellidoUserfind->setGeometry(QRect(110, 120, 401, 41));
        lbl_apellidoUserfind->setFont(font5);
        lbl_correoUserfind = new QLabel(frame_9);
        lbl_correoUserfind->setObjectName(QString::fromUtf8("lbl_correoUserfind"));
        lbl_correoUserfind->setGeometry(QRect(110, 190, 391, 41));
        lbl_correoUserfind->setFont(font5);
        lbl_dateUserfind = new QLabel(frame_9);
        lbl_dateUserfind->setObjectName(QString::fromUtf8("lbl_dateUserfind"));
        lbl_dateUserfind->setGeometry(QRect(110, 270, 391, 41));
        lbl_dateUserfind->setFont(font5);
        stackedWidget->addWidget(page_buscar);
        page_publi = new QWidget();
        page_publi->setObjectName(QString::fromUtf8("page_publi"));
        label_3 = new QLabel(page_publi);
        label_3->setObjectName(QString::fromUtf8("label_3"));
        label_3->setGeometry(QRect(10, 0, 211, 41));
        label_3->setFont(font3);
        frame_2 = new QFrame(page_publi);
        frame_2->setObjectName(QString::fromUtf8("frame_2"));
        frame_2->setGeometry(QRect(10, 40, 281, 341));
        frame_2->setFrameShape(QFrame::StyledPanel);
        frame_2->setFrameShadow(QFrame::Raised);
        frame_3 = new QFrame(page_publi);
        frame_3->setObjectName(QString::fromUtf8("frame_3"));
        frame_3->setGeometry(QRect(300, 40, 481, 341));
        frame_3->setFrameShape(QFrame::StyledPanel);
        frame_3->setFrameShadow(QFrame::Raised);
        btt_hacerPubli = new QPushButton(frame_3);
        btt_hacerPubli->setObjectName(QString::fromUtf8("btt_hacerPubli"));
        btt_hacerPubli->setGeometry(QRect(10, 10, 181, 41));
        btt_hacerPubli->setFont(font1);
        btt_hacerPubli->setStyleSheet(QString::fromUtf8("QPushButton#btt_solicitudes {\n"
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
        stackedWidget->addWidget(page_publi);
        page_soli = new QWidget();
        page_soli->setObjectName(QString::fromUtf8("page_soli"));
        tableV_usuarios = new QTableView(page_soli);
        tableV_usuarios->setObjectName(QString::fromUtf8("tableV_usuarios"));
        tableV_usuarios->setGeometry(QRect(20, 50, 741, 161));
        tableV_soliRec = new QTableView(page_soli);
        tableV_soliRec->setObjectName(QString::fromUtf8("tableV_soliRec"));
        tableV_soliRec->setGeometry(QRect(20, 220, 311, 161));
        tableV_soliEnv = new QTableView(page_soli);
        tableV_soliEnv->setObjectName(QString::fromUtf8("tableV_soliEnv"));
        tableV_soliEnv->setGeometry(QRect(350, 220, 311, 161));
        stackedWidget->addWidget(page_soli);
        page_reportes = new QWidget();
        page_reportes->setObjectName(QString::fromUtf8("page_reportes"));
        frame_4 = new QFrame(page_reportes);
        frame_4->setObjectName(QString::fromUtf8("frame_4"));
        frame_4->setGeometry(QRect(0, 0, 381, 171));
        frame_4->setFrameShape(QFrame::StyledPanel);
        frame_4->setFrameShadow(QFrame::Raised);
        tableView = new QTableView(frame_4);
        tableView->setObjectName(QString::fromUtf8("tableView"));
        tableView->setGeometry(QRect(10, 30, 361, 131));
        label_14 = new QLabel(frame_4);
        label_14->setObjectName(QString::fromUtf8("label_14"));
        label_14->setGeometry(QRect(10, 10, 221, 21));
        QFont font6;
        font6.setFamily(QString::fromUtf8("Kohinoor Devanagari"));
        font6.setPointSize(15);
        font6.setBold(true);
        font6.setWeight(75);
        label_14->setFont(font6);
        frame_5 = new QFrame(page_reportes);
        frame_5->setObjectName(QString::fromUtf8("frame_5"));
        frame_5->setGeometry(QRect(400, 0, 381, 171));
        frame_5->setFrameShape(QFrame::StyledPanel);
        frame_5->setFrameShadow(QFrame::Raised);
        tableView_2 = new QTableView(frame_5);
        tableView_2->setObjectName(QString::fromUtf8("tableView_2"));
        tableView_2->setGeometry(QRect(10, 30, 361, 131));
        label_15 = new QLabel(frame_5);
        label_15->setObjectName(QString::fromUtf8("label_15"));
        label_15->setGeometry(QRect(10, 10, 351, 21));
        label_15->setFont(font6);
        frame_6 = new QFrame(page_reportes);
        frame_6->setObjectName(QString::fromUtf8("frame_6"));
        frame_6->setGeometry(QRect(0, 180, 781, 211));
        frame_6->setFrameShape(QFrame::StyledPanel);
        frame_6->setFrameShadow(QFrame::Raised);
        comboBox = new QComboBox(frame_6);
        comboBox->setObjectName(QString::fromUtf8("comboBox"));
        comboBox->setGeometry(QRect(40, 80, 91, 32));
        stackedWidget->addWidget(page_reportes);
        page_hacerPubli = new QWidget();
        page_hacerPubli->setObjectName(QString::fromUtf8("page_hacerPubli"));
        label_16 = new QLabel(page_hacerPubli);
        label_16->setObjectName(QString::fromUtf8("label_16"));
        label_16->setGeometry(QRect(20, 10, 521, 61));
        QFont font7;
        font7.setFamily(QString::fromUtf8("Kohinoor Devanagari"));
        font7.setPointSize(40);
        font7.setBold(true);
        font7.setWeight(75);
        label_16->setFont(font7);
        txt_hacerPubli = new QLineEdit(page_hacerPubli);
        txt_hacerPubli->setObjectName(QString::fromUtf8("txt_hacerPubli"));
        txt_hacerPubli->setGeometry(QRect(100, 180, 601, 31));
        txt_hacerPubli->setFont(font2);
        txt_hacerPubli->setEchoMode(QLineEdit::Normal);
        btt_publicar = new QPushButton(page_hacerPubli);
        btt_publicar->setObjectName(QString::fromUtf8("btt_publicar"));
        btt_publicar->setGeometry(QRect(310, 320, 141, 41));
        btt_publicar->setFont(font1);
        btt_publicar->setStyleSheet(QString::fromUtf8("QPushButton#btt_publicar{\n"
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
"QPushButton#btt_publicar:hover {\n"
"    background-color: #2980B9; \n"
"    border-color: #1F618D; \n"
"}\n"
"\n"
"QPushButton#btt_publicar:pressed {\n"
"    background-color: #2980B9; /* Color m\303\241s oscuro cuando se presiona */\n"
"    border-color: #1F618D; /* Borde m\303\241s oscuro cuando se presiona"
                        " */\n"
"}"));
        stackedWidget->addWidget(page_hacerPubli);
        page_white = new QWidget();
        page_white->setObjectName(QString::fromUtf8("page_white"));
        stackedWidget->addWidget(page_white);
        page_perfil = new QWidget();
        page_perfil->setObjectName(QString::fromUtf8("page_perfil"));
        frame_7 = new QFrame(page_perfil);
        frame_7->setObjectName(QString::fromUtf8("frame_7"));
        frame_7->setGeometry(QRect(0, 0, 541, 391));
        frame_7->setStyleSheet(QString::fromUtf8("QFrame#frame_7{\n"
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
        frame_7->setFrameShape(QFrame::StyledPanel);
        frame_7->setFrameShadow(QFrame::Raised);
        label_4 = new QLabel(frame_7);
        label_4->setObjectName(QString::fromUtf8("label_4"));
        label_4->setGeometry(QRect(20, 10, 91, 31));
        label_4->setFont(font4);
        label_5 = new QLabel(frame_7);
        label_5->setObjectName(QString::fromUtf8("label_5"));
        label_5->setGeometry(QRect(20, 50, 101, 31));
        label_5->setFont(font4);
        label_6 = new QLabel(frame_7);
        label_6->setObjectName(QString::fromUtf8("label_6"));
        label_6->setGeometry(QRect(20, 90, 81, 31));
        label_6->setFont(font4);
        label_7 = new QLabel(frame_7);
        label_7->setObjectName(QString::fromUtf8("label_7"));
        label_7->setGeometry(QRect(20, 130, 131, 31));
        label_7->setFont(font4);
        label_8 = new QLabel(frame_7);
        label_8->setObjectName(QString::fromUtf8("label_8"));
        label_8->setGeometry(QRect(20, 170, 211, 31));
        label_8->setFont(font4);
        txt_nombres = new QLineEdit(frame_7);
        txt_nombres->setObjectName(QString::fromUtf8("txt_nombres"));
        txt_nombres->setGeometry(QRect(140, 10, 381, 31));
        txt_nombres->setFont(font2);
        txt_nombres->setEchoMode(QLineEdit::Normal);
        txt_apellidos = new QLineEdit(frame_7);
        txt_apellidos->setObjectName(QString::fromUtf8("txt_apellidos"));
        txt_apellidos->setGeometry(QRect(140, 50, 381, 31));
        txt_apellidos->setFont(font2);
        txt_apellidos->setEchoMode(QLineEdit::Normal);
        txt_apellidos->setReadOnly(false);
        txt_correo = new QLineEdit(frame_7);
        txt_correo->setObjectName(QString::fromUtf8("txt_correo"));
        txt_correo->setGeometry(QRect(140, 90, 381, 31));
        txt_correo->setFont(font2);
        txt_correo->setEchoMode(QLineEdit::Normal);
        txt_contrasenia = new QLineEdit(frame_7);
        txt_contrasenia->setObjectName(QString::fromUtf8("txt_contrasenia"));
        txt_contrasenia->setGeometry(QRect(140, 130, 381, 31));
        txt_contrasenia->setFont(font2);
        txt_contrasenia->setEchoMode(QLineEdit::Normal);
        txt_fechaNac = new QLineEdit(frame_7);
        txt_fechaNac->setObjectName(QString::fromUtf8("txt_fechaNac"));
        txt_fechaNac->setGeometry(QRect(230, 170, 291, 31));
        txt_fechaNac->setFont(font2);
        txt_fechaNac->setEchoMode(QLineEdit::Normal);
        btt_modificarDatos = new QPushButton(frame_7);
        btt_modificarDatos->setObjectName(QString::fromUtf8("btt_modificarDatos"));
        btt_modificarDatos->setGeometry(QRect(70, 290, 161, 41));
        btt_modificarDatos->setFont(font1);
        btt_modificarDatos->setStyleSheet(QString::fromUtf8("QPushButton#btt_modificarDatos {\n"
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
"QPushButton#btt_modificarDatos:hover {\n"
"    background-color: #582924; \n"
"    border-color: #3c1e1b; \n"
"}\n"
"\n"
"QPushButton#btt_modificarDatos:press {\n"
"    background-color: #2980B9; /* Color m\303\241s oscuro cuando se presiona */\n"
"    border-color: #3c1e1b; /* Borde m\303\241s oscuro c"
                        "uando se presiona */\n"
"}"));
        btt_eliminarDatos = new QPushButton(frame_7);
        btt_eliminarDatos->setObjectName(QString::fromUtf8("btt_eliminarDatos"));
        btt_eliminarDatos->setGeometry(QRect(260, 290, 161, 41));
        btt_eliminarDatos->setFont(font1);
        btt_eliminarDatos->setStyleSheet(QString::fromUtf8("QPushButton#btt_eliminarDatos {\n"
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
"QPushButton#btt_eliminarDatos:hover {\n"
"    background-color: #582924; \n"
"    border-color: #3c1e1b; \n"
"}\n"
"\n"
"QPushButton#btt_eliminarDatos:press {\n"
"    background-color: #2980B9; /* Color m\303\241s oscuro cuando se presiona */\n"
"    border-color: #3c1e1b; /* Borde m\303\241s oscuro cuan"
                        "do se presiona */\n"
"}"));
        frame_8 = new QFrame(page_perfil);
        frame_8->setObjectName(QString::fromUtf8("frame_8"));
        frame_8->setGeometry(QRect(550, 20, 231, 221));
        frame_8->setStyleSheet(QString::fromUtf8("QFrame#frame_8{\n"
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
        frame_8->setFrameShape(QFrame::StyledPanel);
        frame_8->setFrameShadow(QFrame::Raised);
        view_grphUser = new QGraphicsView(frame_8);
        view_grphUser->setObjectName(QString::fromUtf8("view_grphUser"));
        view_grphUser->setGeometry(QRect(10, 10, 211, 201));
        stackedWidget->addWidget(page_perfil);
        page_edtiPerfil = new QWidget();
        page_edtiPerfil->setObjectName(QString::fromUtf8("page_edtiPerfil"));
        frame_10 = new QFrame(page_edtiPerfil);
        frame_10->setObjectName(QString::fromUtf8("frame_10"));
        frame_10->setGeometry(QRect(0, 0, 541, 391));
        frame_10->setStyleSheet(QString::fromUtf8("QFrame#frame_10{\n"
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
        frame_10->setFrameShape(QFrame::StyledPanel);
        frame_10->setFrameShadow(QFrame::Raised);
        label_9 = new QLabel(frame_10);
        label_9->setObjectName(QString::fromUtf8("label_9"));
        label_9->setGeometry(QRect(20, 10, 91, 31));
        label_9->setFont(font4);
        label_17 = new QLabel(frame_10);
        label_17->setObjectName(QString::fromUtf8("label_17"));
        label_17->setGeometry(QRect(20, 50, 101, 31));
        label_17->setFont(font4);
        label_18 = new QLabel(frame_10);
        label_18->setObjectName(QString::fromUtf8("label_18"));
        label_18->setGeometry(QRect(20, 90, 81, 31));
        label_18->setFont(font4);
        label_19 = new QLabel(frame_10);
        label_19->setObjectName(QString::fromUtf8("label_19"));
        label_19->setGeometry(QRect(20, 130, 131, 31));
        label_19->setFont(font4);
        label_20 = new QLabel(frame_10);
        label_20->setObjectName(QString::fromUtf8("label_20"));
        label_20->setGeometry(QRect(20, 170, 211, 31));
        label_20->setFont(font4);
        txt_nombres_2 = new QLineEdit(frame_10);
        txt_nombres_2->setObjectName(QString::fromUtf8("txt_nombres_2"));
        txt_nombres_2->setGeometry(QRect(140, 10, 381, 31));
        txt_nombres_2->setFont(font2);
        txt_nombres_2->setEchoMode(QLineEdit::Normal);
        txt_apellidos_2 = new QLineEdit(frame_10);
        txt_apellidos_2->setObjectName(QString::fromUtf8("txt_apellidos_2"));
        txt_apellidos_2->setGeometry(QRect(140, 50, 381, 31));
        txt_apellidos_2->setFont(font2);
        txt_apellidos_2->setEchoMode(QLineEdit::Normal);
        txt_apellidos_2->setReadOnly(false);
        txt_correo_2 = new QLineEdit(frame_10);
        txt_correo_2->setObjectName(QString::fromUtf8("txt_correo_2"));
        txt_correo_2->setGeometry(QRect(140, 90, 381, 31));
        txt_correo_2->setFont(font2);
        txt_correo_2->setEchoMode(QLineEdit::Normal);
        txt_contrasenia_2 = new QLineEdit(frame_10);
        txt_contrasenia_2->setObjectName(QString::fromUtf8("txt_contrasenia_2"));
        txt_contrasenia_2->setGeometry(QRect(140, 130, 381, 31));
        txt_contrasenia_2->setFont(font2);
        txt_contrasenia_2->setEchoMode(QLineEdit::Normal);
        txt_fechaNac_2 = new QLineEdit(frame_10);
        txt_fechaNac_2->setObjectName(QString::fromUtf8("txt_fechaNac_2"));
        txt_fechaNac_2->setGeometry(QRect(230, 170, 291, 31));
        txt_fechaNac_2->setFont(font2);
        txt_fechaNac_2->setEchoMode(QLineEdit::Normal);
        btt_modificarDatos_2 = new QPushButton(frame_10);
        btt_modificarDatos_2->setObjectName(QString::fromUtf8("btt_modificarDatos_2"));
        btt_modificarDatos_2->setGeometry(QRect(190, 280, 161, 41));
        btt_modificarDatos_2->setFont(font1);
        btt_modificarDatos_2->setStyleSheet(QString::fromUtf8("QPushButton#btt_modificarDatos_2 {\n"
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
"QPushButton#btt_modificarDatos_2:hover {\n"
"    background-color: #582924; \n"
"    border-color: #3c1e1b; \n"
"}\n"
"\n"
"QPushButton#btt_modificarDatos_2:press {\n"
"    background-color: #2980B9; /* Color m\303\241s oscuro cuando se presiona */\n"
"    border-color: #3c1e1b; /* Borde m\303\241s os"
                        "curo cuando se presiona */\n"
"}"));
        stackedWidget->addWidget(page_edtiPerfil);
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
        lbl_tituloUser = new QLabel(Form_usuario);
        lbl_tituloUser->setObjectName(QString::fromUtf8("lbl_tituloUser"));
        lbl_tituloUser->setGeometry(QRect(480, 30, 331, 61));
        QFont font8;
        font8.setFamily(QString::fromUtf8("Kohinoor Devanagari"));
        font8.setPointSize(20);
        font8.setBold(false);
        font8.setItalic(true);
        font8.setWeight(50);
        font8.setStyleStrategy(QFont::PreferAntialias);
        lbl_tituloUser->setFont(font8);
        lbl_tituloUser->setLayoutDirection(Qt::LeftToRight);
        lbl_tituloUser->setAlignment(Qt::AlignRight|Qt::AlignTrailing|Qt::AlignVCenter);

        retranslateUi(Form_usuario);

        stackedWidget->setCurrentIndex(6);


        QMetaObject::connectSlotsByName(Form_usuario);
    } // setupUi

    void retranslateUi(QWidget *Form_usuario)
    {
        Form_usuario->setWindowTitle(QCoreApplication::translate("Form_usuario", "Form", nullptr));
        label->setText(QCoreApplication::translate("Form_usuario", "Social Structure", nullptr));
        btt_buscar->setText(QCoreApplication::translate("Form_usuario", "Buscar", nullptr));
        btt_solicitudes->setText(QCoreApplication::translate("Form_usuario", "Solicitudes", nullptr));
        btt_reportes->setText(QCoreApplication::translate("Form_usuario", "Reportes", nullptr));
        btt_perfil->setText(QCoreApplication::translate("Form_usuario", "Perfil", nullptr));
        btt_cerrarSesion->setText(QCoreApplication::translate("Form_usuario", "Cerrar sesi\303\263n", nullptr));
        txt_buscarUser->setText(QString());
        label_2->setText(QCoreApplication::translate("Form_usuario", "Buscar:", nullptr));
        btt_buscar2->setText(QCoreApplication::translate("Form_usuario", "\360\237\224\215\357\270\216", nullptr));
        label_10->setText(QCoreApplication::translate("Form_usuario", "Nombres:", nullptr));
        label_11->setText(QCoreApplication::translate("Form_usuario", "Apellidos:", nullptr));
        label_12->setText(QCoreApplication::translate("Form_usuario", "Correo:", nullptr));
        label_13->setText(QCoreApplication::translate("Form_usuario", "Fecha de nacimiento:", nullptr));
        lbl_nombreUserfind->setText(QString());
        lbl_apellidoUserfind->setText(QString());
        lbl_correoUserfind->setText(QString());
        lbl_dateUserfind->setText(QString());
        label_3->setText(QCoreApplication::translate("Form_usuario", "Publicaciones:", nullptr));
        btt_hacerPubli->setText(QCoreApplication::translate("Form_usuario", "Crear nueva publicaci\303\263n", nullptr));
        label_14->setText(QCoreApplication::translate("Form_usuario", "Fechas con m\303\241s publicaciones", nullptr));
        label_15->setText(QCoreApplication::translate("Form_usuario", "Publicaciones con mayor cantidad de comentarios", nullptr));
        label_16->setText(QCoreApplication::translate("Form_usuario", "\302\277Qu\303\251 estas pensando hoy?", nullptr));
        txt_hacerPubli->setText(QString());
        btt_publicar->setText(QCoreApplication::translate("Form_usuario", "PUBLICAR", nullptr));
        label_4->setText(QCoreApplication::translate("Form_usuario", "Nombres:", nullptr));
        label_5->setText(QCoreApplication::translate("Form_usuario", "Apellidos:", nullptr));
        label_6->setText(QCoreApplication::translate("Form_usuario", "Correo:", nullptr));
        label_7->setText(QCoreApplication::translate("Form_usuario", "Contrase\303\261a:", nullptr));
        label_8->setText(QCoreApplication::translate("Form_usuario", "Fecha de nacimiento:", nullptr));
        txt_nombres->setText(QString());
        txt_apellidos->setText(QString());
        txt_correo->setText(QString());
        txt_contrasenia->setText(QString());
        txt_fechaNac->setText(QString());
        btt_modificarDatos->setText(QCoreApplication::translate("Form_usuario", "Modificar datos", nullptr));
        btt_eliminarDatos->setText(QCoreApplication::translate("Form_usuario", "Eliminar Cuenta", nullptr));
        label_9->setText(QCoreApplication::translate("Form_usuario", "Nombres:", nullptr));
        label_17->setText(QCoreApplication::translate("Form_usuario", "Apellidos:", nullptr));
        label_18->setText(QCoreApplication::translate("Form_usuario", "Correo:", nullptr));
        label_19->setText(QCoreApplication::translate("Form_usuario", "Contrase\303\261a:", nullptr));
        label_20->setText(QCoreApplication::translate("Form_usuario", "Fecha de nacimiento:", nullptr));
        txt_nombres_2->setText(QString());
        txt_apellidos_2->setText(QString());
        txt_correo_2->setText(QString());
        txt_contrasenia_2->setText(QString());
        txt_fechaNac_2->setText(QString());
        btt_modificarDatos_2->setText(QCoreApplication::translate("Form_usuario", "Modificar datos", nullptr));
        btt_publicaciones->setText(QCoreApplication::translate("Form_usuario", "Publicaciones", nullptr));
        lbl_tituloUser->setText(QString());
    } // retranslateUi

};

namespace Ui {
    class Form_usuario: public Ui_Form_usuario {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_FORM_USUARIO_H
