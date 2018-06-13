#include "FightAction.h"

FightAction::FightAction()
{

}

FightAction::FightAction(FightActionRequest request)
{
    m_request.doer = request.doer;
    m_request.receiver = request.receiver;
    m_request.skill = new Skill(*request.skill);
}

FightAction::FightAction(const FightAction &action) :
    m_affectedNinjas(action.affectedNinjas()),
    m_request(action.request())
{
    Q_UNUSED(action)
}

void FightAction::affectNinjaIfRequired(QString name, Ninja* ninja)
{
    Q_UNUSED(name)

    if(name == m_request.receiver) {
        if(m_request.skill == nullptr) {
//            ninja->takeAHitByWeapon(*m_request.skill);
        } else {
            ninja->takeAHitBySkill(*m_request.skill);
        }
    }
//    m_affectedNinjas.insert(name, ninja);
}

QMap<QString, Affection> FightAction::affectedNinjas() const
{
    return m_affectedNinjas;
}

FightActionRequest FightAction::request() const
{
    return m_request;
}
