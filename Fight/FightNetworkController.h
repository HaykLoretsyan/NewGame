#ifndef FIGHTNETWORKCONTROLLER_H
#define FIGHTNETWORKCONTROLLER_H

#include "FightController.h"


class FightNetworkController : public FightController
{
public:
    FightNetworkController(QVector<Ninja*> ninjas);

    // FightController interface
public:
    void activate(Ninja* ninja) override;

    void selfRequestHandler(FightActionRequest request);
    void networkActionHandler(FightAction *action);
};

#endif // FIGHTNETWORKCONTROLLER_H
