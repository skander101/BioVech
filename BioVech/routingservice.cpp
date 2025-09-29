#include "routingservice.h"
#include <QGeoCoordinate>

RoutingService::RoutingService(QObject *parent) : QObject(parent) {
    manager = new QNetworkAccessManager(this);
    connect(manager, &QNetworkAccessManager::finished, this, &RoutingService::onRouteReply);
}

void RoutingService::getRoute(double startLat, double startLon, double endLat, double endLon) {
    QString url = QString("https://api.openrouteservice.org/v2/directions/driving-car?api_key=%1&start=%2,%3&end=%4,%5")
    .arg(apiKey)
        .arg(startLon).arg(startLat)
        .arg(endLon).arg(endLat);

    manager->get(QNetworkRequest(QUrl(url)));
}

void RoutingService::onRouteReply(QNetworkReply* reply) {
    QList<QGeoCoordinate> route;

    if (reply->error() == QNetworkReply::NoError) {
        QJsonDocument doc = QJsonDocument::fromJson(reply->readAll());
        QJsonArray coordinates = doc.object()["features"]
                                     .toArray()[0].toObject()["geometry"]
                                     .toObject()["coordinates"].toArray();

        for (const QJsonValue& coord : coordinates) {
            QJsonArray point = coord.toArray();
            route.append(QGeoCoordinate(point[1].toDouble(), point[0].toDouble()));
        }
    }

    emit routeReceived(route);
    reply->deleteLater();
}
