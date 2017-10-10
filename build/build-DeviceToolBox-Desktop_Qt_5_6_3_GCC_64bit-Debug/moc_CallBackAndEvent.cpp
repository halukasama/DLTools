/****************************************************************************
** Meta object code from reading C++ file 'CallBackAndEvent.h'
**
** Created by: The Qt Meta Object Compiler version 67 (Qt 5.6.3)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "../../src/CallBackAndEvent.h"
#include <QtCore/qbytearray.h>
#include <QtCore/qmetatype.h>
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'CallBackAndEvent.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 67
#error "This file was generated using the moc from 5.6.3. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
struct qt_meta_stringdata_RightDoubleClicked_t {
    QByteArrayData data[1];
    char stringdata0[19];
};
#define QT_MOC_LITERAL(idx, ofs, len) \
    Q_STATIC_BYTE_ARRAY_DATA_HEADER_INITIALIZER_WITH_OFFSET(len, \
    qptrdiff(offsetof(qt_meta_stringdata_RightDoubleClicked_t, stringdata0) + ofs \
        - idx * sizeof(QByteArrayData)) \
    )
static const qt_meta_stringdata_RightDoubleClicked_t qt_meta_stringdata_RightDoubleClicked = {
    {
QT_MOC_LITERAL(0, 0, 18) // "RightDoubleClicked"

    },
    "RightDoubleClicked"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_RightDoubleClicked[] = {

 // content:
       7,       // revision
       0,       // classname
       0,    0, // classinfo
       0,    0, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       0,       // signalCount

       0        // eod
};

void RightDoubleClicked::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    Q_UNUSED(_o);
    Q_UNUSED(_id);
    Q_UNUSED(_c);
    Q_UNUSED(_a);
}

const QMetaObject RightDoubleClicked::staticMetaObject = {
    { &QObject::staticMetaObject, qt_meta_stringdata_RightDoubleClicked.data,
      qt_meta_data_RightDoubleClicked,  qt_static_metacall, Q_NULLPTR, Q_NULLPTR}
};


const QMetaObject *RightDoubleClicked::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *RightDoubleClicked::qt_metacast(const char *_clname)
{
    if (!_clname) return Q_NULLPTR;
    if (!strcmp(_clname, qt_meta_stringdata_RightDoubleClicked.stringdata0))
        return static_cast<void*>(const_cast< RightDoubleClicked*>(this));
    return QObject::qt_metacast(_clname);
}

int RightDoubleClicked::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QObject::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    return _id;
}
struct qt_meta_stringdata_DeviceConnectCallBack_t {
    QByteArrayData data[8];
    char stringdata0[149];
};
#define QT_MOC_LITERAL(idx, ofs, len) \
    Q_STATIC_BYTE_ARRAY_DATA_HEADER_INITIALIZER_WITH_OFFSET(len, \
    qptrdiff(offsetof(qt_meta_stringdata_DeviceConnectCallBack_t, stringdata0) + ofs \
        - idx * sizeof(QByteArrayData)) \
    )
static const qt_meta_stringdata_DeviceConnectCallBack_t qt_meta_stringdata_DeviceConnectCallBack = {
    {
QT_MOC_LITERAL(0, 0, 21), // "DeviceConnectCallBack"
QT_MOC_LITERAL(1, 22, 20), // "deviceConnectSuccess"
QT_MOC_LITERAL(2, 43, 0), // ""
QT_MOC_LITERAL(3, 44, 21), // "DeviceLayer::IDevice*"
QT_MOC_LITERAL(4, 66, 22), // "DeviceLayer::IContext*"
QT_MOC_LITERAL(5, 89, 19), // "deviceConnectFailed"
QT_MOC_LITERAL(6, 109, 21), // "DeviceLayer::DLResult"
QT_MOC_LITERAL(7, 131, 17) // "deviceLoseConnect"

    },
    "DeviceConnectCallBack\0deviceConnectSuccess\0"
    "\0DeviceLayer::IDevice*\0DeviceLayer::IContext*\0"
    "deviceConnectFailed\0DeviceLayer::DLResult\0"
    "deviceLoseConnect"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_DeviceConnectCallBack[] = {

 // content:
       7,       // revision
       0,       // classname
       0,    0, // classinfo
       3,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       3,       // signalCount

 // signals: name, argc, parameters, tag, flags
       1,    2,   29,    2, 0x06 /* Public */,
       5,    3,   34,    2, 0x06 /* Public */,
       7,    2,   41,    2, 0x06 /* Public */,

 // signals: parameters
    QMetaType::Void, 0x80000000 | 3, 0x80000000 | 4,    2,    2,
    QMetaType::Void, 0x80000000 | 3, 0x80000000 | 6, 0x80000000 | 4,    2,    2,    2,
    QMetaType::Void, 0x80000000 | 3, 0x80000000 | 6,    2,    2,

       0        // eod
};

