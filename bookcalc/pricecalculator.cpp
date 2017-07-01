#include <QDebug>
#include <QQmlApplicationEngine>
#include <QQmlComponent>

#include "pricecalculator.h"

PriceCalculator::PriceCalculator(QObject *parent) : QObject(parent){
    mProvierAndSyncer = new ProvideAndSyncPrices();
}

PriceCalculator::PriceCalculator(QQmlApplicationEngine* iEngine) :
    mEngine(iEngine),
    mProvierAndSyncer(new ProvideAndSyncPrices())
{
    mProvierAndSyncer->ReceivePrices();

    QObject* test = mEngine->rootObjects().first();
    QObject* next = test->findChild<QObject*>("bookFormatCB");

    if (test)
        qDebug() << test->objectName();
//    QQmlComponent component(mEngine, QUrl(QStringLiteral("qrc:/main.qml")));

//    if( !component.isReady() )
//        qDebug() << "Error: " << component.errorString();
//    QObject *object = component.create();
////    object->setProperty("width", 500);
//    QObject* obj = object->findChild<QObject*>("bookFormatPrices");
//    if (obj)
//        obj->setProperty("text", "blah");
//    qDebug() << "obj info " << object->objectName();
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
