#include <QDebug>
#include <QQmlApplicationEngine>

#include "pricecalculator.h"

PriceCalculator::PriceCalculator(QObject *parent) : QObject(parent){}

PriceCalculator::PriceCalculator(QQmlApplicationEngine* iEngine) : mEngine(iEngine){}

void PriceCalculator::onButtonClicked()
{
    QList<QObject*> lst = mEngine->rootObjects();
    int count = lst.count();
    qDebug() << count;
    if (count == 0) return;

    QObject* object = lst[0];
    QObject* combo = object->findChild<QObject*>("combo");
    qDebug() << "obj info " << combo->objectName();
    qDebug() << "on button action method call \n";
}
