import QtQuick 2.7
import QtQuick.Controls 2.0
import QtQuick.Layouts 1.0
import Qt.labs.settings 1.0

Item {
    id: fasteringLabel
    property alias btnCalc: btnCalc
    property alias cbEnableEditing: cbEnableEditing
    property alias formatPrice: model
    property alias bookFormatCB: bookFormatCB
    property alias coverCB: coverCB

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

    GridLayout {
        id: gridLayout1
        //        cellWidth: 250; cellHeight: 80
        x: 33
        y: 67
        width: 523
        height: 252
        clip: false
        columnSpacing: 10
        rowSpacing: 5
        rows: 5
        columns: 3

        ComboBox {
            id: bookFormatCB
            Layout.fillWidth: true
            currentIndex: 0
            objectName: "combo"
            textRole: 'text'
            model: ListModel {
                id: model
                ListElement { text: "А4"; price: "5" }
                ListElement { text: "А5"; price: "4" }
                ListElement { text: "А6"; price: "3" }
                ListElement { text: "Кишенькова"; price: "2" }
            }
        }

        TextField {
            id: bookFormatPrices
            width: 50
            text: qsTr("Text Field")
            Layout.preferredWidth: 50
            enabled: false
            transformOrigin: Item.Center
        }

        Label {
            id: bookFormatLabel
            text: qsTr("Формат книги")
        }

        ComboBox {
            id: coverCB
            width: 150
            Layout.fillWidth: true
            spacing: 8
            textRole: 'text'
            model: ListModel {
                id: coverModel
                ListElement { text: "Тверда" }
                ListElement { text: "М'яка" }

            }

            //            Settings {
            //                property alias sModel: cb1Model
            //            }
        }


        TextField {
            id: coverPrices
            width: 50
            text: qsTr("Text Field")
            enabled: false
            Layout.preferredWidth: 50
        }

        Label {
            id: coverLabel
            text: qsTr("Обкладинка")
        }

        TextField {
            id: numberOfPagesTF
            width: 50
            text: qsTr("")
            Layout.preferredWidth: 75
            font.pointSize: 10
            Layout.fillWidth: false
        }



        Label {
            id: label
            text: qsTr("Label")
        }

        Label {
            id: nubmerOfPagesLabel
            text: qsTr("Кількість сторінок")
        }

        ComboBox {
            id: fasteningCB
            width: 250
            Layout.fillWidth: true
            textRole: 'text'
            model: ListModel {
                id: fasteningModel
                ListElement { text: "Скоба" }
                ListElement { text: "Термобіндер" }
                ListElement { text: "Твердий переплет" }
                ListElement { text: "Пружинка" }
            }
        }

        TextField {
            id: fasteringPrices
            width: 50
            text: qsTr("Text Field")
            visible: true
            enabled: false
            Layout.preferredWidth: 50
        }

        Label {
            id: fasteningLabel
            text: qsTr("Скріплення")
        }

        ComboBox {
            id: printTypeCB
            width: 250
            Layout.fillWidth: true
            textRole: 'text'
            model: ListModel {
                id: printTypeModel
                ListElement { text: "Різограф"; price: "5" }
                ListElement { text: "цифра"; price: "4" }
            }
        }

        TextField {
            id: printTypePrices
            width: 50
            text: qsTr("Text Field")
            enabled: false
            Layout.preferredWidth: 50
        }
        Label {
            id: printTypeLabel
            text: qsTr("Тип друку")
        }





    }
}
