/****************************************************************************
** Meta object code from reading C++ file 'personnel.h'
**
** Created by: The Qt Meta Object Compiler version 68 (Qt 6.7.3)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "../../../personnel.h"
#include <QtGui/qtextcursor.h>
#include <QtCore/qmetatype.h>
#include <QtCore/QList>

#include <QtCore/qtmochelpers.h>

#include <memory>


#include <QtCore/qxptype_traits.h>
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'personnel.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 68
#error "This file was generated using the moc from 6.7.3. It"
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
struct qt_meta_stringdata_CLASSpersonnelENDCLASS_t {};
constexpr auto qt_meta_stringdata_CLASSpersonnelENDCLASS = QtMocHelpers::stringData(
    "personnel",
    "switchToAppointement",
    "",
    "switchToMicro",
    "switchToEvents",
    "switchToProd",
    "switchToPat",
    "on_pushButton_add_clicked",
    "on_pushButton_update_clicked",
    "on_pushButton_delete_clicked",
    "on_pushButton_clear_clicked",
    "testDatabaseConnection",
    "on_tab_Personnel_cellClicked",
    "row",
    "column",
    "on_filterButton_clicked",
    "on_exportPdfButton_clicked",
    "on_searchPersonnel_returnPressed",
    "on_statisticsButton_clicked",
    "on_cameraButton_clicked",
    "drawPieChart",
    "QPainter&",
    "painter",
    "x",
    "y",
    "width",
    "QList<std::pair<QString,int>>",
    "data",
    "QList<QColor>",
    "colors",
    "title",
    "drawPieChartWidget",
    "rect",
    "startCamera",
    "cameraId",
    "stopCamera",
    "captureImage",
    "handleCameraError",
    "QCamera::Error",
    "error",
    "errorString",
    "detectFaceInViewfinder",
    "on_microvacButton_clicked",
    "on_eventButton_clicked",
    "on_inventoryButton_clicked",
    "on_patientButton_clicked"
);
#else  // !QT_MOC_HAS_STRINGDATA
#error "qtmochelpers.h not found or too old."
#endif // !QT_MOC_HAS_STRINGDATA
} // unnamed namespace

Q_CONSTINIT static const uint qt_meta_data_CLASSpersonnelENDCLASS[] = {

 // content:
      12,       // revision
       0,       // classname
       0,    0, // classinfo
      28,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       5,       // signalCount

 // signals: name, argc, parameters, tag, flags, initial metatype offsets
       1,    0,  182,    2, 0x06,    1 /* Public */,
       3,    0,  183,    2, 0x06,    2 /* Public */,
       4,    0,  184,    2, 0x06,    3 /* Public */,
       5,    0,  185,    2, 0x06,    4 /* Public */,
       6,    0,  186,    2, 0x06,    5 /* Public */,

 // slots: name, argc, parameters, tag, flags, initial metatype offsets
       7,    0,  187,    2, 0x08,    6 /* Private */,
       8,    0,  188,    2, 0x08,    7 /* Private */,
       9,    0,  189,    2, 0x08,    8 /* Private */,
      10,    0,  190,    2, 0x08,    9 /* Private */,
      11,    0,  191,    2, 0x08,   10 /* Private */,
      12,    2,  192,    2, 0x08,   11 /* Private */,
      15,    0,  197,    2, 0x08,   14 /* Private */,
      16,    0,  198,    2, 0x08,   15 /* Private */,
      17,    0,  199,    2, 0x08,   16 /* Private */,
      18,    0,  200,    2, 0x08,   17 /* Private */,
      19,    0,  201,    2, 0x08,   18 /* Private */,
      20,    7,  202,    2, 0x08,   19 /* Private */,
      31,    4,  217,    2, 0x08,   27 /* Private */,
      33,    1,  226,    2, 0x08,   32 /* Private */,
      33,    0,  229,    2, 0x28,   34 /* Private | MethodCloned */,
      35,    0,  230,    2, 0x08,   35 /* Private */,
      36,    0,  231,    2, 0x08,   36 /* Private */,
      37,    2,  232,    2, 0x08,   37 /* Private */,
      41,    0,  237,    2, 0x08,   40 /* Private */,
      42,    0,  238,    2, 0x08,   41 /* Private */,
      43,    0,  239,    2, 0x08,   42 /* Private */,
      44,    0,  240,    2, 0x08,   43 /* Private */,
      45,    0,  241,    2, 0x08,   44 /* Private */,

 // signals: parameters
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,

 // slots: parameters
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void, QMetaType::Int, QMetaType::Int,   13,   14,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Int, 0x80000000 | 21, QMetaType::Int, QMetaType::Int, QMetaType::Int, 0x80000000 | 26, 0x80000000 | 28, QMetaType::QString,   22,   23,   24,   25,   27,   29,   30,
    QMetaType::Void, 0x80000000 | 21, QMetaType::QRect, 0x80000000 | 26, 0x80000000 | 28,   22,   32,   27,   29,
    QMetaType::Void, QMetaType::QByteArray,   34,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void, 0x80000000 | 38, QMetaType::QString,   39,   40,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,

       0        // eod
};

