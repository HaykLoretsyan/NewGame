#ifndef FIGHTLOCALCONTROLLER_H
#define FIGHTLOCALCONTROLLER_H

#include "FightController.h"
#include "BotController.h"
#include "FightAction.h"

#include "CustomExceptions.h"


class FightLocalController : public FightController
{
public:
    FightLocalController(QMap<QString, Ninja*> ninjas);
    ~FightLocalController();

    // FightController interface
public:
    void activate(Ninja* ninja) override;

    void selfRequestHandler(FightActionRequest request);
    void networkActionHandler(FightAction *action);

private:
    void botActionHandler(FightAction *action);

private:
    BotController* m_botController;
};

#endif // FIGHTLOCALCONTROLLER_H
