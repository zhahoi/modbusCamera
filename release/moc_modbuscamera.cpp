/****************************************************************************
** Meta object code from reading C++ file 'modbuscamera.h'
**
** Created by: The Qt Meta Object Compiler version 67 (Qt 5.14.2)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include <memory>
#include "../modbuscamera.h"
#include <QtCore/qbytearray.h>
#include <QtCore/qmetatype.h>
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'modbuscamera.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 67
#error "This file was generated using the moc from 5.14.2. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
QT_WARNING_PUSH
QT_WARNING_DISABLE_DEPRECATED
struct qt_meta_stringdata_modbusCamera_t {
    QByteArrayData data[26];
    char stringdata0[435];
};
#define QT_MOC_LITERAL(idx, ofs, len) \
    Q_STATIC_BYTE_ARRAY_DATA_HEADER_INITIALIZER_WITH_OFFSET(len, \
    qptrdiff(offsetof(qt_meta_stringdata_modbusCamera_t, stringdata0) + ofs \
        - idx * sizeof(QByteArrayData)) \
    )
static const qt_meta_stringdata_modbusCamera_t qt_meta_stringdata_modbusCamera = {
    {
QT_MOC_LITERAL(0, 0, 12), // "modbusCamera"
QT_MOC_LITERAL(1, 13, 14), // "updateTextEdit"
QT_MOC_LITERAL(2, 28, 0), // ""
QT_MOC_LITERAL(3, 29, 7), // "message"
QT_MOC_LITERAL(4, 37, 23), // "sendRegistorsDataSignal"
QT_MOC_LITERAL(5, 61, 12), // "displayImage"
QT_MOC_LITERAL(6, 74, 5), // "image"
QT_MOC_LITERAL(7, 80, 19), // "displayDetectResult"
QT_MOC_LITERAL(8, 100, 8), // "ret_code"
QT_MOC_LITERAL(9, 109, 25), // "on_connect_modbus_clicked"
QT_MOC_LITERAL(10, 135, 28), // "on_disconnect_modbus_clicked"
QT_MOC_LITERAL(11, 164, 17), // "readRegistersData"
QT_MOC_LITERAL(12, 182, 18), // "replyRegistersData"
QT_MOC_LITERAL(13, 201, 23), // "onSendRegistorsDataSlot"
QT_MOC_LITERAL(14, 225, 18), // "updateImageDisplay"
QT_MOC_LITERAL(15, 244, 25), // "updateDetectResultDisplay"
QT_MOC_LITERAL(16, 270, 22), // "on_modbus_stateChanged"
QT_MOC_LITERAL(17, 293, 20), // "QModbusDevice::State"
QT_MOC_LITERAL(18, 314, 5), // "state"
QT_MOC_LITERAL(19, 320, 23), // "on_modbus_errorOccurred"
QT_MOC_LITERAL(20, 344, 20), // "QModbusDevice::Error"
QT_MOC_LITERAL(21, 365, 5), // "error"
QT_MOC_LITERAL(22, 371, 20), // "on_connectionTimeout"
QT_MOC_LITERAL(23, 392, 21), // "on_comboBox_activated"
QT_MOC_LITERAL(24, 414, 5), // "index"
QT_MOC_LITERAL(25, 420, 14) // "loadCameraList"

    },
    "modbusCamera\0updateTextEdit\0\0message\0"
    "sendRegistorsDataSignal\0displayImage\0"
    "image\0displayDetectResult\0ret_code\0"
    "on_connect_modbus_clicked\0"
    "on_disconnect_modbus_clicked\0"
    "readRegistersData\0replyRegistersData\0"
    "onSendRegistorsDataSlot\0updateImageDisplay\0"
    "updateDetectResultDisplay\0"
    "on_modbus_stateChanged\0QModbusDevice::State\0"
    "state\0on_modbus_errorOccurred\0"
    "QModbusDevice::Error\0error\0"
    "on_connectionTimeout\0on_comboBox_activated\0"
    "index\0loadCameraList"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_modbusCamera[] = {

 // content:
       8,       // revision
       0,       // classname
       0,    0, // classinfo
      16,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       4,       // signalCount

 // signals: name, argc, parameters, tag, flags
       1,    1,   94,    2, 0x06 /* Public */,
       4,    0,   97,    2, 0x06 /* Public */,
       5,    1,   98,    2, 0x06 /* Public */,
       7,    1,  101,    2, 0x06 /* Public */,

 // slots: name, argc, parameters, tag, flags
       9,    0,  104,    2, 0x08 /* Private */,
      10,    0,  105,    2, 0x08 /* Private */,
      11,    0,  106,    2, 0x08 /* Private */,
      12,    0,  107,    2, 0x08 /* Private */,
      13,    0,  108,    2, 0x08 /* Private */,
      14,    1,  109,    2, 0x08 /* Private */,
      15,    1,  112,    2, 0x08 /* Private */,
      16,    1,  115,    2, 0x08 /* Private */,
      19,    1,  118,    2, 0x08 /* Private */,
      22,    0,  121,    2, 0x08 /* Private */,
      23,    1,  122,    2, 0x08 /* Private */,
      25,    0,  125,    2, 0x08 /* Private */,

 // signals: parameters
    QMetaType::Void, QMetaType::QString,    3,
    QMetaType::Void,
    QMetaType::Void, QMetaType::QImage,    6,
    QMetaType::Void, QMetaType::Int,    8,

 // slots: parameters
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void, QMetaType::QImage,    6,
    QMetaType::Void, QMetaType::Int,    8,
    QMetaType::Void, 0x80000000 | 17,   18,
    QMetaType::Void, 0x80000000 | 20,   21,
    QMetaType::Void,
    QMetaType::Void, QMetaType::Int,   24,
    QMetaType::Void,

       0        // eod
};

