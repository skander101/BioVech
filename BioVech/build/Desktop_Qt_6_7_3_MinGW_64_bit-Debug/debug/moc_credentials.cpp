/****************************************************************************
** Meta object code from reading C++ file 'credentials.h'
**
** Created by: The Qt Meta Object Compiler version 68 (Qt 6.7.3)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "../../../credentials.h"
#include <QtGui/qtextcursor.h>
#include <QtCore/qmetatype.h>

#include <QtCore/qtmochelpers.h>

#include <memory>


#include <QtCore/qxptype_traits.h>
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'credentials.h' doesn't include <QObject>."
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
struct qt_meta_stringdata_CLASScredentialsENDCLASS_t {};
constexpr auto qt_meta_stringdata_CLASScredentialsENDCLASS = QtMocHelpers::stringData(
    "credentials",
    "switchToPersonnel",
    "",
    "switch_to_login",
    "switch_to_create_account",
    "create_account",
    "login",
    "startSpeechRecognition",
    "loadAvailableMicrophones",
    "onMicrophoneSelected",
    "index",
    "processSpeechResult",
    "processSpeechError",
    "handleSpeechOutput",
    "on_cinButton_clicked",
    "on_passwordButton_clicked",
    "on_cameraButton_clicked",
    "on_cameraButton2_clicked",
    "on_create_account_button_clicked",
    "on_Log_in_button_clicked",
    "on_switch_login_butt_clicked",
    "on_switch_create_account_button_clicked",
    "startCamera",
    "cameraId",
    "stopCamera",
    "captureImage",
    "handleCameraError",
    "QCamera::Error",
    "error",
    "errorString",
    "detectFaceInViewfinder",
    "on_skipbutton_clicked"
);
#else  // !QT_MOC_HAS_STRINGDATA
#error "qtmochelpers.h not found or too old."
#endif // !QT_MOC_HAS_STRINGDATA
} // unnamed namespace

Q_CONSTINIT static const uint qt_meta_data_CLASScredentialsENDCLASS[] = {

 // content:
      12,       // revision
       0,       // classname
       0,    0, // classinfo
      26,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       1,       // signalCount

 // signals: name, argc, parameters, tag, flags, initial metatype offsets
       1,    0,  170,    2, 0x06,    1 /* Public */,

 // slots: name, argc, parameters, tag, flags, initial metatype offsets
       3,    0,  171,    2, 0x08,    2 /* Private */,
       4,    0,  172,    2, 0x08,    3 /* Private */,
       5,    0,  173,    2, 0x08,    4 /* Private */,
       6,    0,  174,    2, 0x08,    5 /* Private */,
       7,    0,  175,    2, 0x08,    6 /* Private */,
       8,    0,  176,    2, 0x08,    7 /* Private */,
       9,    1,  177,    2, 0x08,    8 /* Private */,
      11,    0,  180,    2, 0x08,   10 /* Private */,
      12,    0,  181,    2, 0x08,   11 /* Private */,
      13,    0,  182,    2, 0x08,   12 /* Private */,
      14,    0,  183,    2, 0x08,   13 /* Private */,
      15,    0,  184,    2, 0x08,   14 /* Private */,
      16,    0,  185,    2, 0x08,   15 /* Private */,
      17,    0,  186,    2, 0x08,   16 /* Private */,
      18,    0,  187,    2, 0x08,   17 /* Private */,
      19,    0,  188,    2, 0x08,   18 /* Private */,
      20,    0,  189,    2, 0x08,   19 /* Private */,
      21,    0,  190,    2, 0x08,   20 /* Private */,
      22,    1,  191,    2, 0x08,   21 /* Private */,
      22,    0,  194,    2, 0x28,   23 /* Private | MethodCloned */,
      24,    0,  195,    2, 0x08,   24 /* Private */,
      25,    0,  196,    2, 0x08,   25 /* Private */,
      26,    2,  197,    2, 0x08,   26 /* Private */,
      30,    0,  202,    2, 0x08,   29 /* Private */,
      31,    0,  203,    2, 0x08,   30 /* Private */,

 // signals: parameters
    QMetaType::Void,

 // slots: parameters
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void, QMetaType::Int,   10,
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
    QMetaType::Void, QMetaType::QByteArray,   23,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void, 0x80000000 | 27, QMetaType::QString,   28,   29,
    QMetaType::Void,
    QMetaType::Void,

       0        // eod
};

