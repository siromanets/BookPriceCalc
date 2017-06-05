import QtQuick 2.7
import QtQuick.Controls 2.0
import QtQuick.Layouts 1.0

Item {
    property alias btnCalc: btnCalc
    property alias combo: comboBox

    ColumnLayout {
        x: 20
        y: 8
        width: 401
        height: 170

        RowLayout {

            ComboBox {
                id: comboBox
                objectName: "combo"
                textRole: 'text'
                model: ListModel {
                    id: model
                    ListElement {
                        text: "Banana"
                        //color: "Yellow"
                    }
                    ListElement {
                        text: "Apple"
                        //color: "Green"
                    }
                    ListElement {
                        text: "Coconut"
                        //color: "Brown"
                    }
                }
            }

            Label {
                id: label
                x: 117
                y: 12
                text: qsTr("Формат книги")
            }
        }
    }

    Button {
        id: btnCalc
        x: 270
        y: 374
        text: qsTr("Вирахувати")
    }
}
