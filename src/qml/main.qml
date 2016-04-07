import QtQuick 2.3
import QtQuick.Window 2.2
import QtQuick.Layouts 1.2
import KeyboardHelper 1.0
import "jslogic.js" as Logic

import "."

Window {
    id: window
    //width: grid.width
    //height: grid.height
    x: (Screen.desktopAvailableWidth - 500)/2
    y: Screen.desktopAvailableHeight - 150
    property bool loaded: false
    property real initial_width: 1
    property real scale: window.loaded ? window.width/window.initial_width : 1
    visible: true
    color: "#00000000"
    //opacity: 0.5
    //flags: Qt.Tool | Qt.WindowSystemMenuHint | Qt.WindowStaysOnTopHint
    property string defaultButtonColor: "white"

    MouseArea {
        anchors.fill: parent
        //onClicked: {}
    }

    KeyboardHelper {
        id: keyboardHelper
    }

    Component.onCompleted: Logic.LayoutHelper.InitLayout()

    GridLayout {
        id: grid
        focus: true
        columns: 1
        rowSpacing: Logic.Globals.GRID_SPACING * window.scale
        Keys.onPressed: Logic.EventHelper.onKeyEvent(event, true)
        Keys.onReleased: Logic.EventHelper.onKeyEvent(event, false)
        Component.onCompleted: function() { console.log("grid loaded") };
    }
}
