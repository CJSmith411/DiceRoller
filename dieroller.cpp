#include "dieroller.h"
#include <QRandomGenerator>

DieRoller::DieRoller()
    : DieRoller(2, 1, 1, 0, 1, 2, false)
{

}

DieRoller::DieRoller(int die, int num, int keep, int mod, int min, int max, bool keeplow)
{
    this->d = die;
    this->n = num;
    this->k = keep;
    this->a = mod;
    this->min = min;
    this->max = max;
    this->kl = keeplow;
    this->dice = QList<SingleDie>();
    this->result = "";
}

void DieRoller::rollDice()
{
    total = a;
    for (int i = 0; i < n; i++)
    {
        SingleDie sd(d, min, max);
        sd.Roll();
        dice.append(sd);
    }
    if (k < n) {
        if (kl) {
            std::sort(
                dice.begin(),
                dice.end(),
                [](SingleDie a, SingleDie b)
                {
                    return a.getValue() < b.getValue();
                });
        }
        else {
            std::sort(
                dice.begin(),
                dice.end(),
                [](SingleDie a, SingleDie b)
                {
                    return a.getValue() > b.getValue();
                });
        }
    }
    for(int i = 0; i < n; i++)
    {
        int dieValue = dice.at(i).getValue();
        int dieRoll = dice.at(i).getActualRoll();
        QString formatString = "%1";
        if (dieValue != dieRoll)
        {
            formatString.append("(%2)");
        }
        if (k < n && i < k)
        {
            formatString.append(" #");
        }
        formatString.append("\r\n");
        if (k == n || i < k)
        {
            total += dieValue;
        }
        result.append(QString(formatString).arg(dieValue).arg(dieRoll));
    }
}

int DieRoller::getTotal()
{
    return total;
}

QString DieRoller::getResult()
{
    return result;
}