void DeviceConnectCallBack::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        DeviceConnectCallBack *_t = static_cast<DeviceConnectCallBack *>(_o);
        Q_UNUSED(_t)
        switch (_id) {
        case 0: _t->deviceConnectSuccess((*reinterpret_cast< DeviceLayer::IDevice*(*)>(_a[1])),(*reinterpret_cast< DeviceLayer::IContext*(*)>(_a[2]))); break;
        case 1: _t->deviceConnectFailed((*reinterpret_cast< DeviceLayer::IDevice*(*)>(_a[1])),(*reinterpret_cast< DeviceLayer::DLResult(*)>(_a[2])),(*reinterpret_cast< DeviceLayer::IContext*(*)>(_a[3]))); break;
        case 2: _t->deviceLoseConnect((*reinterpret_cast< DeviceLayer::IDevice*(*)>(_a[1])),(*reinterpret_cast< DeviceLayer::DLResult(*)>(_a[2]))); break;
        default: ;
        }
    } else if (_c == QMetaObject::IndexOfMethod) {
        int *result = reinterpret_cast<int *>(_a[0]);
        void **func = reinterpret_cast<void **>(_a[1]);
        {
            typedef void (DeviceConnectCallBack::*_t)(DeviceLayer::IDevice * , DeviceLayer::IContext * );
            if (*reinterpret_cast<_t *>(func) == static_cast<_t>(&DeviceConnectCallBack::deviceConnectSuccess)) {
                *result = 0;
                return;
            }
        }
        {
            typedef void (DeviceConnectCallBack::*_t)(DeviceLayer::IDevice * , DeviceLayer::DLResult , DeviceLayer::IContext * );
            if (*reinterpret_cast<_t *>(func) == static_cast<_t>(&DeviceConnectCallBack::deviceConnectFailed)) {
                *result = 1;
                return;
            }
        }
        {
            typedef void (DeviceConnectCallBack::*_t)(DeviceLayer::IDevice * , DeviceLayer::DLResult );
            if (*reinterpret_cast<_t *>(func) == static_cast<_t>(&DeviceConnectCallBack::deviceLoseConnect)) {
                *result = 2;
                return;
            }
        }
    }
}

const QMetaObject DeviceConnectCallBack::staticMetaObject = {
    { &QObject::staticMetaObject, qt_meta_stringdata_DeviceConnectCallBack.data,
      qt_meta_data_DeviceConnectCallBack,  qt_static_metacall, Q_NULLPTR, Q_NULLPTR}
};


const QMetaObject *DeviceConnectCallBack::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *DeviceConnectCallBack::qt_metacast(const char *_clname)
{
    if (!_clname) return Q_NULLPTR;
    if (!strcmp(_clname, qt_meta_stringdata_DeviceConnectCallBack.stringdata0))
        return static_cast<void*>(const_cast< DeviceConnectCallBack*>(this));
    if (!strcmp(_clname, "DeviceLayer::IDeviceConnectionCallback"))
        return static_cast< DeviceLayer::IDeviceConnectionCallback*>(const_cast< DeviceConnectCallBack*>(this));
    return QObject::qt_metacast(_clname);
}

