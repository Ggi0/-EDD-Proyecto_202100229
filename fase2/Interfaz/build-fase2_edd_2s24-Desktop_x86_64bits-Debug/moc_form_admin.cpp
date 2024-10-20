/****************************************************************************
** Meta object code from reading C++ file 'form_admin.h'
**
** Created by: The Qt Meta Object Compiler version 67 (Qt 5.15.2)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include <memory>
#include "../../../fase3/Intefaz/fase2_edd_2s24/form_admin.h"
#include <QtCore/qbytearray.h>
#include <QtCore/qmetatype.h>
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'form_admin.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 67
#error "This file was generated using the moc from 5.15.2. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
QT_WARNING_PUSH
QT_WARNING_DISABLE_DEPRECATED
struct qt_meta_stringdata_Form_admin_t {
    QByteArrayData data[14];
    char stringdata0[314];
};
#define QT_MOC_LITERAL(idx, ofs, len) \
    Q_STATIC_BYTE_ARRAY_DATA_HEADER_INITIALIZER_WITH_OFFSET(len, \
    qptrdiff(offsetof(qt_meta_stringdata_Form_admin_t, stringdata0) + ofs \
        - idx * sizeof(QByteArrayData)) \
    )
static const qt_meta_stringdata_Form_admin_t qt_meta_stringdata_Form_admin = {
    {
QT_MOC_LITERAL(0, 0, 10), // "Form_admin"
QT_MOC_LITERAL(1, 11, 21), // "on_btt_buscar_clicked"
QT_MOC_LITERAL(2, 33, 0), // ""
QT_MOC_LITERAL(3, 34, 23), // "on_btt_cargarAr_clicked"
QT_MOC_LITERAL(4, 58, 23), // "on_btt_reportes_clicked"
QT_MOC_LITERAL(5, 82, 27), // "on_btt_cerrarSesion_clicked"
QT_MOC_LITERAL(6, 110, 24), // "on_btt_cUsuarios_clicked"
QT_MOC_LITERAL(7, 135, 27), // "on_btt_cSolicitudes_clicked"
QT_MOC_LITERAL(8, 163, 29), // "on_btt_cPublicaciones_clicked"
QT_MOC_LITERAL(9, 193, 22), // "on_btt_buscar2_clicked"
QT_MOC_LITERAL(10, 216, 32), // "on_cbx_orden_currentIndexChanged"
QT_MOC_LITERAL(11, 249, 5), // "index"
QT_MOC_LITERAL(12, 255, 27), // "on_btt_eliminarUser_clicked"
QT_MOC_LITERAL(13, 283, 30) // "on_btt_generarReportes_clicked"

    },
    "Form_admin\0on_btt_buscar_clicked\0\0"
    "on_btt_cargarAr_clicked\0on_btt_reportes_clicked\0"
    "on_btt_cerrarSesion_clicked\0"
    "on_btt_cUsuarios_clicked\0"
    "on_btt_cSolicitudes_clicked\0"
    "on_btt_cPublicaciones_clicked\0"
    "on_btt_buscar2_clicked\0"
    "on_cbx_orden_currentIndexChanged\0index\0"
    "on_btt_eliminarUser_clicked\0"
    "on_btt_generarReportes_clicked"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_Form_admin[] = {

 // content:
       8,       // revision
       0,       // classname
       0,    0, // classinfo
      11,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       0,       // signalCount

 // slots: name, argc, parameters, tag, flags
       1,    0,   69,    2, 0x08 /* Private */,
       3,    0,   70,    2, 0x08 /* Private */,
       4,    0,   71,    2, 0x08 /* Private */,
       5,    0,   72,    2, 0x08 /* Private */,
       6,    0,   73,    2, 0x08 /* Private */,
       7,    0,   74,    2, 0x08 /* Private */,
       8,    0,   75,    2, 0x08 /* Private */,
       9,    0,   76,    2, 0x08 /* Private */,
      10,    1,   77,    2, 0x08 /* Private */,
      12,    0,   80,    2, 0x08 /* Private */,
      13,    0,   81,    2, 0x08 /* Private */,

 // slots: parameters
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void, QMetaType::Int,   11,
    QMetaType::Void,
    QMetaType::Void,

       0        // eod
};

void Form_admin::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        auto *_t = static_cast<Form_admin *>(_o);
        Q_UNUSED(_t)
        switch (_id) {
        case 0: _t->on_btt_buscar_clicked(); break;
        case 1: _t->on_btt_cargarAr_clicked(); break;
        case 2: _t->on_btt_reportes_clicked(); break;
        case 3: _t->on_btt_cerrarSesion_clicked(); break;
        case 4: _t->on_btt_cUsuarios_clicked(); break;
        case 5: _t->on_btt_cSolicitudes_clicked(); break;
        case 6: _t->on_btt_cPublicaciones_clicked(); break;
        case 7: _t->on_btt_buscar2_clicked(); break;
        case 8: _t->on_cbx_orden_currentIndexChanged((*reinterpret_cast< int(*)>(_a[1]))); break;
        case 9: _t->on_btt_eliminarUser_clicked(); break;
        case 10: _t->on_btt_generarReportes_clicked(); break;
        default: ;
        }
    }
}

QT_INIT_METAOBJECT const QMetaObject Form_admin::staticMetaObject = { {
    QMetaObject::SuperData::link<QWidget::staticMetaObject>(),
    qt_meta_stringdata_Form_admin.data,
    qt_meta_data_Form_admin,
    qt_static_metacall,
    nullptr,
    nullptr
} };


const QMetaObject *Form_admin::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *Form_admin::qt_metacast(const char *_clname)
{
    if (!_clname) return nullptr;
    if (!strcmp(_clname, qt_meta_stringdata_Form_admin.stringdata0))
        return static_cast<void*>(this);
    return QWidget::qt_metacast(_clname);
}

int Form_admin::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QWidget::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        if (_id < 11)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 11;
    } else if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        if (_id < 11)
            *reinterpret_cast<int*>(_a[0]) = -1;
        _id -= 11;
    }
    return _id;
}
QT_WARNING_POP
QT_END_MOC_NAMESPACE
