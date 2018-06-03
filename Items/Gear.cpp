#include "Gear.h"

Gear::Gear(QString name,
           Money cost,
           QPixmap icon) :
    Item(name, cost, icon)
{

}

Gear::Gear(const Gear & other) :
    Item(other.name(), other.cost(), other.icon()),
    m_effects(other.effects())
{

}

void Gear::addEffect(Gear::EFFECT effect, unsigned power)
{
    m_effects.insert(effect, power);
}

QMap<Gear::EFFECT, unsigned> Gear::effects() const
{
    return m_effects;
}

unsigned Gear::healthRegeneration() const
{
    if(!m_effects.contains(EFFECT::HealthRegeneration)) {
        return 0;
    }

    return m_effects[EFFECT::HealthRegeneration];
}

unsigned Gear::energyRegeneration() const
{
    if(!m_effects.contains(EFFECT::EnergyRegeneration)) {
        return 0;
    }

    return m_effects[EFFECT::EnergyRegeneration];
}

unsigned Gear::damageProtection() const
{
    if(!m_effects.contains(EFFECT::DamageProtection)) {
        return 0;
    }

    return m_effects[EFFECT::DamageProtection];
}
