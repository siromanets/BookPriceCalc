#ifndef PROVIDEANDSYNCPRICES_H
#define PROVIDEANDSYNCPRICES_H

#include <map>
#include <QXmlStreamWriter>
#include <QXmlStreamReader>

class ProvideAndSyncPrices
{
public:
    ProvideAndSyncPrices();
    void SavePrices();
    void ReceivePrices();

private:
    struct BookPrices
    {
        std::map<QString, double> format;
        std::map<QString, double> cover;
        std::map<QString, double> fastening;
    };

private:
    QXmlStreamWriter mXmlWriter;
    QXmlStreamReader mXmlReader;
    BookPrices bookPrices;
};

#endif // PROVIDEANDSYNCPRICES_H
