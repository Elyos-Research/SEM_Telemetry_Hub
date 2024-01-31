/****************************************************************************
** Meta object code from reading C++ file 'serialhandle.h'
**
** Created by: The Qt Meta Object Compiler version 68 (Qt 6.6.1)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "../../../TelemetryHub/serialhandle.h"
#include <QtCore/qmetatype.h>

#if __has_include(<QtCore/qtmochelpers.h>)
#include <QtCore/qtmochelpers.h>
#else
QT_BEGIN_MOC_NAMESPACE
#endif


#include <memory>

#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'serialhandle.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 68
#error "This file was generated using the moc from 6.6.1. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

#ifndef Q_CONSTINIT
#define Q_CONSTINIT
#endif

QT_WARNING_PUSH
QT_WARNING_DISABLE_DEPRECATED
QT_WARNING_DISABLE_GCC("-Wuseless-cast")
namespace {

#ifdef QT_MOC_HAS_STRINGDATA
struct qt_meta_stringdata_CLASSSerialHandleENDCLASS_t {};
static constexpr auto qt_meta_stringdata_CLASSSerialHandleENDCLASS = QtMocHelpers::stringData(
    "SerialHandle",
    "dataReceived",
    "",
    "data",
    "errorOccurred",
    "errorString",
    "serialPortClosed",
    "openSerialPort",
    "portName",
    "Mode",
    "mode",
    "QSerialPort::BaudRate",
    "baudRate",
    "closeSerialPort",
    "availablePorts",
    "readLine",
    "writeData",
    "setBaudRate",
    "setComPort",
    "port"
);
#else  // !QT_MOC_HAS_STRING_DATA
struct qt_meta_stringdata_CLASSSerialHandleENDCLASS_t {
    uint offsetsAndSizes[40];
    char stringdata0[13];
    char stringdata1[13];
    char stringdata2[1];
    char stringdata3[5];
    char stringdata4[14];
    char stringdata5[12];
    char stringdata6[17];
    char stringdata7[15];
    char stringdata8[9];
    char stringdata9[5];
    char stringdata10[5];
    char stringdata11[22];
    char stringdata12[9];
    char stringdata13[16];
    char stringdata14[15];
    char stringdata15[9];
    char stringdata16[10];
    char stringdata17[12];
    char stringdata18[11];
    char stringdata19[5];
};
#define QT_MOC_LITERAL(ofs, len) \
    uint(sizeof(qt_meta_stringdata_CLASSSerialHandleENDCLASS_t::offsetsAndSizes) + ofs), len 
Q_CONSTINIT static const qt_meta_stringdata_CLASSSerialHandleENDCLASS_t qt_meta_stringdata_CLASSSerialHandleENDCLASS = {
    {
        QT_MOC_LITERAL(0, 12),  // "SerialHandle"
        QT_MOC_LITERAL(13, 12),  // "dataReceived"
        QT_MOC_LITERAL(26, 0),  // ""
        QT_MOC_LITERAL(27, 4),  // "data"
        QT_MOC_LITERAL(32, 13),  // "errorOccurred"
        QT_MOC_LITERAL(46, 11),  // "errorString"
        QT_MOC_LITERAL(58, 16),  // "serialPortClosed"
        QT_MOC_LITERAL(75, 14),  // "openSerialPort"
        QT_MOC_LITERAL(90, 8),  // "portName"
        QT_MOC_LITERAL(99, 4),  // "Mode"
        QT_MOC_LITERAL(104, 4),  // "mode"
        QT_MOC_LITERAL(109, 21),  // "QSerialPort::BaudRate"
        QT_MOC_LITERAL(131, 8),  // "baudRate"
        QT_MOC_LITERAL(140, 15),  // "closeSerialPort"
        QT_MOC_LITERAL(156, 14),  // "availablePorts"
        QT_MOC_LITERAL(171, 8),  // "readLine"
        QT_MOC_LITERAL(180, 9),  // "writeData"
        QT_MOC_LITERAL(190, 11),  // "setBaudRate"
        QT_MOC_LITERAL(202, 10),  // "setComPort"
        QT_MOC_LITERAL(213, 4)   // "port"
    },
    "SerialHandle",
    "dataReceived",
    "",
    "data",
    "errorOccurred",
    "errorString",
    "serialPortClosed",
    "openSerialPort",
    "portName",
    "Mode",
    "mode",
    "QSerialPort::BaudRate",
    "baudRate",
    "closeSerialPort",
    "availablePorts",
    "readLine",
    "writeData",
    "setBaudRate",
    "setComPort",
    "port"
};
#undef QT_MOC_LITERAL
#endif // !QT_MOC_HAS_STRING_DATA
} // unnamed namespace

Q_CONSTINIT static const uint qt_meta_data_CLASSSerialHandleENDCLASS[] = {

 // content:
      12,       // revision
       0,       // classname
       0,    0, // classinfo
      10,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       3,       // signalCount

 // signals: name, argc, parameters, tag, flags, initial metatype offsets
       1,    1,   74,    2, 0x06,    1 /* Public */,
       4,    1,   77,    2, 0x06,    3 /* Public */,
       6,    0,   80,    2, 0x06,    5 /* Public */,

 // methods: name, argc, parameters, tag, flags, initial metatype offsets
       7,    3,   81,    2, 0x02,    6 /* Public */,
      13,    0,   88,    2, 0x02,   10 /* Public */,
      14,    0,   89,    2, 0x102,   11 /* Public | MethodIsConst  */,
      15,    0,   90,    2, 0x02,   12 /* Public */,
      16,    1,   91,    2, 0x02,   13 /* Public */,
      17,    1,   94,    2, 0x02,   15 /* Public */,
      18,    1,   97,    2, 0x02,   17 /* Public */,

 // signals: parameters
    QMetaType::Void, QMetaType::QString,    3,
    QMetaType::Void, QMetaType::QString,    5,
    QMetaType::Void,

 // methods: parameters
    QMetaType::Bool, QMetaType::QString, 0x80000000 | 9, 0x80000000 | 11,    8,   10,   12,
    QMetaType::Void,
    QMetaType::QStringList,
    QMetaType::QString,
    QMetaType::Bool, QMetaType::QByteArray,    3,
    QMetaType::Void, QMetaType::QString,   12,
    QMetaType::Void, QMetaType::QString,   19,

       0        // eod
};

