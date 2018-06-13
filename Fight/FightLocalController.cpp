#include "FightLocalController.h"

FightLocalController::FightLocalController(QMap<QString, Ninja *> ninjas) : FightController(ninjas)
{
    m_botController = new BotController();
}

FightLocalController::~FightLocalController()
{
    delete m_botController;
}

void FightLocalController::activate(Ninja *ninja)
{
    switch(ninja->control())
    {
    case Ninja::Control::Bot:
        break;
    case Ninja::Control::Self:
        break;
    default:
        throw NetworkingNotAvailableException();
        break;
    }
}

void FightLocalController::selfRequestHandler(FightActionRequest request)
{
    FightAction* act = new FightAction(request);

    emit action(act);
}

void FightLocalController::networkActionHandler(FightAction *action)
{
    Q_UNUSED(action)

    throw NetworkingNotAvailableException();
}

void FightLocalController::botActionHandler(FightAction *action)
{
    Q_UNUSED(action)
}
