/****************************************************************************
** Meta object code from reading C++ file 'mainwindow.h'
**
** Created by: The Qt Meta Object Compiler version 68 (Qt 6.7.3)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "../../../mainwindow.h"
#include <QtGui/qtextcursor.h>
#include <QtGui/qscreen.h>
#include <QtNetwork/QSslPreSharedKeyAuthenticator>
#include <QtNetwork/QSslError>
#include <QtCharts/qlineseries.h>
#include <QtCharts/qabstractbarseries.h>
#include <QtCharts/qvbarmodelmapper.h>
#include <QtCharts/qboxplotseries.h>
#include <QtCharts/qcandlestickseries.h>
#include <QtCore/qabstractitemmodel.h>
#include <QtCharts/qpieseries.h>
#include <QtCore/qabstractitemmodel.h>
#include <QtCharts/qboxplotseries.h>
#include <QtCore/qabstractitemmodel.h>
#include <QtCharts/qpieseries.h>
#include <QtCharts/qpieseries.h>
#include <QtCore/qabstractitemmodel.h>
#include <QtCharts/qxyseries.h>
#include <QtCharts/qxyseries.h>
#include <QtCore/qabstractitemmodel.h>
#include <QtCore/qabstractitemmodel.h>
#include <QtCharts/qboxplotseries.h>
#include <QtCore/qabstractitemmodel.h>
#include <QtCharts/qpieseries.h>
#include <QtCore/qabstractitemmodel.h>
#include <QtCharts/qxyseries.h>
#include <QtCore/qabstractitemmodel.h>
#include <QtCore/qmetatype.h>

#include <QtCore/qtmochelpers.h>

#include <memory>


#include <QtCore/qxptype_traits.h>
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'mainwindow.h' doesn't include <QObject>."
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
struct qt_meta_stringdata_CLASSMainWindowENDCLASS_t {};
constexpr auto qt_meta_stringdata_CLASSMainWindowENDCLASS = QtMocHelpers::stringData(
    "MainWindow",
    "latitudeChanged",
    "",
    "longitudeChanged",
    "locationNameChanged",
    "centerChanged",
    "latitude",
    "longitude",
    "locationMarkingChanged",
    "name",
    "on_Button_Vac_pressed",
    "on_Button_Staff_pressed",
    "on_Button_Inventory_pressed",
    "on_Button_Events_pressed",
    "on_Button_Appoitment_pressed",
    "on_Button_Analytics_pressed",
    "on_Button_Analytics_clicked",
    "on_Button_Patient_pressed",
    "on_pushButton_5_clicked",
    "on_Add_Event_clicked",
    "on_Save_Add_clicked",
    "on_Delete_Event_clicked",
    "on_Modify_Event_clicked",
    "on_tableWidget_cellClicked",
    "row",
    "column",
    "on_Cancel_Add_clicked",
    "on_Cancel_Modify_clicked",
    "on_Cancel_Delete_clicked",
    "on_comboBox_currentTextChanged",
    "arg1",
    "on_Search_Button_clicked",
    "on_pdf_Button_clicked",
    "on_Suggestions_Button_clicked",
    "on_mapClicked_Add",
    "on_mapClicked_Suggest",
    "onTabChanged",
    "index",
    "on_positionMapButton_clicked",
    "on_updatePositionMapButton_clicked",
    "setCenter",
    "setLocationMarking",
    "handleMapClick",
    "addMarker",
    "locationName"
);
#else  // !QT_MOC_HAS_STRINGDATA
#error "qtmochelpers.h not found or too old."
#endif // !QT_MOC_HAS_STRINGDATA
} // unnamed namespace

Q_CONSTINIT static const uint qt_meta_data_CLASSMainWindowENDCLASS[] = {

 // content:
      12,       // revision
       0,       // classname
       0,    0, // classinfo
      35,   14, // methods
       3,  297, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       5,       // signalCount

 // signals: name, argc, parameters, tag, flags, initial metatype offsets
       1,    0,  224,    2, 0x06,    4 /* Public */,
       3,    0,  225,    2, 0x06,    5 /* Public */,
       4,    0,  226,    2, 0x06,    6 /* Public */,
       5,    2,  227,    2, 0x06,    7 /* Public */,
       8,    3,  232,    2, 0x06,   10 /* Public */,

 // slots: name, argc, parameters, tag, flags, initial metatype offsets
      10,    0,  239,    2, 0x08,   14 /* Private */,
      11,    0,  240,    2, 0x08,   15 /* Private */,
      12,    0,  241,    2, 0x08,   16 /* Private */,
      13,    0,  242,    2, 0x08,   17 /* Private */,
      14,    0,  243,    2, 0x08,   18 /* Private */,
      15,    0,  244,    2, 0x08,   19 /* Private */,
      16,    0,  245,    2, 0x08,   20 /* Private */,
      17,    0,  246,    2, 0x08,   21 /* Private */,
      18,    0,  247,    2, 0x08,   22 /* Private */,
      19,    0,  248,    2, 0x08,   23 /* Private */,
      20,    0,  249,    2, 0x08,   24 /* Private */,
      21,    0,  250,    2, 0x08,   25 /* Private */,
      22,    0,  251,    2, 0x08,   26 /* Private */,
      23,    2,  252,    2, 0x08,   27 /* Private */,
      26,    0,  257,    2, 0x08,   30 /* Private */,
      27,    0,  258,    2, 0x08,   31 /* Private */,
      28,    0,  259,    2, 0x08,   32 /* Private */,
      29,    1,  260,    2, 0x08,   33 /* Private */,
      31,    0,  263,    2, 0x08,   35 /* Private */,
      32,    0,  264,    2, 0x08,   36 /* Private */,
      33,    0,  265,    2, 0x08,   37 /* Private */,
      34,    0,  266,    2, 0x08,   38 /* Private */,
      35,    0,  267,    2, 0x08,   39 /* Private */,
      36,    1,  268,    2, 0x08,   40 /* Private */,
      38,    0,  271,    2, 0x08,   42 /* Private */,
      39,    0,  272,    2, 0x08,   43 /* Private */,

 // methods: name, argc, parameters, tag, flags, initial metatype offsets
      40,    2,  273,    2, 0x02,   44 /* Public */,
      41,    3,  278,    2, 0x02,   47 /* Public */,
      42,    2,  285,    2, 0x02,   51 /* Public */,
      43,    3,  290,    2, 0x02,   54 /* Public */,

 // signals: parameters
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void, QMetaType::Double, QMetaType::Double,    6,    7,
    QMetaType::Void, QMetaType::Double, QMetaType::Double, QMetaType::QString,    6,    7,    9,

 // slots: parameters
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void, QMetaType::Int, QMetaType::Int,   24,   25,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void, QMetaType::QString,   30,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void, QMetaType::Int,   37,
    QMetaType::Void,
    QMetaType::Void,

 // methods: parameters
    QMetaType::Void, QMetaType::Double, QMetaType::Double,    6,    7,
    QMetaType::Void, QMetaType::Double, QMetaType::Double, QMetaType::QString,    6,    7,    9,
    QMetaType::Void, QMetaType::Double, QMetaType::Double,    6,    7,
    QMetaType::Void, QMetaType::Double, QMetaType::Double, QMetaType::QString,    6,    7,    9,

 // properties: name, type, flags
       6, QMetaType::Double, 0x00015103, uint(0), 0,
       7, QMetaType::Double, 0x00015103, uint(1), 0,
      44, QMetaType::QString, 0x00015103, uint(2), 0,

       0        // eod
};

