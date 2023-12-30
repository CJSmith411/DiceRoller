#ifndef SINGLEDIE_H
#define SINGLEDIE_H


class SingleDie
{
public:
    SingleDie();
    SingleDie(int size, int minimum, int maximum);
    void Roll();

    int getActualRoll() const;

    int getValue() const;

private:
    int size, min, max;
    int actualRoll, value;
};

#endif // SINGLEDIE_H
