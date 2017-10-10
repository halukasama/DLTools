/****************************************************************************
** Meta object code from reading C++ file 'ConfigDialog.h'
**
** Created by: The Qt Meta Object Compiler version 67 (Qt 5.6.3)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "../../src/ConfigDialog.h"
#include <QtCore/qbytearray.h>
#include <QtCore/qmetatype.h>
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'ConfigDialog.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 67
#error "This file was generated using the moc from 5.6.3. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
struct qt_meta_stringdata_ConfigCallBack_t {
    QByteArrayData data[8];
    char stringdata0[94];
};
#define QT_MOC_LITERAL(idx, ofs, len) \
    Q_STATIC_BYTE_ARRAY_DATA_HEADER_INITIALIZER_WITH_OFFSET(len, \
    qptrdiff(offsetof(qt_meta_stringdata_ConfigCallBack_t, stringdata0) + ofs \
        - idx * sizeof(QByteArrayData)) \
    )
static const qt_meta_stringdata_ConfigCallBack_t qt_meta_stringdata_ConfigCallBack = {
    {
QT_MOC_LITERAL(0, 0, 14), // "ConfigCallBack"
QT_MOC_LITERAL(1, 15, 10), // "configInfo"
QT_MOC_LITERAL(2, 26, 0), // ""
QT_MOC_LITERAL(3, 27, 21), // "DeviceLayer::IDevice*"
QT_MOC_LITERAL(4, 49, 7), // "pDevice"
QT_MOC_LITERAL(5, 57, 10), // "paramsList"
QT_MOC_LITERAL(6, 68, 19), // "setConfigInfoResult"
QT_MOC_LITERAL(7, 88, 5) // "error"

    },
    "ConfigCallBack\0configInfo\0\0"
    "DeviceLayer::IDevice*\0pDevice\0paramsList\0"
    "setConfigInfoResult\0error"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_ConfigCallBack[] = {

 // content:
       7,       // revision
       0,       // classname
       0,    0, // classinfo
       2,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       2,       // signalCount

 // signals: name, argc, parameters, tag, flags
       1,    2,   24,    2, 0x06 /* Public */,
       6,    2,   29,    2, 0x06 /* Public */,

 // signals: parameters
    QMetaType::Void, 0x80000000 | 3, QMetaType::QStringList,    4,    5,
    QMetaType::Void, 0x80000000 | 3, QMetaType::Bool,    4,    7,

       0        // eod
};

void ConfigCallBack::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        ConfigCallBack *_t = static_cast<ConfigCallBack *>(_o);
        Q_UNUSED(_t)
        switch (_id) {
        case 0: _t->configInfo((*reinterpret_cast< DeviceLayer::IDevice*(*)>(_a[1])),(*reinterpret_cast< QStringList(*)>(_a[2]))); break;
        case 1: _t->setConfigInfoResult((*reinterpret_cast< DeviceLayer::IDevice*(*)>(_a[1])),(*reinterpret_cast< bool(*)>(_a[2]))); break;
        default: ;
        }
    } else if (_c == QMetaObject::IndexOfMethod) {
        int *result = reinterpret_cast<int *>(_a[0]);
        void **func = reinterpret_cast<void **>(_a[1]);
        {
            typedef void (ConfigCallBack::*_t)(DeviceLayer::IDevice * , QStringList );
            if (*reinterpret_cast<_t *>(func) == static_cast<_t>(&ConfigCallBack::configInfo)) {
                *result = 0;
                return;
            }
        }
        {
            typedef void (ConfigCallBack::*_t)(DeviceLayer::IDevice * , bool );
            if (*reinterpret_cast<_t *>(func) == static_cast<_t>(&ConfigCallBack::setConfigInfoResult)) {
                *result = 1;
                return;
            }
        }
    }
}

const QMetaObject ConfigCallBack::staticMetaObject = {
    { &QObject::staticMetaObject, qt_meta_stringdata_ConfigCallBack.data,
      qt_meta_data_ConfigCallBack,  qt_static_metacall, Q_NULLPTR, Q_NULLPTR}
};


const QMetaObject *ConfigCallBack::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *ConfigCallBack::qt_metacast(const char *_clname)
{
    if (!_clname) return Q_NULLPTR;
    if (!strcmp(_clname, qt_meta_stringdata_ConfigCallBack.stringdata0))
        return static_cast<void*>(const_cast< ConfigCallBack*>(this));
    if (!strcmp(_clname, "DeviceLayer::IConfigCallback"))
        return static_cast< DeviceLayer::IConfigCallback*>(const_cast< ConfigCallBack*>(this));
    return QObject::qt_metacast(_clname);
}

int ConfigCallBack::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QObject::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        if (_id < 2)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 2;
    } else if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        if (_id < 2)
            *reinterpret_cast<int*>(_a[0]) = -1;
        _id -= 2;
    }
    return _id;
}

// SIGNAL 0
void ConfigCallBack::configInfo(DeviceLayer::IDevice * _t1, QStringList _t2)
{
    void *_a[] = { Q_NULLPTR, const_cast<void*>(reinterpret_cast<const void*>(&_t1)), const_cast<void*>(reinterpret_cast<const void*>(&_t2)) };
    QMetaObject::activate(this, &staticMetaObject, 0, _a);
}

