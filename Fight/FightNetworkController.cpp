#include "FightNetworkController.h"

FightNetworkController::FightNetworkController(QVector<Ninja *> ninjas) : FightController(ninjas)
{

}

void FightNetworkController::activate(Ninja *ninja)
{
    Q_UNUSED(ninja)
}

void FightNetworkController::selfRequestHandler(FightActionRequest request)
{
    Q_UNUSED(request)
}

void FightNetworkController::networkActionHandler(FightAction *action)
{
    Q_UNUSED(action)
}
