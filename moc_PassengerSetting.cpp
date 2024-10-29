/****************************************************************************
** Meta object code from reading C++ file 'PassengerSetting.h'
**
** Created by: The Qt Meta Object Compiler version 67 (Qt 5.15.3)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include <memory>
#include "PassengerSetting.h"
#include <QtCore/qbytearray.h>
#include <QtCore/qmetatype.h>
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'PassengerSetting.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 67
#error "This file was generated using the moc from 5.15.3. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
QT_WARNING_PUSH
QT_WARNING_DISABLE_DEPRECATED
struct qt_meta_stringdata_PassengerSetting_t {
    QByteArrayData data[13];
    char stringdata0[372];
};
#define QT_MOC_LITERAL(idx, ofs, len) \
    Q_STATIC_BYTE_ARRAY_DATA_HEADER_INITIALIZER_WITH_OFFSET(len, \
    qptrdiff(offsetof(qt_meta_stringdata_PassengerSetting_t, stringdata0) + ofs \
        - idx * sizeof(QByteArrayData)) \
    )
static const qt_meta_stringdata_PassengerSetting_t qt_meta_stringdata_PassengerSetting = {
    {
QT_MOC_LITERAL(0, 0, 16), // "PassengerSetting"
QT_MOC_LITERAL(1, 17, 45), // "on_timeFloorButtonPressedSpin..."
QT_MOC_LITERAL(2, 63, 0), // ""
QT_MOC_LITERAL(3, 64, 4), // "arg1"
QT_MOC_LITERAL(4, 69, 33), // "on_startFloorSpinBox_valueCha..."
QT_MOC_LITERAL(5, 103, 39), // "on_directionComboBox_currentT..."
QT_MOC_LITERAL(6, 143, 39), // "on_destinationFloorSpinBox_va..."
QT_MOC_LITERAL(7, 183, 28), // "on_helpCheckBox_stateChanged"
QT_MOC_LITERAL(8, 212, 27), // "on_helpSpinBox_valueChanged"
QT_MOC_LITERAL(9, 240, 32), // "on_openDoorCheckBox_stateChanged"
QT_MOC_LITERAL(10, 273, 31), // "on_openDoorSpinBox_valueChanged"
QT_MOC_LITERAL(11, 305, 33), // "on_closeDoorCheckBox_stateCha..."
QT_MOC_LITERAL(12, 339, 32) // "on_closeDoorSpinBox_valueChanged"

    },
    "PassengerSetting\0"
    "on_timeFloorButtonPressedSpinBox_valueChanged\0"
    "\0arg1\0on_startFloorSpinBox_valueChanged\0"
    "on_directionComboBox_currentTextChanged\0"
    "on_destinationFloorSpinBox_valueChanged\0"
    "on_helpCheckBox_stateChanged\0"
    "on_helpSpinBox_valueChanged\0"
    "on_openDoorCheckBox_stateChanged\0"
    "on_openDoorSpinBox_valueChanged\0"
    "on_closeDoorCheckBox_stateChanged\0"
    "on_closeDoorSpinBox_valueChanged"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_PassengerSetting[] = {

 // content:
       8,       // revision
       0,       // classname
       0,    0, // classinfo
      10,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       0,       // signalCount

 // slots: name, argc, parameters, tag, flags
       1,    1,   64,    2, 0x08 /* Private */,
       4,    1,   67,    2, 0x08 /* Private */,
       5,    1,   70,    2, 0x08 /* Private */,
       6,    1,   73,    2, 0x08 /* Private */,
       7,    1,   76,    2, 0x08 /* Private */,
       8,    1,   79,    2, 0x08 /* Private */,
       9,    1,   82,    2, 0x08 /* Private */,
      10,    1,   85,    2, 0x08 /* Private */,
      11,    1,   88,    2, 0x08 /* Private */,
      12,    1,   91,    2, 0x08 /* Private */,

 // slots: parameters
    QMetaType::Void, QMetaType::Int,    3,
    QMetaType::Void, QMetaType::Int,    3,
    QMetaType::Void, QMetaType::QString,    3,
    QMetaType::Void, QMetaType::Int,    3,
    QMetaType::Void, QMetaType::Int,    3,
    QMetaType::Void, QMetaType::Int,    3,
    QMetaType::Void, QMetaType::Int,    3,
    QMetaType::Void, QMetaType::Int,    3,
    QMetaType::Void, QMetaType::Int,    3,
    QMetaType::Void, QMetaType::Int,    3,

       0        // eod
};

void PassengerSetting::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        auto *_t = static_cast<PassengerSetting *>(_o);
        (void)_t;
        switch (_id) {
        case 0: _t->on_timeFloorButtonPressedSpinBox_valueChanged((*reinterpret_cast< int(*)>(_a[1]))); break;
        case 1: _t->on_startFloorSpinBox_valueChanged((*reinterpret_cast< int(*)>(_a[1]))); break;
        case 2: _t->on_directionComboBox_currentTextChanged((*reinterpret_cast< const QString(*)>(_a[1]))); break;
        case 3: _t->on_destinationFloorSpinBox_valueChanged((*reinterpret_cast< int(*)>(_a[1]))); break;
        case 4: _t->on_helpCheckBox_stateChanged((*reinterpret_cast< int(*)>(_a[1]))); break;
        case 5: _t->on_helpSpinBox_valueChanged((*reinterpret_cast< int(*)>(_a[1]))); break;
        case 6: _t->on_openDoorCheckBox_stateChanged((*reinterpret_cast< int(*)>(_a[1]))); break;
        case 7: _t->on_openDoorSpinBox_valueChanged((*reinterpret_cast< int(*)>(_a[1]))); break;
        case 8: _t->on_closeDoorCheckBox_stateChanged((*reinterpret_cast< int(*)>(_a[1]))); break;
        case 9: _t->on_closeDoorSpinBox_valueChanged((*reinterpret_cast< int(*)>(_a[1]))); break;
        default: ;
        }
    }
}

QT_INIT_METAOBJECT const QMetaObject PassengerSetting::staticMetaObject = { {
    QMetaObject::SuperData::link<QWidget::staticMetaObject>(),
    qt_meta_stringdata_PassengerSetting.data,
    qt_meta_data_PassengerSetting,
    qt_static_metacall,
    nullptr,
    nullptr
} };


const QMetaObject *PassengerSetting::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *PassengerSetting::qt_metacast(const char *_clname)
{
    if (!_clname) return nullptr;
    if (!strcmp(_clname, qt_meta_stringdata_PassengerSetting.stringdata0))
        return static_cast<void*>(this);
    return QWidget::qt_metacast(_clname);
}

int PassengerSetting::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QWidget::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        if (_id < 10)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 10;
    } else if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        if (_id < 10)
            *reinterpret_cast<int*>(_a[0]) = -1;
        _id -= 10;
    }
    return _id;
}
QT_WARNING_POP
QT_END_MOC_NAMESPACE