int DeviceConnectCallBack::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QObject::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        if (_id < 3)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 3;
    } else if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        if (_id < 3)
            *reinterpret_cast<int*>(_a[0]) = -1;
        _id -= 3;
    }
    return _id;
}

// SIGNAL 0
void DeviceConnectCallBack::deviceConnectSuccess(DeviceLayer::IDevice * _t1, DeviceLayer::IContext * _t2)
{
    void *_a[] = { Q_NULLPTR, const_cast<void*>(reinterpret_cast<const void*>(&_t1)), const_cast<void*>(reinterpret_cast<const void*>(&_t2)) };
    QMetaObject::activate(this, &staticMetaObject, 0, _a);
}

// SIGNAL 1
void DeviceConnectCallBack::deviceConnectFailed(DeviceLayer::IDevice * _t1, DeviceLayer::DLResult _t2, DeviceLayer::IContext * _t3)
{
    void *_a[] = { Q_NULLPTR, const_cast<void*>(reinterpret_cast<const void*>(&_t1)), const_cast<void*>(reinterpret_cast<const void*>(&_t2)), const_cast<void*>(reinterpret_cast<const void*>(&_t3)) };
    QMetaObject::activate(this, &staticMetaObject, 1, _a);
}

// SIGNAL 2
void DeviceConnectCallBack::deviceLoseConnect(DeviceLayer::IDevice * _t1, DeviceLayer::DLResult _t2)
{
    void *_a[] = { Q_NULLPTR, const_cast<void*>(reinterpret_cast<const void*>(&_t1)), const_cast<void*>(reinterpret_cast<const void*>(&_t2)) };
    QMetaObject::activate(this, &staticMetaObject, 2, _a);
}
struct qt_meta_stringdata_UpgradeDeviceCallback_t {
    QByteArrayData data[15];
    char stringdata0[184];
};
#define QT_MOC_LITERAL(idx, ofs, len) \
    Q_STATIC_BYTE_ARRAY_DATA_HEADER_INITIALIZER_WITH_OFFSET(len, \
    qptrdiff(offsetof(qt_meta_stringdata_UpgradeDeviceCallback_t, stringdata0) + ofs \
        - idx * sizeof(QByteArrayData)) \
    )
