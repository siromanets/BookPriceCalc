import QtQuick 2.7
import QtQuick.Controls 1.1

Page1Form {

    btnCalc.onClicked: {

        console.debug(formatPrice.get( bookFormat.currentIndex ).price)
        priceCalc.onButtonClicked( formatPrice.get( bookFormat.currentIndex ).price )
    }
//    comboBox1.onCurrentIndexChanged: console.debug(cbItems.get(currentIndex).text + ", " + cbItems.get(currentIndex).color)

}
