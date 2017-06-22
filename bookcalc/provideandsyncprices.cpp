#include <QFile>
#include <QDebug>
#include <QtWidgets/QApplication>
#include <QtWidgets/QMessageBox>
#include <QFileInfo>

#include "provideandsyncprices.h"

ProvideAndSyncPrices::ProvideAndSyncPrices()
{
    mXmlWriter.setAutoFormatting(true);
}

void ProvideAndSyncPrices::SavePrices()
{
    qDebug() << QFileInfo("prices.xml").exists();

    QFile* file = new QFile(QCoreApplication::applicationDirPath() + "/prices.xml");

    if ( !file->open(QIODevice::WriteOnly) )
    {
        QMessageBox::warning(NULL, QObject::tr("Price saving:"),
                             QObject::tr("Cannot write file %1:\n%2.")
                             .arg(QString("prices.xml"))
                             .arg(file->errorString()));
        return;
    }

    mXmlWriter.setDevice(file);
    mXmlWriter.writeStartDocument();
    mXmlWriter.writeDTD("<!DOCTYPE xbel>");
    mXmlWriter.writeStartElement("xbel");
    mXmlWriter.writeAttribute("version", "1.0");


    mXmlWriter.writeEndDocument();
}

//bool ProvideAndSyncPrices::writeFile()
//{
//    xml.setDevice(device);

//    xml.writeStartDocument();
//    xml.writeDTD("<!DOCTYPE xbel>");
//    xml.writeStartElement("xbel");
//    xml.writeAttribute("version", "1.0");
//    for (int i = 0; i < treeWidget->topLevelItemCount(); ++i)
//        writeItem(treeWidget->topLevelItem(i));

//    xml.writeEndDocument();
//    return true;
//}
