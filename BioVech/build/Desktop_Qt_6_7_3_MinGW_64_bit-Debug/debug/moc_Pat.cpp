/****************************************************************************
** Meta object code from reading C++ file 'Pat.h'
**
** Created by: The Qt Meta Object Compiler version 68 (Qt 6.7.3)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "../../../Pat.h"
#include <QtGui/qtextcursor.h>
#include <QtNetwork/QSslError>
#include <QtCore/qmetatype.h>
#include <QtCore/QList>

#include <QtCore/qtmochelpers.h>

#include <memory>


#include <QtCore/qxptype_traits.h>
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'Pat.h' doesn't include <QObject>."
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
struct qt_meta_stringdata_CLASSPatENDCLASS_t {};
constexpr auto qt_meta_stringdata_CLASSPatENDCLASS = QtMocHelpers::stringData(
    "Pat",
    "switchToPersonnel",
    "",
    "switchToAppointement",
    "switchToEvents",
    "switchToProd",
    "switchToMicro",
    "clearPatientForm",
    "validateInputFields",
    "savePatient",
    "showRegistrationTab",
    "searchPatients",
    "sortPatients",
    "exportPDF",
    "editPatient",
    "selectedRow",
    "deletePatient",
    "showHelp",
    "showAbout",
    "connectToDatabase",
    "loadPatients",
    "refreshPatients",
    "refreshMedicalPatients",
    "setupTableWidget",
    "setupMedicalTableWidget",
    "loadMedicalPatients",
    "searchMedicalPatients",
    "on_tableWidget_medical_patients_itemClicked",
    "QTableWidgetItem*",
    "item",
    "displayMedicalFile",
    "formatJsonForDisplay",
    "jsonData",
    "updateMedicalFile",
    "importMedicalFile",
    "exportMedicalFile",
    "on_pushButton_browse_clicked",
    "on_pushButton_browse_photo_clicked",
    "setupPhotoElements",
    "setupCountryCodeComboBox",
    "removePatientPredictionCard",
    "QWidget*",
    "card",
    "setupStatisticsTab",
    "updateStatistics",
    "generateAgeStatistics",
    "generateSexStatistics",
    "sortStatisticsByAge",
    "sortStatisticsBySex",
    "updateStatisticsTable",
    "createPredictionTab",
    "predictRiskForSelectedPatient",
    "createPredictionCard",
    "Patient",
    "patient",
    "risk",
    "percentage",
    "heritage",
    "patientPredictionExists",
    "cin",
    "createChatbotTab",
    "sendChatbotMessage",
    "displayChatbotResponse",
    "response",
    "displayQueryResults",
    "headers",
    "QList<QStringList>",
    "data",
    "handleChatbotError",
    "error",
    "handleDirectApiResponse",
    "sqlResponse",
    "executeDirectSqlQuery",
    "sqlQuery",
    "on_tableWidget_patients_itemDoubleClicked",
    "on_microvacButton_clicked",
    "on_personnelButton_clicked",
    "on_inventoryButton_clicked",
    "on_appointmentButton_clicked",
    "on_eventButton_clicked"
);
#else  // !QT_MOC_HAS_STRINGDATA
#error "qtmochelpers.h not found or too old."
#endif // !QT_MOC_HAS_STRINGDATA
} // unnamed namespace

Q_CONSTINIT static const uint qt_meta_data_CLASSPatENDCLASS[] = {

 // content:
      12,       // revision
       0,       // classname
       0,    0, // classinfo
      61,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       5,       // signalCount

 // signals: name, argc, parameters, tag, flags, initial metatype offsets
       1,    0,  380,    2, 0x06,    1 /* Public */,
       3,    0,  381,    2, 0x06,    2 /* Public */,
       4,    0,  382,    2, 0x06,    3 /* Public */,
       5,    0,  383,    2, 0x06,    4 /* Public */,
       6,    0,  384,    2, 0x06,    5 /* Public */,

 // slots: name, argc, parameters, tag, flags, initial metatype offsets
       7,    0,  385,    2, 0x08,    6 /* Private */,
       8,    0,  386,    2, 0x08,    7 /* Private */,
       9,    0,  387,    2, 0x08,    8 /* Private */,
      10,    0,  388,    2, 0x08,    9 /* Private */,
      11,    0,  389,    2, 0x08,   10 /* Private */,
      12,    0,  390,    2, 0x08,   11 /* Private */,
      13,    0,  391,    2, 0x08,   12 /* Private */,
      14,    0,  392,    2, 0x08,   13 /* Private */,
      14,    1,  393,    2, 0x08,   14 /* Private */,
      16,    0,  396,    2, 0x08,   16 /* Private */,
      17,    0,  397,    2, 0x08,   17 /* Private */,
      18,    0,  398,    2, 0x08,   18 /* Private */,
      19,    0,  399,    2, 0x08,   19 /* Private */,
      20,    0,  400,    2, 0x08,   20 /* Private */,
      21,    0,  401,    2, 0x08,   21 /* Private */,
      22,    0,  402,    2, 0x08,   22 /* Private */,
      23,    0,  403,    2, 0x08,   23 /* Private */,
      24,    0,  404,    2, 0x08,   24 /* Private */,
      25,    0,  405,    2, 0x08,   25 /* Private */,
      26,    0,  406,    2, 0x08,   26 /* Private */,
      27,    1,  407,    2, 0x08,   27 /* Private */,
      30,    0,  410,    2, 0x08,   29 /* Private */,
      31,    1,  411,    2, 0x08,   30 /* Private */,
      33,    0,  414,    2, 0x08,   32 /* Private */,
      34,    0,  415,    2, 0x08,   33 /* Private */,
      35,    0,  416,    2, 0x08,   34 /* Private */,
      36,    0,  417,    2, 0x08,   35 /* Private */,
      37,    0,  418,    2, 0x08,   36 /* Private */,
      38,    0,  419,    2, 0x08,   37 /* Private */,
      39,    0,  420,    2, 0x08,   38 /* Private */,
      40,    0,  421,    2, 0x08,   39 /* Private */,
      40,    1,  422,    2, 0x08,   40 /* Private */,
      43,    0,  425,    2, 0x08,   42 /* Private */,
      44,    0,  426,    2, 0x08,   43 /* Private */,
      45,    0,  427,    2, 0x08,   44 /* Private */,
      46,    0,  428,    2, 0x08,   45 /* Private */,
      47,    0,  429,    2, 0x08,   46 /* Private */,
      48,    0,  430,    2, 0x08,   47 /* Private */,
      49,    0,  431,    2, 0x08,   48 /* Private */,
      50,    0,  432,    2, 0x08,   49 /* Private */,
      51,    0,  433,    2, 0x08,   50 /* Private */,
      52,    4,  434,    2, 0x08,   51 /* Private */,
      58,    1,  443,    2, 0x08,   56 /* Private */,
      60,    0,  446,    2, 0x08,   58 /* Private */,
      61,    0,  447,    2, 0x08,   59 /* Private */,
      62,    1,  448,    2, 0x08,   60 /* Private */,
      64,    2,  451,    2, 0x08,   62 /* Private */,
      68,    1,  456,    2, 0x08,   65 /* Private */,
      70,    1,  459,    2, 0x08,   67 /* Private */,
      72,    1,  462,    2, 0x08,   69 /* Private */,
      74,    1,  465,    2, 0x08,   71 /* Private */,
      75,    0,  468,    2, 0x08,   73 /* Private */,
      76,    0,  469,    2, 0x08,   74 /* Private */,
      77,    0,  470,    2, 0x08,   75 /* Private */,
      78,    0,  471,    2, 0x08,   76 /* Private */,
      79,    0,  472,    2, 0x08,   77 /* Private */,

 // signals: parameters
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,

 // slots: parameters
    QMetaType::Void,
    QMetaType::Bool,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void, QMetaType::Int,   15,
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
    QMetaType::Void, 0x80000000 | 28,   29,
    QMetaType::Void,
    QMetaType::QString, QMetaType::QByteArray,   32,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void, 0x80000000 | 41,   42,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    0x80000000 | 41, 0x80000000 | 53, QMetaType::QString, QMetaType::QString, QMetaType::QString,   54,   55,   56,   57,
    QMetaType::Bool, QMetaType::Int,   59,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void, QMetaType::QString,   63,
    QMetaType::Void, QMetaType::QStringList, 0x80000000 | 66,   65,   67,
    QMetaType::Void, QMetaType::QString,   69,
    QMetaType::Void, QMetaType::QString,   71,
    QMetaType::Void, QMetaType::QString,   73,
    QMetaType::Void, 0x80000000 | 28,   29,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,

       0        // eod
};

