#include "mainwindow.h"
#include "ui_mainwindow.h"

#include "form_admin.h"
#include "form_registrarusuarios.h"
#include "form_usuario.h"

#include "../../publicaciones/arbolBinario/bst_publi.h"
#include "../../publicaciones/comentario/listaComentarios/lista_comentarios.h"
#include "../../publicaciones/comentario/comentario.h"
//#include "../../publicaciones/comentario/arbolB/arbolB.h"
#include "../../usuarios/usuario.h"

#include "../../usuarios/global_usuariosAVL.h"

#include "../../publicaciones/publicacion.h"
#include "../../publicaciones/comentario/listaComentarios/lista_comentarios.h"
#include "../../publicaciones/registroPublicaciones.h"


MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);

}


MainWindow::~MainWindow()
{
    delete ui;
}


// ------------ BOTON LOGIN -----------------
void MainWindow::on_btt_login_clicked()
{
    std::string loginUser_global;

    /*
    // ----------- probar lista ------------------
    listaAdyacencia grafo;

        Usuarios usuario1("José", "Martínez", "15/04/1990", "jose", "password123");
        Usuarios usuario2("Javier", "González", "22/08/1987", "javier", "password456");
        Usuarios usuario3("Pedro", "López", "30/01/1985", "pedro", "password789");
        Usuarios usuario4("Adriana", "Pérez", "17/07/1992", "adriana", "password321");
        Usuarios usuario5("Cristian", "Ramírez", "05/12/1993", "cristian", "password654");
        Usuarios usuario6("María", "Hernández", "10/03/1989", "maria@", "password987");
        Usuarios usuario7("Melisa", "Gómez", "25/09/1991", "melisa", "password741");
        Usuarios usuario8("Kevin", "Díaz", "19/11/1990", "kevin", "password852");
        Usuarios usuario9("Mario", "Sánchez", "03/05/1988", "mario", "password963");
        Usuarios usuario10("Juan", "Cc", "03/05/1988", "juan", "password964");

        grafo.insert(usuario1);
        grafo.insert(usuario2);
        grafo.insert(usuario3);
        grafo.insert(usuario4);
        grafo.insert(usuario5);
        grafo.insert(usuario6);
        grafo.insert(usuario7);
        grafo.insert(usuario8);
        grafo.insert(usuario9);
        grafo.insert(usuario10);

        crearConexionGrafo(grafo, usuario1, usuario2); // José - Javier
        crearConexionGrafo(grafo, usuario1, usuario3); // José - Pedro
        crearConexionGrafo(grafo, usuario1, usuario4); // José - Adriana
        crearConexionGrafo(grafo, usuario1, usuario6); // José - María

        crearConexionGrafo(grafo, usuario5, usuario2); // Cristian - Javier
        crearConexionGrafo(grafo, usuario5, usuario3); // Cristian - Pedro
        crearConexionGrafo(grafo, usuario5, usuario4); // Cristian - Adriana

        crearConexionGrafo(grafo, usuario3, usuario4); // Pedro - Adriana

        crearConexionGrafo(grafo, usuario6, usuario8); // María - Kevin
        crearConexionGrafo(grafo, usuario6, usuario9); // María - Mario
        crearConexionGrafo(grafo, usuario6, usuario7); // María - Melisa

        crearConexionGrafo(grafo, usuario7, usuario4); // Melisa - Adriana

        crearConexionGrafo(grafo, usuario10, usuario2); // Melisa - Adriana
        crearConexionGrafo(grafo, usuario10, usuario3); // Melisa - Adriana
        crearConexionGrafo(grafo, usuario10, usuario4); // Melisa - Adriana
        crearConexionGrafo(grafo, usuario10, usuario6); // Melisa - Adriana


        grafo.crearGrafo();
        grafo.crearGrafoLista();


        // Obtener sugerencias para José
        listaSugerencias* sugerencias = grafo.sugerirAmistades("maria@");
        sugerencias->mostrarSugerencias();
        delete sugerencias;  // No olvides liberar la memoria

    // -------------------------------------------------------------------
*/

    // Obtén los textos de los QLineEdit
    QString username = ui->txt_user->text();    // usuario
    QString password = ui->txt_pasword->text(); // contrasenia

    // Validar los campos, que no esten vacios
    if(username.isEmpty() || password.isEmpty()) {
        QMessageBox::warning(this, "Error", "Todos los campos deben estar completos.");
        return;
    }

    // Convertir de QString a std::string
    std::string username_str = username.toStdString();
    std::string password_str = password.toStdString();

    // Llamar la funcion para verficar el LOGIN
    int resultado = iniciarSesion(username_str, password_str);

    if (resultado == 0){ // error login
        QMessageBox::warning(this, "Login fallido", "Usuario o contraseña incorrectos.");
    }else if (resultado == 1) { // acceso usuarios

        /*   // probando si se puede graficar por fecha. (si se puede)
        NodoAVL* usue_preuba = arbolGlobal_usuarios.buscarPorCorreo(username_str);
        Usuarios& usuario = usue_preuba->getData();
        usuario.graficar_fecha("22/08/2024");
        */

        // Crear una instancia de la nueva ventana
        Form_usuario *formUser = new Form_usuario(); // Ahora utiliza Form_usuario
        formUser->show(); // Muestra la ventana form_usuario
        // Cierra la ventana actual (login)
        this->close();

    }else if (resultado == 2){
        // Crear una instancia de la nueva ventana
        Form_admin *formAdmin = new Form_admin(); // Ahora utiliza Form_admin (ventana de ADMIN)
        formAdmin->show(); // Muestra la ventana form_admin
        // Cierra la ventana actual (login)
        this->close();

    }

    if (username == "gio" && password == "gio") {
                // Crear una instancia de la nueva ventana
                Form_usuario *formUser = new Form_usuario(); // Ahora utiliza Form_admin
                formUser->show(); // Muestra la ventana form_admin

                // Cierra la ventana actual (login)
                this->close();
    }


}




void MainWindow::on_btt_registro_clicked()
{
    // Crear una instancia de la nueva ventana
    Form_registrarUsuarios *formRegistroUsuarios = new Form_registrarUsuarios(); // Ahora utiliza Form_admin
    formRegistroUsuarios->show(); // Muestra la ventana form_admin

    // Cierra la ventana actual (login)
    this->close();

}




void MainWindow::crearConexionGrafo(listaAdyacencia &grafo, Usuarios origen, Usuarios destino){
    grafo.crearConexion(origen, destino);
    grafo.crearConexion(destino, origen);
}

