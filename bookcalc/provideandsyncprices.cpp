#include <QFile>
#include <QDebug>
#include <QtWidgets/QApplication>
#include <QtWidgets/QMessageBox>
#include <QFileInfo>

#include "provideandsyncprices.h"

ProvideAndSyncPrices::ProvideAndSyncPrices():mXmlWriter()
{
    mXmlWriter.setAutoFormatting(true);
}

void ProvideAndSyncPrices::SavePrices()
{

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
    mXmlWriter.writeDTD("====================<!DOCTYPE BookPrice>====================");
    mXmlWriter.writeStartElement("ElementPrices");
    mXmlWriter.writeAttribute("version", "1.0");

    mXmlWriter.writeStartElement("Формат Книги");
    mXmlWriter.writeTextElement("A4", "1.5");
    mXmlWriter.writeTextElement("A5", "1.0");
    mXmlWriter.writeTextElement("A6", "0.8");
    mXmlWriter.writeTextElement("Кишенькова", "1.2");
    mXmlWriter.writeEndElement();

    mXmlWriter.writeStartElement("Обкладинка");
    mXmlWriter.writeTextElement("Тверда", "5");
    mXmlWriter.writeTextElement("М'яка", "3");
    mXmlWriter.writeEndElement();

    mXmlWriter.writeStartElement("Скріплення");
    mXmlWriter.writeTextElement("Сковаба", "3");
    mXmlWriter.writeTextElement("Термобіндер", "3");
    mXmlWriter.writeTextElement("Твердий переплет", "3");
    mXmlWriter.writeTextElement("Пружинка", "3");
    mXmlWriter.writeEndElement();

//    mXmlWriter.writeEndElement();
    mXmlWriter.writeEndDocument();
    file->close();
}

//    for (int i = 0; i < treeWidget->topLevelItemCount(); ++i)
//        writeItem(treeWidget->topLevelItem(i));


