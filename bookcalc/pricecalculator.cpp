#include <QDebug>
#include <QQmlApplicationEngine>

#include "pricecalculator.h"

PriceCalculator::PriceCalculator(QObject *parent) : QObject(parent){
    mProvierAndSyncer = new ProvideAndSyncPrices();
}

PriceCalculator::PriceCalculator(QQmlApplicationEngine* iEngine) :
    mEngine(iEngine),
    mProvierAndSyncer(new ProvideAndSyncPrices())
{
    mProvierAndSyncer->ReceivePrices();
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
