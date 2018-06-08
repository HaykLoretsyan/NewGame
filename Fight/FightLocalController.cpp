#include "FightLocalController.h"

FightLocalController::FightLocalController(QVector<Ninja *> ninjas) : FightController(ninjas)
{

}

void FightLocalController::activate(Ninja *ninja)
{
    Q_UNUSED(ninja)
}

void FightLocalController::selfRequestHandler(FightActionRequest request)
{
    Q_UNUSED(request)
}

void FightLocalController::networkActionHandler(FightAction *action)
{
    Q_UNUSED(action)

    throw NetworkingNotAvailableException();
}