Q_CONSTINIT const QMetaObject Pat::staticMetaObject = { {
    QMetaObject::SuperData::link<QMainWindow::staticMetaObject>(),
    qt_meta_stringdata_CLASSPatENDCLASS.offsetsAndSizes,
    qt_meta_data_CLASSPatENDCLASS,
    qt_static_metacall,
    nullptr,
    qt_incomplete_metaTypeArray<qt_meta_stringdata_CLASSPatENDCLASS_t,
        // Q_OBJECT / Q_GADGET
        QtPrivate::TypeAndForceComplete<Pat, std::true_type>,
        // method 'switchToPersonnel'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        // method 'switchToAppointement'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        // method 'switchToEvents'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        // method 'switchToProd'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        // method 'switchToMicro'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        // method 'clearPatientForm'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        // method 'validateInputFields'
        QtPrivate::TypeAndForceComplete<bool, std::false_type>,
        // method 'savePatient'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        // method 'showRegistrationTab'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        // method 'searchPatients'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        // method 'sortPatients'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        // method 'exportPDF'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        // method 'editPatient'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        // method 'editPatient'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        QtPrivate::TypeAndForceComplete<int, std::false_type>,
        // method 'deletePatient'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        // method 'showHelp'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        // method 'showAbout'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        // method 'connectToDatabase'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        // method 'loadPatients'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        // method 'refreshPatients'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        // method 'refreshMedicalPatients'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        // method 'setupTableWidget'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        // method 'setupMedicalTableWidget'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        // method 'loadMedicalPatients'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        // method 'searchMedicalPatients'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        // method 'on_tableWidget_medical_patients_itemClicked'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        QtPrivate::TypeAndForceComplete<QTableWidgetItem *, std::false_type>,
        // method 'displayMedicalFile'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        // method 'formatJsonForDisplay'
        QtPrivate::TypeAndForceComplete<QString, std::false_type>,
        QtPrivate::TypeAndForceComplete<const QByteArray &, std::false_type>,
        // method 'updateMedicalFile'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        // method 'importMedicalFile'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        // method 'exportMedicalFile'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        // method 'on_pushButton_browse_clicked'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        // method 'on_pushButton_browse_photo_clicked'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        // method 'setupPhotoElements'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        // method 'setupCountryCodeComboBox'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        // method 'removePatientPredictionCard'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        // method 'removePatientPredictionCard'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        QtPrivate::TypeAndForceComplete<QWidget *, std::false_type>,
        // method 'setupStatisticsTab'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        // method 'updateStatistics'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        // method 'generateAgeStatistics'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        // method 'generateSexStatistics'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        // method 'sortStatisticsByAge'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        // method 'sortStatisticsBySex'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        // method 'updateStatisticsTable'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        // method 'createPredictionTab'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        // method 'predictRiskForSelectedPatient'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        // method 'createPredictionCard'
        QtPrivate::TypeAndForceComplete<QWidget *, std::false_type>,
        QtPrivate::TypeAndForceComplete<const Patient &, std::false_type>,
        QtPrivate::TypeAndForceComplete<const QString &, std::false_type>,
        QtPrivate::TypeAndForceComplete<const QString &, std::false_type>,
        QtPrivate::TypeAndForceComplete<const QString &, std::false_type>,
        // method 'patientPredictionExists'
        QtPrivate::TypeAndForceComplete<bool, std::false_type>,
        QtPrivate::TypeAndForceComplete<int, std::false_type>,
        // method 'createChatbotTab'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        // method 'sendChatbotMessage'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        // method 'displayChatbotResponse'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        QtPrivate::TypeAndForceComplete<const QString &, std::false_type>,
        // method 'displayQueryResults'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        QtPrivate::TypeAndForceComplete<const QStringList &, std::false_type>,
        QtPrivate::TypeAndForceComplete<const QList<QStringList> &, std::false_type>,
        // method 'handleChatbotError'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        QtPrivate::TypeAndForceComplete<const QString &, std::false_type>,
        // method 'handleDirectApiResponse'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        QtPrivate::TypeAndForceComplete<const QString &, std::false_type>,
        // method 'executeDirectSqlQuery'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        QtPrivate::TypeAndForceComplete<const QString &, std::false_type>,
        // method 'on_tableWidget_patients_itemDoubleClicked'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        QtPrivate::TypeAndForceComplete<QTableWidgetItem *, std::false_type>,
        // method 'on_microvacButton_clicked'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        // method 'on_personnelButton_clicked'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        // method 'on_inventoryButton_clicked'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        // method 'on_appointmentButton_clicked'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        // method 'on_eventButton_clicked'
        QtPrivate::TypeAndForceComplete<void, std::false_type>
    >,
    nullptr
} };

