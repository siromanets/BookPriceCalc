#ifndef PROVIDEANDSYNCPRICES_H
#define PROVIDEANDSYNCPRICES_H

#include <map>
#include <QXmlStreamWriter>
#include <QXmlStreamReader>

class ProvideAndSyncPrices
{
public:
    enum EBookPrices
    {
        eFormat,
        eCover,
        eFastering
    };

public:
    ProvideAndSyncPrices();
    void SavePrices();
    void ReceivePrices();
    std::map<QString, double>& GetBookPrices(EBookPrices iKey);

private:
    struct BookPrices
    {
        std::map<QString, double> format;
        std::map<QString, double> cover;
        std::map<QString, double> fastening;
    };

private:
    QXmlStreamWriter    mXmlWriter;
    QXmlStreamReader    mXmlReader;
    BookPrices          mBookPrices;
};

#endif // PROVIDEANDSYNCPRICES_H