Q_CONSTINIT const QMetaObject personnel::staticMetaObject = { {
    QMetaObject::SuperData::link<QMainWindow::staticMetaObject>(),
    qt_meta_stringdata_CLASSpersonnelENDCLASS.offsetsAndSizes,
    qt_meta_data_CLASSpersonnelENDCLASS,
    qt_static_metacall,
    nullptr,
    qt_incomplete_metaTypeArray<qt_meta_stringdata_CLASSpersonnelENDCLASS_t,
        // Q_OBJECT / Q_GADGET
        QtPrivate::TypeAndForceComplete<personnel, std::true_type>,
        // method 'switchToAppointement'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        // method 'switchToMicro'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        // method 'switchToEvents'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        // method 'switchToProd'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        // method 'switchToPat'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        // method 'on_pushButton_add_clicked'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        // method 'on_pushButton_update_clicked'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        // method 'on_pushButton_delete_clicked'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        // method 'on_pushButton_clear_clicked'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        // method 'testDatabaseConnection'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        // method 'on_tab_Personnel_cellClicked'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        QtPrivate::TypeAndForceComplete<int, std::false_type>,
        QtPrivate::TypeAndForceComplete<int, std::false_type>,
        // method 'on_filterButton_clicked'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        // method 'on_exportPdfButton_clicked'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        // method 'on_searchPersonnel_returnPressed'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        // method 'on_statisticsButton_clicked'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        // method 'on_cameraButton_clicked'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        // method 'drawPieChart'
        QtPrivate::TypeAndForceComplete<int, std::false_type>,
        QtPrivate::TypeAndForceComplete<QPainter &, std::false_type>,
        QtPrivate::TypeAndForceComplete<int, std::false_type>,
        QtPrivate::TypeAndForceComplete<int, std::false_type>,
        QtPrivate::TypeAndForceComplete<int, std::false_type>,
        QtPrivate::TypeAndForceComplete<const QVector<QPair<QString,int>> &, std::false_type>,
        QtPrivate::TypeAndForceComplete<const QVector<QColor> &, std::false_type>,
        QtPrivate::TypeAndForceComplete<const QString &, std::false_type>,
        // method 'drawPieChartWidget'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        QtPrivate::TypeAndForceComplete<QPainter &, std::false_type>,
        QtPrivate::TypeAndForceComplete<const QRect &, std::false_type>,
        QtPrivate::TypeAndForceComplete<const QVector<QPair<QString,int>> &, std::false_type>,
        QtPrivate::TypeAndForceComplete<const QVector<QColor> &, std::false_type>,
        // method 'startCamera'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        QtPrivate::TypeAndForceComplete<const QByteArray &, std::false_type>,
        // method 'startCamera'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        // method 'stopCamera'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        // method 'captureImage'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        // method 'handleCameraError'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        QtPrivate::TypeAndForceComplete<QCamera::Error, std::false_type>,
        QtPrivate::TypeAndForceComplete<const QString &, std::false_type>,
        // method 'detectFaceInViewfinder'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        // method 'on_microvacButton_clicked'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        // method 'on_eventButton_clicked'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        // method 'on_inventoryButton_clicked'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        // method 'on_patientButton_clicked'
        QtPrivate::TypeAndForceComplete<void, std::false_type>
    >,
    nullptr
} };

