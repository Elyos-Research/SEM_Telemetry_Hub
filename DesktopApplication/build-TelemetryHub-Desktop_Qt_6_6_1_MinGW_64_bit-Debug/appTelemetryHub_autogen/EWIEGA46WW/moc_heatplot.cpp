/****************************************************************************
** Meta object code from reading C++ file 'heatplot.h'
**
** Created by: The Qt Meta Object Compiler version 68 (Qt 6.6.1)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "../../../TelemetryHub/heatplot.h"
#include <QtCore/qmetatype.h>

#if __has_include(<QtCore/qtmochelpers.h>)
#include <QtCore/qtmochelpers.h>
#else
QT_BEGIN_MOC_NAMESPACE
#endif


#include <memory>

#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'heatplot.h' doesn't include <QObject>."
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
struct qt_meta_stringdata_CLASSHeatPlotENDCLASS_t {};
static constexpr auto qt_meta_stringdata_CLASSHeatPlotENDCLASS = QtMocHelpers::stringData(
    "HeatPlot",
    "pointSizeChanged",
    "",
    "scalingFactorChanged",
    "paddingChanged",
    "setHeatData",
    "data",
    "updatePlot",
    "pointSize",
    "scalingFactor",
    "padding"
);
#else  // !QT_MOC_HAS_STRING_DATA
struct qt_meta_stringdata_CLASSHeatPlotENDCLASS_t {
    uint offsetsAndSizes[22];
    char stringdata0[9];
    char stringdata1[17];
    char stringdata2[1];
    char stringdata3[21];
    char stringdata4[15];
    char stringdata5[12];
    char stringdata6[5];
    char stringdata7[11];
    char stringdata8[10];
    char stringdata9[14];
    char stringdata10[8];
};
#define QT_MOC_LITERAL(ofs, len) \
    uint(sizeof(qt_meta_stringdata_CLASSHeatPlotENDCLASS_t::offsetsAndSizes) + ofs), len 
Q_CONSTINIT static const qt_meta_stringdata_CLASSHeatPlotENDCLASS_t qt_meta_stringdata_CLASSHeatPlotENDCLASS = {
    {
        QT_MOC_LITERAL(0, 8),  // "HeatPlot"
        QT_MOC_LITERAL(9, 16),  // "pointSizeChanged"
        QT_MOC_LITERAL(26, 0),  // ""
        QT_MOC_LITERAL(27, 20),  // "scalingFactorChanged"
        QT_MOC_LITERAL(48, 14),  // "paddingChanged"
        QT_MOC_LITERAL(63, 11),  // "setHeatData"
        QT_MOC_LITERAL(75, 4),  // "data"
        QT_MOC_LITERAL(80, 10),  // "updatePlot"
        QT_MOC_LITERAL(91, 9),  // "pointSize"
        QT_MOC_LITERAL(101, 13),  // "scalingFactor"
        QT_MOC_LITERAL(115, 7)   // "padding"
    },
    "HeatPlot",
    "pointSizeChanged",
    "",
    "scalingFactorChanged",
    "paddingChanged",
    "setHeatData",
    "data",
    "updatePlot",
    "pointSize",
    "scalingFactor",
    "padding"
};
#undef QT_MOC_LITERAL
#endif // !QT_MOC_HAS_STRING_DATA
} // unnamed namespace

Q_CONSTINIT static const uint qt_meta_data_CLASSHeatPlotENDCLASS[] = {

 // content:
      12,       // revision
       0,       // classname
       0,    0, // classinfo
       5,   14, // methods
       3,   51, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       3,       // signalCount

 // signals: name, argc, parameters, tag, flags, initial metatype offsets
       1,    0,   44,    2, 0x06,    4 /* Public */,
       3,    0,   45,    2, 0x06,    5 /* Public */,
       4,    0,   46,    2, 0x06,    6 /* Public */,

 // methods: name, argc, parameters, tag, flags, initial metatype offsets
       5,    1,   47,    2, 0x02,    7 /* Public */,
       7,    0,   50,    2, 0x02,    9 /* Public */,

 // signals: parameters
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,

 // methods: parameters
    QMetaType::Void, QMetaType::QVariantList,    6,
    QMetaType::Void,

 // properties: name, type, flags
       8, QMetaType::Double, 0x00015103, uint(0), 0,
       9, QMetaType::Double, 0x00015103, uint(1), 0,
      10, QMetaType::Double, 0x00015103, uint(2), 0,

       0        // eod
};

