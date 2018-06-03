#ifndef ARENA_H
#define ARENA_H

#include <QObject>
#include <QVector>

#include "Scene.h"
#include "PlayerAttributes/Player.h"


class Arena : public Scene
{
    Q_OBJECT

public:
    Arena(Player* player);

signals:


private:
    Player* m_player;


    // Scene interface
public:
    void activateScene() override;
    void deactivateScene() override;
};

#endif // ARENA_H
