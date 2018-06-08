#ifndef FIGHTLOCALCONTROLLER_H
#define FIGHTLOCALCONTROLLER_H

#include "FightController.h"

#include "CustomExceptions.h"


class FightLocalController : public FightController
{
public:
    FightLocalController(QVector<Ninja*> ninjas);

    // FightController interface
public:
    void activate(Ninja* ninja) override;

    void selfRequestHandler(FightActionRequest request);
    void networkActionHandler(FightAction *action);
};

#endif // FIGHTLOCALCONTROLLER_H
