#ifndef SKILLEFFECT_H
#define SKILLEFFECT_H

#include <QString>
#include <QMap>


class SkillEffect
{
public:

    enum class Type
    {
        Burning,
        Bleeding,
        Blinding,
        Paralyzing,
        Sleeping,
        HealthGain,
        EnergyGain,
        HealthRegeneration,
        EnergyRegeneration,
        DamageProtection
    };

public:
    SkillEffect();

    SkillEffect(Type type,
                unsigned duration = 1,
                unsigned power = 1);

    Type type() const;

    QString description() const;
    void setDescription(const QString &description);

    unsigned duration() const;
    void setDuration(const unsigned &value);

    unsigned power() const;
    void setPower(const unsigned &value);


private:
    Type m_type;

    QString m_description;
    unsigned m_duration;
    unsigned m_power;
};

#endif // SKILLEFFECT_H
