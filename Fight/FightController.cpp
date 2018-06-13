#include "FightController.h"

FightController::FightController(QMap<QString, Ninja*> ninjas) :
    m_allNinjas(ninjas)
{
    for(Ninja* ninja : m_allNinjas.values()) {
        if(ninja->control() == Ninja::Control::Self) {
            m_self = ninja;
            break;
        }
    }
}

FightController::~FightController()
{
    for(FightAction* action : m_allActions) {
        delete action;
    }
}
