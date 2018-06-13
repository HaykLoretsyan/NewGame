#ifndef FIGHTNETWORKCONTROLLER_H
#define FIGHTNETWORKCONTROLLER_H

#include "FightController.h"
#include "BotController.h"


class FightNetworkController : public FightController
{
public:
    FightNetworkController(QMap<QString, Ninja*> ninjas);

    // FightController interface
public:
    void activate(Ninja* ninja) override;

    void selfRequestHandler(FightActionRequest request);
    void networkActionHandler(FightAction *action);
};

#endif // FIGHTNETWORKCONTROLLER_H
