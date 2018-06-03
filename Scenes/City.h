#ifndef CITY_H
#define CITY_H

#include <QBrush>
#include <QColor>

#include "Scene.h"

#include "PlayerAttributes/Player.h"


class City : public Scene
{
public:
    City(Player* player);

    // Scene interface
public:
    void activateScene() override;
    void deactivateScene() override;

private:
    Player* m_player;
};

#endif // CITY_H