static const qt_meta_stringdata_UpgradeDeviceCallback_t qt_meta_stringdata_UpgradeDeviceCallback = {
    {
QT_MOC_LITERAL(0, 0, 21), // "UpgradeDeviceCallback"
QT_MOC_LITERAL(1, 22, 7), // "started"
QT_MOC_LITERAL(2, 30, 0), // ""
QT_MOC_LITERAL(3, 31, 21), // "DeviceLayer::IDevice*"
QT_MOC_LITERAL(4, 53, 6), // "device"
QT_MOC_LITERAL(5, 60, 22), // "DeviceLayer::IContext*"
QT_MOC_LITERAL(6, 83, 8), // "pContext"
QT_MOC_LITERAL(7, 92, 11), // "startFailed"
QT_MOC_LITERAL(8, 104, 21), // "DeviceLayer::DLResult"
QT_MOC_LITERAL(9, 126, 6), // "result"
QT_MOC_LITERAL(10, 133, 16), // "notifyProcessing"
QT_MOC_LITERAL(11, 150, 11), // "const char*"
QT_MOC_LITERAL(12, 162, 4), // "desc"
QT_MOC_LITERAL(13, 167, 6), // "faults"
QT_MOC_LITERAL(14, 174, 9) // "completed"

    },
    "UpgradeDeviceCallback\0started\0\0"
    "DeviceLayer::IDevice*\0device\0"
    "DeviceLayer::IContext*\0pContext\0"
    "startFailed\0DeviceLayer::DLResult\0"
    "result\0notifyProcessing\0const char*\0"
    "desc\0faults\0completed"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_UpgradeDeviceCallback[] = {

 // content:
       7,       // revision
       0,       // classname
       0,    0, // classinfo
       5,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       5,       // signalCount

 // signals: name, argc, parameters, tag, flags
       1,    2,   39,    2, 0x06 /* Public */,
       7,    3,   44,    2, 0x06 /* Public */,
      10,    3,   51,    2, 0x06 /* Public */,
      13,    2,   58,    2, 0x06 /* Public */,
      14,    2,   63,    2, 0x06 /* Public */,

 // signals: parameters
    QMetaType::Void, 0x80000000 | 3, 0x80000000 | 5,    4,    6,
    QMetaType::Void, 0x80000000 | 3, 0x80000000 | 8, 0x80000000 | 5,    4,    9,    6,
    QMetaType::Void, 0x80000000 | 3, 0x80000000 | 11, 0x80000000 | 5,    4,   12,    6,
    QMetaType::Void, 0x80000000 | 3, 0x80000000 | 5,    4,    6,
    QMetaType::Void, 0x80000000 | 3, 0x80000000 | 5,    4,    6,

       0        // eod
};

void UpgradeDeviceCallback::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        UpgradeDeviceCallback *_t = static_cast<UpgradeDeviceCallback *>(_o);
        Q_UNUSED(_t)
        switch (_id) {
        case 0: _t->started((*reinterpret_cast< DeviceLayer::IDevice*(*)>(_a[1])),(*reinterpret_cast< DeviceLayer::IContext*(*)>(_a[2]))); break;
        case 1: _t->startFailed((*reinterpret_cast< DeviceLayer::IDevice*(*)>(_a[1])),(*reinterpret_cast< DeviceLayer::DLResult(*)>(_a[2])),(*reinterpret_cast< DeviceLayer::IContext*(*)>(_a[3]))); break;
        case 2: _t->notifyProcessing((*reinterpret_cast< DeviceLayer::IDevice*(*)>(_a[1])),(*reinterpret_cast< const char*(*)>(_a[2])),(*reinterpret_cast< DeviceLayer::IContext*(*)>(_a[3]))); break;
        case 3: _t->faults((*reinterpret_cast< DeviceLayer::IDevice*(*)>(_a[1])),(*reinterpret_cast< DeviceLayer::IContext*(*)>(_a[2]))); break;
        case 4: _t->completed((*reinterpret_cast< DeviceLayer::IDevice*(*)>(_a[1])),(*reinterpret_cast< DeviceLayer::IContext*(*)>(_a[2]))); break;
        default: ;
        }
    } else if (_c == QMetaObject::IndexOfMethod) {
        int *result = reinterpret_cast<int *>(_a[0]);
        void **func = reinterpret_cast<void **>(_a[1]);
        {
            typedef void (UpgradeDeviceCallback::*_t)(DeviceLayer::IDevice * , DeviceLayer::IContext * );
            if (*reinterpret_cast<_t *>(func) == static_cast<_t>(&UpgradeDeviceCallback::started)) {
                *result = 0;
                return;
            }
        }
        {
            typedef void (UpgradeDeviceCallback::*_t)(DeviceLayer::IDevice * , DeviceLayer::DLResult , DeviceLayer::IContext * );
            if (*reinterpret_cast<_t *>(func) == static_cast<_t>(&UpgradeDeviceCallback::startFailed)) {
                *result = 1;
                return;
            }
        }
        {
            typedef void (UpgradeDeviceCallback::*_t)(DeviceLayer::IDevice * , const char * , DeviceLayer::IContext * );
            if (*reinterpret_cast<_t *>(func) == static_cast<_t>(&UpgradeDeviceCallback::notifyProcessing)) {
                *result = 2;
                return;
            }
        }
        {
            typedef void (UpgradeDeviceCallback::*_t)(DeviceLayer::IDevice * , DeviceLayer::IContext * );
            if (*reinterpret_cast<_t *>(func) == static_cast<_t>(&UpgradeDeviceCallback::faults)) {
                *result = 3;
                return;
            }
        }
        {
            typedef void (UpgradeDeviceCallback::*_t)(DeviceLayer::IDevice * , DeviceLayer::IContext * );
            if (*reinterpret_cast<_t *>(func) == static_cast<_t>(&UpgradeDeviceCallback::completed)) {
                *result = 4;
                return;
            }
        }
    }
}

