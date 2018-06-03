#ifndef NINJASTATE_H
#define NINJASTATE_H

#include <QVector>
#include <QMap>
#include <QObject>

#include "PlayerAttributes/NinjaCharacteristics.h"
#include "NinjaSkills/Skill.h"
#include "Items/Weapon.h"
#include "Items/Gear.h"


class NinjaState : public QObject
{
    Q_OBJECT

public:
    enum class Side
    {
        RED,
        BLUE
    };

public:
    NinjaState(NinjaCharacteristics* characteristics,
               Weapon* weapon,
               Gear* gear,
               Side side);

    /**
     * @brief proceedTurn Do all necesserary staff before
     *        starting your turn (proceeding effects etc.)
     */
    void proceedTurn();

    /**
     * @brief takeAHitByWeapon called when another ninja attacked
     *        by weapon
     * @param weapon
     */
    void takeAHitByWeapon(Weapon weapon);

    /**
     * @brief takeAHitBySkill called when another ninja attacked
     *        by skill
     * @param skill
     */
    void takeAHitBySkill(Skill skill);

    /**
     * @brief consumableSkills skills that are available with
     *        current energy level
     * @return
     */
    QVector<Skill> consumableSkills() const;

    /**
     * @brief consumeASkill consume skill using energy
     * @param skill
     */
    void consumeASkill(Skill skill);

    /**
     * @brief position current progress to your turn
     */
    unsigned position() const;

    /**
     * @brief resetCurrentPosition reset current progress to zero
     */
    void resetCurrentPosition();

    /**
     * @brief incrementCurrentPosition increment your position according
     *        to current speed
     */
    void incrementCurrentPosition();

    /**
     * @brief side team of the ninja (red or blue)
     * @return
     */
    Side side() const;

signals:
    void isDead();

private:
    /**
     * @brief skillIsConsumable check whether there is enough energy
     *        to consume the skill 'skill'
     * @param skill
     * @return
     */
    bool skillIsConsumable(Skill &skill) const;

    /**
     * @brief checkIfIsAlive Checking if health is above 0 and
     *        if not emit isDead() signal
     * @return
     */
    bool checkIfIsAlive();

private:
    bool m_isAlive;

    Weapon* m_weapon;
    Gear* m_gear;

    unsigned m_currentHealth;
    unsigned m_currentEnergy;
    unsigned m_currentSpeed;

    QVector<Skill> m_availableSkills;
    QMap<SkillEffect::Type, unsigned> m_currentEffectResistances;

    QVector<SkillEffect> m_currentConditions;
    unsigned m_currentPosition;

private:
    NinjaCharacteristics* m_characteristics;
    Side m_side;
};

#endif // NINJASTATE_H
