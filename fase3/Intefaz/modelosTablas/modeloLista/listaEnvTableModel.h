#ifndef LISTAENVTABLEMODEL_H
#define LISTAENVTABLEMODEL_H

#include <QAbstractTableModel>
#include "../../../usuarios/global_usuariosAVL.h"  // Incluye tu AVL con arbolGlobal_usuarios
#include <vector>
#include <QString>

#include "../../../solicitudes/registroSolicitudes.h"


class listaEnvTableModel : public QAbstractTableModel {
    Q_OBJECT

public:
    explicit listaEnvTableModel(QObject *parent = nullptr);
    int rowCount(const QModelIndex &parent = QModelIndex()) const override;
    int columnCount(const QModelIndex &parent = QModelIndex()) const override;
    QVariant data(const QModelIndex &index, int role = Qt::DisplayRole) const override;
    QVariant headerData(int section, Qt::Orientation orientation, int role = Qt::DisplayRole) const override;

    // Método para actualizar los datos del modelo basándose en el correo actual y el árbol de usuarios
    void actualizarSolicitudes(const std::string& correoActual, AVL& arbolGlobal_usuarios);

    // Método para procesar la acción de cancelar
    void procesarAccion(const QModelIndex &index);

signals:
    void solicitudCancelada(QString mensaje);  // Señal para indicar la solicitud cancelada

private:
    std::vector<Solicitud> solicitudes;  // Vector para almacenar solicitudes enviadas
};

#endif // LISTAENVTABLEMODEL_H
