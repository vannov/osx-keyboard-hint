import QtQuick 2.0
import QtQuick.Controls.Styles 1.4

pragma Singleton

Item {
    property string color: "yellow"
    property alias buttonStyle: btnStyle
    ButtonStyle {
        id: btnStyle
        background: Rectangle {
        color: "red"
    }
   }
}
