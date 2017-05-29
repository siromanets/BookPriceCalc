#ifndef PRICECALCULATOR_H
#define PRICECALCULATOR_H
#include <QObject>
#include <QQmlApplicationEngine>

class PriceCalculator : public QObject
{
    Q_OBJECT
public:
    explicit PriceCalculator(QObject *parent = 0);
    PriceCalculator(QQmlApplicationEngine* iEngine);

signals:

public slots:

private:
    QQmlApplicationEngine* mEngine;
};

#endif // PRICECALCULATOR_H