Q_CONSTINIT const QMetaObject MainWindow::staticMetaObject = { {
    QMetaObject::SuperData::link<QMainWindow::staticMetaObject>(),
    qt_meta_stringdata_CLASSMainWindowENDCLASS.offsetsAndSizes,
    qt_meta_data_CLASSMainWindowENDCLASS,
    qt_static_metacall,
    nullptr,
    qt_incomplete_metaTypeArray<qt_meta_stringdata_CLASSMainWindowENDCLASS_t,
        // property 'latitude'
        QtPrivate::TypeAndForceComplete<double, std::true_type>,
        // property 'longitude'
        QtPrivate::TypeAndForceComplete<double, std::true_type>,
        // property 'locationName'
        QtPrivate::TypeAndForceComplete<QString, std::true_type>,
        // Q_OBJECT / Q_GADGET
        QtPrivate::TypeAndForceComplete<MainWindow, std::true_type>,
        // method 'latitudeChanged'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        // method 'longitudeChanged'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        // method 'locationNameChanged'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        // method 'centerChanged'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        QtPrivate::TypeAndForceComplete<double, std::false_type>,
        QtPrivate::TypeAndForceComplete<double, std::false_type>,
        // method 'locationMarkingChanged'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        QtPrivate::TypeAndForceComplete<double, std::false_type>,
        QtPrivate::TypeAndForceComplete<double, std::false_type>,
        QtPrivate::TypeAndForceComplete<const QString &, std::false_type>,
        // method 'on_Button_Vac_pressed'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        // method 'on_Button_Staff_pressed'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        // method 'on_Button_Inventory_pressed'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        // method 'on_Button_Events_pressed'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        // method 'on_Button_Appoitment_pressed'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        // method 'on_Button_Analytics_pressed'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        // method 'on_Button_Analytics_clicked'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        // method 'on_Button_Patient_pressed'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        // method 'on_pushButton_5_clicked'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        // method 'on_Add_Event_clicked'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        // method 'on_Save_Add_clicked'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        // method 'on_Delete_Event_clicked'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        // method 'on_Modify_Event_clicked'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        // method 'on_tableWidget_cellClicked'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        QtPrivate::TypeAndForceComplete<int, std::false_type>,
        QtPrivate::TypeAndForceComplete<int, std::false_type>,
        // method 'on_Cancel_Add_clicked'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        // method 'on_Cancel_Modify_clicked'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        // method 'on_Cancel_Delete_clicked'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        // method 'on_comboBox_currentTextChanged'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        QtPrivate::TypeAndForceComplete<const QString &, std::false_type>,
        // method 'on_Search_Button_clicked'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        // method 'on_pdf_Button_clicked'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        // method 'on_Suggestions_Button_clicked'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        // method 'on_mapClicked_Add'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        // method 'on_mapClicked_Suggest'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        // method 'onTabChanged'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        QtPrivate::TypeAndForceComplete<int, std::false_type>,
        // method 'on_positionMapButton_clicked'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        // method 'on_updatePositionMapButton_clicked'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        // method 'setCenter'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        QtPrivate::TypeAndForceComplete<double, std::false_type>,
        QtPrivate::TypeAndForceComplete<double, std::false_type>,
        // method 'setLocationMarking'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        QtPrivate::TypeAndForceComplete<double, std::false_type>,
        QtPrivate::TypeAndForceComplete<double, std::false_type>,
        QtPrivate::TypeAndForceComplete<const QString &, std::false_type>,
        // method 'handleMapClick'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        QtPrivate::TypeAndForceComplete<double, std::false_type>,
        QtPrivate::TypeAndForceComplete<double, std::false_type>,
        // method 'addMarker'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        QtPrivate::TypeAndForceComplete<double, std::false_type>,
        QtPrivate::TypeAndForceComplete<double, std::false_type>,
        QtPrivate::TypeAndForceComplete<const QString &, std::false_type>
    >,
    nullptr
} };

