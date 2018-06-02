#ifndef PLAYER_H
#define PLAYER_H

#include <QString>

#include "NinjaCharacteristics.h"


class Player
{
public:
    Player(QString accountName);

private:
    NinjaCharacteristics* characteristics;

    QString m_account_name;
};

#endif // PLAYER_H
