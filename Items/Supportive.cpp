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

void Supportive::addEffect(SkillEffect effect)
{
    if(effect.type() != SkillEffect::Type::HealthGain &&
       effect.type() != SkillEffect::Type::EnergyGain &&
       effect.type() != SkillEffect::Type::HealthRegeneration &&
       effect.type() != SkillEffect::Type::EnergyRegeneration)
    {
        return;
    }

    m_effects.insert(effect.type(), effect);
}

QMap<SkillEffect::Type, SkillEffect> Supportive::effects() const
{
    return m_effects;
}

unsigned Supportive::healthGain() const
{
    if(!m_effects.contains(SkillEffect::Type::HealthGain)) {
        return 0;
    }

    return m_effects[SkillEffect::Type::HealthGain].power();
}

unsigned Supportive::energyGain() const
{
    if(!m_effects.contains(SkillEffect::Type::EnergyGain)) {
        return 0;
    }

    return m_effects[SkillEffect::Type::EnergyGain].power();
}

unsigned Supportive::healthRegenerationDuration() const
{
    if(!m_effects.contains(SkillEffect::Type::HealthRegeneration)) {
        return 0;
    }

    return m_effects[SkillEffect::Type::HealthRegeneration].duration();
}

unsigned Supportive::healthRegenerationPower() const
{
    if(!m_effects.contains(SkillEffect::Type::HealthRegeneration)) {
        return 0;
    }

    return m_effects[SkillEffect::Type::HealthRegeneration].power();
}

unsigned Supportive::energyRegenerationDuration() const
{
    if(!m_effects.contains(SkillEffect::Type::EnergyRegeneration)) {
        return 0;
    }

    return m_effects[SkillEffect::Type::EnergyRegeneration].duration();
}

unsigned Supportive::energyRegenerationPower() const
{
    if(!m_effects.contains(SkillEffect::Type::EnergyRegeneration)) {
        return 0;
    }

    return m_effects[SkillEffect::Type::EnergyRegeneration].power();
}
