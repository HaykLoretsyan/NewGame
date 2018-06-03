#ifndef SUPPORTIVE_H
#define SUPPORTIVE_H

#include <QMap>

#include "Item.h"
#include "NinjaSkills/SkillEffect.h"


class Supportive : public Item
{
public:
    Supportive(QString name,
               Money cost,
               QPixmap icon);

    Supportive(const Supportive & other);

    void addEffect(SkillEffect effect);
    QMap<SkillEffect::Type, SkillEffect> effects() const;

    unsigned healthGain() const;
    unsigned energyGain() const;

    unsigned healthRegenerationDuration() const;
    unsigned healthRegenerationPower() const;
    unsigned energyRegenerationDuration() const;
    unsigned energyRegenerationPower() const;

private:
    QMap<SkillEffect::Type, SkillEffect> m_effects;

};

#endif // SUPPORTIVE_H
