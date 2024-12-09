#include "SoliRecividasTableModel.h"

SoliRecividasTableModel::SoliRecividasTableModel(QObject *parent)
    : QAbstractTableModel(parent) {}

int SoliRecividasTableModel::rowCount(const QModelIndex &parent) const {
    return parent.isValid() ? 0 : solicitudes.size();  // Número de filas es el tamaño de las solicitudes
}

int SoliRecividasTableModel::columnCount(const QModelIndex &parent) const {
    return parent.isValid() ? 0 : 3;  // Tres columnas: Correo, Aceptar, Rechazar
}

QVariant SoliRecividasTableModel::data(const QModelIndex &index, int role) const {
    if (!index.isValid()) return QVariant();

    const Solicitud& solicitud = solicitudes[index.row()];
    if (role == Qt::DisplayRole) {
        switch (index.column()) {
            case 0: return QString::fromStdString(solicitud.getEmisor());  // Columna de Correo
            case 1: return "Aceptar";  // Columna de Aceptar
            case 2: return "Rechazar";  // Columna de Rechazar
            default: return QVariant();
        }
    }
    return QVariant();
}

QVariant SoliRecividasTableModel::headerData(int section, Qt::Orientation orientation, int role) const {
    if (role == Qt::DisplayRole && orientation == Qt::Horizontal) {
        switch (section) {
            case 0: return "Correo";
            case 1: return "Aceptar";
            case 2: return "Rechazar";
            default: return QVariant();
        }
    }
    return QVariant();
}

void SoliRecividasTableModel::actualizarSolicitudes(const std::string& correoActual, AVL& arbolGlobal_usuarios) {
    beginResetModel();
    solicitudes.clear();

    // Busca el usuario actual en el árbol global y obtiene la pila de solicitudes
    auto usuarioNodo = arbolGlobal_usuarios.buscarPorCorreo(correoActual);
    if (usuarioNodo) {
        auto& pilaSolicitudes = usuarioNodo->getData().getPilaSolicitudes();

        // Copiar solicitudes desde la pila para visualización en la tabla
        solicitud_pila copiaPila = pilaSolicitudes;  // Copia de la pila
        while (!copiaPila.estaVacia()) {
            solicitudes.push_back(copiaPila.top());
            copiaPila.pop();
        }
    }
    endResetModel();
}

void SoliRecividasTableModel::procesarAccion(const QModelIndex &index, const QString& accion) {
    if (!index.isValid() || index.column() < 1 || index.column() > 2) return;

    // Obtener el correo del emisor de la solicitud en la fila seleccionada
    std::string correoEmisor = solicitudes[index.row()].getEmisor();
    QString mensaje;

    // Verificar la acción (Aceptar o Rechazar) y crear el mensaje adecuado
    if (accion == "Aceptar") {
        registroSolicitudes(loginUser_global, correoEmisor, "ACEPTADA");
        mensaje = "Usted ha aceptado la solicitud de " + QString::fromStdString(correoEmisor);
    } else if (accion == "Rechazar") {
        registroSolicitudes(loginUser_global, correoEmisor, "RECHAZADA");
        mensaje = "Usted ha rechazado la solicitud de " + QString::fromStdString(correoEmisor);
    }

    // Emitir señal con el mensaje para mostrar al usuario
    emit solicitudProcesada(mensaje);

    // Remover la solicitud aceptada/rechazada de la lista y actualizar la tabla
    beginRemoveRows(QModelIndex(), index.row(), index.row());
    solicitudes.erase(solicitudes.begin() + index.row());
    endRemoveRows();
}
