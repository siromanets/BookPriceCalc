#include <QDebug>
#include <QQmlApplicationEngine>
#include <QQmlComponent>
#include <QQuickItem>
#include <QComboBox>

#include "pricecalculator.h"

PriceCalculator::PriceCalculator(QObject *parent) : QObject(parent){
    mProvierAndSyncer = new ProvideAndSyncPrices();
}

PriceCalculator::PriceCalculator(QQmlApplicationEngine* iEngine) :
    mEngine(iEngine),
    mProvierAndSyncer(new ProvideAndSyncPrices())
{
    mProvierAndSyncer->ReceivePrices();

    std::map<QString, double> formatPrice = mProvierAndSyncer->GetBookPrices(ProvideAndSyncPrices::eFormat);

    QObject* test = mEngine->rootObjects().first();
    QQuickItem* next = test->findChild<QQuickItem*>("bookFormatCB");


    QString str = (next->property("currentText")).toString();
    if (!str.isEmpty())
    {
        double currentPrice = formatPrice[str];
        QQuickItem* priceFiels = test->findChild<QQuickItem*>("bookFormatP");
        if (priceFiels)
            priceFiels->setProperty("text", currentPrice);
    }
   // int i = (next->property("currentIndex")).toInt();
    if (test)
        qDebug() << test->objectName();
    if (next)
        qDebug() << next->objectName() << str;
}

PriceCalculator::~PriceCalculator()
{
    delete mProvierAndSyncer;
}

void PriceCalculator::onButtonClicked(const QString &iBookFormat)
{
    mProvierAndSyncer->SavePrices();

    //temporary comented out for testing
//    QList<QObject*> lst = mEngine->rootObjects();
//    int count = lst.count();
//    qDebug() << count;
//    if (count == 0) return;

//    QObject* object = lst[0];
//    QObject* combo = object->findChild<QObject*>("combo");
////    qDebug() << "obj info " << combo->objectName();
//    QString str = QString::number(iBookFormat.toInt() + 100);
//    qDebug() << "some price: " <<  str;
//    qDebug() << "on button action method call \n";
}
