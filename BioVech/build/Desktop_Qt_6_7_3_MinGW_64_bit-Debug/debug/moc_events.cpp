/****************************************************************************
** Meta object code from reading C++ file 'events.h'
**
** Created by: The Qt Meta Object Compiler version 68 (Qt 6.7.3)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "../../../events.h"
#include <QtGui/qtextcursor.h>
#include <QtNetwork/QSslError>
#include <QtGui/qscreen.h>
#include <QtNetwork/QSslPreSharedKeyAuthenticator>
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
#include <QtCore/QList>

#include <QtCore/qtmochelpers.h>

#include <memory>


#include <QtCore/qxptype_traits.h>
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'events.h' doesn't include <QObject>."
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
struct qt_meta_stringdata_CLASSeventsENDCLASS_t {};
constexpr auto qt_meta_stringdata_CLASSeventsENDCLASS = QtMocHelpers::stringData(
    "events",
    "latitudeChanged",
    "",
    "longitudeChanged",
    "locationNameChanged",
    "centerChanged",
    "latitude",
    "longitude",
    "locationMarkingChanged",
    "name",
    "requestRoute",
    "startLat",
    "startLon",
    "endLat",
    "endLon",
    "switchToAppointement",
    "switchToMicro",
    "switchToPerso",
    "switchToProd",
    "switchToPat",
    "showRouteToNearestEvent",
    "userLat",
    "userLng",
    "QList<QStringList>",
    "allEvents",
    "setCenter",
    "setLocationMarking",
    "handleMapClick",
    "addMarker",
    "getUserLocation",
    "showNearbyEvents",
    "radius",
    "addCustomMarker",
    "type",
    "setLMarking",
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
    "on_Cancel_Modify_clicked",
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
    "on_Stat_Event_clicked",
    "on_Button_Staff_clicked",
    "on_Button_Appoitment_clicked",
    "on_Button_Vac_clicked",
    "on_Button_Inventory_clicked",
    "on_Button_Patient_clicked",
    "locationName"
);
#else  // !QT_MOC_HAS_STRINGDATA
#error "qtmochelpers.h not found or too old."
#endif // !QT_MOC_HAS_STRINGDATA
} // unnamed namespace

Q_CONSTINIT static const uint qt_meta_data_CLASSeventsENDCLASS[] = {

 // content:
      12,       // revision
       0,       // classname
       0,    0, // classinfo
      50,   14, // methods
       3,  436, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
      11,       // signalCount

 // signals: name, argc, parameters, tag, flags, initial metatype offsets
       1,    0,  314,    2, 0x06,    4 /* Public */,
       3,    0,  315,    2, 0x06,    5 /* Public */,
       4,    0,  316,    2, 0x06,    6 /* Public */,
       5,    2,  317,    2, 0x06,    7 /* Public */,
       8,    3,  322,    2, 0x06,   10 /* Public */,
      10,    4,  329,    2, 0x06,   14 /* Public */,
      15,    0,  338,    2, 0x06,   19 /* Public */,
      16,    0,  339,    2, 0x06,   20 /* Public */,
      17,    0,  340,    2, 0x06,   21 /* Public */,
      18,    0,  341,    2, 0x06,   22 /* Public */,
      19,    0,  342,    2, 0x06,   23 /* Public */,

 // slots: name, argc, parameters, tag, flags, initial metatype offsets
      20,    3,  343,    2, 0x0a,   24 /* Public */,
      25,    2,  350,    2, 0x0a,   28 /* Public */,
      26,    3,  355,    2, 0x0a,   31 /* Public */,
      27,    2,  362,    2, 0x0a,   35 /* Public */,
      28,    3,  367,    2, 0x0a,   38 /* Public */,
      29,    0,  374,    2, 0x0a,   42 /* Public */,
      30,    3,  375,    2, 0x0a,   43 /* Public */,
      32,    4,  382,    2, 0x0a,   47 /* Public */,
      34,    3,  391,    2, 0x0a,   52 /* Public */,
      35,    0,  398,    2, 0x08,   56 /* Private */,
      36,    0,  399,    2, 0x08,   57 /* Private */,
      37,    0,  400,    2, 0x08,   58 /* Private */,
      38,    0,  401,    2, 0x08,   59 /* Private */,
      39,    0,  402,    2, 0x08,   60 /* Private */,
      40,    0,  403,    2, 0x08,   61 /* Private */,
      41,    0,  404,    2, 0x08,   62 /* Private */,
      42,    0,  405,    2, 0x08,   63 /* Private */,
      43,    0,  406,    2, 0x08,   64 /* Private */,
      44,    0,  407,    2, 0x08,   65 /* Private */,
      45,    0,  408,    2, 0x08,   66 /* Private */,
      46,    0,  409,    2, 0x08,   67 /* Private */,
      47,    0,  410,    2, 0x08,   68 /* Private */,
      48,    2,  411,    2, 0x08,   69 /* Private */,
      51,    0,  416,    2, 0x08,   72 /* Private */,
      52,    1,  417,    2, 0x08,   73 /* Private */,
      54,    0,  420,    2, 0x08,   75 /* Private */,
      55,    0,  421,    2, 0x08,   76 /* Private */,
      56,    0,  422,    2, 0x08,   77 /* Private */,
      57,    0,  423,    2, 0x08,   78 /* Private */,
      58,    0,  424,    2, 0x08,   79 /* Private */,
      59,    1,  425,    2, 0x08,   80 /* Private */,
      61,    0,  428,    2, 0x08,   82 /* Private */,
      62,    0,  429,    2, 0x08,   83 /* Private */,
      63,    0,  430,    2, 0x08,   84 /* Private */,
      64,    0,  431,    2, 0x08,   85 /* Private */,
      65,    0,  432,    2, 0x08,   86 /* Private */,
      66,    0,  433,    2, 0x08,   87 /* Private */,
      67,    0,  434,    2, 0x08,   88 /* Private */,
      68,    0,  435,    2, 0x08,   89 /* Private */,

 // signals: parameters
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void, QMetaType::Double, QMetaType::Double,    6,    7,
    QMetaType::Void, QMetaType::Double, QMetaType::Double, QMetaType::QString,    6,    7,    9,
    QMetaType::Void, QMetaType::Double, QMetaType::Double, QMetaType::Double, QMetaType::Double,   11,   12,   13,   14,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,

 // slots: parameters
    QMetaType::Void, QMetaType::Double, QMetaType::Double, 0x80000000 | 23,   21,   22,   24,
    QMetaType::Void, QMetaType::Double, QMetaType::Double,    6,    7,
    QMetaType::Void, QMetaType::Double, QMetaType::Double, QMetaType::QString,    6,    7,    9,
    QMetaType::Void, QMetaType::Double, QMetaType::Double,    6,    7,
    QMetaType::Void, QMetaType::Double, QMetaType::Double, QMetaType::QString,    6,    7,    9,
    QMetaType::Void,
    QMetaType::Void, QMetaType::Double, QMetaType::Double, QMetaType::Double,    6,    7,   31,
    QMetaType::Void, QMetaType::Double, QMetaType::Double, QMetaType::QString, QMetaType::QString,    6,    7,    9,   33,
    QMetaType::Void, QMetaType::Double, QMetaType::Double, QMetaType::QString,    6,    7,    9,
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
    QMetaType::Void, QMetaType::Int, QMetaType::Int,   49,   50,
    QMetaType::Void,
    QMetaType::Void, QMetaType::QString,   53,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void, QMetaType::Int,   60,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,

 // properties: name, type, flags
       6, QMetaType::Double, 0x00015103, uint(0), 0,
       7, QMetaType::Double, 0x00015103, uint(1), 0,
      69, QMetaType::QString, 0x00015103, uint(2), 0,

       0        // eod
};

