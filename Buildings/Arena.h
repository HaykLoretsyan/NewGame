#ifndef ARENA_H
#define ARENA_H

#include <QObject>
#include <QVector>

#include "PlayerAttributes/Player.h"


class Arena : public QObject
{
    Q_OBJECT

public:
    Arena(Player* player);

signals:


private:
    Player* m_player;


};

#endif // ARENA_H
