#ifndef NINJACHARACTERISTICS_H
#define NINJACHARACTERISTICS_H

#include <QString>
#include <QMap>

#include "NinjaSkills/Skill.h"
#include "NinjaSkills/SkillEffect.h"
#include "Character.h"


struct NinjaCharacteristics
{
    unsigned health;
    unsigned energy;

    unsigned dodge;
    unsigned accuracy;
    unsigned damageResistance;

    QVector<Skill> skills;
    QMap<SkillEffect::Type, unsigned> effectResistances;

    Character character;
};

#endif // NINJACHARACTERISTICS_H