Q_CONSTINIT const QMetaObject HeatPlot::staticMetaObject = { {
    QMetaObject::SuperData::link<QQuickPaintedItem::staticMetaObject>(),
    qt_meta_stringdata_CLASSHeatPlotENDCLASS.offsetsAndSizes,
    qt_meta_data_CLASSHeatPlotENDCLASS,
    qt_static_metacall,
    nullptr,
    qt_incomplete_metaTypeArray<qt_meta_stringdata_CLASSHeatPlotENDCLASS_t,
        // property 'pointSize'
        QtPrivate::TypeAndForceComplete<double, std::true_type>,
        // property 'scalingFactor'
        QtPrivate::TypeAndForceComplete<double, std::true_type>,
        // property 'padding'
        QtPrivate::TypeAndForceComplete<double, std::true_type>,
        // Q_OBJECT / Q_GADGET
        QtPrivate::TypeAndForceComplete<HeatPlot, std::true_type>,
        // method 'pointSizeChanged'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        // method 'scalingFactorChanged'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        // method 'paddingChanged'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        // method 'setHeatData'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        QtPrivate::TypeAndForceComplete<const QVariantList &, std::false_type>,
        // method 'updatePlot'
        QtPrivate::TypeAndForceComplete<void, std::false_type>
    >,
    nullptr
} };

void HeatPlot::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        auto *_t = static_cast<HeatPlot *>(_o);
        (void)_t;
        switch (_id) {
        case 0: _t->pointSizeChanged(); break;
        case 1: _t->scalingFactorChanged(); break;
        case 2: _t->paddingChanged(); break;
        case 3: _t->setHeatData((*reinterpret_cast< std::add_pointer_t<QVariantList>>(_a[1]))); break;
        case 4: _t->updatePlot(); break;
        default: ;
        }
    } else if (_c == QMetaObject::IndexOfMethod) {
        int *result = reinterpret_cast<int *>(_a[0]);
        {
            using _t = void (HeatPlot::*)();
            if (_t _q_method = &HeatPlot::pointSizeChanged; *reinterpret_cast<_t *>(_a[1]) == _q_method) {
                *result = 0;
                return;
            }
        }
        {
            using _t = void (HeatPlot::*)();
            if (_t _q_method = &HeatPlot::scalingFactorChanged; *reinterpret_cast<_t *>(_a[1]) == _q_method) {
                *result = 1;
                return;
            }
        }
        {
            using _t = void (HeatPlot::*)();
            if (_t _q_method = &HeatPlot::paddingChanged; *reinterpret_cast<_t *>(_a[1]) == _q_method) {
                *result = 2;
                return;
            }
        }
    } else if (_c == QMetaObject::ReadProperty) {
        auto *_t = static_cast<HeatPlot *>(_o);
        (void)_t;
        void *_v = _a[0];
        switch (_id) {
        case 0: *reinterpret_cast< double*>(_v) = _t->pointSize(); break;
        case 1: *reinterpret_cast< double*>(_v) = _t->scalingFactor(); break;
        case 2: *reinterpret_cast< double*>(_v) = _t->padding(); break;
        default: break;
        }
    } else if (_c == QMetaObject::WriteProperty) {
        auto *_t = static_cast<HeatPlot *>(_o);
        (void)_t;
        void *_v = _a[0];
        switch (_id) {
        case 0: _t->setPointSize(*reinterpret_cast< double*>(_v)); break;
        case 1: _t->setScalingFactor(*reinterpret_cast< double*>(_v)); break;
        case 2: _t->setPadding(*reinterpret_cast< double*>(_v)); break;
        default: break;
        }
    } else if (_c == QMetaObject::ResetProperty) {
    } else if (_c == QMetaObject::BindableProperty) {
    }
}

const QMetaObject *HeatPlot::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *HeatPlot::qt_metacast(const char *_clname)
{
    if (!_clname) return nullptr;
    if (!strcmp(_clname, qt_meta_stringdata_CLASSHeatPlotENDCLASS.stringdata0))
        return static_cast<void*>(this);
    return QQuickPaintedItem::qt_metacast(_clname);
}

int HeatPlot::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QQuickPaintedItem::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        if (_id < 5)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 5;
    } else if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        if (_id < 5)
            *reinterpret_cast<QMetaType *>(_a[0]) = QMetaType();
        _id -= 5;
    }else if (_c == QMetaObject::ReadProperty || _c == QMetaObject::WriteProperty
            || _c == QMetaObject::ResetProperty || _c == QMetaObject::BindableProperty
            || _c == QMetaObject::RegisterPropertyMetaType) {
        qt_static_metacall(this, _c, _id, _a);
        _id -= 3;
    }
    return _id;
}

// SIGNAL 0
void HeatPlot::pointSizeChanged()
{
    QMetaObject::activate(this, &staticMetaObject, 0, nullptr);
}

// SIGNAL 1
void HeatPlot::scalingFactorChanged()
{
    QMetaObject::activate(this, &staticMetaObject, 1, nullptr);
}

// SIGNAL 2
void HeatPlot::paddingChanged()
{
    QMetaObject::activate(this, &staticMetaObject, 2, nullptr);
}
QT_WARNING_POP
