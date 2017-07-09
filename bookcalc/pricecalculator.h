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


    void savePrices();

signals:

public slots:
    void onButtonClicked(const QString& iBookFormat);
    void updatePrice(const QString& iObjName);

private:

    QString fixName(QString iName);

private:
    QQmlApplicationEngine* mEngine;
    ProvideAndSyncPrices* mProvierAndSyncer;
    std::map<ProvideAndSyncPrices::EBookPrices, std::pair<QString, QString> > mItemMap;
};

#endif // PRICECALCULATOR_H
