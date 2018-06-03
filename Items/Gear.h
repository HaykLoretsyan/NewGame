#ifndef GEAR_H
#define GEAR_H

#include <QMap>

#include "Item.h"


class Gear : public Item
{
public:
    enum class EFFECT
    {
        HealthRegeneration,
        EnergyRegeneration,
        DamageProtection
    };

public:
    Gear(QString name,
         Money cost,
         QPixmap icon);

    Gear(const Gear & other);

    void addEffect(Gear::EFFECT effect, unsigned power);
    QMap<EFFECT, unsigned> effects() const;

    unsigned healthRegeneration() const;
    unsigned energyRegeneration() const;
    unsigned damageProtection() const;

private:
    QMap<EFFECT, unsigned> m_effects;
};

#endif // GEAR_H
