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

    std::map<ProvideAndSyncPrices::EBookPrices, QString> items;
    items.emplace(ProvideAndSyncPrices::eFormat, QString("bookFormatCB"));
    items.emplace(ProvideAndSyncPrices::eCover, QString("coverCB"));

    for (auto& it : items)
    {
        qDebug() << it.second;
        std::map<QString, double> prices = mProvierAndSyncer->GetBookPrices(it.first);
        QQuickItem* bookCB = rootObj->findChild<QQuickItem*>(it.second);

        if (bookCB)
        {
            QString str = (bookCB->property("currentText")).toString();
            if (!str.isEmpty())
            {
                double currentPrice = prices[str];
                QQuickItem* priceFiels = rootObj->findChild<QQuickItem*>("bookFormatP");
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

bool PriceCalculator::UpdatePrice(QQuickItem* iItem)
{
    return false;
}



