// AVLTableModel.h
#ifndef AVLTABLEMODEL_H
#define AVLTABLEMODEL_H

#include <QAbstractTableModel>
#include <QMessageBox>


#include "../global_usuariosAVL.h"
#include <vector>

class AVLTableModel : public QAbstractTableModel {
    Q_OBJECT

    public:
        explicit AVLTableModel(QObject *parent = nullptr);
        
        // Funciones obligatorias de QAbstractTableModel
        int rowCount(const QModelIndex &parent = QModelIndex()) const override;
        int columnCount(const QModelIndex &parent = QModelIndex()) const override;
        QVariant data(const QModelIndex &index, int role = Qt::DisplayRole) const override;
        QVariant headerData(int section, Qt::Orientation orientation, int role = Qt::DisplayRole) const override;
        
        // Función para actualizar los datos desde el árbol AVL
        //void actualizarDatosDesdeAVL(AVL& arbol);

        // Funciones para actualizar los datos según el tipo de recorrido
        void actualizarDatosDesdeAVL(AVL& arbol);
        void actualizarDatosPreOrden(AVL& arbol);
        void actualizarDatosInOrden(AVL& arbol);
        void actualizarDatosPostOrden(AVL& arbol);

        // Método para buscar y posicionar un usuario en la primera fila
        void buscarYPosicionarUsuario(AVL& arbol, const std::string& correo);

        // Método para eliminar un usuario por correo
        void eliminarUsuario(AVL& arbol, const std::string& correo);

        

    private:
        // Vector para almacenar los datos del árbol
        std::vector<Usuarios> datos;
        
        // Función auxiliar para recorrer el árbol
        //void recorrerArbol(NodoAVL* nodo);

        // Funciones auxiliares para recorridos
        void recorrerArbol(NodoAVL* nodo);
        void recorrerPreOrden(NodoAVL* nodo);
        void recorrerInOrden(NodoAVL* nodo);
        void recorrerPostOrden(NodoAVL* nodo);
};

#endif // AVLTABLEMODEL_H