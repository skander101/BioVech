import QtQuick 2.15
import QtLocation 5.11
import QtPositioning 5.11

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
        center: QtPositioning.coordinate(36.8065, 10.1815) // Exemple : Tunis
        zoomLevel: 20
        // Ajouter un marqueur
        MapQuickItem {
            id: marker
            anchorPoint.x: image.width / 2
            anchorPoint.y: image.height
            coordinate: QtPositioning.coordinate(36.8065, 10.1815)

            sourceItem: Row {
                spacing: 5
                Image {
                    id: image
                    source: "qrc:/Static/Static/marker.png"
                    width: 32
                    height: 32
                }
                Text {
                    text: "ByteBuilders"
                    color: "#9ACD32"
                    font.bold: true
                    verticalAlignment: Text.AlignVCenter
                }
            }
        }

        // MouseArea pour la navigation
        MouseArea {
            anchors.fill: parent
            property real startX
            property real startY
            property bool isPanning: false

            onPressed: {
                startX = mouse.x
                startY = mouse.y
                isPanning = true
            }

            onReleased: {
                isPanning = false
            }

            onPositionChanged: {
                if (isPanning) {
                    var dx = mouse.x - startX
                    var dy = mouse.y - startY
                    mapview.pan(-dx, -dy)
                    startX = mouse.x
                    startY = mouse.y
                }
            }

            onWheel: {
                // Zoom avec la molette de la souris
                if (wheel.angleDelta.y > 0) {
                    mapview.zoomLevel += 0.5
                } else {
                    mapview.zoomLevel -= 0.5
                }
            }
        }
    }
}
