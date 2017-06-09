import QtQuick 2.7
import QtQuick.Controls 2.0
import QtQuick.Controls 1.4
import QtQuick.Layouts 1.0
import Qt.labs.settings 1.0

Item {
    property alias btnCalc: btnCalc
    property alias combo: bookFormat
    property alias comboBox1: comboBox1
    property alias cbEnableEditing: cbEnableEditing
    property alias bookFormat: bookFormat
    property alias formatPrice: model

    ColumnLayout {
        x: 20
        y: 8
        RowLayout {

            ComboBox {
                id: bookFormat
                currentIndex: 0
                objectName: "combo"
                textRole: 'text'
                model: ListModel {
                    id: model
                    ListElement { text: "Banana"; price: "3" }
                    ListElement { text: "Apple"; price: "4" }
                    ListElement { text: "Coconut"; price: "5" }
                }
            }

            Label {
                id: label
                text: qsTr("Формат книги")
            }
        }

        ComboBox {
            id: comboBox1
            enabled: true
            textRole: 'text'
            model: ListModel {
                id: cb1Model
                ListElement { text: "Banana" }
                ListElement { text: "Apple" }
                ListElement { text: "Coconut" }
            }

            Settings {
                property alias sModel: cb1Model
            }
        }
    }

    Button {
        id: btnCalc
        x: 270
        y: 374
        text: qsTr("Вирахувати")
    }

    CheckBox {
        id: cbEnableEditing
        x: 427
        y: 8
        text: qsTr("Включити редагування")
    }
}
