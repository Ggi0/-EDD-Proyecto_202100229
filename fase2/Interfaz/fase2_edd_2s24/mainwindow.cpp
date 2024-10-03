#include "mainwindow.h"
#include "ui_mainwindow.h"

#include "form_admin.h"
#include "form_registrarusuarios.h"
#include "form_usuario.h"

#include "../../publicaciones/arbolBinario/bst_publi.h"
#include "../../publicaciones/comentario/listaComentarios/lista_comentarios.h"
#include "../../publicaciones/comentario/comentario.h"
#include "../../publicaciones/comentario/arbolB/arbolB.h"
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
    // -------------------- probando arbol binario -----------------------
    BST arbolPrueba;

    arbolPrueba.insertAndGetNode("10/11/2021");
    arbolPrueba.insertAndGetNode("10/10/2021");
    arbolPrueba.insertAndGetNode("10/11/2024");
    arbolPrueba.insertAndGetNode("21/11/2024");
    arbolPrueba.insertAndGetNode("1/3/2024");
    arbolPrueba.insertAndGetNode("6/10/2024");
    arbolPrueba.insertAndGetNode("30/5/2024");
    arbolPrueba.insertAndGetNode("23/12/2024");
    arbolPrueba.insertAndGetNode("13/6/2024");
    arbolPrueba.insertAndGetNode("2/8/2024");
    arbolPrueba.insertAndGetNode("20/11/2024");
    arbolPrueba.insertAndGetNode("21/2/2024");
    arbolPrueba.insertAndGetNode("29/5/2024");
    arbolPrueba.insertAndGetNode("1/6/2024");
    arbolPrueba.insertAndGetNode("1/6/2023");
    arbolPrueba.graph();
