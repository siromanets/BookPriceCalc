import QtQuick 2.7
import QtQuick.Controls 2.0
import QtQuick.Layouts 1.0

ApplicationWindow {
    visible: true
    width: 640
    height: 480
    title: qsTr("Hello World")

    SwipeView {
        id: swipeView
        anchors.fill: parent
        currentIndex: tabBar.currentIndex

        Page1 {
        }
        Page2{
        }

//        Page {
//            Label {
//                text: qsTr("fffffffffffffffffffffffffffffffff")
//                anchors.centerIn: parent
//            }
//        }
    }

    footer: TabBar {
        id: tabBar
        currentIndex: swipeView.currentIndex
        TabButton {
            text: qsTr("Книги")
        }
        TabButton {
            text: qsTr("Друк постера")
        }
//        TabButton {
//            text: qsTr("Третя")
//        }
//        TabButton {
//            text: qsTr("Четвертя")
//        }
//        TabButton {
//            text: qsTr("П'ята")
//        }
    }
}