// SIGNAL 1
void ConfigCallBack::setConfigInfoResult(DeviceLayer::IDevice * _t1, bool _t2)
{
    void *_a[] = { Q_NULLPTR, const_cast<void*>(reinterpret_cast<const void*>(&_t1)), const_cast<void*>(reinterpret_cast<const void*>(&_t2)) };
    QMetaObject::activate(this, &staticMetaObject, 1, _a);
}
struct qt_meta_stringdata_ConfigDialog_t {
    QByteArrayData data[11];
    char stringdata0[133];
};
#define QT_MOC_LITERAL(idx, ofs, len) \
    Q_STATIC_BYTE_ARRAY_DATA_HEADER_INITIALIZER_WITH_OFFSET(len, \
    qptrdiff(offsetof(qt_meta_stringdata_ConfigDialog_t, stringdata0) + ofs \
        - idx * sizeof(QByteArrayData)) \
    )
static const qt_meta_stringdata_ConfigDialog_t qt_meta_stringdata_ConfigDialog = {
    {
QT_MOC_LITERAL(0, 0, 12), // "ConfigDialog"
QT_MOC_LITERAL(1, 13, 15), // "setDeviceResult"
QT_MOC_LITERAL(2, 29, 0), // ""
QT_MOC_LITERAL(3, 30, 21), // "DeviceLayer::IDevice*"
QT_MOC_LITERAL(4, 52, 7), // "pDevice"
QT_MOC_LITERAL(5, 60, 5), // "error"
QT_MOC_LITERAL(6, 66, 6), // "accept"
QT_MOC_LITERAL(7, 73, 19), // "lineEditChangedSlot"
QT_MOC_LITERAL(8, 93, 14), // "showDeviceInfo"
QT_MOC_LITERAL(9, 108, 10), // "paramsList"
QT_MOC_LITERAL(10, 119, 13) // "setDeviceInfo"

    },
    "ConfigDialog\0setDeviceResult\0\0"
    "DeviceLayer::IDevice*\0pDevice\0error\0"
    "accept\0lineEditChangedSlot\0showDeviceInfo\0"
    "paramsList\0setDeviceInfo"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_ConfigDialog[] = {

 // content:
       7,       // revision
       0,       // classname
       0,    0, // classinfo
       5,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       1,       // signalCount

 // signals: name, argc, parameters, tag, flags
       1,    2,   39,    2, 0x06 /* Public */,

 // slots: name, argc, parameters, tag, flags
       6,    0,   44,    2, 0x08 /* Private */,
       7,    0,   45,    2, 0x08 /* Private */,
       8,    2,   46,    2, 0x08 /* Private */,
      10,    2,   51,    2, 0x08 /* Private */,

 // signals: parameters
    QMetaType::Void, 0x80000000 | 3, QMetaType::Bool,    4,    5,

 // slots: parameters
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void, 0x80000000 | 3, QMetaType::QStringList,    4,    9,
    QMetaType::Void, 0x80000000 | 3, QMetaType::Bool,    4,    5,

       0        // eod
};

void ConfigDialog::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        ConfigDialog *_t = static_cast<ConfigDialog *>(_o);
        Q_UNUSED(_t)
        switch (_id) {
        case 0: _t->setDeviceResult((*reinterpret_cast< DeviceLayer::IDevice*(*)>(_a[1])),(*reinterpret_cast< bool(*)>(_a[2]))); break;
        case 1: _t->accept(); break;
        case 2: _t->lineEditChangedSlot(); break;
        case 3: _t->showDeviceInfo((*reinterpret_cast< DeviceLayer::IDevice*(*)>(_a[1])),(*reinterpret_cast< QStringList(*)>(_a[2]))); break;
        case 4: _t->setDeviceInfo((*reinterpret_cast< DeviceLayer::IDevice*(*)>(_a[1])),(*reinterpret_cast< bool(*)>(_a[2]))); break;
        default: ;
        }
    } else if (_c == QMetaObject::IndexOfMethod) {
        int *result = reinterpret_cast<int *>(_a[0]);
        void **func = reinterpret_cast<void **>(_a[1]);
        {
            typedef void (ConfigDialog::*_t)(DeviceLayer::IDevice * , bool );
            if (*reinterpret_cast<_t *>(func) == static_cast<_t>(&ConfigDialog::setDeviceResult)) {
                *result = 0;
                return;
            }
        }
    }
}

const QMetaObject ConfigDialog::staticMetaObject = {
    { &QDialog::staticMetaObject, qt_meta_stringdata_ConfigDialog.data,
      qt_meta_data_ConfigDialog,  qt_static_metacall, Q_NULLPTR, Q_NULLPTR}
};


const QMetaObject *ConfigDialog::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *ConfigDialog::qt_metacast(const char *_clname)
{
    if (!_clname) return Q_NULLPTR;
    if (!strcmp(_clname, qt_meta_stringdata_ConfigDialog.stringdata0))
        return static_cast<void*>(const_cast< ConfigDialog*>(this));
    return QDialog::qt_metacast(_clname);
}

int ConfigDialog::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
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

// SIGNAL 0
void ConfigDialog::setDeviceResult(DeviceLayer::IDevice * _t1, bool _t2)
{
    void *_a[] = { Q_NULLPTR, const_cast<void*>(reinterpret_cast<const void*>(&_t1)), const_cast<void*>(reinterpret_cast<const void*>(&_t2)) };
    QMetaObject::activate(this, &staticMetaObject, 0, _a);
}
QT_END_MOC_NAMESPACE
