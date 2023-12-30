#include "singledie.h"
#include <QRandomGenerator>

SingleDie::SingleDie()
    : SingleDie(2, 1, 2)
{

}

SingleDie::SingleDie(int size, int minimum, int maximum)
{
    this->size = size;
    this->min = minimum;
    this->max = maximum;
}

void SingleDie::Roll()
{
    actualRoll = QRandomGenerator::securelySeeded().bounded(1, size + 1);
    value = std::min(std::max(actualRoll, min), max);
}

int SingleDie::getActualRoll() const
{
    return actualRoll;
}

int SingleDie::getValue() const
{
    return value;
}
