#include "FightController.h"

FightController::FightController(QVector<Ninja *> ninjas) :
    m_allNinjas(ninjas)
{

}

FightController::~FightController()
{
    for(FightAction* action : m_allActions) {
        delete action;
    }
}
