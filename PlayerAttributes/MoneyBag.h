#ifndef MONEYBAG_H
#define MONEYBAG_H

#include <QString>

#include "Items/Money.h"

class MoneyBag
{
public:
    MoneyBag(Money money);


    Money money() const;
    void addMoney(Money money);

    bool isPurchasable(Money cost);
    void purchase(Money cost);

private:
    Money m_money;
};

#endif // MONEYBAG_H