const QMetaObject UpgradeDeviceCallback::staticMetaObject = {
    { &QObject::staticMetaObject, qt_meta_stringdata_UpgradeDeviceCallback.data,
      qt_meta_data_UpgradeDeviceCallback,  qt_static_metacall, Q_NULLPTR, Q_NULLPTR}
};


const QMetaObject *UpgradeDeviceCallback::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *UpgradeDeviceCallback::qt_metacast(const char *_clname)
{
    if (!_clname) return Q_NULLPTR;
    if (!strcmp(_clname, qt_meta_stringdata_UpgradeDeviceCallback.stringdata0))
        return static_cast<void*>(const_cast< UpgradeDeviceCallback*>(this));
    if (!strcmp(_clname, "DeviceLayer::IUpgradeCallback"))
        return static_cast< DeviceLayer::IUpgradeCallback*>(const_cast< UpgradeDeviceCallback*>(this));
    return QObject::qt_metacast(_clname);
}

int UpgradeDeviceCallback::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QObject::qt_metacall(_c, _id, _a);
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
void UpgradeDeviceCallback::started(DeviceLayer::IDevice * _t1, DeviceLayer::IContext * _t2)
{
    void *_a[] = { Q_NULLPTR, const_cast<void*>(reinterpret_cast<const void*>(&_t1)), const_cast<void*>(reinterpret_cast<const void*>(&_t2)) };
    QMetaObject::activate(this, &staticMetaObject, 0, _a);
}

// SIGNAL 1
void UpgradeDeviceCallback::startFailed(DeviceLayer::IDevice * _t1, DeviceLayer::DLResult _t2, DeviceLayer::IContext * _t3)
{
    void *_a[] = { Q_NULLPTR, const_cast<void*>(reinterpret_cast<const void*>(&_t1)), const_cast<void*>(reinterpret_cast<const void*>(&_t2)), const_cast<void*>(reinterpret_cast<const void*>(&_t3)) };
    QMetaObject::activate(this, &staticMetaObject, 1, _a);
}

// SIGNAL 2
void UpgradeDeviceCallback::notifyProcessing(DeviceLayer::IDevice * _t1, const char * _t2, DeviceLayer::IContext * _t3)
{
    void *_a[] = { Q_NULLPTR, const_cast<void*>(reinterpret_cast<const void*>(&_t1)), const_cast<void*>(reinterpret_cast<const void*>(&_t2)), const_cast<void*>(reinterpret_cast<const void*>(&_t3)) };
    QMetaObject::activate(this, &staticMetaObject, 2, _a);
}

// SIGNAL 3
void UpgradeDeviceCallback::faults(DeviceLayer::IDevice * _t1, DeviceLayer::IContext * _t2)
{
    void *_a[] = { Q_NULLPTR, const_cast<void*>(reinterpret_cast<const void*>(&_t1)), const_cast<void*>(reinterpret_cast<const void*>(&_t2)) };
    QMetaObject::activate(this, &staticMetaObject, 3, _a);
}

// SIGNAL 4
void UpgradeDeviceCallback::completed(DeviceLayer::IDevice * _t1, DeviceLayer::IContext * _t2)
{
    void *_a[] = { Q_NULLPTR, const_cast<void*>(reinterpret_cast<const void*>(&_t1)), const_cast<void*>(reinterpret_cast<const void*>(&_t2)) };
    QMetaObject::activate(this, &staticMetaObject, 4, _a);
}
QT_END_MOC_NAMESPACE
