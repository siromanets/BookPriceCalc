#include <QDebug>

#include "pricecalculator.h"

PriceCalculator::PriceCalculator(QObject *parent) : QObject(parent){}

PriceCalculator::PriceCalculator(QQmlApplicationEngine* iEngine) : mEngine(iEngine){}

void PriceCalculator::onButtonClicked(const QString &iString)
{
    qDebug() << "on button action method call \n";
}
