#ifndef USUARIOSTABLEMODEL_H
#define USUARIOSTABLEMODEL_H

#include <QAbstractTableModel>
#include <QPushButton>
#include "../../../usuarios/global_usuariosAVL.h"  // Incluye tu AVL con arbolGlobal_usuarios
#include <vector>
#include <QMessageBox>
#include <QColor>
#include <QDebug>

class UsuariosTableModel : public QAbstractTableModel {
    Q_OBJECT

public:
    explicit UsuariosTableModel(QObject *parent = nullptr);
    int rowCount(const QModelIndex &parent = QModelIndex()) const override;
    int columnCount(const QModelIndex &parent = QModelIndex()) const override;
    QVariant data(const QModelIndex &index, int role = Qt::DisplayRole) const override;
    QVariant headerData(int section, Qt::Orientation orientation, int role = Qt::DisplayRole) const override;
    void actualizarDatosDesdeAVL(AVL& arbol, const std::string& correoExcluido);
    std::string procesarSeleccion(const QModelIndex &index);  // Método para manejar la selección

signals:
    void enviarSolicitud(QString correo);

private:
    std::vector<Usuarios> datos;

    // Método para llenar 'datos' con el recorrido in-orden
    void recorrerInOrden(NodoAVL* nodo, const std::string& correoExcluido);
};

#endif // USUARIOSTABLEMODEL_H