Q_CONSTINIT const QMetaObject SerialHandle::staticMetaObject = { {
    QMetaObject::SuperData::link<QObject::staticMetaObject>(),
    qt_meta_stringdata_CLASSSerialHandleENDCLASS.offsetsAndSizes,
    qt_meta_data_CLASSSerialHandleENDCLASS,
    qt_static_metacall,
    nullptr,
    qt_incomplete_metaTypeArray<qt_meta_stringdata_CLASSSerialHandleENDCLASS_t,
        // Q_OBJECT / Q_GADGET
        QtPrivate::TypeAndForceComplete<SerialHandle, std::true_type>,
        // method 'dataReceived'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        QtPrivate::TypeAndForceComplete<const QString &, std::false_type>,
        // method 'errorOccurred'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        QtPrivate::TypeAndForceComplete<const QString &, std::false_type>,
        // method 'serialPortClosed'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        // method 'openSerialPort'
        QtPrivate::TypeAndForceComplete<bool, std::false_type>,
        QtPrivate::TypeAndForceComplete<const QString &, std::false_type>,
        QtPrivate::TypeAndForceComplete<Mode, std::false_type>,
        QtPrivate::TypeAndForceComplete<QSerialPort::BaudRate, std::false_type>,
        // method 'closeSerialPort'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        // method 'availablePorts'
        QtPrivate::TypeAndForceComplete<QStringList, std::false_type>,
        // method 'readLine'
        QtPrivate::TypeAndForceComplete<QString, std::false_type>,
        // method 'writeData'
        QtPrivate::TypeAndForceComplete<bool, std::false_type>,
        QtPrivate::TypeAndForceComplete<const QByteArray &, std::false_type>,
        // method 'setBaudRate'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        QtPrivate::TypeAndForceComplete<QString, std::false_type>,
        // method 'setComPort'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        QtPrivate::TypeAndForceComplete<QString, std::false_type>
    >,
    nullptr
} };

