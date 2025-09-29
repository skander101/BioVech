/****************************************************************************
** Meta object code from reading C++ file 'cameradialog.h'
**
** Created by: The Qt Meta Object Compiler version 68 (Qt 6.7.3)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "../../../cameradialog.h"
#include <QtGui/qtextcursor.h>
#include <QtCore/qmetatype.h>

#include <QtCore/qtmochelpers.h>

#include <memory>


#include <QtCore/qxptype_traits.h>
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'cameradialog.h' doesn't include <QObject>."
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
struct qt_meta_stringdata_CLASSCameraDialogENDCLASS_t {};
constexpr auto qt_meta_stringdata_CLASSCameraDialogENDCLASS = QtMocHelpers::stringData(
    "CameraDialog",
    "barcodeDetected",
    "",
    "barcode",
    "imageCaptured",
    "image",
    "textDetected",
    "text",
    "processImage",
    "id",
    "on_captureButton_clicked",
    "on_cameraComboBox_currentIndexChanged",
    "index",
    "on_settingsButton_clicked",
    "setupOV7670UI",
    "onOV7670ConnectClicked",
    "onOV7670DisconnectClicked",
    "onOV7670RefreshPortsClicked",
    "onOV7670SendCommandClicked",
    "onOV7670ClearLogClicked",
    "onOV7670FrameReceived",
    "frame",
    "onOV7670ConnectionStatusChanged",
    "connected",
    "onOV7670ErrorOccurred",
    "message",
    "onOV7670LogMessage",
    "launchArduImageCapture",
    "installArduImageCaptureToProject",
    "selectCustomJarFile",
    "captureOV7670Image",
    "setupArduImageCaptureWatcher",
    "onDirectoryChanged",
    "path",
    "onFileChanged",
    "checkForNewCapturedImages",
    "importCapturedImage",
    "imagePath",
    "completeImageImport",
    "pixmap",
    "setupArduImageWatcher",
    "checkForNewImages",
    "processNewImage",
    "addCaptureDirectoryButton",
    "importImagesFromFolder",
    "loadLastImageFromSavedPics"
);
#else  // !QT_MOC_HAS_STRINGDATA
#error "qtmochelpers.h not found or too old."
#endif // !QT_MOC_HAS_STRINGDATA
} // unnamed namespace

Q_CONSTINIT static const uint qt_meta_data_CLASSCameraDialogENDCLASS[] = {

 // content:
      12,       // revision
       0,       // classname
       0,    0, // classinfo
      33,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       3,       // signalCount

 // signals: name, argc, parameters, tag, flags, initial metatype offsets
       1,    1,  212,    2, 0x06,    1 /* Public */,
       4,    1,  215,    2, 0x06,    3 /* Public */,
       6,    1,  218,    2, 0x06,    5 /* Public */,

 // slots: name, argc, parameters, tag, flags, initial metatype offsets
       8,    2,  221,    2, 0x08,    7 /* Private */,
      10,    0,  226,    2, 0x08,   10 /* Private */,
      11,    1,  227,    2, 0x08,   11 /* Private */,
      13,    0,  230,    2, 0x08,   13 /* Private */,
      14,    0,  231,    2, 0x08,   14 /* Private */,
      15,    0,  232,    2, 0x08,   15 /* Private */,
      16,    0,  233,    2, 0x08,   16 /* Private */,
      17,    0,  234,    2, 0x08,   17 /* Private */,
      18,    0,  235,    2, 0x08,   18 /* Private */,
      19,    0,  236,    2, 0x08,   19 /* Private */,
      20,    1,  237,    2, 0x08,   20 /* Private */,
      22,    1,  240,    2, 0x08,   22 /* Private */,
      24,    1,  243,    2, 0x08,   24 /* Private */,
      26,    1,  246,    2, 0x08,   26 /* Private */,
      27,    0,  249,    2, 0x08,   28 /* Private */,
      28,    0,  250,    2, 0x08,   29 /* Private */,
      29,    0,  251,    2, 0x08,   30 /* Private */,
      30,    0,  252,    2, 0x08,   31 /* Private */,
      31,    0,  253,    2, 0x08,   32 /* Private */,
      32,    1,  254,    2, 0x08,   33 /* Private */,
      34,    1,  257,    2, 0x08,   35 /* Private */,
      35,    0,  260,    2, 0x08,   37 /* Private */,
      36,    1,  261,    2, 0x08,   38 /* Private */,
      38,    3,  264,    2, 0x08,   40 /* Private */,
      40,    0,  271,    2, 0x08,   44 /* Private */,
      41,    0,  272,    2, 0x08,   45 /* Private */,
      42,    1,  273,    2, 0x08,   46 /* Private */,
      43,    0,  276,    2, 0x08,   48 /* Private */,
      44,    0,  277,    2, 0x08,   49 /* Private */,
      45,    0,  278,    2, 0x08,   50 /* Private */,

 // signals: parameters
    QMetaType::Void, QMetaType::QString,    3,
    QMetaType::Void, QMetaType::QImage,    5,
    QMetaType::Void, QMetaType::QString,    7,

 // slots: parameters
    QMetaType::Void, QMetaType::Int, QMetaType::QImage,    9,    5,
    QMetaType::Void,
    QMetaType::Void, QMetaType::Int,   12,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void, QMetaType::QPixmap,   21,
    QMetaType::Void, QMetaType::Bool,   23,
    QMetaType::Void, QMetaType::QString,   25,
    QMetaType::Void, QMetaType::QString,   25,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void, QMetaType::QString,   33,
    QMetaType::Void, QMetaType::QString,   33,
    QMetaType::Void,
    QMetaType::Void, QMetaType::QString,   37,
    QMetaType::Void, QMetaType::QImage, QMetaType::QString, QMetaType::QPixmap,    5,   37,   39,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void, QMetaType::QString,   37,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,

       0        // eod
};