Q_CONSTINIT const QMetaObject credentials::staticMetaObject = { {
    QMetaObject::SuperData::link<QWidget::staticMetaObject>(),
    qt_meta_stringdata_CLASScredentialsENDCLASS.offsetsAndSizes,
    qt_meta_data_CLASScredentialsENDCLASS,
    qt_static_metacall,
    nullptr,
    qt_incomplete_metaTypeArray<qt_meta_stringdata_CLASScredentialsENDCLASS_t,
        // Q_OBJECT / Q_GADGET
        QtPrivate::TypeAndForceComplete<credentials, std::true_type>,
        // method 'switchToPersonnel'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        // method 'switch_to_login'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        // method 'switch_to_create_account'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        // method 'create_account'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        // method 'login'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        // method 'startSpeechRecognition'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        // method 'loadAvailableMicrophones'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        // method 'onMicrophoneSelected'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        QtPrivate::TypeAndForceComplete<int, std::false_type>,
        // method 'processSpeechResult'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        // method 'processSpeechError'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        // method 'handleSpeechOutput'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        // method 'on_cinButton_clicked'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        // method 'on_passwordButton_clicked'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        // method 'on_cameraButton_clicked'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        // method 'on_cameraButton2_clicked'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        // method 'on_create_account_button_clicked'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        // method 'on_Log_in_button_clicked'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        // method 'on_switch_login_butt_clicked'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        // method 'on_switch_create_account_button_clicked'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
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
        // method 'on_skipbutton_clicked'
        QtPrivate::TypeAndForceComplete<void, std::false_type>
    >,
    nullptr
} };

void credentials::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        auto *_t = static_cast<credentials *>(_o);
        (void)_t;
        switch (_id) {
        case 0: _t->switchToPersonnel(); break;
        case 1: _t->switch_to_login(); break;
        case 2: _t->switch_to_create_account(); break;
        case 3: _t->create_account(); break;
        case 4: _t->login(); break;
        case 5: _t->startSpeechRecognition(); break;
        case 6: _t->loadAvailableMicrophones(); break;
        case 7: _t->onMicrophoneSelected((*reinterpret_cast< std::add_pointer_t<int>>(_a[1]))); break;
        case 8: _t->processSpeechResult(); break;
        case 9: _t->processSpeechError(); break;
        case 10: _t->handleSpeechOutput(); break;
        case 11: _t->on_cinButton_clicked(); break;
        case 12: _t->on_passwordButton_clicked(); break;
        case 13: _t->on_cameraButton_clicked(); break;
        case 14: _t->on_cameraButton2_clicked(); break;
        case 15: _t->on_create_account_button_clicked(); break;
        case 16: _t->on_Log_in_button_clicked(); break;
        case 17: _t->on_switch_login_butt_clicked(); break;
        case 18: _t->on_switch_create_account_button_clicked(); break;
        case 19: _t->startCamera((*reinterpret_cast< std::add_pointer_t<QByteArray>>(_a[1]))); break;
        case 20: _t->startCamera(); break;
        case 21: _t->stopCamera(); break;
        case 22: _t->captureImage(); break;
        case 23: _t->handleCameraError((*reinterpret_cast< std::add_pointer_t<QCamera::Error>>(_a[1])),(*reinterpret_cast< std::add_pointer_t<QString>>(_a[2]))); break;
        case 24: _t->detectFaceInViewfinder(); break;
        case 25: _t->on_skipbutton_clicked(); break;
        default: ;
        }
    } else if (_c == QMetaObject::IndexOfMethod) {
        int *result = reinterpret_cast<int *>(_a[0]);
        {
            using _t = void (credentials::*)();
            if (_t _q_method = &credentials::switchToPersonnel; *reinterpret_cast<_t *>(_a[1]) == _q_method) {
                *result = 0;
                return;
            }
        }
    }
}

const QMetaObject *credentials::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *credentials::qt_metacast(const char *_clname)
{
    if (!_clname) return nullptr;
    if (!strcmp(_clname, qt_meta_stringdata_CLASScredentialsENDCLASS.stringdata0))
        return static_cast<void*>(this);
    return QWidget::qt_metacast(_clname);
}

int credentials::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QWidget::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        if (_id < 26)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 26;
    } else if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        if (_id < 26)
            *reinterpret_cast<QMetaType *>(_a[0]) = QMetaType();
        _id -= 26;
    }
    return _id;
}

// SIGNAL 0
void credentials::switchToPersonnel()
{
    QMetaObject::activate(this, &staticMetaObject, 0, nullptr);
}
QT_WARNING_POP
