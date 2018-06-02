#include "MoneyBag.h"

MoneyBag::MoneyBag(Money money) :
    m_money(money)
{

}

Money MoneyBag::money() const
{
    return m_money;
}

bool MoneyBag::isPurchasable(Money cost)
{
    return (m_money > cost);
}

void MoneyBag::purchase(Money cost)
{
    m_money -= cost;
}