Q_CONSTINIT const QMetaObject events::staticMetaObject = { {
    QMetaObject::SuperData::link<QMainWindow::staticMetaObject>(),
    qt_meta_stringdata_CLASSeventsENDCLASS.offsetsAndSizes,
    qt_meta_data_CLASSeventsENDCLASS,
    qt_static_metacall,
    nullptr,
    qt_incomplete_metaTypeArray<qt_meta_stringdata_CLASSeventsENDCLASS_t,
        // property 'latitude'
        QtPrivate::TypeAndForceComplete<double, std::true_type>,
        // property 'longitude'
        QtPrivate::TypeAndForceComplete<double, std::true_type>,
        // property 'locationName'
        QtPrivate::TypeAndForceComplete<QString, std::true_type>,
        // Q_OBJECT / Q_GADGET
        QtPrivate::TypeAndForceComplete<events, std::true_type>,
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
        // method 'requestRoute'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        QtPrivate::TypeAndForceComplete<double, std::false_type>,
        QtPrivate::TypeAndForceComplete<double, std::false_type>,
        QtPrivate::TypeAndForceComplete<double, std::false_type>,
        QtPrivate::TypeAndForceComplete<double, std::false_type>,
        // method 'switchToAppointement'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        // method 'switchToMicro'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        // method 'switchToPerso'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        // method 'switchToProd'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        // method 'switchToPat'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        // method 'showRouteToNearestEvent'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        QtPrivate::TypeAndForceComplete<double, std::false_type>,
        QtPrivate::TypeAndForceComplete<double, std::false_type>,
        QtPrivate::TypeAndForceComplete<const QList<QStringList> &, std::false_type>,
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
        QtPrivate::TypeAndForceComplete<const QString &, std::false_type>,
        // method 'getUserLocation'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        // method 'showNearbyEvents'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        QtPrivate::TypeAndForceComplete<double, std::false_type>,
        QtPrivate::TypeAndForceComplete<double, std::false_type>,
        QtPrivate::TypeAndForceComplete<double, std::false_type>,
        // method 'addCustomMarker'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        QtPrivate::TypeAndForceComplete<double, std::false_type>,
        QtPrivate::TypeAndForceComplete<double, std::false_type>,
        QtPrivate::TypeAndForceComplete<const QString &, std::false_type>,
        QtPrivate::TypeAndForceComplete<const QString &, std::false_type>,
        // method 'setLMarking'
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
        // method 'on_Cancel_Modify_clicked'
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
        // method 'on_Stat_Event_clicked'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        // method 'on_Button_Staff_clicked'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        // method 'on_Button_Appoitment_clicked'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        // method 'on_Button_Vac_clicked'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        // method 'on_Button_Inventory_clicked'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        // method 'on_Button_Patient_clicked'
        QtPrivate::TypeAndForceComplete<void, std::false_type>
    >,
    nullptr
} };