void SerialHandle::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        auto *_t = static_cast<SerialHandle *>(_o);
        (void)_t;
        switch (_id) {
        case 0: _t->dataReceived((*reinterpret_cast< std::add_pointer_t<QString>>(_a[1]))); break;
        case 1: _t->errorOccurred((*reinterpret_cast< std::add_pointer_t<QString>>(_a[1]))); break;
        case 2: _t->serialPortClosed(); break;
        case 3: { bool _r = _t->openSerialPort((*reinterpret_cast< std::add_pointer_t<QString>>(_a[1])),(*reinterpret_cast< std::add_pointer_t<Mode>>(_a[2])),(*reinterpret_cast< std::add_pointer_t<QSerialPort::BaudRate>>(_a[3])));
            if (_a[0]) *reinterpret_cast< bool*>(_a[0]) = std::move(_r); }  break;
        case 4: _t->closeSerialPort(); break;
        case 5: { QStringList _r = _t->availablePorts();
            if (_a[0]) *reinterpret_cast< QStringList*>(_a[0]) = std::move(_r); }  break;
        case 6: { QString _r = _t->readLine();
            if (_a[0]) *reinterpret_cast< QString*>(_a[0]) = std::move(_r); }  break;
        case 7: { bool _r = _t->writeData((*reinterpret_cast< std::add_pointer_t<QByteArray>>(_a[1])));
            if (_a[0]) *reinterpret_cast< bool*>(_a[0]) = std::move(_r); }  break;
        case 8: _t->setBaudRate((*reinterpret_cast< std::add_pointer_t<QString>>(_a[1]))); break;
        case 9: _t->setComPort((*reinterpret_cast< std::add_pointer_t<QString>>(_a[1]))); break;
        default: ;
        }
    } else if (_c == QMetaObject::IndexOfMethod) {
        int *result = reinterpret_cast<int *>(_a[0]);
        {
            using _t = void (SerialHandle::*)(const QString & );
            if (_t _q_method = &SerialHandle::dataReceived; *reinterpret_cast<_t *>(_a[1]) == _q_method) {
                *result = 0;
                return;
            }
        }
        {
            using _t = void (SerialHandle::*)(const QString & );
            if (_t _q_method = &SerialHandle::errorOccurred; *reinterpret_cast<_t *>(_a[1]) == _q_method) {
                *result = 1;
                return;
            }
        }
        {
            using _t = void (SerialHandle::*)();
            if (_t _q_method = &SerialHandle::serialPortClosed; *reinterpret_cast<_t *>(_a[1]) == _q_method) {
                *result = 2;
                return;
            }
        }
    }
}

const QMetaObject *SerialHandle::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *SerialHandle::qt_metacast(const char *_clname)
{
    if (!_clname) return nullptr;
    if (!strcmp(_clname, qt_meta_stringdata_CLASSSerialHandleENDCLASS.stringdata0))
        return static_cast<void*>(this);
    return QObject::qt_metacast(_clname);
}

int SerialHandle::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QObject::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        if (_id < 10)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 10;
    } else if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        if (_id < 10)
            *reinterpret_cast<QMetaType *>(_a[0]) = QMetaType();
        _id -= 10;
    }
    return _id;
}

// SIGNAL 0
void SerialHandle::dataReceived(const QString & _t1)
{
    void *_a[] = { nullptr, const_cast<void*>(reinterpret_cast<const void*>(std::addressof(_t1))) };
    QMetaObject::activate(this, &staticMetaObject, 0, _a);
}

// SIGNAL 1
void SerialHandle::errorOccurred(const QString & _t1)
{
    void *_a[] = { nullptr, const_cast<void*>(reinterpret_cast<const void*>(std::addressof(_t1))) };
    QMetaObject::activate(this, &staticMetaObject, 1, _a);
}

// SIGNAL 2
void SerialHandle::serialPortClosed()
{
    QMetaObject::activate(this, &staticMetaObject, 2, nullptr);
}
QT_WARNING_POP
