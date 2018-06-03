#include "NinjaState.h"

NinjaState::NinjaState(NinjaCharacteristics *characteristics,
                       Weapon *weapon,
                       Gear *gear,
                       Side side) :
    m_isAlive(true),
    m_weapon(weapon),
    m_gear(gear),
    m_currentHealth(characteristics->health),
    m_currentEnergy(characteristics->energy),
    m_currentSpeed(characteristics->speed),
    m_currentEffectResistances(characteristics->effectResistances),
    m_currentPosition(0),

    m_characteristics(characteristics),
    m_side(side)
{

}

void NinjaState::proceedTurn()
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


void NinjaState::takeAHitByWeapon(Weapon weapon)
{
    m_currentHealth -= weapon.damage();

    if(!checkIfIsAlive()) {
        return;
    }

    m_currentConditions += weapon.effects();
}

void NinjaState::takeAHitBySkill(Skill skill)
{
    m_currentHealth -= skill.characteristics().damage;

    if(!checkIfIsAlive()) {
        return;
    }

    m_currentConditions += skill.characteristics().rivalEffects;
}

QVector<Skill> NinjaState::consumableSkills() const
{
    return m_availableSkills;
}

void NinjaState::consumeASkill(Skill skill)
{
    m_currentEnergy -= skill.characteristics().energyConsume;

    m_currentConditions += skill.characteristics().selfEffects;
}

unsigned NinjaState::position() const
{
    return m_currentPosition;
}

void NinjaState::resetCurrentPosition()
{
    m_currentPosition = 0;
}

void NinjaState::incrementCurrentPosition()
{
    m_currentPosition += m_currentSpeed;
}

NinjaState::Side NinjaState::side() const
{
    return m_side;
}

bool NinjaState::skillIsConsumable(Skill& skill) const
{
    if(m_currentEnergy > skill.characteristics().energyConsume) {
        return true;
    }

    return false;
}

bool NinjaState::checkIfIsAlive()
{
    if(m_currentHealth <= 0) {
        m_isAlive = false;
        m_currentSpeed = 0;

        emit isDead();

        return false;
    }

    return true;
}
