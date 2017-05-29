#include "pricecalculator.h"

PriceCalculator::PriceCalculator(QObject *parent) : QObject(parent){}

PriceCalculator::PriceCalculator(QQmlApplicationEngine* iEngine) : mEngine(iEngine){}
