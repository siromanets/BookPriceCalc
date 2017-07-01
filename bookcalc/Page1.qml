import QtQuick 2.7
import QtQuick.Controls 1.1

Page1Form {
    cbEnableEditing.onCheckStateChanged: {
        bookFormatPrices.enabled = !(bookFormatPrices.enabled)
        coverPrices.enabled = !(coverPrices.enabled)
        fasteringPrices.enabled = !(fasteringPrices.enabled)
        printTypePrices.enabled = !(printTypePrices.enabled)
}

    btnCalc.onClicked: {

        //console.debug(formatPrice.get( bookFormatCB.currentIndex ).price)
        priceCalc.onButtonClicked( formatPrice.get( bookFormatCB.currentIndex ).price )
    }
//    comboBox1.onCurrentIndexChanged: console.debug(cbItems.get(currentIndex).text + ", " + cbItems.get(currentIndex).color)

}
