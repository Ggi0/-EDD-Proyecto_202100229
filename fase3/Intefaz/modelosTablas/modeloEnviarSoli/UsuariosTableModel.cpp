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
            case 4: return "Enviar Solicitud";  // Texto para el botón
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

void UsuariosTableModel::recorrerInOrden(NodoAVL* nodo, const std::string& correoExcluido) {
    if (nodo == nullptr) return;

    // Recorrido in-orden
    recorrerInOrden(nodo->getIzq(), correoExcluido);

    if (nodo->getData().getCorreo() != correoExcluido) {
        datos.push_back(nodo->getData());
    }

    recorrerInOrden(nodo->getDrcha(), correoExcluido);
}

std::string UsuariosTableModel::procesarSeleccion(const QModelIndex &index) {
    if (!index.isValid() || index.column() != 4) return "";  // Verificar que esté en la última columna

    int row = index.row();
    std::string correoReceptor = datos[row].getCorreo();

    // Emitir señal para enviar solicitud
    emit enviarSolicitud(QString::fromStdString(correoReceptor));

    // Eliminar la fila seleccionada y actualizar la tabla
    beginRemoveRows(QModelIndex(), row, row);
    datos.erase(datos.begin() + row);
    endRemoveRows();

    return correoReceptor;
}