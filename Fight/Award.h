#ifndef AWARD_H
#define AWARD_H

#include <QVector>

#include "Items/Money.h"
#include "Items/Item.h"


struct AwardAttributes
{
    uint8_t prizeGoodness;

    int minExperience;
    int maxExperience;

    Money minMoney;
    Money maxMoney;

    bool itemsAvailable;
};


struct Award
{
    Money money;
    QVector<Item*> items;
};

#endif // AWARD_H