void MainWindow::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        auto *_t = static_cast<MainWindow *>(_o);
        (void)_t;
        switch (_id) {
        case 0: _t->latitudeChanged(); break;
        case 1: _t->longitudeChanged(); break;
        case 2: _t->locationNameChanged(); break;
        case 3: _t->centerChanged((*reinterpret_cast< std::add_pointer_t<double>>(_a[1])),(*reinterpret_cast< std::add_pointer_t<double>>(_a[2]))); break;
        case 4: _t->locationMarkingChanged((*reinterpret_cast< std::add_pointer_t<double>>(_a[1])),(*reinterpret_cast< std::add_pointer_t<double>>(_a[2])),(*reinterpret_cast< std::add_pointer_t<QString>>(_a[3]))); break;
        case 5: _t->on_Button_Vac_pressed(); break;
        case 6: _t->on_Button_Staff_pressed(); break;
        case 7: _t->on_Button_Inventory_pressed(); break;
        case 8: _t->on_Button_Events_pressed(); break;
        case 9: _t->on_Button_Appoitment_pressed(); break;
        case 10: _t->on_Button_Analytics_pressed(); break;
        case 11: _t->on_Button_Analytics_clicked(); break;
        case 12: _t->on_Button_Patient_pressed(); break;
        case 13: _t->on_pushButton_5_clicked(); break;
        case 14: _t->on_Add_Event_clicked(); break;
        case 15: _t->on_Save_Add_clicked(); break;
        case 16: _t->on_Delete_Event_clicked(); break;
        case 17: _t->on_Modify_Event_clicked(); break;
        case 18: _t->on_tableWidget_cellClicked((*reinterpret_cast< std::add_pointer_t<int>>(_a[1])),(*reinterpret_cast< std::add_pointer_t<int>>(_a[2]))); break;
        case 19: _t->on_Cancel_Add_clicked(); break;
        case 20: _t->on_Cancel_Modify_clicked(); break;
        case 21: _t->on_Cancel_Delete_clicked(); break;
        case 22: _t->on_comboBox_currentTextChanged((*reinterpret_cast< std::add_pointer_t<QString>>(_a[1]))); break;
        case 23: _t->on_Search_Button_clicked(); break;
        case 24: _t->on_pdf_Button_clicked(); break;
        case 25: _t->on_Suggestions_Button_clicked(); break;
        case 26: _t->on_mapClicked_Add(); break;
        case 27: _t->on_mapClicked_Suggest(); break;
        case 28: _t->onTabChanged((*reinterpret_cast< std::add_pointer_t<int>>(_a[1]))); break;
        case 29: _t->on_positionMapButton_clicked(); break;
        case 30: _t->on_updatePositionMapButton_clicked(); break;
        case 31: _t->setCenter((*reinterpret_cast< std::add_pointer_t<double>>(_a[1])),(*reinterpret_cast< std::add_pointer_t<double>>(_a[2]))); break;
        case 32: _t->setLocationMarking((*reinterpret_cast< std::add_pointer_t<double>>(_a[1])),(*reinterpret_cast< std::add_pointer_t<double>>(_a[2])),(*reinterpret_cast< std::add_pointer_t<QString>>(_a[3]))); break;
        case 33: _t->handleMapClick((*reinterpret_cast< std::add_pointer_t<double>>(_a[1])),(*reinterpret_cast< std::add_pointer_t<double>>(_a[2]))); break;
        case 34: _t->addMarker((*reinterpret_cast< std::add_pointer_t<double>>(_a[1])),(*reinterpret_cast< std::add_pointer_t<double>>(_a[2])),(*reinterpret_cast< std::add_pointer_t<QString>>(_a[3]))); break;
        default: ;
        }
    } else if (_c == QMetaObject::IndexOfMethod) {
        int *result = reinterpret_cast<int *>(_a[0]);
        {
            using _t = void (MainWindow::*)();
            if (_t _q_method = &MainWindow::latitudeChanged; *reinterpret_cast<_t *>(_a[1]) == _q_method) {
                *result = 0;
                return;
            }
        }
        {
            using _t = void (MainWindow::*)();
            if (_t _q_method = &MainWindow::longitudeChanged; *reinterpret_cast<_t *>(_a[1]) == _q_method) {
                *result = 1;
                return;
            }
        }
        {
            using _t = void (MainWindow::*)();
            if (_t _q_method = &MainWindow::locationNameChanged; *reinterpret_cast<_t *>(_a[1]) == _q_method) {
                *result = 2;
                return;
            }
        }
        {
            using _t = void (MainWindow::*)(double , double );
            if (_t _q_method = &MainWindow::centerChanged; *reinterpret_cast<_t *>(_a[1]) == _q_method) {
                *result = 3;
                return;
            }
        }
        {
            using _t = void (MainWindow::*)(double , double , const QString & );
            if (_t _q_method = &MainWindow::locationMarkingChanged; *reinterpret_cast<_t *>(_a[1]) == _q_method) {
                *result = 4;
                return;
            }
        }
    } else if (_c == QMetaObject::ReadProperty) {
        auto *_t = static_cast<MainWindow *>(_o);
        (void)_t;
        void *_v = _a[0];
        switch (_id) {
        case 0: *reinterpret_cast< double*>(_v) = _t->latitude(); break;
        case 1: *reinterpret_cast< double*>(_v) = _t->longitude(); break;
        case 2: *reinterpret_cast< QString*>(_v) = _t->locationName(); break;
        default: break;
        }
    } else if (_c == QMetaObject::WriteProperty) {
        auto *_t = static_cast<MainWindow *>(_o);
        (void)_t;
        void *_v = _a[0];
        switch (_id) {
        case 0: _t->setLatitude(*reinterpret_cast< double*>(_v)); break;
        case 1: _t->setLongitude(*reinterpret_cast< double*>(_v)); break;
        case 2: _t->setLocationName(*reinterpret_cast< QString*>(_v)); break;
        default: break;
        }
    } else if (_c == QMetaObject::ResetProperty) {
    } else if (_c == QMetaObject::BindableProperty) {
    }
}

