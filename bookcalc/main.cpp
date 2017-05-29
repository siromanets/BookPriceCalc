#include <QGuiApplication>
#include <QQmlApplicationEngine>
#include <QQmlComponent>
#include <QObject>
#include <QDebug>
#include <QQmlProperty>
#include <QQuickView>
#include <QQuickItem>
#include <QList>

#include "pricecalculator.h"

int main(int argc, char *argv[])
{
    QCoreApplication::setAttribute(Qt::AA_EnableHighDpiScaling);
    QGuiApplication app(argc, argv);

    QQmlApplicationEngine engine;
    engine.load(QUrl(QLatin1String("qrc:/main.qml")));



    PriceCalculator* priceCalc = new PriceCalculator(&engine);


    QList<QObject*> lst = engine.rootObjects();
    int count = lst.count();
    qDebug() << count;
    if (count == 0) return -1;

//    QObject *object = lst[0];

    // Using QQmlComponent
/********************************************************************************/
//    QQmlComponent component(&engine, QUrl(QStringLiteral("qrc:/main.qml")));

//    if( !component.isReady() )
//        qDebug() << "Error: " << component.errorString();
//    QObject *object = component.create();
//    object->setProperty("width", 500);
//    qDebug() << "obj info " << object->objectName();

/********************************************************************************/

//    QQuickView view;
//    view.setSource(QUrl::fromLocalFile("qrc:/main.qml"));
//    view.show();
//    QQuickItem* object = view.rootObject();

//    object->setProperty("width", 1000);
//    QObject* obj = object->findChild<QObject*>("combo");
//    if (obj)
//        obj->property("text");

    return  app.exec();
}
