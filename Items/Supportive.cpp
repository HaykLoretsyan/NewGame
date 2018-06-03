#include "Supportive.h"

Supportive::Supportive(QString name,
                       Money cost,
                       QPixmap icon) :
    Item(name, cost, icon)
{

}

Supportive::Supportive(const Supportive &other) :
    Item(other.name(), other.cost(), other.icon()),
    m_effects(other.effects())
{

}

void Supportive::addEffect(Supportive::EFFECT effect, unsigned power)
{
    m_effects.insert(effect, power);
}

QMap<Supportive::EFFECT, unsigned> Supportive::effects() const
{
    return m_effects;
}

unsigned Supportive::healthGain() const
{
    if(!m_effects.contains(EFFECT::HealthGain)) {
        return 0;
    }

    return m_effects[EFFECT::HealthGain];
}

unsigned Supportive::energyGain() const
{
    if(!m_effects.contains(EFFECT::EnergyGain)) {
        return 0;
    }

    return m_effects[EFFECT::EnergyGain];
}

unsigned Supportive::healthRegeneration() const
{
    if(!m_effects.contains(EFFECT::HealthRegeneration)) {
        return 0;
    }

    return m_effects[EFFECT::HealthRegeneration];
}

unsigned Supportive::energyRegeneration() const
{
    if(!m_effects.contains(EFFECT::EnergyRegeneration)) {
        return 0;
    }

    return m_effects[EFFECT::EnergyRegeneration];
}
