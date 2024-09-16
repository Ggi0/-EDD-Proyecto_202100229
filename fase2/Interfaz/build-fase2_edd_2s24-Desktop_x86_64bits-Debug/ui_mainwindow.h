/********************************************************************************
** Form generated from reading UI file 'mainwindow.ui'
**
** Created by: Qt User Interface Compiler version 5.15.2
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_MAINWINDOW_H
#define UI_MAINWINDOW_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QFrame>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QMenuBar>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_MainWindow
{
public:
    QWidget *centralwidget;
    QLabel *label;
    QFrame *frame;
    QLabel *label_2;
    QLineEdit *txt_user;
    QLineEdit *txt_pasword;
    QLabel *label_3;
    QLabel *label_4;
    QPushButton *btt_login;
    QLabel *label_5;
    QPushButton *btt_registro;
    QLabel *label_6;
    QMenuBar *menubar;

    void setupUi(QMainWindow *MainWindow)
    {
        if (MainWindow->objectName().isEmpty())
            MainWindow->setObjectName(QString::fromUtf8("MainWindow"));
        MainWindow->resize(384, 550);
        QFont font;
        font.setPointSize(60);
        MainWindow->setFont(font);
        MainWindow->setStyleSheet(QString::fromUtf8("QWidget#centralwidget {\n"
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
        centralwidget = new QWidget(MainWindow);
        centralwidget->setObjectName(QString::fromUtf8("centralwidget"));
        label = new QLabel(centralwidget);
        label->setObjectName(QString::fromUtf8("label"));
        label->setGeometry(QRect(30, 10, 181, 61));
        QFont font1;
        font1.setFamily(QString::fromUtf8("Kohinoor Devanagari"));
        font1.setPointSize(60);
        font1.setBold(true);
        font1.setWeight(75);
        label->setFont(font1);
        frame = new QFrame(centralwidget);
        frame->setObjectName(QString::fromUtf8("frame"));
        frame->setGeometry(QRect(30, 150, 321, 361));
        frame->setStyleSheet(QString::fromUtf8("QFrame#frame {\n"
"    background-color: #E0F7FA; /* Azul claro con un toque vibrante */\n"
"    border: 2px solid #00796B; /* Borde en verde azulado para un contraste atractivo */\n"
"    border-radius: 12px; /* Bordes redondeados para suavidad */\n"
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
        label_2 = new QLabel(frame);
        label_2->setObjectName(QString::fromUtf8("label_2"));
        label_2->setGeometry(QRect(10, 10, 111, 16));
        QFont font2;
        font2.setFamily(QString::fromUtf8("Kohinoor Devanagari"));
        font2.setPointSize(20);
        font2.setBold(true);
        font2.setWeight(75);
        label_2->setFont(font2);
        txt_user = new QLineEdit(frame);
        txt_user->setObjectName(QString::fromUtf8("txt_user"));
        txt_user->setGeometry(QRect(40, 90, 231, 31));
        QFont font3;
        font3.setFamily(QString::fromUtf8("Kohinoor Devanagari"));
        font3.setPointSize(16);
        txt_user->setFont(font3);
        txt_user->setEchoMode(QLineEdit::Normal);
        txt_pasword = new QLineEdit(frame);
        txt_pasword->setObjectName(QString::fromUtf8("txt_pasword"));
        txt_pasword->setGeometry(QRect(40, 170, 231, 31));
        txt_pasword->setFont(font3);
        txt_pasword->setEchoMode(QLineEdit::Password);
        label_3 = new QLabel(frame);
        label_3->setObjectName(QString::fromUtf8("label_3"));
        label_3->setGeometry(QRect(40, 60, 111, 16));
        QFont font4;
        font4.setFamily(QString::fromUtf8("Kohinoor Devanagari"));
        font4.setPointSize(20);
        font4.setBold(false);
        font4.setWeight(50);
        label_3->setFont(font4);
        label_4 = new QLabel(frame);
        label_4->setObjectName(QString::fromUtf8("label_4"));
        label_4->setGeometry(QRect(40, 140, 111, 16));
        label_4->setFont(font4);
        btt_login = new QPushButton(frame);
        btt_login->setObjectName(QString::fromUtf8("btt_login"));
        btt_login->setGeometry(QRect(100, 220, 112, 41));
        QFont font5;
        font5.setFamily(QString::fromUtf8("Kohinoor Devanagari"));
        btt_login->setFont(font5);
        btt_login->setStyleSheet(QString::fromUtf8("QPushButton#btt_login {\n"
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
"QPushButton#btt_login:hover {\n"
"    background-color: #2980B9; \n"
"    border-color: #1F618D; \n"
"}\n"
"\n"
"QPushButton#btt_login:pressed {\n"
"    background-color: #2980B9; /* Color m\303\241s oscuro cuando se presiona */\n"
"    border-color: #1F618D; /* Borde m\303\241s oscuro cuando se presiona */\n"
""
                        "}"));
        label_5 = new QLabel(frame);
        label_5->setObjectName(QString::fromUtf8("label_5"));
        label_5->setGeometry(QRect(50, 330, 121, 16));
        QFont font6;
        font6.setFamily(QString::fromUtf8("Kohinoor Devanagari"));
        font6.setPointSize(14);
        font6.setBold(false);
        font6.setWeight(50);
        label_5->setFont(font6);
        btt_registro = new QPushButton(frame);
        btt_registro->setObjectName(QString::fromUtf8("btt_registro"));
        btt_registro->setGeometry(QRect(180, 330, 61, 21));
        QFont font7;
        font7.setFamily(QString::fromUtf8("Kohinoor Devanagari"));
        font7.setPointSize(12);
        font7.setItalic(false);
        font7.setUnderline(false);
        font7.setStrikeOut(false);
        font7.setKerning(true);
        btt_registro->setFont(font7);
        btt_registro->setStyleSheet(QString::fromUtf8("QPushButton#btt_registro {\n"
"    background-color: #E0F7FA; /* Azul claro con un toque vibrante */\n"
"\n"
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
        label_6 = new QLabel(centralwidget);
        label_6->setObjectName(QString::fromUtf8("label_6"));
        label_6->setGeometry(QRect(80, 80, 271, 61));
        label_6->setFont(font1);
        MainWindow->setCentralWidget(centralwidget);
        menubar = new QMenuBar(MainWindow);
        menubar->setObjectName(QString::fromUtf8("menubar"));
        menubar->setGeometry(QRect(0, 0, 384, 22));
        MainWindow->setMenuBar(menubar);

        retranslateUi(MainWindow);

        QMetaObject::connectSlotsByName(MainWindow);
    } // setupUi

    void retranslateUi(QMainWindow *MainWindow)
    {
        MainWindow->setWindowTitle(QCoreApplication::translate("MainWindow", "MainWindow", nullptr));
        label->setText(QCoreApplication::translate("MainWindow", "Social", nullptr));
        label_2->setText(QCoreApplication::translate("MainWindow", "Bienvenido!!", nullptr));
        txt_user->setText(QString());
        label_3->setText(QCoreApplication::translate("MainWindow", "Usuario:", nullptr));
        label_4->setText(QCoreApplication::translate("MainWindow", "Contrase\303\261a", nullptr));
        btt_login->setText(QCoreApplication::translate("MainWindow", "Login", nullptr));
        label_5->setText(QCoreApplication::translate("MainWindow", "\302\277no tienes cuenta?", nullptr));
        btt_registro->setText(QCoreApplication::translate("MainWindow", "Registrate", nullptr));
        label_6->setText(QCoreApplication::translate("MainWindow", "Structure", nullptr));
    } // retranslateUi

};

namespace Ui {
    class MainWindow: public Ui_MainWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MAINWINDOW_H
