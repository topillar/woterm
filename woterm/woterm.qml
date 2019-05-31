import QtQuick 2.11
import QtQuick.Window 2.11
import QtQuick.Layouts 1.11
import QtQuick.Dialogs 1.3
import QtQuick.Controls 1.4
import QtQuick.Controls.Styles 1.4
import "layout"
import "control"
import WoItem 1.0
import WoTermItem 1.0


Item {
    visible: true
    property var sshRemote: []

    Component.onCompleted: {
        sshRemote.push("A");
        sshRemote.push("B");
        sshRemote.push("C")
    }

    WoTheme {
        id:g_theme
    }

    ColumnLayout {
        spacing: 0
        anchors.fill: parent
        ToolBar {
            Layout.fillWidth: true
            Layout.margins:0
            RowLayout {
                anchors.fill: parent
                ToolButton {
                    text: qsTr("New")
                    onClicked: {

                    }
                }
                ToolButton {
                    text: qsTr("Connect")
                    implicitWidth: 60
                    onClicked: {

                    }
                    Button{
                        width: 20
                        anchors.right: parent.right
                        text : "Drop"
                    }
                }
                Item {
                    Layout.fillWidth: true
                }
            }
        }
        TabView {
            id: bar
            anchors.fill: parent

            Repeater {
                id: repeater;
                Component.onCompleted: {
                    lstModel.append({"server":"dddddddddA"})
                    lstModel.append({"server":"Bdddd"})
                    lstModel.append({"server":"C"})
                }

                model: ListModel{
                    id: lstModel
                }

                delegate:Component {
                    Tab {
                        title: model.server
                        width: implicitWidth
                        WoTermItem {
                            id: m_term
                            Layout.fillWidth: true
                            Layout.fillHeight: true
                            Layout.margins: 0

                            Component.onCompleted: {
                                m_term.connect("target")
                            }

                            Rectangle {
                                anchors.fill: parent
                                border.width: 3
                                border.color: "yellow"
                                color: "green"
                            }
                        }
                    }
                }
            }
        }      
    }
}
