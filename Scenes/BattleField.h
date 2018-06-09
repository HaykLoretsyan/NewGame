#ifndef BATTLEFIELD_H
#define BATTLEFIELD_H

#include <QString>

#include "Scene.h"

#include "PlayerAttributes/Player.h"
#include "Fight/FightAction.h"
#include "Fight/Award.h"


class BattleField : public Scene
{
    Q_OBJECT

public:
    BattleField();

public:
    void activateCharacter(QString characterName);
    void takeAction(FightAction* action);

    void showAward(Award award);

public: // Scene interface
    void activateScene() override;
    void deactivateScene() override;

signals:
    void started();
    void resumed();
    void finished();

    void actionRequest(FightActionRequest action);
};

#endif // BATTLEFIELD_H
