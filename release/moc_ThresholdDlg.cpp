/****************************************************************************
** Meta object code from reading C++ file 'ThresholdDlg.h'
**
** Created by: The Qt Meta Object Compiler version 67 (Qt 5.14.2)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include <memory>
#include "../ThresholdDlg.h"
#include <QtCore/qbytearray.h>
#include <QtCore/qmetatype.h>
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'ThresholdDlg.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 67
#error "This file was generated using the moc from 5.14.2. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
QT_WARNING_PUSH
QT_WARNING_DISABLE_DEPRECATED
struct qt_meta_stringdata_ThresholdDlg_t {
    QByteArrayData data[8];
    char stringdata0[203];
};
#define QT_MOC_LITERAL(idx, ofs, len) \
    Q_STATIC_BYTE_ARRAY_DATA_HEADER_INITIALIZER_WITH_OFFSET(len, \
    qptrdiff(offsetof(qt_meta_stringdata_ThresholdDlg_t, stringdata0) + ofs \
        - idx * sizeof(QByteArrayData)) \
    )
static const qt_meta_stringdata_ThresholdDlg_t qt_meta_stringdata_ThresholdDlg = {
    {
QT_MOC_LITERAL(0, 0, 12), // "ThresholdDlg"
QT_MOC_LITERAL(1, 13, 44), // "on_horizontalSliderMinThresho..."
QT_MOC_LITERAL(2, 58, 0), // ""
QT_MOC_LITERAL(3, 59, 5), // "value"
QT_MOC_LITERAL(4, 65, 44), // "on_horizontalSliderMaxThresho..."
QT_MOC_LITERAL(5, 110, 35), // "on_spinBoxMinThreshold_valueC..."
QT_MOC_LITERAL(6, 146, 35), // "on_spinBoxMaxThreshold_valueC..."
QT_MOC_LITERAL(7, 182, 20) // "on_btnSelect_clicked"

    },
    "ThresholdDlg\0on_horizontalSliderMinThreshold_valueChanged\0"
    "\0value\0on_horizontalSliderMaxThreshold_valueChanged\0"
    "on_spinBoxMinThreshold_valueChanged\0"
    "on_spinBoxMaxThreshold_valueChanged\0"
    "on_btnSelect_clicked"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_ThresholdDlg[] = {

 // content:
       8,       // revision
       0,       // classname
       0,    0, // classinfo
       5,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       0,       // signalCount

 // slots: name, argc, parameters, tag, flags
       1,    1,   39,    2, 0x08 /* Private */,
       4,    1,   42,    2, 0x08 /* Private */,
       5,    1,   45,    2, 0x08 /* Private */,
       6,    1,   48,    2, 0x08 /* Private */,
       7,    0,   51,    2, 0x08 /* Private */,

 // slots: parameters
    QMetaType::Void, QMetaType::Int,    3,
    QMetaType::Void, QMetaType::Int,    3,
    QMetaType::Void, QMetaType::Int,    3,
    QMetaType::Void, QMetaType::Int,    3,
    QMetaType::Void,

       0        // eod
};

void ThresholdDlg::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        auto *_t = static_cast<ThresholdDlg *>(_o);
        Q_UNUSED(_t)
        switch (_id) {
        case 0: _t->on_horizontalSliderMinThreshold_valueChanged((*reinterpret_cast< int(*)>(_a[1]))); break;
        case 1: _t->on_horizontalSliderMaxThreshold_valueChanged((*reinterpret_cast< int(*)>(_a[1]))); break;
        case 2: _t->on_spinBoxMinThreshold_valueChanged((*reinterpret_cast< int(*)>(_a[1]))); break;
        case 3: _t->on_spinBoxMaxThreshold_valueChanged((*reinterpret_cast< int(*)>(_a[1]))); break;
        case 4: _t->on_btnSelect_clicked(); break;
        default: ;
        }
    }
}

QT_INIT_METAOBJECT const QMetaObject ThresholdDlg::staticMetaObject = { {
    QMetaObject::SuperData::link<QDialog::staticMetaObject>(),
    qt_meta_stringdata_ThresholdDlg.data,
    qt_meta_data_ThresholdDlg,
    qt_static_metacall,
    nullptr,
    nullptr
} };


const QMetaObject *ThresholdDlg::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *ThresholdDlg::qt_metacast(const char *_clname)
{
    if (!_clname) return nullptr;
    if (!strcmp(_clname, qt_meta_stringdata_ThresholdDlg.stringdata0))
        return static_cast<void*>(this);
    return QDialog::qt_metacast(_clname);
}

int ThresholdDlg::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QDialog::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        if (_id < 5)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 5;
    } else if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        if (_id < 5)
            *reinterpret_cast<int*>(_a[0]) = -1;
        _id -= 5;
    }
    return _id;
}
QT_WARNING_POP
QT_END_MOC_NAMESPACE
