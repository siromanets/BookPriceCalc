#ifndef PROVIDEANDSYNCPRICES_H
#define PROVIDEANDSYNCPRICES_H

#include <QXmlStreamWriter>

class ProvideAndSyncPrices
{
public:
    ProvideAndSyncPrices();
    void SavePrices();

private:
    QXmlStreamWriter mXmlWriter;
};

#endif // PROVIDEANDSYNCPRICES_H
