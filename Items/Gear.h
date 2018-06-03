#ifndef GEAR_H
#define GEAR_H

#include <QMap>

#include "Item.h"
#include "NinjaSkills/SkillEffect.h"


class Gear : public Item
{

public:
    Gear(QString name,
         Money cost,
         QPixmap icon);

    Gear(const Gear & other);

    void addEffect(SkillEffect effect);
    QMap<SkillEffect::Type, SkillEffect> effects() const;

    unsigned healthRegeneration() const;
    unsigned energyRegeneration() const;
    unsigned damageProtection() const;

private:
    QMap<SkillEffect::Type, SkillEffect> m_effects;
};

#endif // GEAR_H