Q_CONSTINIT const QMetaObject CameraDialog::staticMetaObject = { {
    QMetaObject::SuperData::link<QDialog::staticMetaObject>(),
    qt_meta_stringdata_CLASSCameraDialogENDCLASS.offsetsAndSizes,
    qt_meta_data_CLASSCameraDialogENDCLASS,
    qt_static_metacall,
    nullptr,
    qt_incomplete_metaTypeArray<qt_meta_stringdata_CLASSCameraDialogENDCLASS_t,
        // Q_OBJECT / Q_GADGET
        QtPrivate::TypeAndForceComplete<CameraDialog, std::true_type>,
        // method 'barcodeDetected'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        QtPrivate::TypeAndForceComplete<const QString &, std::false_type>,
        // method 'imageCaptured'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        QtPrivate::TypeAndForceComplete<const QImage &, std::false_type>,
        // method 'textDetected'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        QtPrivate::TypeAndForceComplete<const QString &, std::false_type>,
        // method 'processImage'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        QtPrivate::TypeAndForceComplete<int, std::false_type>,
        QtPrivate::TypeAndForceComplete<const QImage &, std::false_type>,
        // method 'on_captureButton_clicked'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        // method 'on_cameraComboBox_currentIndexChanged'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        QtPrivate::TypeAndForceComplete<int, std::false_type>,
        // method 'on_settingsButton_clicked'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        // method 'setupOV7670UI'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        // method 'onOV7670ConnectClicked'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        // method 'onOV7670DisconnectClicked'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        // method 'onOV7670RefreshPortsClicked'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        // method 'onOV7670SendCommandClicked'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        // method 'onOV7670ClearLogClicked'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        // method 'onOV7670FrameReceived'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        QtPrivate::TypeAndForceComplete<const QPixmap &, std::false_type>,
        // method 'onOV7670ConnectionStatusChanged'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        QtPrivate::TypeAndForceComplete<bool, std::false_type>,
        // method 'onOV7670ErrorOccurred'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        QtPrivate::TypeAndForceComplete<const QString &, std::false_type>,
        // method 'onOV7670LogMessage'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        QtPrivate::TypeAndForceComplete<const QString &, std::false_type>,
        // method 'launchArduImageCapture'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        // method 'installArduImageCaptureToProject'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        // method 'selectCustomJarFile'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        // method 'captureOV7670Image'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        // method 'setupArduImageCaptureWatcher'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        // method 'onDirectoryChanged'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        QtPrivate::TypeAndForceComplete<const QString &, std::false_type>,
        // method 'onFileChanged'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        QtPrivate::TypeAndForceComplete<const QString &, std::false_type>,
        // method 'checkForNewCapturedImages'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        // method 'importCapturedImage'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        QtPrivate::TypeAndForceComplete<const QString &, std::false_type>,
        // method 'completeImageImport'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        QtPrivate::TypeAndForceComplete<const QImage &, std::false_type>,
        QtPrivate::TypeAndForceComplete<const QString &, std::false_type>,
        QtPrivate::TypeAndForceComplete<const QPixmap &, std::false_type>,
        // method 'setupArduImageWatcher'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        // method 'checkForNewImages'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        // method 'processNewImage'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        QtPrivate::TypeAndForceComplete<const QString &, std::false_type>,
        // method 'addCaptureDirectoryButton'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        // method 'importImagesFromFolder'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        // method 'loadLastImageFromSavedPics'
        QtPrivate::TypeAndForceComplete<void, std::false_type>
    >,
    nullptr
} };

