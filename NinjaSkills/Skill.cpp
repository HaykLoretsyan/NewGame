#include "Skill.h"

Skill::Skill()
{

}

Skill::Skill(SkillCharacteristics characteristics) :
    m_characteristics(characteristics)
{

}

Skill::Skill(const Skill &other) :
    m_characteristics(other.characteristics())
{

}

QString Skill::name() const
{
    return m_characteristics.name;
}

QString Skill::description() const
{
    return m_characteristics.description;
}

Money Skill::cost() const
{
    return m_characteristics.cost;
}

QPixmap *Skill::icon() const
{
    return m_characteristics.icon;
}

SkillCharacteristics Skill::characteristics() const
{
    return m_characteristics;
}
