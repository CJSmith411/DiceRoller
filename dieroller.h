#ifndef DIEROLLER_H
#define DIEROLLER_H

#include <QString>
#include <QList>
#include "singledie.h"
class DieRoller
{
public:
    DieRoller();
    DieRoller(int die, int num, int keep, int mod, int min, int max, bool keeplow);

private:
    int d, n, k, a, min, max;
    bool kl;
    int total;
    QString result;
    QList<SingleDie> dice;

public:
    void rollDice();
    int getTotal();
    QString getResult();
};

#endif // DIEROLLER_H
