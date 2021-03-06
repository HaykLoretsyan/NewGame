#ifndef WEAPON_H
#define WEAPON_H

#include <QVector>

#include "Item.h"

#include "NinjaSkills/SkillEffect.h"


class Weapon : public Item
{
public:
    Weapon(QString name, Money cost, QPixmap icon);
    Weapon(const Weapon & other);

    unsigned damage() const;
    QVector<SkillEffect> effects() const;

private:
    unsigned m_damage;
    QVector<SkillEffect> m_effects;

};

#endif // WEAPON_H
