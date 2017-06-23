#ifndef PRICECALCULATOR_H
#define PRICECALCULATOR_H
#include <QObject>
#include <QString>
#include <QQmlApplicationEngine>

#include <provideandsyncprices.h>

class PriceCalculator : public QObject
{
    Q_OBJECT
public:
    explicit PriceCalculator(QObject *parent = 0);
    PriceCalculator(QQmlApplicationEngine* iEngine);
    ~PriceCalculator();

signals:

public slots:
    void onButtonClicked(const QString& iBookFormat);

private:
    QQmlApplicationEngine* mEngine;
    ProvideAndSyncPrices* mProvierAndSyncer;
};

#endif // PRICECALCULATOR_H
