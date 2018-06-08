#ifndef FIGHTACTION_H
#define FIGHTACTION_H

#include <QMap>
#include <QString>

#include "NinjaSkills/Skill.h"

#include "Fight/Ninja.h"


struct FightActionRequest
{
    Ninja* doer;
    Ninja* receiver;
    Skill* skill;
};


class FightAction
{
    enum class AffectionType
    {
        SkillConsumed,
        WeaponUsed,
        Damaged,
        Killed,
        Healed,
        Energized,
        PositiveBuffed,
        NegativeBuffed
    };

public:
    FightAction();
    FightAction(FightActionRequest request);
    FightAction(const FightAction& action);

    void affectNinjaIfRequired(QString name, Ninja* ninja);

    QMap<QString, AffectionType> affectedNinjas() const;

private:
    QMap<QString, AffectionType> m_affectedNinjas;
};

#endif // FIGHTACTION_H
