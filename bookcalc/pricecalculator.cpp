#include <QDebug>
#include <QQmlApplicationEngine>

#include "pricecalculator.h"

PriceCalculator::PriceCalculator(QObject *parent) : QObject(parent){}

PriceCalculator::PriceCalculator(QQmlApplicationEngine* iEngine) : mEngine(iEngine){}

void PriceCalculator::onButtonClicked(const QString &iBookFormat)
{
    QList<QObject*> lst = mEngine->rootObjects();
    int count = lst.count();
    qDebug() << count;
    if (count == 0) return;

    QObject* object = lst[0];
    QObject* combo = object->findChild<QObject*>("combo");
//    qDebug() << "obj info " << combo->objectName();
    QString str = QString::number(iBookFormat.toInt() + 100);
    qDebug() << "some price: " <<  str;
    qDebug() << "on button action method call \n";
}
