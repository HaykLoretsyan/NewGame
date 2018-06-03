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

void Gear::addEffect(SkillEffect effect)
{
    if(effect.type() != SkillEffect::Type::HealthRegeneration &&
       effect.type() != SkillEffect::Type::EnergyRegeneration &&
       effect.type() != SkillEffect::Type::DamageProtection )
    {
        return;
    }

    m_effects.insert(effect.type(), effect);
}

QMap<SkillEffect::Type, SkillEffect> Gear::effects() const
{
    return m_effects;
}

unsigned Gear::healthRegeneration() const
{
    if(!m_effects.contains(SkillEffect::Type::HealthRegeneration)) {
        return 0;
    }

    return m_effects[SkillEffect::Type::HealthRegeneration].power();
}

unsigned Gear::energyRegeneration() const
{
    if(!m_effects.contains(SkillEffect::Type::EnergyRegeneration)) {
        return 0;
    }

    return m_effects[SkillEffect::Type::EnergyRegeneration].power();
}

unsigned Gear::damageProtection() const
{
    if(!m_effects.contains(SkillEffect::Type::DamageProtection)) {
        return 0;
    }

    return m_effects[SkillEffect::Type::DamageProtection].power();
}
