#ifndef SKILL_H
#define SKILL_H

#include "SkillCharacteristics.h"

#include "Items/Money.h"


class Skill
{
public:
    Skill();
    Skill(SkillCharacteristics characteristics);
    Skill(const Skill &other);

    QString name() const;
    QString description() const;
    Money cost() const;
    QPixmap* icon() const;

    SkillCharacteristics characteristics() const;

private:
    SkillCharacteristics m_characteristics;
};

#endif // SKILL_H
