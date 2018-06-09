#ifndef FIGHTACTION_H
#define FIGHTACTION_H

#include <QMap>
#include <QString>

#include "NinjaSkills/Skill.h"

#include "Fight/Ninja.h"


struct FightActionRequest
{
    QString doer;
    QString receiver;
    Skill* skill;
};

struct Affection
{
    enum class Type
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

    QMap<Type, int> allAffections;
};

class FightAction
{
public:
    FightAction();
    FightAction(FightActionRequest request);
    FightAction(const FightAction& action);

    void affectNinjaIfRequired(QString name, Ninja* ninja);

    QMap<QString, Affection> affectedNinjas() const;

private:
    QMap<QString, Affection> m_affectedNinjas;
};

#endif // FIGHTACTION_H
