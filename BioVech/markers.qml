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
            id: markerView
            model: ListModel {
                id: markerModel
                // This will be populated with markers
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
                        color: model.name === "Your Location" ? "#FF5722" : (model.type === "Nearby" ? "#9ACD32" : "#1E90FF")
                        border.width: 2
                        border.color: "white"

                        // Pulse animation for "Your Location" marker
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
                        color: model.name === "Your Location" ? "#FF5722" : "#1E90FF"
                        font.bold: true
                        anchors.horizontalCenter: parent.horizontalCenter
                    }
                }
            }
        }

        // MouseArea for handling map clicks and navigation
        MouseArea {
            anchors.fill: parent
            property real startX
            property real startY
            property bool isPanning: false
            property bool isSingleClick: false
            property var clickTimer: null  // Changed from int to var to accept QObject

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
                    // This will be called if no release happened within the interval
                    isSingleClick = false
                })
            }

            onReleased: function(event) {
                isPanning = false
                if (isSingleClick) {
                    // Get the clicked position on map
                    var coordinate = mapview.toCoordinate(Qt.point(event.x, event.y))

                    // Signal to C++ that map was clicked
                    mainWindow.handleMapClick(coordinate.latitude, coordinate.longitude)
                }
            }

            onPositionChanged: function(event) {
                if (isPanning) {
                    var dx = event.x - startX
                    var dy = event.y - startY
                    mapview.pan(-dx, -dy)
                    startX = event.x
                    startY = event.y
                    // If dragging, disable single click
                    if (Math.abs(dx) > 5 || Math.abs(dy) > 5) {
                        isSingleClick = false
                    }
                }
            }

            onWheel: function(event) {
                // Zoom with mouse wheel
                if (event.angleDelta.y > 0) {
                    mapview.zoomLevel += 0.5
                } else {
                    mapview.zoomLevel -= 0.5
                }
            }
        }
    }

    // JavaScript function to add marker programmatically
    function addMarker(latitude, longitude, name, type) {
        // Add the new marker
        markerModel.append({"latitude": latitude, "longitude": longitude, "name": name, "type": type});
    }

    // JavaScript function to clear all markers
    function clearMarkers() {
        markerModel.clear()
    }

    // Add a function to set the center of the map
    function setCenter(latitude, longitude) {
        mapview.center = QtPositioning.coordinate(latitude, longitude);
    }
}