void CameraDialog::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        auto *_t = static_cast<CameraDialog *>(_o);
        (void)_t;
        switch (_id) {
        case 0: _t->barcodeDetected((*reinterpret_cast< std::add_pointer_t<QString>>(_a[1]))); break;
        case 1: _t->imageCaptured((*reinterpret_cast< std::add_pointer_t<QImage>>(_a[1]))); break;
        case 2: _t->textDetected((*reinterpret_cast< std::add_pointer_t<QString>>(_a[1]))); break;
        case 3: _t->processImage((*reinterpret_cast< std::add_pointer_t<int>>(_a[1])),(*reinterpret_cast< std::add_pointer_t<QImage>>(_a[2]))); break;
        case 4: _t->on_captureButton_clicked(); break;
        case 5: _t->on_cameraComboBox_currentIndexChanged((*reinterpret_cast< std::add_pointer_t<int>>(_a[1]))); break;
        case 6: _t->on_settingsButton_clicked(); break;
        case 7: _t->setupOV7670UI(); break;
        case 8: _t->onOV7670ConnectClicked(); break;
        case 9: _t->onOV7670DisconnectClicked(); break;
        case 10: _t->onOV7670RefreshPortsClicked(); break;
        case 11: _t->onOV7670SendCommandClicked(); break;
        case 12: _t->onOV7670ClearLogClicked(); break;
        case 13: _t->onOV7670FrameReceived((*reinterpret_cast< std::add_pointer_t<QPixmap>>(_a[1]))); break;
        case 14: _t->onOV7670ConnectionStatusChanged((*reinterpret_cast< std::add_pointer_t<bool>>(_a[1]))); break;
        case 15: _t->onOV7670ErrorOccurred((*reinterpret_cast< std::add_pointer_t<QString>>(_a[1]))); break;
        case 16: _t->onOV7670LogMessage((*reinterpret_cast< std::add_pointer_t<QString>>(_a[1]))); break;
        case 17: _t->launchArduImageCapture(); break;
        case 18: _t->installArduImageCaptureToProject(); break;
        case 19: _t->selectCustomJarFile(); break;
        case 20: _t->captureOV7670Image(); break;
        case 21: _t->setupArduImageCaptureWatcher(); break;
        case 22: _t->onDirectoryChanged((*reinterpret_cast< std::add_pointer_t<QString>>(_a[1]))); break;
        case 23: _t->onFileChanged((*reinterpret_cast< std::add_pointer_t<QString>>(_a[1]))); break;
        case 24: _t->checkForNewCapturedImages(); break;
        case 25: _t->importCapturedImage((*reinterpret_cast< std::add_pointer_t<QString>>(_a[1]))); break;
        case 26: _t->completeImageImport((*reinterpret_cast< std::add_pointer_t<QImage>>(_a[1])),(*reinterpret_cast< std::add_pointer_t<QString>>(_a[2])),(*reinterpret_cast< std::add_pointer_t<QPixmap>>(_a[3]))); break;
        case 27: _t->setupArduImageWatcher(); break;
        case 28: _t->checkForNewImages(); break;
        case 29: _t->processNewImage((*reinterpret_cast< std::add_pointer_t<QString>>(_a[1]))); break;
        case 30: _t->addCaptureDirectoryButton(); break;
        case 31: _t->importImagesFromFolder(); break;
        case 32: _t->loadLastImageFromSavedPics(); break;
        default: ;
        }
    } else if (_c == QMetaObject::IndexOfMethod) {
        int *result = reinterpret_cast<int *>(_a[0]);
        {
            using _t = void (CameraDialog::*)(const QString & );
            if (_t _q_method = &CameraDialog::barcodeDetected; *reinterpret_cast<_t *>(_a[1]) == _q_method) {
                *result = 0;
                return;
            }
        }
        {
            using _t = void (CameraDialog::*)(const QImage & );
            if (_t _q_method = &CameraDialog::imageCaptured; *reinterpret_cast<_t *>(_a[1]) == _q_method) {
                *result = 1;
                return;
            }
        }
        {
            using _t = void (CameraDialog::*)(const QString & );
            if (_t _q_method = &CameraDialog::textDetected; *reinterpret_cast<_t *>(_a[1]) == _q_method) {
                *result = 2;
                return;
            }
        }
    }
}

const QMetaObject *CameraDialog::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *CameraDialog::qt_metacast(const char *_clname)
{
    if (!_clname) return nullptr;
    if (!strcmp(_clname, qt_meta_stringdata_CLASSCameraDialogENDCLASS.stringdata0))
        return static_cast<void*>(this);
    return QDialog::qt_metacast(_clname);
}

int CameraDialog::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QDialog::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        if (_id < 33)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 33;
    } else if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        if (_id < 33)
            *reinterpret_cast<QMetaType *>(_a[0]) = QMetaType();
        _id -= 33;
    }
    return _id;
}

// SIGNAL 0
void CameraDialog::barcodeDetected(const QString & _t1)
{
    void *_a[] = { nullptr, const_cast<void*>(reinterpret_cast<const void*>(std::addressof(_t1))) };
    QMetaObject::activate(this, &staticMetaObject, 0, _a);
}

// SIGNAL 1
void CameraDialog::imageCaptured(const QImage & _t1)
{
    void *_a[] = { nullptr, const_cast<void*>(reinterpret_cast<const void*>(std::addressof(_t1))) };
    QMetaObject::activate(this, &staticMetaObject, 1, _a);
}

// SIGNAL 2
void CameraDialog::textDetected(const QString & _t1)
{
    void *_a[] = { nullptr, const_cast<void*>(reinterpret_cast<const void*>(std::addressof(_t1))) };
    QMetaObject::activate(this, &staticMetaObject, 2, _a);
}
QT_WARNING_POP
