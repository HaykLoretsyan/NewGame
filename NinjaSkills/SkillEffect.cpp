#include "SkillEffect.h"

SkillEffect::SkillEffect(Type type,
                         unsigned duration,
                         unsigned level) :
    m_type(type),
    m_duration(duration),
    m_level(level)
{

}

SkillEffect::Type SkillEffect::type() const
{
    return m_type;
}

QString SkillEffect::description() const
{
    return m_description;
}

void SkillEffect::setDescription(const QString &description)
{
    m_description = description;
}

unsigned SkillEffect::duration() const
{
    return m_duration;
}

void SkillEffect::setDuration(const unsigned &value)
{
    m_duration = value;
}

unsigned SkillEffect::level() const
{
    return m_level;
}

void SkillEffect::setLevel(const unsigned &value)
{
    m_level = value;
}
