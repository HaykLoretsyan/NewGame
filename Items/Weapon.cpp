#include "Weapon.h"

Weapon::Weapon(QString name,
               Money cost,
               QPixmap icon) :
    Item(name, cost, icon)
{

}

Weapon::Weapon(const Weapon &other) :
    Item(other.name(), other.cost(), other.icon()),
    m_damage(other.damage()),
    m_effects(other.effects())
{

}

unsigned Weapon::damage() const
{
    return m_damage;
}

QVector<SkillEffect> Weapon::effects() const
{
    return m_effects;
}
