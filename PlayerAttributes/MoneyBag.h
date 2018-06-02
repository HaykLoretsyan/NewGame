#ifndef MONEYBAG_H
#define MONEYBAG_H

#include <QString>

#include "ResourceManager.h"


class MoneyBag
{
public:
    MoneyBag(QString accountName);

    bool idPurchasable();
    void purchase();

private:
    QString m_accountName;

    unsigned m_gold;
    unsigned m_token;

    unsigned m_redGem;
    unsigned m_blueGem;
    unsigned m_greenGem;
};

#endif // MONEYBAG_H
