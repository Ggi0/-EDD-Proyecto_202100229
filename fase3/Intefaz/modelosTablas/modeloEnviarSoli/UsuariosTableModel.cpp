#include "UsuariosTableModel.h"

UsuariosTableModel::UsuariosTableModel(QObject *parent)
    : QAbstractTableModel(parent) {
}

int UsuariosTableModel::rowCount(const QModelIndex &parent) const {
    return parent.isValid() ? 0 : datos.size();
}

int UsuariosTableModel::columnCount(const QModelIndex &parent) const {
    return parent.isValid() ? 0 : 5;  // 5 columnas
}

QVariant UsuariosTableModel::data(const QModelIndex &index, int role) const {
    if (!index.isValid()) return QVariant();

    // Crear una copia no-const del usuario
    Usuarios usuario = datos[index.row()];
    if (role == Qt::DisplayRole) {
        switch (index.column()) {
            case 0: return QString::fromStdString(usuario.getNombres());
            case 1: return QString::fromStdString(usuario.getApellidos());
            case 2: return QString::fromStdString(usuario.getCorreo());
            case 3: return QString::fromStdString(usuario.getFechaN());
            case 4: return "Enviar solicitud";  // Texto para el botón
            default: return QVariant();
        }
    }
    return QVariant();
}

QVariant UsuariosTableModel::headerData(int section, Qt::Orientation orientation, int role) const {
    if (role == Qt::DisplayRole && orientation == Qt::Horizontal) {
        switch (section) {
            case 0: return "Nombre";
            case 1: return "Apellidos";
            case 2: return "Correo";
            case 3: return "Fecha Nacimiento";
            case 4: return "Acción";
            default: return QVariant();
        }
    }
    return QVariant();
}

void UsuariosTableModel::actualizarDatosDesdeAVL(AVL& arbol, const std::string& correoExcluido) {
    beginResetModel();
    datos.clear();

    // Llenar datos con el recorrido in-orden
    if (auto raiz = arbol.getRaiz()) {
        recorrerInOrden(raiz, correoExcluido);
    }

    endResetModel();
}

// Método para recorrer el árbol in-orden y llenar 'datos'
void UsuariosTableModel::recorrerInOrden(NodoAVL* nodo, const std::string& correoExcluido) {
    if (nodo == nullptr) return;

    // Recorrido in-orden
    recorrerInOrden(nodo->getIzq(), correoExcluido);

    // Excluir al usuario con el correo especificado
    if (nodo->getData().getCorreo() != correoExcluido) {
        datos.push_back(nodo->getData());
    }

    recorrerInOrden(nodo->getDrcha(), correoExcluido);
}