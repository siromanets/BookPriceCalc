#ifndef PRICECALCULATOR_H
#define PRICECALCULATOR_H
#include <QObject>
#include <QString>
#include <QQuickItem>
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
    bool UpdatePrice(QQuickItem *iItem);

private:
    QQmlApplicationEngine* mEngine;
    ProvideAndSyncPrices* mProvierAndSyncer;
    std::map<ProvideAndSyncPrices::EBookPrices, QString> mItemMap;
};

#endif // PRICECALCULATOR_H