void Pat::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        auto *_t = static_cast<Pat *>(_o);
        (void)_t;
        switch (_id) {
        case 0: _t->switchToPersonnel(); break;
        case 1: _t->switchToAppointement(); break;
        case 2: _t->switchToEvents(); break;
        case 3: _t->switchToProd(); break;
        case 4: _t->switchToMicro(); break;
        case 5: _t->clearPatientForm(); break;
        case 6: { bool _r = _t->validateInputFields();
            if (_a[0]) *reinterpret_cast< bool*>(_a[0]) = std::move(_r); }  break;
        case 7: _t->savePatient(); break;
        case 8: _t->showRegistrationTab(); break;
        case 9: _t->searchPatients(); break;
        case 10: _t->sortPatients(); break;
        case 11: _t->exportPDF(); break;
        case 12: _t->editPatient(); break;
        case 13: _t->editPatient((*reinterpret_cast< std::add_pointer_t<int>>(_a[1]))); break;
        case 14: _t->deletePatient(); break;
        case 15: _t->showHelp(); break;
        case 16: _t->showAbout(); break;
        case 17: _t->connectToDatabase(); break;
        case 18: _t->loadPatients(); break;
        case 19: _t->refreshPatients(); break;
        case 20: _t->refreshMedicalPatients(); break;
        case 21: _t->setupTableWidget(); break;
        case 22: _t->setupMedicalTableWidget(); break;
        case 23: _t->loadMedicalPatients(); break;
        case 24: _t->searchMedicalPatients(); break;
        case 25: _t->on_tableWidget_medical_patients_itemClicked((*reinterpret_cast< std::add_pointer_t<QTableWidgetItem*>>(_a[1]))); break;
        case 26: _t->displayMedicalFile(); break;
        case 27: { QString _r = _t->formatJsonForDisplay((*reinterpret_cast< std::add_pointer_t<QByteArray>>(_a[1])));
            if (_a[0]) *reinterpret_cast< QString*>(_a[0]) = std::move(_r); }  break;
        case 28: _t->updateMedicalFile(); break;
        case 29: _t->importMedicalFile(); break;
        case 30: _t->exportMedicalFile(); break;
        case 31: _t->on_pushButton_browse_clicked(); break;
        case 32: _t->on_pushButton_browse_photo_clicked(); break;
        case 33: _t->setupPhotoElements(); break;
        case 34: _t->setupCountryCodeComboBox(); break;
        case 35: _t->removePatientPredictionCard(); break;
        case 36: _t->removePatientPredictionCard((*reinterpret_cast< std::add_pointer_t<QWidget*>>(_a[1]))); break;
        case 37: _t->setupStatisticsTab(); break;
        case 38: _t->updateStatistics(); break;
        case 39: _t->generateAgeStatistics(); break;
        case 40: _t->generateSexStatistics(); break;
        case 41: _t->sortStatisticsByAge(); break;
        case 42: _t->sortStatisticsBySex(); break;
        case 43: _t->updateStatisticsTable(); break;
        case 44: _t->createPredictionTab(); break;
        case 45: _t->predictRiskForSelectedPatient(); break;
        case 46: { QWidget* _r = _t->createPredictionCard((*reinterpret_cast< std::add_pointer_t<Patient>>(_a[1])),(*reinterpret_cast< std::add_pointer_t<QString>>(_a[2])),(*reinterpret_cast< std::add_pointer_t<QString>>(_a[3])),(*reinterpret_cast< std::add_pointer_t<QString>>(_a[4])));
            if (_a[0]) *reinterpret_cast< QWidget**>(_a[0]) = std::move(_r); }  break;
        case 47: { bool _r = _t->patientPredictionExists((*reinterpret_cast< std::add_pointer_t<int>>(_a[1])));
            if (_a[0]) *reinterpret_cast< bool*>(_a[0]) = std::move(_r); }  break;
        case 48: _t->createChatbotTab(); break;
        case 49: _t->sendChatbotMessage(); break;
        case 50: _t->displayChatbotResponse((*reinterpret_cast< std::add_pointer_t<QString>>(_a[1]))); break;
        case 51: _t->displayQueryResults((*reinterpret_cast< std::add_pointer_t<QStringList>>(_a[1])),(*reinterpret_cast< std::add_pointer_t<QList<QStringList>>>(_a[2]))); break;
        case 52: _t->handleChatbotError((*reinterpret_cast< std::add_pointer_t<QString>>(_a[1]))); break;
        case 53: _t->handleDirectApiResponse((*reinterpret_cast< std::add_pointer_t<QString>>(_a[1]))); break;
        case 54: _t->executeDirectSqlQuery((*reinterpret_cast< std::add_pointer_t<QString>>(_a[1]))); break;
        case 55: _t->on_tableWidget_patients_itemDoubleClicked((*reinterpret_cast< std::add_pointer_t<QTableWidgetItem*>>(_a[1]))); break;
        case 56: _t->on_microvacButton_clicked(); break;
        case 57: _t->on_personnelButton_clicked(); break;
        case 58: _t->on_inventoryButton_clicked(); break;
        case 59: _t->on_appointmentButton_clicked(); break;
        case 60: _t->on_eventButton_clicked(); break;
        default: ;
        }
    } else if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        switch (_id) {
        default: *reinterpret_cast<QMetaType *>(_a[0]) = QMetaType(); break;
        case 36:
            switch (*reinterpret_cast<int*>(_a[1])) {
            default: *reinterpret_cast<QMetaType *>(_a[0]) = QMetaType(); break;
            case 0:
                *reinterpret_cast<QMetaType *>(_a[0]) = QMetaType::fromType< QWidget* >(); break;
            }
            break;
        case 51:
            switch (*reinterpret_cast<int*>(_a[1])) {
            default: *reinterpret_cast<QMetaType *>(_a[0]) = QMetaType(); break;
            case 1:
                *reinterpret_cast<QMetaType *>(_a[0]) = QMetaType::fromType< QList<QStringList> >(); break;
            }
            break;
        }
    } else if (_c == QMetaObject::IndexOfMethod) {
        int *result = reinterpret_cast<int *>(_a[0]);
        {
            using _t = void (Pat::*)();
            if (_t _q_method = &Pat::switchToPersonnel; *reinterpret_cast<_t *>(_a[1]) == _q_method) {
                *result = 0;
                return;
            }
        }
        {
            using _t = void (Pat::*)();
            if (_t _q_method = &Pat::switchToAppointement; *reinterpret_cast<_t *>(_a[1]) == _q_method) {
                *result = 1;
                return;
            }
        }
        {
            using _t = void (Pat::*)();
            if (_t _q_method = &Pat::switchToEvents; *reinterpret_cast<_t *>(_a[1]) == _q_method) {
                *result = 2;
                return;
            }
        }
        {
            using _t = void (Pat::*)();
            if (_t _q_method = &Pat::switchToProd; *reinterpret_cast<_t *>(_a[1]) == _q_method) {
                *result = 3;
                return;
            }
        }
        {
            using _t = void (Pat::*)();
            if (_t _q_method = &Pat::switchToMicro; *reinterpret_cast<_t *>(_a[1]) == _q_method) {
                *result = 4;
                return;
            }
        }
    }
}

const QMetaObject *Pat::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *Pat::qt_metacast(const char *_clname)
{
    if (!_clname) return nullptr;
    if (!strcmp(_clname, qt_meta_stringdata_CLASSPatENDCLASS.stringdata0))
        return static_cast<void*>(this);
    return QMainWindow::qt_metacast(_clname);
}

int Pat::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QMainWindow::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        if (_id < 61)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 61;
    } else if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        if (_id < 61)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 61;
    }
    return _id;
}

// SIGNAL 0
void Pat::switchToPersonnel()
{
    QMetaObject::activate(this, &staticMetaObject, 0, nullptr);
}

// SIGNAL 1
void Pat::switchToAppointement()
{
    QMetaObject::activate(this, &staticMetaObject, 1, nullptr);
}

// SIGNAL 2
void Pat::switchToEvents()
{
    QMetaObject::activate(this, &staticMetaObject, 2, nullptr);
}

// SIGNAL 3
void Pat::switchToProd()
{
    QMetaObject::activate(this, &staticMetaObject, 3, nullptr);
}

// SIGNAL 4
void Pat::switchToMicro()
{
    QMetaObject::activate(this, &staticMetaObject, 4, nullptr);
}
QT_WARNING_POP
