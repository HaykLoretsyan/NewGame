#include "Ninja.h"

Ninja::Ninja(NinjaCharacteristics *characteristics,
             Weapon *weapon,
             Gear *gear,
             Side side,
             Control control) :
    m_isAlive(true),
    m_weapon(weapon),
    m_gear(gear),
    m_currentHealth(characteristics->health),
    m_currentEnergy(characteristics->energy),
    m_currentSpeed(characteristics->speed),
    m_currentEffectResistances(characteristics->effectResistances),
    m_currentPosition(0),

    m_characteristics(characteristics),
    m_side(side),
    m_control(control)
{

}

void Ninja::proceedTurn()
{
    for(SkillEffect& effect : m_currentConditions) {
        // TODO proceed every effect
        Q_UNUSED(effect)
    }

    m_availableSkills.clear();

    for(Skill& skill : m_characteristics->skills) {
        if(skillIsConsumable(skill)) {
            m_availableSkills.push_back(skill);
        }
    }
}


void Ninja::takeAHitByWeapon(Weapon weapon, bool directHit)
{
    if(directHit)
    {
        m_currentHealth -= weapon.damage();

        if(!checkIfIsAlive()) {
            return;
        }

        m_currentConditions += weapon.effects();
    }
}

void Ninja::takeAHitBySkill(Skill skill, bool directHit)
{
    if(directHit)
    {
        m_currentHealth -= skill.characteristics().damage;

        if(!checkIfIsAlive()) {
            return;
        }

        m_currentConditions += skill.characteristics().rivalEffects;
    }
}

QVector<Skill> Ninja::consumableSkills() const
{
    return m_availableSkills;
}

void Ninja::consumeASkill(Skill skill)
{
    m_currentEnergy -= skill.characteristics().energyConsume;

    m_currentConditions += skill.characteristics().selfEffects;
}

unsigned Ninja::position() const
{
    return m_currentPosition;
}

void Ninja::resetCurrentPosition()
{
    m_currentPosition = 0;
}

void Ninja::incrementCurrentPosition()
{
    m_currentPosition += m_currentSpeed;
}

NinjaCharacteristics *Ninja::characteristics() const
{
    return m_characteristics;
}

Ninja::Side Ninja::side() const
{
    return m_side;
}

Ninja::Control Ninja::control() const
{
    return m_control;
}

bool Ninja::skillIsConsumable(Skill& skill) const
{
    if(m_currentEnergy > skill.characteristics().energyConsume) {
        return true;
    }

    return false;
}

bool Ninja::checkIfIsAlive()
{
    if(m_currentHealth <= 0) {
        m_isAlive = false;
        m_currentSpeed = 0;

        emit isDead();

        return false;
    }

    return true;
}
