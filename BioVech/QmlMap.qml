import QtQuick 2.15
import QtLocation 6.7
import QtPositioning 6.7

Rectangle {
    id: window
    width: 800
    height: 600

    // Plugin OpenStreetMap
    Plugin {
        id: osmPlugin
        name: "osm"
    }

    Map {
        id: mapview
        anchors.fill: parent
        plugin: osmPlugin
        center: QtPositioning.coordinate(36.8065, 10.1815) // Example: Tunis
        zoomLevel: 14

        // Collection for storing multiple markers
        MapItemView {
            z: 100
            id: markerView
            model: ListModel {
                id: markerModel
            }

            delegate: MapQuickItem {
                coordinate: QtPositioning.coordinate(model.latitude, model.longitude)
                anchorPoint.x: markerRect.width / 2
                anchorPoint.y: markerRect.height

                sourceItem: Column {
                    spacing: 5

                    // Marker with color based on type
                    Rectangle {
                        id: markerRect
                        width: 24
                        height: 24
                        radius: 12
                        color: {
                            if (model.name === "Your Location") return "#FF5722";
                            if (model.eventType === "Charity") return "red";
                            if (model.eventType === "Summit") return "royalblue";
                            if (model.eventType === "Q&A") return "Indigo";
                            if (model.eventType === "Vaccination") return "rgb(30,143,83)";
                            return "#9ACD32";
                        }
                        border.width: 2
                        border.color: "white"

                        NumberAnimation on scale {
                            from: 1.0
                            to: 1.2
                            duration: 1000
                            loops: model.name === "Your Location" ? Animation.Infinite : 0
                            running: model.name === "Your Location"
                            easing.type: Easing.InOutQuad
                            alwaysRunToEnd: true
                        }
                    }

                    // Label for the marker
                    Text {
                        text: model.name
                        color: model.name === "Your Location" ? "#FF5722" : "#000000"
                        font.bold: true
                        anchors.horizontalCenter: parent.horizontalCenter
                    }
                }
            }
        }

        // Route between user and nearest event
        MapItemView {
            id: routeView
            model: ListModel {
                id: routeModel
            }
            delegate: MapPolyline {
                line.width: 3
                line.color: "#1e8f53"
                path: [
                    { latitude: model.startLat, longitude: model.startLng },
                    { latitude: model.endLat, longitude: model.endLng }
                ]
            }
        }

        // MouseArea for handling map clicks and navigation
        MouseArea {
            anchors.fill: parent
            property real startX
            property real startY
            property bool isPanning: false
            property bool isSingleClick: false
            property var clickTimer: null

            onPressed: function(event) {
                startX = event.x
                startY = event.y
                isPanning = true
                isSingleClick = true
                if (clickTimer) {
                    clickTimer.destroy()
                }
                clickTimer = Qt.createQmlObject("import QtQuick 2.0; Timer {interval: 200; repeat: false; running: true;}", parent)
                clickTimer.triggered.connect(function() {
                    isSingleClick = false
                })
            }

            onReleased: function(event) {
                isPanning = false
                if (isSingleClick) {
                    var coordinate = mapview.toCoordinate(Qt.point(event.x, event.y))
                    mainWindow.handleMapClick(coordinate.latitude, coordinate.longitude);
                    mainWindow.addMarker(coordinate.latitude, coordinate.longitude, "Selected Location");
                }
            }

            onPositionChanged: function(event) {
                if (isPanning) {
                    var dx = event.x - startX
                    var dy = event.y - startY
                    mapview.pan(-dx, -dy)
                    startX = event.x
                    startY = event.y
                    if (Math.abs(dx) > 5 || Math.abs(dy) > 5) {
                        isSingleClick = false
                    }
                }
            }

            onWheel: function(event) {
                if (event.angleDelta.y > 0) {
                    mapview.zoomLevel += 0.5
                } else {
                    mapview.zoomLevel -= 0.5
                }
            }
        }
    }

    // JavaScript functions
    function addMarker(latitude, longitude, name, eventType) {
        markerModel.append({
            "latitude": latitude,
            "longitude": longitude,
            "name": name,
            "eventType": eventType
        });
    }

    function clearMarkers() {
        markerModel.clear();
    }

    function setCenter(latitude, longitude) {
        mapview.center = QtPositioning.coordinate(latitude, longitude);
    }

    function showRoute(startLat, startLng, endLat, endLng, endName) {
        clearRoutes();
        routeModel.append({
            "startLat": startLat,
            "startLng": startLng,
            "endLat": endLat,
            "endLng": endLng,
            "endName": endName
        });

        // Adjust view to show both points
        var startCoord = QtPositioning.coordinate(startLat, startLng);
        var endCoord = QtPositioning.coordinate(endLat, endLng);
        mapview.fitViewportToGeoRectangle(QtPositioning.rectangle(startCoord, endCoord));
    }

    function clearRoutes() {
        routeModel.clear();
    }
}
