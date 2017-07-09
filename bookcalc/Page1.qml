import QtQuick 2.7
import QtQuick.Controls 1.1

Page1Form {
    bookFormatP.onTextChanged: {
//        if (bookFormatPrices.enabled && )
        priceCalc.updatePrice(bookFormatCB.objectName);
}
    cbEnableEditing.onCheckStateChanged: {
        bookFormatP.enabled = !(bookFormatP.enabled)
        coverPrices.enabled = !(coverPrices.enabled)
        fasteningP.enabled = !(fasteningP.enabled)
        printTypeP.enabled = !(printTypeP.enabled)
}

    btnCalc.onClicked: {
        //console.debug(formatPrice.get( bookFormatCB.currentIndex ).price)
        priceCalc.onButtonClicked( formatPrice.get( bookFormatCB.currentIndex ).price )
    }
//    comboBox1.onCurrentIndexChanged: console.debug(cbItems.get(currentIndex).text + ", " + cbItems.get(currentIndex).color)

}
