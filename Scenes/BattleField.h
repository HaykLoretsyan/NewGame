#ifndef BATTLEFIELD_H
#define BATTLEFIELD_H

#include <QString>

#include "Scene.h"

#include "PlayerAttributes/Player.h"
#include "Fight/FightAction.h"


class BattleField : public Scene
{
    Q_OBJECT

public:
    BattleField();

public:
    void activateCharacter(QString characterName);
    void takeAction(FightAction* action);

    // Scene interface
public:
    void activateScene() override;
    void deactivateScene() override;

signals:
    void started();
    void resumed();
    void finished();

    void actionRequest(FightAction* action);
};

#endif // BATTLEFIELD_H
