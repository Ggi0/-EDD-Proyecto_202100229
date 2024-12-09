#ifndef SOLIRECIVIDASTABLEMODEL_H
#define SOLIRECIVIDASTABLEMODEL_H

#include <QAbstractTableModel>
#include <QPushButton>
#include "../../../usuarios/global_usuariosAVL.h"  // Incluye tu AVL con arbolGlobal_usuarios
#include <vector>
#include <QMessageBox>
#include <QColor>
#include <QDebug>

#include "../../../solicitudes/registroSolicitudes.h"


class SoliRecividasTableModel : public QAbstractTableModel {
    Q_OBJECT

public:
    explicit SoliRecividasTableModel(QObject *parent = nullptr);
    int rowCount(const QModelIndex &parent = QModelIndex()) const override;
    int columnCount(const QModelIndex &parent = QModelIndex()) const override;
    QVariant data(const QModelIndex &index, int role = Qt::DisplayRole) const override;
    QVariant headerData(int section, Qt::Orientation orientation, int role = Qt::DisplayRole) const override;

    // Método para actualizar los datos del modelo basándose en el correo actual y el arbol de usuarios
    void actualizarSolicitudes(const std::string& correoActual, AVL& arbolGlobal_usuarios);

    // Método para procesar el clic en "Aceptar" o "Rechazar"
    void procesarAccion(const QModelIndex &index, const QString& accion);

signals:
    void solicitudProcesada(QString mensaje);  // Señal para indicar la solicitud procesada

private:
    std::vector<Solicitud> solicitudes;  // Vector para almacenar solicitudes
};

#endif // SOLIRECIVIDASTABLEMODEL_H