void modbusCamera::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        auto *_t = static_cast<modbusCamera *>(_o);
        Q_UNUSED(_t)
        switch (_id) {
        case 0: _t->updateTextEdit((*reinterpret_cast< const QString(*)>(_a[1]))); break;
        case 1: _t->sendRegistorsDataSignal(); break;
        case 2: _t->displayImage((*reinterpret_cast< const QImage(*)>(_a[1]))); break;
        case 3: _t->displayDetectResult((*reinterpret_cast< int(*)>(_a[1]))); break;
        case 4: _t->on_connect_modbus_clicked(); break;
        case 5: _t->on_disconnect_modbus_clicked(); break;
        case 6: _t->readRegistersData(); break;
        case 7: _t->replyRegistersData(); break;
        case 8: _t->onSendRegistorsDataSlot(); break;
        case 9: _t->updateImageDisplay((*reinterpret_cast< const QImage(*)>(_a[1]))); break;
        case 10: _t->updateDetectResultDisplay((*reinterpret_cast< int(*)>(_a[1]))); break;
        case 11: _t->on_modbus_stateChanged((*reinterpret_cast< QModbusDevice::State(*)>(_a[1]))); break;
        case 12: _t->on_modbus_errorOccurred((*reinterpret_cast< QModbusDevice::Error(*)>(_a[1]))); break;
        case 13: _t->on_connectionTimeout(); break;
        case 14: _t->on_comboBox_activated((*reinterpret_cast< int(*)>(_a[1]))); break;
        case 15: _t->loadCameraList(); break;
        default: ;
        }
    } else if (_c == QMetaObject::IndexOfMethod) {
        int *result = reinterpret_cast<int *>(_a[0]);
        {
            using _t = void (modbusCamera::*)(const QString & );
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&modbusCamera::updateTextEdit)) {
                *result = 0;
                return;
            }
        }
        {
            using _t = void (modbusCamera::*)();
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&modbusCamera::sendRegistorsDataSignal)) {
                *result = 1;
                return;
            }
        }
        {
            using _t = void (modbusCamera::*)(const QImage & );
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&modbusCamera::displayImage)) {
                *result = 2;
                return;
            }
        }
        {
            using _t = void (modbusCamera::*)(int );
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&modbusCamera::displayDetectResult)) {
                *result = 3;
                return;
            }
        }
    }
}

QT_INIT_METAOBJECT const QMetaObject modbusCamera::staticMetaObject = { {
    QMetaObject::SuperData::link<QMainWindow::staticMetaObject>(),
    qt_meta_stringdata_modbusCamera.data,
    qt_meta_data_modbusCamera,
    qt_static_metacall,
    nullptr,
    nullptr
} };


const QMetaObject *modbusCamera::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *modbusCamera::qt_metacast(const char *_clname)
{
    if (!_clname) return nullptr;
    if (!strcmp(_clname, qt_meta_stringdata_modbusCamera.stringdata0))
        return static_cast<void*>(this);
    return QMainWindow::qt_metacast(_clname);
}

int modbusCamera::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QMainWindow::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        if (_id < 16)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 16;
    } else if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        if (_id < 16)
            *reinterpret_cast<int*>(_a[0]) = -1;
        _id -= 16;
    }
    return _id;
}

// SIGNAL 0
void modbusCamera::updateTextEdit(const QString & _t1)
{
    void *_a[] = { nullptr, const_cast<void*>(reinterpret_cast<const void*>(std::addressof(_t1))) };
    QMetaObject::activate(this, &staticMetaObject, 0, _a);
}

// SIGNAL 1
void modbusCamera::sendRegistorsDataSignal()
{
    QMetaObject::activate(this, &staticMetaObject, 1, nullptr);
}

// SIGNAL 2
void modbusCamera::displayImage(const QImage & _t1)
{
    void *_a[] = { nullptr, const_cast<void*>(reinterpret_cast<const void*>(std::addressof(_t1))) };
    QMetaObject::activate(this, &staticMetaObject, 2, _a);
}

// SIGNAL 3
void modbusCamera::displayDetectResult(int _t1)
{
    void *_a[] = { nullptr, const_cast<void*>(reinterpret_cast<const void*>(std::addressof(_t1))) };
    QMetaObject::activate(this, &staticMetaObject, 3, _a);
}
QT_WARNING_POP
QT_END_MOC_NAMESPACE