void events::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        auto *_t = static_cast<events *>(_o);
        (void)_t;
        switch (_id) {
        case 0: _t->latitudeChanged(); break;
        case 1: _t->longitudeChanged(); break;
        case 2: _t->locationNameChanged(); break;
        case 3: _t->centerChanged((*reinterpret_cast< std::add_pointer_t<double>>(_a[1])),(*reinterpret_cast< std::add_pointer_t<double>>(_a[2]))); break;
        case 4: _t->locationMarkingChanged((*reinterpret_cast< std::add_pointer_t<double>>(_a[1])),(*reinterpret_cast< std::add_pointer_t<double>>(_a[2])),(*reinterpret_cast< std::add_pointer_t<QString>>(_a[3]))); break;
        case 5: _t->requestRoute((*reinterpret_cast< std::add_pointer_t<double>>(_a[1])),(*reinterpret_cast< std::add_pointer_t<double>>(_a[2])),(*reinterpret_cast< std::add_pointer_t<double>>(_a[3])),(*reinterpret_cast< std::add_pointer_t<double>>(_a[4]))); break;
        case 6: _t->switchToAppointement(); break;
        case 7: _t->switchToMicro(); break;
        case 8: _t->switchToPerso(); break;
        case 9: _t->switchToProd(); break;
        case 10: _t->switchToPat(); break;
        case 11: _t->showRouteToNearestEvent((*reinterpret_cast< std::add_pointer_t<double>>(_a[1])),(*reinterpret_cast< std::add_pointer_t<double>>(_a[2])),(*reinterpret_cast< std::add_pointer_t<QList<QStringList>>>(_a[3]))); break;
        case 12: _t->setCenter((*reinterpret_cast< std::add_pointer_t<double>>(_a[1])),(*reinterpret_cast< std::add_pointer_t<double>>(_a[2]))); break;
        case 13: _t->setLocationMarking((*reinterpret_cast< std::add_pointer_t<double>>(_a[1])),(*reinterpret_cast< std::add_pointer_t<double>>(_a[2])),(*reinterpret_cast< std::add_pointer_t<QString>>(_a[3]))); break;
        case 14: _t->handleMapClick((*reinterpret_cast< std::add_pointer_t<double>>(_a[1])),(*reinterpret_cast< std::add_pointer_t<double>>(_a[2]))); break;
        case 15: _t->addMarker((*reinterpret_cast< std::add_pointer_t<double>>(_a[1])),(*reinterpret_cast< std::add_pointer_t<double>>(_a[2])),(*reinterpret_cast< std::add_pointer_t<QString>>(_a[3]))); break;
        case 16: _t->getUserLocation(); break;
        case 17: _t->showNearbyEvents((*reinterpret_cast< std::add_pointer_t<double>>(_a[1])),(*reinterpret_cast< std::add_pointer_t<double>>(_a[2])),(*reinterpret_cast< std::add_pointer_t<double>>(_a[3]))); break;
        case 18: _t->addCustomMarker((*reinterpret_cast< std::add_pointer_t<double>>(_a[1])),(*reinterpret_cast< std::add_pointer_t<double>>(_a[2])),(*reinterpret_cast< std::add_pointer_t<QString>>(_a[3])),(*reinterpret_cast< std::add_pointer_t<QString>>(_a[4]))); break;
        case 19: _t->setLMarking((*reinterpret_cast< std::add_pointer_t<double>>(_a[1])),(*reinterpret_cast< std::add_pointer_t<double>>(_a[2])),(*reinterpret_cast< std::add_pointer_t<QString>>(_a[3]))); break;
        case 20: _t->on_Button_Vac_pressed(); break;
        case 21: _t->on_Button_Staff_pressed(); break;
        case 22: _t->on_Button_Inventory_pressed(); break;
        case 23: _t->on_Button_Events_pressed(); break;
        case 24: _t->on_Button_Appoitment_pressed(); break;
        case 25: _t->on_Button_Analytics_pressed(); break;
        case 26: _t->on_Button_Analytics_clicked(); break;
        case 27: _t->on_Button_Patient_pressed(); break;
        case 28: _t->on_pushButton_5_clicked(); break;
        case 29: _t->on_Add_Event_clicked(); break;
        case 30: _t->on_Save_Add_clicked(); break;
        case 31: _t->on_Delete_Event_clicked(); break;
        case 32: _t->on_Modify_Event_clicked(); break;
        case 33: _t->on_tableWidget_cellClicked((*reinterpret_cast< std::add_pointer_t<int>>(_a[1])),(*reinterpret_cast< std::add_pointer_t<int>>(_a[2]))); break;
        case 34: _t->on_Cancel_Modify_clicked(); break;
        case 35: _t->on_comboBox_currentTextChanged((*reinterpret_cast< std::add_pointer_t<QString>>(_a[1]))); break;
        case 36: _t->on_Search_Button_clicked(); break;
        case 37: _t->on_pdf_Button_clicked(); break;
        case 38: _t->on_Suggestions_Button_clicked(); break;
        case 39: _t->on_mapClicked_Add(); break;
        case 40: _t->on_mapClicked_Suggest(); break;
        case 41: _t->onTabChanged((*reinterpret_cast< std::add_pointer_t<int>>(_a[1]))); break;
        case 42: _t->on_positionMapButton_clicked(); break;
        case 43: _t->on_updatePositionMapButton_clicked(); break;
        case 44: _t->on_Stat_Event_clicked(); break;
        case 45: _t->on_Button_Staff_clicked(); break;
        case 46: _t->on_Button_Appoitment_clicked(); break;
        case 47: _t->on_Button_Vac_clicked(); break;
        case 48: _t->on_Button_Inventory_clicked(); break;
        case 49: _t->on_Button_Patient_clicked(); break;
        default: ;
        }
    } else if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        switch (_id) {
        default: *reinterpret_cast<QMetaType *>(_a[0]) = QMetaType(); break;
        case 11:
            switch (*reinterpret_cast<int*>(_a[1])) {
            default: *reinterpret_cast<QMetaType *>(_a[0]) = QMetaType(); break;
            case 2:
                *reinterpret_cast<QMetaType *>(_a[0]) = QMetaType::fromType< QList<QStringList> >(); break;
            }
            break;
        }
    } else if (_c == QMetaObject::IndexOfMethod) {
        int *result = reinterpret_cast<int *>(_a[0]);
        {
            using _t = void (events::*)();
            if (_t _q_method = &events::latitudeChanged; *reinterpret_cast<_t *>(_a[1]) == _q_method) {
                *result = 0;
                return;
            }
        }
        {
            using _t = void (events::*)();
            if (_t _q_method = &events::longitudeChanged; *reinterpret_cast<_t *>(_a[1]) == _q_method) {
                *result = 1;
                return;
            }
        }
        {
            using _t = void (events::*)();
            if (_t _q_method = &events::locationNameChanged; *reinterpret_cast<_t *>(_a[1]) == _q_method) {
                *result = 2;
                return;
            }
        }
        {
            using _t = void (events::*)(double , double );
            if (_t _q_method = &events::centerChanged; *reinterpret_cast<_t *>(_a[1]) == _q_method) {
                *result = 3;
                return;
            }
        }
        {
            using _t = void (events::*)(double , double , const QString & );
            if (_t _q_method = &events::locationMarkingChanged; *reinterpret_cast<_t *>(_a[1]) == _q_method) {
                *result = 4;
                return;
            }
        }
        {
            using _t = void (events::*)(double , double , double , double );
            if (_t _q_method = &events::requestRoute; *reinterpret_cast<_t *>(_a[1]) == _q_method) {
                *result = 5;
                return;
            }
        }
        {
            using _t = void (events::*)();
            if (_t _q_method = &events::switchToAppointement; *reinterpret_cast<_t *>(_a[1]) == _q_method) {
                *result = 6;
                return;
            }
        }
        {
            using _t = void (events::*)();
            if (_t _q_method = &events::switchToMicro; *reinterpret_cast<_t *>(_a[1]) == _q_method) {
                *result = 7;
                return;
            }
        }
        {
            using _t = void (events::*)();
            if (_t _q_method = &events::switchToPerso; *reinterpret_cast<_t *>(_a[1]) == _q_method) {
                *result = 8;
                return;
            }
        }
        {
            using _t = void (events::*)();
            if (_t _q_method = &events::switchToProd; *reinterpret_cast<_t *>(_a[1]) == _q_method) {
                *result = 9;
                return;
            }
        }
        {
            using _t = void (events::*)();
            if (_t _q_method = &events::switchToPat; *reinterpret_cast<_t *>(_a[1]) == _q_method) {
                *result = 10;
                return;
            }
        }
    } else if (_c == QMetaObject::ReadProperty) {
        auto *_t = static_cast<events *>(_o);
        (void)_t;
        void *_v = _a[0];
        switch (_id) {
        case 0: *reinterpret_cast< double*>(_v) = _t->latitude(); break;
        case 1: *reinterpret_cast< double*>(_v) = _t->longitude(); break;
        case 2: *reinterpret_cast< QString*>(_v) = _t->locationName(); break;
        default: break;
        }
    } else if (_c == QMetaObject::WriteProperty) {
        auto *_t = static_cast<events *>(_o);
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

const QMetaObject *events::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *events::qt_metacast(const char *_clname)
{
    if (!_clname) return nullptr;
    if (!strcmp(_clname, qt_meta_stringdata_CLASSeventsENDCLASS.stringdata0))
        return static_cast<void*>(this);
    return QMainWindow::qt_metacast(_clname);
}

int events::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QMainWindow::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        if (_id < 50)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 50;
    } else if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        if (_id < 50)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 50;
    }else if (_c == QMetaObject::ReadProperty || _c == QMetaObject::WriteProperty
            || _c == QMetaObject::ResetProperty || _c == QMetaObject::BindableProperty
            || _c == QMetaObject::RegisterPropertyMetaType) {
        qt_static_metacall(this, _c, _id, _a);
        _id -= 3;
    }
    return _id;
}

