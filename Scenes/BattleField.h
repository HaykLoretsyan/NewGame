#ifndef BATTLEFIELD_H
#define BATTLEFIELD_H

#include "Scene.h"

#include "PlayerAttributes/Player.h"
#include "Fight/Fight.h"


class BattleField : public Scene
{
    Q_OBJECT

public:
    BattleField(Fight* fight);

    // Scene interface
public:
    void activateScene() override;
    void deactivateScene() override;

private:
    Fight* m_fight;
};

#endif // BATTLEFIELD_H