*/


    // ------------ probando arbol b --------------------------------
    Comentario nuevoComentario1("Ana", "mensaje1", "01/01/2024", "08:15");
     Comentario nuevoComentario1_2("Ana2", "mensaje2ana", "01/01/2024", "08:16");
    Comentario nuevoComentario2("Luis", "mensaje2", "15/02/2024", "09:30");
    Comentario nuevoComentario3("Maria", "mensaje3", "28/03/2024", "10:45");
    Comentario nuevoComentario4("Carlos", "mensaje4", "12/04/2024", "11:00");
    Comentario nuevoComentario5("Elena", "mensaje5", "25/05/2024", "12:15");
    Comentario nuevoComentario6("Jorge", "mensaje6", "07/06/2024", "13:30");
    Comentario nuevoComentario7("Lucia", "mensaje7", "19/07/2024", "14:45");
    Comentario nuevoComentario8("Pedro", "mensaje8", "30/08/2024", "15:00");
    Comentario nuevoComentario9("Sofia", "mensaje9", "11/09/2024", "16:15");
    Comentario nuevoComentario10("Miguel", "mensaje10", "23/10/2024", "17:30");
    Comentario nuevoComentario11("Laura", "mensaje11", "04/11/2024", "18:45");
    Comentario nuevoComentario12("MARCOS aurelio", "mensaje12", "16/12/2024", "19:00");
    Comentario nuevoComentario13("Jorge MAtias", "mensaje13", "06/6/2024", "13:31");


    ArbolB arbolB_prueba;  // Crear un árbol B de orden 5 (t = 3)

    arbolB_prueba.insertar(nuevoComentario1);
    arbolB_prueba.insertar(nuevoComentario1_2);
    arbolB_prueba.insertar(nuevoComentario2);
    arbolB_prueba.insertar(nuevoComentario3);
    arbolB_prueba.insertar(nuevoComentario4);
    arbolB_prueba.insertar(nuevoComentario5);
    arbolB_prueba.insertar(nuevoComentario6);
    arbolB_prueba.insertar(nuevoComentario7);
    arbolB_prueba.insertar(nuevoComentario8);
    arbolB_prueba.insertar(nuevoComentario9);
    arbolB_prueba.insertar(nuevoComentario10);
    arbolB_prueba.insertar(nuevoComentario11);
    arbolB_prueba.insertar(nuevoComentario12);
    arbolB_prueba.insertar(nuevoComentario13);

    arbolB_prueba.graficar();  // Genera el gráfico del árbol



    /*// -------------- porbando arbol BINARIO BST -------------------- *
    // haciendo usuario:
    Usuarios nuevoUsuario ("Gio", "Cc", "12/10/2002", "Gio@123", "123contra");
    Usuarios nuevoUsuario1 ("Gio", "Cc", "12/10/2002", "Gio2@123", "123contra");

    arbolGlobal_usuarios.insert(nuevoUsuario);
    arbolGlobal_usuarios.insert(nuevoUsuario1);


    lista_comentarios listaVacia;
    arbolGlobal_usuarios.graph();
    //nuevoUsuario.getBST_feedPublicaciones().graph();

    verificarCorreo_publicacion("Gio@123","1ra publicacion", "10/02/2024", "14:23", listaVacia);
    verificarCorreo_publicacion("Gio@123","2ra publicacion", "10/01/2024", "12:03", listaVacia);
    verificarCorreo_publicacion("Gio@123","3ra publicacion", "10/05/2024", "14:23", listaVacia);
    verificarCorreo_publicacion("Gio@123","4ra publicacion", "11/02/2024", "18:23", listaVacia);
    verificarCorreo_publicacion("Gio@123","5ra publicacion", "10/02/2024", "14:13", listaVacia);
    verificarCorreo_publicacion("Gio@123","6ra publicacion", "10/02/2024", "16:23", listaVacia);
    verificarCorreo_publicacion("Gio@123","7ra publicacion", "13/02/2024", "16:23", listaVacia);
    verificarCorreo_publicacion("Gio@123","8ra publicacion", "9/02/2024", "16:23", listaVacia);
    verificarCorreo_publicacion("Gio@123","9ra publicacion", "13/02/2024", "16:43", listaVacia);
    verificarCorreo_publicacion("Gio@123","10ra publicacion", "13/02/2024", "14:43", listaVacia);
    verificarCorreo_publicacion("Gio@123","11ra publicacion", "13/12/2024", "16:43", listaVacia);



    //nuevoUsuario.graficar_fecha("10/02/2024");
    //nuevoUsuario.generarGraficoBSTPersonal();

    std::cout <<"--------correo---------"<<std::endl;
    std::cout<< nuevoUsuario.getCorreo()<<std::endl;
    // Buscar el usuario por correo en el árbol AVL
    NodoAVL* usuarioEncontrado = arbolGlobal_usuarios.buscarPorCorreo(nuevoUsuario.getCorreo());

    std::cout <<"--------generar grafico---------"<<std::endl;
    usuarioEncontrado->getData().generarGraficoBSTPersonal();
    usuarioEncontrado->getData().getBST_feedPublicaciones().inOrden();
    usuarioEncontrado->getData().graficar_fecha("10/02/2024");
    std::cout <<"-----------------"<<std::endl;
    //nuevoUsuario.getBST_feedPublicaciones().inOrden();*/



    /*
    // ------------- probando LISTA COMENTARIOS --------------------
    lista_comentarios listaPrueba;

    listaPrueba.append(nuevoComentario1);
    listaPrueba.append(nuevoComentario2);
    listaPrueba.append(nuevoComentario3);
    listaPrueba.printAll();
    listaPrueba.graficar();
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


    /*
    // ------------- probando ARBOL AVL -------------------------

    Usuarios nuevoUsuario1("gio1", "gioApellido", "21 sep", "Carlos", "123");
    Usuarios nuevoUsuario2("gio2", "gioApellido2", "22 sep", "Francisco", "abc");
    Usuarios nuevoUsuario3("gio3", "gioApellido3", "23 sep", "Daniel", "abc");
    Usuarios nuevoUsuario4("gio4", "gioApellido4", "22 sep", "Jio", "abc");
    Usuarios nuevoUsuario5("gio5", "gioApellido5", "23 sep", "Xavier", "abc");

    nuevoUsuario1.printUsuario();
    nuevoUsuario2.printUsuario();
    nuevoUsuario3.printUsuario();
    nuevoUsuario4.printUsuario();
    nuevoUsuario5.printUsuario();

    AVL arbol;

    arbol.insert(nuevoUsuario1);
    arbol.insert(nuevoUsuario2);
    arbol.insert(nuevoUsuario3);
    arbol.insert(nuevoUsuario4);
    arbol.insert(nuevoUsuario5);

    arbol.graph();
    */

}




void MainWindow::on_btt_registro_clicked()
{
    // Crear una instancia de la nueva ventana
    Form_registrarUsuarios *formRegistroUsuarios = new Form_registrarUsuarios(); // Ahora utiliza Form_admin
    formRegistroUsuarios->show(); // Muestra la ventana form_admin

    // Cierra la ventana actual (login)
    this->close();

}

