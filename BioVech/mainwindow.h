#ifndef MAINWINDOW_H
#define MAINWINDOW_H
#include "Evenement.h"
#include "Connection.h"
#include "openlocationcode.h"
#include "Dialogue.h"
#include "routingservice.h"
#include <QMainWindow>
#include <QVariant>
#include <QtCore>
#include <QtGui>
#include <QtQuick>
#include <QQuickWidget>
#include <QMessageBox>
#include <QFileDialog>
#include <QSqlQuery>
#include <QDate>
#include <QPrinter>
#include <QPainter>
#include <QtCharts>
#include <QChartView>
#include <QChart>
#include <QPdfWriter>
#include <QPieSeries>
#include <QBarSeries>
#include <QtLocation/QGeoServiceProvider>
#include <QtLocation/QGeoRoutingManager>
#include <QGeoRouteReply>
#include <QGeoServiceProvider>
#include <QGeoRoutingManager>
#include <QGeoCoordinate>
#include <QSerialPort>
#include <QSerialPortInfo>
QT_BEGIN_NAMESPACE
namespace Ui {
class MainWindow;
}
QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
    Q_OBJECT
    Q_PROPERTY(double latitude READ latitude WRITE setLatitude NOTIFY latitudeChanged)
    Q_PROPERTY(double longitude READ longitude WRITE setLongitude NOTIFY longitudeChanged)
    Q_PROPERTY(QString locationName READ locationName WRITE setLocationName NOTIFY locationNameChanged)

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();
    bool locationAlreadySelected;
    QDialog* locationDialog = nullptr;
    // Getters
    double latitude() const;
    double longitude() const;
    QString locationName() const;

    // Setters
    void setLatitude(double latitude);
    void setLongitude(double longitude);
    void setLocationName(const QString &name);
    void refresh_table();
    void update_table(const QList<QStringList>&);
    bool Control(const QString&,const QString&,const QString&,const QDate&,const QString&,const QString&);
    void onDialogueFinished(int result);
    void resetLocationSelection();
    void resetEventsDialog();
    void resetEventsNotification();
    void clearInputFields();

public slots:
    void showRouteToNearestEvent(double userLat, double userLng, const QList<QStringList>& allEvents);
    //void onRouteReceived(const QList<QGeoCoordinate>& route);
    //void updateRoute(const QVariantList &coordinates);






    // Method to center the map
    Q_INVOKABLE void setCenter(double latitude, double longitude);

    // Method to add a marker
    Q_INVOKABLE void setLocationMarking(double latitude, double longitude, const QString &name);
    
    // Method to handle map clicks from QML
    Q_INVOKABLE void handleMapClick(double latitude, double longitude);
    // Method to add a marker to the map
    Q_INVOKABLE void addMarker(double latitude, double longitude, const QString &name);

    // Method to get user's location for suggestions
    void getUserLocation();
    
    // Method to find and display nearby events
    void showNearbyEvents(double latitude, double longitude, double radius);
    void addCustomMarker(double latitude, double longitude, const QString &name, const QString &type);
    void setLMarking(double latitude, double longitude, const QString &name);
    void readSerial();
    void sendFirstEventToArduino();

signals:
    void latitudeChanged();
    void longitudeChanged();
    void locationNameChanged();
    void centerChanged(double latitude, double longitude);
    void locationMarkingChanged(double latitude, double longitude, const QString &name);
    void requestRoute(double startLat, double startLon, double endLat, double endLon);


private slots:
    void on_Button_Vac_pressed();
    void on_Button_Staff_pressed();
    void on_Button_Inventory_pressed();
    void on_Button_Events_pressed();
    void on_Button_Appoitment_pressed();
    void on_Button_Analytics_pressed();
    void on_Button_Analytics_clicked();
    void on_Button_Patient_pressed();
    void on_pushButton_5_clicked();
    void on_Add_Event_clicked();
    void on_Save_Add_clicked();
    void on_Delete_Event_clicked();
    void on_Modify_Event_clicked();
    void on_tableWidget_cellClicked(int row, int column);
    void on_Cancel_Modify_clicked();
    void on_comboBox_currentTextChanged(const QString &arg1);
    void on_Search_Button_clicked();
    void on_pdf_Button_clicked();
    void on_Suggestions_Button_clicked();
    void on_mapClicked_Add();
    void on_mapClicked_Suggest();
    void onTabChanged(int index);
    void on_positionMapButton_clicked();
    void on_updatePositionMapButton_clicked();
    void initializeSerialPortWrite();
    void initializeSerialPortRead(QString port);
    void processSerialData(const QString &data);
    void decreaseEventQuantity(int id);
    void on_Search_Button_2_clicked();

    void on_LCD_clicked();

    void on_Stat_Event_clicked();

private:
    Ui::MainWindow *ui;
    double m_userLatitude = 36.8065;  // Default location (Tunisia)
    double m_userLongitude = 10.1815; // Default location (Tunisia)
    QString m_locationName;
    Evenement Etmp;
    QString selectedIdEv;
    const QString DBpath=QCoreApplication::applicationDirPath()+"/BD_HOSPITAL.db";
    int lastIdUsed = 0;
    bool Control();
    void centerMapOnEventLocation(const QString &plusCode);
    double getUserLatitude() const;
    double getUserLongitude() const;
    void readData();
    void displayLcd();

    
    // Add quickWidget_Add as a class member
    QQuickWidget *quickWidget_Add;
    
    // Helper to generate PlusCode from coordinates
    QString generatePlusCode(double latitude, double longitude);
    
    // Flag to determine which map click handler to use
    bool mapForAddEvent;
    
    // Map dialog for position selection
    QDialog *mapDialog = nullptr;
    void showPositionMapDialog(bool forUpdate = false);
    
    // New method to show map in main tab
    void showMapInMainTab();
    bool mainLocationSet=false;
    QGeoCoordinate m_userLocation;
    QGeoCoordinate m_nearestEvent;
    double m_nearestDistance;
    RoutingService *routingService;
    QSerialPort* serial,serialLcd;
    static const quint16 arduino_uno_vendor_id = 9025;
    static const quint16 arduino_uno_product_id = 67;
    QString arduino_port_name;
    bool arduino_is_available;
    QString serialBuffer;
    QByteArray serialData;
    QTextEdit* ArduinoText;


};

#endif // MAINWINDOW_H
