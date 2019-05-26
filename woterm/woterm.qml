import QtQuick 2.11
import QtQuick.Window 2.11
import QtQuick.Layouts 1.11
import QtQuick.Dialogs 1.3
import QtQuick.Controls 2.4
import QtQuick.Controls.Styles 1.4
import QtQuick.Controls.Imagine 2.4
import "layout"

ApplicationWindow {
    visible: true
    width: 1280
    height: 720
    minimumWidth: 800
    minimumHeight: 600
    menuBar: MenuBar {
        focusPolicy: Qt.ClickFocus

        delegate: MenuBarItem {
                  id: menuBarItem

                  contentItem: Text {
                      text: menuBarItem.text
                      font: menuBarItem.font
                      opacity: enabled ? 1.0 : 0.3
                      color: menuBarItem.highlighted ? "#ffffff" : "#21be2b"
                      horizontalAlignment: Text.AlignLeft
                      verticalAlignment: Text.AlignVCenter
                      elide: Text.ElideRight
                  }

                  background: Rectangle {
                      implicitWidth: 40
                      implicitHeight: 40
                      opacity: enabled ? 1 : 0.3
                      color: menuBarItem.highlighted ? "#21be2b" : "transparent"
                  }
              }

              background: Rectangle {
                  implicitWidth: 40
                  implicitHeight: 40
                  color: "#ffffff"

                  Rectangle {
                      color: "#21be2b"
                      width: parent.width
                      height: 1
                      anchors.bottom: parent.bottom
                  }
              }
        Menu {
             id: menu
             title: "sdfdsfdf"

             Action { text: qsTr("Tool Bar"); checkable: true }
             Action { text: qsTr("Side Bar"); checkable: true; checked: true }
             Action { text: qsTr("Status Bar"); checkable: true; checked: true }

             MenuSeparator {
                 contentItem: Rectangle {
                     implicitWidth: 200
                     implicitHeight: 1
                     color: "#21be2b"
                 }
             }

             Menu {
                 title: qsTr("Advanced")
                 // ...
             }

             topPadding: 2
             bottomPadding: 2

             delegate: MenuItem {
                 id: menuItem
                 implicitWidth: 200
                 implicitHeight: 40

                 arrow: Canvas {
                     x: parent.width - width
                     implicitWidth: 40
                     implicitHeight: 40
                     visible: menuItem.subMenu
                     onPaint: {
                         var ctx = getContext("2d")
                         ctx.fillStyle = menuItem.highlighted ? "#ffffff" : "#21be2b"
                         ctx.moveTo(15, 15)
                         ctx.lineTo(width - 15, height / 2)
                         ctx.lineTo(15, height - 15)
                         ctx.closePath()
                         ctx.fill()
                     }
                 }

                 indicator: Item {
                     implicitWidth: 40
                     implicitHeight: 40
                     Rectangle {
                         width: 26
                         height: 26
                         anchors.centerIn: parent
                         visible: menuItem.checkable
                         border.color: "#21be2b"
                         radius: 3
                         Rectangle {
                             width: 14
                             height: 14
                             anchors.centerIn: parent
                             visible: menuItem.checked
                             color: "#21be2b"
                             radius: 2
                         }
                     }
                 }

                 contentItem: Text {
                     leftPadding: menuItem.indicator.width
                     rightPadding: menuItem.arrow.width
                     text: menuItem.text
                     font: menuItem.font
                     opacity: enabled ? 1.0 : 0.3
                     color: menuItem.highlighted ? "#ffffff" : "#21be2b"
                     horizontalAlignment: Text.AlignLeft
                     verticalAlignment: Text.AlignVCenter
                     elide: Text.ElideRight
                 }

                 background: Rectangle {
                     implicitWidth: 200
                     implicitHeight: 40
                     opacity: enabled ? 1 : 0.3
                     color: menuItem.highlighted ? "#21be2b" : "transparent"
                 }
             }

             background: Rectangle {
                 implicitWidth: 200
                 implicitHeight: 40
                 color: "#ffffff"
                 border.color: "#21be2b"
                 radius: 2
             }
         }
        Menu {
            title: qsTr("&Edit")
            Action { text: qsTr("Cu&t") }
            Action { text: qsTr("&Copy") }
            Action { text: qsTr("&Paste") }
        }
        Menu {
            title: qsTr("&Help")
            Action { text: qsTr("&About") }
        }
    }
}
