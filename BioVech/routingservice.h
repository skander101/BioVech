#include <QObject>
#include <QNetworkAccessManager>
#include <QNetworkReply>
#include <QJsonDocument>
#include <QJsonObject>
#include <QJsonArray>
#include <QGeoCoordinate>

class RoutingService : public QObject {
    Q_OBJECT
public:
    explicit RoutingService(QObject *parent = nullptr);
    void getRoute(double startLat, double startLon, double endLat, double endLon);

signals:
    void routeReceived(const QList<QGeoCoordinate>& route);

private slots:
    void onRouteReply(QNetworkReply* reply);

private:
    QNetworkAccessManager *manager;
    QString apiKey = "5b3ce3597851110001cf62486950f77f72dd4634b458f176f2aaea94"; // Obtenez une clé gratuite sur openrouteservice.org
};
