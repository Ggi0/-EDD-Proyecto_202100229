#include "listaEnvTableModel.h"

listaEnvTableModel::listaEnvTableModel(QObject *parent)
    : QAbstractTableModel(parent) {}

int listaEnvTableModel::rowCount(const QModelIndex &parent) const {
    return parent.isValid() ? 0 : solicitudes.size();  // Número de filas es el tamaño de las solicitudes
}

int listaEnvTableModel::columnCount(const QModelIndex &parent) const {
    return parent.isValid() ? 0 : 2;  // Dos columnas: Correo, Cancelar
}

QVariant listaEnvTableModel::data(const QModelIndex &index, int role) const {
    if (!index.isValid()) return QVariant();

    const Solicitud& solicitud = solicitudes[index.row()];
    if (role == Qt::DisplayRole) {
        switch (index.column()) {
            case 0: return QString::fromStdString(solicitud.getReceptor());  // Columna de Correo
            case 1: return "Cancelar";  // Columna de Cancelar
            default: return QVariant();
        }
    }
    return QVariant();
}

QVariant listaEnvTableModel::headerData(int section, Qt::Orientation orientation, int role) const {
    if (role == Qt::DisplayRole && orientation == Qt::Horizontal) {
        switch (section) {
            case 0: return "Correo";
            case 1: return "Cancelar";
            default: return QVariant();
        }
    }
    return QVariant();
}

void listaEnvTableModel::actualizarSolicitudes(const std::string& correoActual, AVL& arbolGlobal_usuarios) {
    beginResetModel();
    solicitudes.clear();

    // Busca el usuario actual en el árbol global y obtiene la lista de solicitudes enviadas
    auto usuarioNodo = arbolGlobal_usuarios.buscarPorCorreo(correoActual);
    if (usuarioNodo) {
        arrayList_soli& listaSolicitudes = usuarioNodo->getData().getListaSolicitudes();

        // Recorrer manualmente la lista simplemente enlazada y agregar cada solicitud a `solicitudes`
        solicitud_Nodo* actual = listaSolicitudes.getPrimero();
        while (actual != nullptr) {
            solicitudes.push_back(actual->getDato());
            actual = actual->getSig();
        }
    }
    endResetModel();
}

void listaEnvTableModel::procesarAccion(const QModelIndex &index) {
    if (!index.isValid() || index.column() != 1) return;

    // Obtener el correo del receptor de la solicitud en la fila seleccionada
    std::string correoReceptor = solicitudes[index.row()].getReceptor();
    registroSolicitudes(correoReceptor, loginUser_global, "RECHAZADA");
    QString mensaje = "Usted ha cancelado la solicitud a " + QString::fromStdString(correoReceptor);

    // Emitir señal con el mensaje para mostrar al usuario
    emit solicitudCancelada(mensaje);

    // Eliminar la solicitud solo de la vista sin afectar la lista original
    beginRemoveRows(QModelIndex(), index.row(), index.row());
    solicitudes.erase(solicitudes.begin() + index.row());
    endRemoveRows();
}
