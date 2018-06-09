#include "FightAction.h"

FightAction::FightAction()
{

}

FightAction::FightAction(FightActionRequest request)
{
    Q_UNUSED(request)
}

FightAction::FightAction(const FightAction &action)
{
    Q_UNUSED(action)
}

void FightAction::affectNinjaIfRequired(QString name, Ninja* ninja)
{
    Q_UNUSED(name)
    Q_UNUSED(ninja)
}

QMap<QString, Affection> FightAction::affectedNinjas() const
{
    return m_affectedNinjas;
}
