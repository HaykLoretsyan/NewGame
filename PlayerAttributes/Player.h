#ifndef PLAYER_H
#define PLAYER_H

#include <QObject>
#include <QString>

#include "NinjaCharacteristics.h"


class Player : public QObject
{
    Q_OBJECT

public:
    Player(QString accountName);

private:
    NinjaCharacteristics* characteristics;

    QString m_account_name;
};

#endif // PLAYER_H
