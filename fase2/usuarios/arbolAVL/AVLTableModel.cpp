// AVLTableModel.cpp
#include "AVLTableModel.h"

AVLTableModel::AVLTableModel(QObject *parent)
    : QAbstractTableModel(parent)
{
}

int AVLTableModel::rowCount(const QModelIndex &parent) const
{
    if (parent.isValid())
        return 0;
    return datos.size();
}

int AVLTableModel::columnCount(const QModelIndex &parent) const
{
    if (parent.isValid())
        return 0;
    return 6; // Número total de columnas
}

QVariant AVLTableModel::data(const QModelIndex &index, int role) const
{
    if (!index.isValid() || role != Qt::DisplayRole)
        return QVariant();

    // Creamos una copia no-const del usuario para poder llamar a los métodos
    Usuarios usuario = datos[index.row()];
    
    switch (index.column()) {
        case 0: return QString::fromStdString(usuario.getNombres());
        case 1: return QString::fromStdString(usuario.getApellidos());
        case 2: return QString::fromStdString(usuario.getCorreo());
        case 3: return QString::fromStdString(usuario.getFechaN());
        case 4: return usuario.getID();
        case 5: return QString::fromStdString(usuario.getContrasenia());
        default: return QVariant();
    }
}

QVariant AVLTableModel::headerData(int section, Qt::Orientation orientation, int role) const
{
    if (role != Qt::DisplayRole)
        return QVariant();

    if (orientation == Qt::Horizontal) {
        switch (section) {
            case 0: return "Nombre";
            case 1: return "Apellidos";
            case 2: return "Correo";
            case 3: return "Fecha";
            case 4: return "ID";
            case 5: return "Contraseña";
            default: return QVariant();
        }
    }
    return QVariant();
}


void AVLTableModel::actualizarDatosDesdeAVL(AVL& arbol)
{
    // Limpiamos los datos actuales
    beginResetModel();
    datos.clear();
    
    // Recorremos el árbol y llenamos el vector
    if (arbol.getRaiz()) {  // Ahora usamos una referencia, no un puntero
        recorrerArbol(arbol.getRaiz());
    }
    
    endResetModel();
}

void AVLTableModel::recorrerArbol(NodoAVL* nodo)
{
    if (nodo == nullptr) return;
    
    // Recorrido in-orden
    recorrerArbol(nodo->getIzq());
    datos.push_back(nodo->getData());
    recorrerArbol(nodo->getDrcha());
}

// Actualizar datos en PreOrden
void AVLTableModel::actualizarDatosPreOrden(AVL& arbol)
{
    beginResetModel();
    datos.clear();
    
    if (arbol.getRaiz()) {
        recorrerPreOrden(arbol.getRaiz());
    }
    
    endResetModel();
}

// Actualizar datos en InOrden
void AVLTableModel::actualizarDatosInOrden(AVL& arbol)
{
    beginResetModel();
    datos.clear();
    
    if (arbol.getRaiz()) {
        recorrerInOrden(arbol.getRaiz());
    }
    
    endResetModel();
}

// Actualizar datos en PostOrden
void AVLTableModel::actualizarDatosPostOrden(AVL& arbol)
{
    beginResetModel();
    datos.clear();
    
    if (arbol.getRaiz()) {
        recorrerPostOrden(arbol.getRaiz());
    }
    
    endResetModel();
}

// Recorrido PreOrden
void AVLTableModel::recorrerPreOrden(NodoAVL* nodo)
{
    if (nodo == nullptr) return;
    
    datos.push_back(nodo->getData());
    recorrerPreOrden(nodo->getIzq());
    recorrerPreOrden(nodo->getDrcha());
}

// Recorrido InOrden
void AVLTableModel::recorrerInOrden(NodoAVL* nodo)
{
    if (nodo == nullptr) return;
    
    recorrerInOrden(nodo->getIzq());
    datos.push_back(nodo->getData());
    recorrerInOrden(nodo->getDrcha());
}

// Recorrido PostOrden
void AVLTableModel::recorrerPostOrden(NodoAVL* nodo)
{
    if (nodo == nullptr) return;
    
    recorrerPostOrden(nodo->getIzq());
    recorrerPostOrden(nodo->getDrcha());
    datos.push_back(nodo->getData());
}

// Método para buscar y posicionar un usuario en la primera fila
void AVLTableModel::buscarYPosicionarUsuario(AVL& arbol, const std::string& correo) {
    // Buscar el usuario en el árbol AVL
    NodoAVL* nodo = arbol.buscarPorCorreo(correo);
    
    // Si no se encuentra el usuario, mostramos un mensaje
    if (nodo == nullptr) {
        QMessageBox::information(nullptr, "Usuario no encontrado", "El usuario con este correo no existe.");
        return;
    }

    // Si encontramos el usuario, lo extraemos
    Usuarios usuario = nodo->getData();

    // Limpiamos la tabla y movemos al usuario encontrado a la primera posición
    beginResetModel();
    
    // Verificamos si el usuario ya está en la lista
    auto it = std::find_if(datos.begin(), datos.end(), [&](Usuarios& u) {
        return u.getCorreo() == correo;
    });

    if (it != datos.end()) {
        // Eliminamos al usuario de su posición actual
        datos.erase(it);
    }

    // Insertamos al usuario en la primera fila
    datos.insert(datos.begin(), usuario);

    endResetModel();
}


void AVLTableModel::eliminarUsuario(AVL& arbol, const std::string& correo) {
    // Eliminar el usuario del árbol AVL
    arbol.delPorCorreo(correo);
    
    // Actualizar los datos del modelo después de eliminar el usuario
    actualizarDatosDesdeAVL(arbol);
    
    // Opcional: Mensaje de confirmación de eliminación
    QMessageBox::information(nullptr, "Usuario Eliminado", "El usuario ha sido eliminado exitosamente.");
}