// SIGNAL 0
void events::latitudeChanged()
{
    QMetaObject::activate(this, &staticMetaObject, 0, nullptr);
}

// SIGNAL 1
void events::longitudeChanged()
{
    QMetaObject::activate(this, &staticMetaObject, 1, nullptr);
}

// SIGNAL 2
void events::locationNameChanged()
{
    QMetaObject::activate(this, &staticMetaObject, 2, nullptr);
}

// SIGNAL 3
void events::centerChanged(double _t1, double _t2)
{
    void *_a[] = { nullptr, const_cast<void*>(reinterpret_cast<const void*>(std::addressof(_t1))), const_cast<void*>(reinterpret_cast<const void*>(std::addressof(_t2))) };
    QMetaObject::activate(this, &staticMetaObject, 3, _a);
}

// SIGNAL 4
void events::locationMarkingChanged(double _t1, double _t2, const QString & _t3)
{
    void *_a[] = { nullptr, const_cast<void*>(reinterpret_cast<const void*>(std::addressof(_t1))), const_cast<void*>(reinterpret_cast<const void*>(std::addressof(_t2))), const_cast<void*>(reinterpret_cast<const void*>(std::addressof(_t3))) };
    QMetaObject::activate(this, &staticMetaObject, 4, _a);
}

// SIGNAL 5
void events::requestRoute(double _t1, double _t2, double _t3, double _t4)
{
    void *_a[] = { nullptr, const_cast<void*>(reinterpret_cast<const void*>(std::addressof(_t1))), const_cast<void*>(reinterpret_cast<const void*>(std::addressof(_t2))), const_cast<void*>(reinterpret_cast<const void*>(std::addressof(_t3))), const_cast<void*>(reinterpret_cast<const void*>(std::addressof(_t4))) };
    QMetaObject::activate(this, &staticMetaObject, 5, _a);
}

// SIGNAL 6
void events::switchToAppointement()
{
    QMetaObject::activate(this, &staticMetaObject, 6, nullptr);
}

// SIGNAL 7
void events::switchToMicro()
{
    QMetaObject::activate(this, &staticMetaObject, 7, nullptr);
}

// SIGNAL 8
void events::switchToPerso()
{
    QMetaObject::activate(this, &staticMetaObject, 8, nullptr);
}

// SIGNAL 9
void events::switchToProd()
{
    QMetaObject::activate(this, &staticMetaObject, 9, nullptr);
}

// SIGNAL 10
void events::switchToPat()
{
    QMetaObject::activate(this, &staticMetaObject, 10, nullptr);
}
QT_WARNING_POP
