#ifndef PROVIDEANDSYNCPRICES_H
#define PROVIDEANDSYNCPRICES_H

#include <QXmlStreamWriter>
#include <QXmlStreamReader>

class ProvideAndSyncPrices
{
public:
    ProvideAndSyncPrices();
    void SavePrices();
    void GetPrices();

private:
    QXmlStreamWriter mXmlWriter;
    QXmlStreamReader mXmlReader;
};

#endif // PROVIDEANDSYNCPRICES_H
