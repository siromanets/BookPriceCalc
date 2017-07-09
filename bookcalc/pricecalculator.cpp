#include <QDebug>
#include <QQmlApplicationEngine>
#include <QQmlComponent>
#include <QQuickItem>
#include <QComboBox>

#include "pricecalculator.h"

PriceCalculator::PriceCalculator(QObject *parent) : QObject(parent){
    mProvierAndSyncer = new ProvideAndSyncPrices();
}

PriceCalculator::PriceCalculator(QQmlApplicationEngine* iEngine) :
    mEngine(iEngine),
    mProvierAndSyncer(new ProvideAndSyncPrices())
{
    mProvierAndSyncer->ReceivePrices();
    QObject* rootObj = mEngine->rootObjects().first();

    mItemMap.emplace(ProvideAndSyncPrices::eFormat, std::make_pair<QString, QString>("bookFormatCB", "bookFormatP"));
    mItemMap.emplace(ProvideAndSyncPrices::eCover, std::make_pair<QString, QString>("coverCB", "coverP"));
    mItemMap.emplace(ProvideAndSyncPrices::eFastering, std::make_pair<QString, QString>("fasteningCB", "fasteningP"));

    for (auto& it : mItemMap)
    {
        qDebug() << it.second;
        std::map<QString, double> prices = mProvierAndSyncer->GetBookPrices(it.first);
        QQuickItem* bookCB = rootObj->findChild<QQuickItem*>(it.second.first);

        if (bookCB)
        {
            QString str = fixName((bookCB->property("currentText")).toString());
            if (!str.isEmpty())
            {
                double currentPrice = prices[str];
                QQuickItem* priceFiels = rootObj->findChild<QQuickItem*>(it.second.second);
                if (priceFiels)
                    priceFiels->setProperty("text", currentPrice);
            }
        }
    }
}

PriceCalculator::~PriceCalculator()
{
    delete mProvierAndSyncer;
}

void PriceCalculator::savePrices()
{
    mProvierAndSyncer->SavePrices();
}

void PriceCalculator::onButtonClicked(const QString &iBookFormat)
{


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
    //    qDebug() << "on button action method call \";
}

void PriceCalculator::updatePrice(const QString &iObjName)
{
    ProvideAndSyncPrices::EBookPrices key;
    QString priceField;
    for(auto& it : mItemMap)
    {
        if (!iObjName.compare(it.second.first))
        {
            key = it.first;
            priceField = it.second.second;
            break;
        }
    }


    QObject* rootObj = mEngine->rootObjects().first();

    std::map<QString, double> prices = mProvierAndSyncer->GetBookPrices(key);
    QQuickItem* bookCB = rootObj->findChild<QQuickItem*>(iObjName);

    if (bookCB)
    {
        QString str = fixName((bookCB->property("currentText")).toString());
        if (!str.isEmpty())
        {

            QQuickItem* priceF = rootObj->findChild<QQuickItem*>(priceField);
            if (priceF)
            {
                prices[str] = priceF->property("text").toDouble();
            }
        }
    }
}

QString PriceCalculator::fixName(QString iName)
{
    QString str = iName.replace("'",".");
    return str.replace(" ","_");
}