const QMetaObject *MainWindow::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *MainWindow::qt_metacast(const char *_clname)
{
    if (!_clname) return nullptr;
    if (!strcmp(_clname, qt_meta_stringdata_CLASSMainWindowENDCLASS.stringdata0))
        return static_cast<void*>(this);
    return QMainWindow::qt_metacast(_clname);
}

int MainWindow::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QMainWindow::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        if (_id < 35)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 35;
    } else if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        if (_id < 35)
            *reinterpret_cast<QMetaType *>(_a[0]) = QMetaType();
        _id -= 35;
    }else if (_c == QMetaObject::ReadProperty || _c == QMetaObject::WriteProperty
            || _c == QMetaObject::ResetProperty || _c == QMetaObject::BindableProperty
            || _c == QMetaObject::RegisterPropertyMetaType) {
        qt_static_metacall(this, _c, _id, _a);
        _id -= 3;
    }
    return _id;
}

// SIGNAL 0
void MainWindow::latitudeChanged()
{
    QMetaObject::activate(this, &staticMetaObject, 0, nullptr);
}

// SIGNAL 1
void MainWindow::longitudeChanged()
{
    QMetaObject::activate(this, &staticMetaObject, 1, nullptr);
}

// SIGNAL 2
void MainWindow::locationNameChanged()
{
    QMetaObject::activate(this, &staticMetaObject, 2, nullptr);
}

// SIGNAL 3
void MainWindow::centerChanged(double _t1, double _t2)
{
    void *_a[] = { nullptr, const_cast<void*>(reinterpret_cast<const void*>(std::addressof(_t1))), const_cast<void*>(reinterpret_cast<const void*>(std::addressof(_t2))) };
    QMetaObject::activate(this, &staticMetaObject, 3, _a);
}

// SIGNAL 4
void MainWindow::locationMarkingChanged(double _t1, double _t2, const QString & _t3)
{
    void *_a[] = { nullptr, const_cast<void*>(reinterpret_cast<const void*>(std::addressof(_t1))), const_cast<void*>(reinterpret_cast<const void*>(std::addressof(_t2))), const_cast<void*>(reinterpret_cast<const void*>(std::addressof(_t3))) };
    QMetaObject::activate(this, &staticMetaObject, 4, _a);
}
QT_WARNING_POP
