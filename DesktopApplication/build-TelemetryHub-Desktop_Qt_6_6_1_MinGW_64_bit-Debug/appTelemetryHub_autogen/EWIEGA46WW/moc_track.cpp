/****************************************************************************
** Meta object code from reading C++ file 'track.h'
**
** Created by: The Qt Meta Object Compiler version 68 (Qt 6.6.1)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "../../../TelemetryHub/track.h"
#include <QtCore/qmetatype.h>

#if __has_include(<QtCore/qtmochelpers.h>)
#include <QtCore/qtmochelpers.h>
#else
QT_BEGIN_MOC_NAMESPACE
#endif


#include <memory>

#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'track.h' doesn't include <QObject>."
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
struct qt_meta_stringdata_CLASSTrackENDCLASS_t {};
static constexpr auto qt_meta_stringdata_CLASSTrackENDCLASS = QtMocHelpers::stringData(
    "Track",
    "dataLoaded",
    "",
    "loadData",
    "fileUrl",
    "getTableModel"
);
#else  // !QT_MOC_HAS_STRING_DATA
struct qt_meta_stringdata_CLASSTrackENDCLASS_t {
    uint offsetsAndSizes[12];
    char stringdata0[6];
    char stringdata1[11];
    char stringdata2[1];
    char stringdata3[9];
    char stringdata4[8];
    char stringdata5[14];
};
#define QT_MOC_LITERAL(ofs, len) \
    uint(sizeof(qt_meta_stringdata_CLASSTrackENDCLASS_t::offsetsAndSizes) + ofs), len 
Q_CONSTINIT static const qt_meta_stringdata_CLASSTrackENDCLASS_t qt_meta_stringdata_CLASSTrackENDCLASS = {
    {
        QT_MOC_LITERAL(0, 5),  // "Track"
        QT_MOC_LITERAL(6, 10),  // "dataLoaded"
        QT_MOC_LITERAL(17, 0),  // ""
        QT_MOC_LITERAL(18, 8),  // "loadData"
        QT_MOC_LITERAL(27, 7),  // "fileUrl"
        QT_MOC_LITERAL(35, 13)   // "getTableModel"
    },
    "Track",
    "dataLoaded",
    "",
    "loadData",
    "fileUrl",
    "getTableModel"
};
#undef QT_MOC_LITERAL
#endif // !QT_MOC_HAS_STRING_DATA
} // unnamed namespace

Q_CONSTINIT static const uint qt_meta_data_CLASSTrackENDCLASS[] = {

 // content:
      12,       // revision
       0,       // classname
       0,    0, // classinfo
       3,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       1,       // signalCount

 // signals: name, argc, parameters, tag, flags, initial metatype offsets
       1,    0,   32,    2, 0x06,    1 /* Public */,

 // methods: name, argc, parameters, tag, flags, initial metatype offsets
       3,    1,   33,    2, 0x02,    2 /* Public */,
       5,    0,   36,    2, 0x102,    4 /* Public | MethodIsConst  */,

 // signals: parameters
    QMetaType::Void,

 // methods: parameters
    QMetaType::Void, QMetaType::QUrl,    4,
    QMetaType::QVariantList,

       0        // eod
};

Q_CONSTINIT const QMetaObject Track::staticMetaObject = { {
    QMetaObject::SuperData::link<QObject::staticMetaObject>(),
    qt_meta_stringdata_CLASSTrackENDCLASS.offsetsAndSizes,
    qt_meta_data_CLASSTrackENDCLASS,
    qt_static_metacall,
    nullptr,
    qt_incomplete_metaTypeArray<qt_meta_stringdata_CLASSTrackENDCLASS_t,
        // Q_OBJECT / Q_GADGET
        QtPrivate::TypeAndForceComplete<Track, std::true_type>,
        // method 'dataLoaded'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        // method 'loadData'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        QtPrivate::TypeAndForceComplete<const QUrl &, std::false_type>,
        // method 'getTableModel'
        QtPrivate::TypeAndForceComplete<QVariantList, std::false_type>
    >,
    nullptr
} };

void Track::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        auto *_t = static_cast<Track *>(_o);
        (void)_t;
        switch (_id) {
        case 0: _t->dataLoaded(); break;
        case 1: _t->loadData((*reinterpret_cast< std::add_pointer_t<QUrl>>(_a[1]))); break;
        case 2: { QVariantList _r = _t->getTableModel();
            if (_a[0]) *reinterpret_cast< QVariantList*>(_a[0]) = std::move(_r); }  break;
        default: ;
        }
    } else if (_c == QMetaObject::IndexOfMethod) {
        int *result = reinterpret_cast<int *>(_a[0]);
        {
            using _t = void (Track::*)();
            if (_t _q_method = &Track::dataLoaded; *reinterpret_cast<_t *>(_a[1]) == _q_method) {
                *result = 0;
                return;
            }
        }
    }
}

const QMetaObject *Track::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *Track::qt_metacast(const char *_clname)
{
    if (!_clname) return nullptr;
    if (!strcmp(_clname, qt_meta_stringdata_CLASSTrackENDCLASS.stringdata0))
        return static_cast<void*>(this);
    return QObject::qt_metacast(_clname);
}

int Track::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
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
            *reinterpret_cast<QMetaType *>(_a[0]) = QMetaType();
        _id -= 3;
    }
    return _id;
}

// SIGNAL 0
void Track::dataLoaded()
{
    QMetaObject::activate(this, &staticMetaObject, 0, nullptr);
}
QT_WARNING_POP
