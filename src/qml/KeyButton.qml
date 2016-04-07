import QtQuick 2.0
import QtQuick.Controls 1.4
import QtQuick.Controls.Styles 1.4
import "jslogic.js" as Logic
import "."

Button {
    id: btn
    text: btn.default_text
    //highText: ""
    property string shifted_text: ""
    property string default_text: ""
    property var lang: 0
    property bool active: false

    property var w: 1.0
    property var h: 1.0
    property int default_size: Logic.Globals.BUTTON_DEFAULT_SIZE
    property bool bump: false;

    property int code: 0    //key code
    onClicked: callback(this.code)

    property string color: ""
    style: ButtonStyle {
        background: Rectangle {
            border.width: btn.active ? 2 : 1
            color: btn.color
            implicitWidth: btn.default_size * btn.w * window.scale
            implicitHeight: btn.default_size * btn.h * window.scale
            radius: 3
            opacity: 0.7
            anchors.fill: parent
        }
        label: Text {
            renderType: Text.NativeRendering
            verticalAlignment: Text.AlignVCenter
            horizontalAlignment: Text.AlignHCenter
            font.family: "Helvetica"
            font.pointSize: 14
            font.underline: bump
            text: btn.bump ? (" " + btn.text + " ") : btn.text
        }
    }

    function callback(code) {}
}