void personnel::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        auto *_t = static_cast<personnel *>(_o);
        (void)_t;
        switch (_id) {
        case 0: _t->switchToAppointement(); break;
        case 1: _t->switchToMicro(); break;
        case 2: _t->switchToEvents(); break;
        case 3: _t->switchToProd(); break;
        case 4: _t->switchToPat(); break;
        case 5: _t->on_pushButton_add_clicked(); break;
        case 6: _t->on_pushButton_update_clicked(); break;
        case 7: _t->on_pushButton_delete_clicked(); break;
        case 8: _t->on_pushButton_clear_clicked(); break;
        case 9: _t->testDatabaseConnection(); break;
        case 10: _t->on_tab_Personnel_cellClicked((*reinterpret_cast< std::add_pointer_t<int>>(_a[1])),(*reinterpret_cast< std::add_pointer_t<int>>(_a[2]))); break;
        case 11: _t->on_filterButton_clicked(); break;
        case 12: _t->on_exportPdfButton_clicked(); break;
        case 13: _t->on_searchPersonnel_returnPressed(); break;
        case 14: _t->on_statisticsButton_clicked(); break;
        case 15: _t->on_cameraButton_clicked(); break;
        case 16: { int _r = _t->drawPieChart((*reinterpret_cast< std::add_pointer_t<QPainter&>>(_a[1])),(*reinterpret_cast< std::add_pointer_t<int>>(_a[2])),(*reinterpret_cast< std::add_pointer_t<int>>(_a[3])),(*reinterpret_cast< std::add_pointer_t<int>>(_a[4])),(*reinterpret_cast< std::add_pointer_t<QList<std::pair<QString,int>>>>(_a[5])),(*reinterpret_cast< std::add_pointer_t<QList<QColor>>>(_a[6])),(*reinterpret_cast< std::add_pointer_t<QString>>(_a[7])));
            if (_a[0]) *reinterpret_cast< int*>(_a[0]) = std::move(_r); }  break;
        case 17: _t->drawPieChartWidget((*reinterpret_cast< std::add_pointer_t<QPainter&>>(_a[1])),(*reinterpret_cast< std::add_pointer_t<QRect>>(_a[2])),(*reinterpret_cast< std::add_pointer_t<QList<std::pair<QString,int>>>>(_a[3])),(*reinterpret_cast< std::add_pointer_t<QList<QColor>>>(_a[4]))); break;
        case 18: _t->startCamera((*reinterpret_cast< std::add_pointer_t<QByteArray>>(_a[1]))); break;
        case 19: _t->startCamera(); break;
        case 20: _t->stopCamera(); break;
        case 21: _t->captureImage(); break;
        case 22: _t->handleCameraError((*reinterpret_cast< std::add_pointer_t<QCamera::Error>>(_a[1])),(*reinterpret_cast< std::add_pointer_t<QString>>(_a[2]))); break;
        case 23: _t->detectFaceInViewfinder(); break;
        case 24: _t->on_microvacButton_clicked(); break;
        case 25: _t->on_eventButton_clicked(); break;
        case 26: _t->on_inventoryButton_clicked(); break;
        case 27: _t->on_patientButton_clicked(); break;
        default: ;
        }
    } else if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        switch (_id) {
        default: *reinterpret_cast<QMetaType *>(_a[0]) = QMetaType(); break;
        case 16:
            switch (*reinterpret_cast<int*>(_a[1])) {
            default: *reinterpret_cast<QMetaType *>(_a[0]) = QMetaType(); break;
            case 5:
                *reinterpret_cast<QMetaType *>(_a[0]) = QMetaType::fromType< QList<QColor> >(); break;
            }
            break;
        case 17:
            switch (*reinterpret_cast<int*>(_a[1])) {
            default: *reinterpret_cast<QMetaType *>(_a[0]) = QMetaType(); break;
            case 3:
                *reinterpret_cast<QMetaType *>(_a[0]) = QMetaType::fromType< QList<QColor> >(); break;
            }
            break;
        }
    } else if (_c == QMetaObject::IndexOfMethod) {
        int *result = reinterpret_cast<int *>(_a[0]);
        {
            using _t = void (personnel::*)();
            if (_t _q_method = &personnel::switchToAppointement; *reinterpret_cast<_t *>(_a[1]) == _q_method) {
                *result = 0;
                return;
            }
        }
        {
            using _t = void (personnel::*)();
            if (_t _q_method = &personnel::switchToMicro; *reinterpret_cast<_t *>(_a[1]) == _q_method) {
                *result = 1;
                return;
            }
        }
        {
            using _t = void (personnel::*)();
            if (_t _q_method = &personnel::switchToEvents; *reinterpret_cast<_t *>(_a[1]) == _q_method) {
                *result = 2;
                return;
            }
        }
        {
            using _t = void (personnel::*)();
            if (_t _q_method = &personnel::switchToProd; *reinterpret_cast<_t *>(_a[1]) == _q_method) {
                *result = 3;
                return;
            }
        }
        {
            using _t = void (personnel::*)();
            if (_t _q_method = &personnel::switchToPat; *reinterpret_cast<_t *>(_a[1]) == _q_method) {
                *result = 4;
                return;
            }
        }
    }
}

const QMetaObject *personnel::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *personnel::qt_metacast(const char *_clname)
{
    if (!_clname) return nullptr;
    if (!strcmp(_clname, qt_meta_stringdata_CLASSpersonnelENDCLASS.stringdata0))
        return static_cast<void*>(this);
    return QMainWindow::qt_metacast(_clname);
}

int personnel::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QMainWindow::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        if (_id < 28)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 28;
    } else if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        if (_id < 28)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 28;
    }
    return _id;
}

// SIGNAL 0
void personnel::switchToAppointement()
{
    QMetaObject::activate(this, &staticMetaObject, 0, nullptr);
}

// SIGNAL 1
void personnel::switchToMicro()
{
    QMetaObject::activate(this, &staticMetaObject, 1, nullptr);
}

// SIGNAL 2
void personnel::switchToEvents()
{
    QMetaObject::activate(this, &staticMetaObject, 2, nullptr);
}

// SIGNAL 3
void personnel::switchToProd()
{
    QMetaObject::activate(this, &staticMetaObject, 3, nullptr);
}

// SIGNAL 4
void personnel::switchToPat()
{
    QMetaObject::activate(this, &staticMetaObject, 4, nullptr);
}
QT_WARNING_POP
