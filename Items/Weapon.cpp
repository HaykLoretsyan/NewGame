#include "Weapon.h"

Weapon::Weapon(QString name,
               Money cost,
               QPixmap icon) :
    Item(name, cost, icon)
{

}

unsigned Weapon::damage() const
{
    return m_damage;
}

QVector<SkillEffect> &Weapon::effects()
{
    return m_effects;
}
