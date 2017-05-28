#ifndef PRICECALCULATOR_H
#define PRICECALCULATOR_H
#include <QObject>

class PriceCalculator : public QObject
{
    Q_OBJECT
public:
    explicit PriceCalculator(QObject *parent = 0);

signals:

public slots:
};

#endif // PRICECALCULATOR_H
