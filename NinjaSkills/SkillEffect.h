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
        Sleeping
    };

public:
    SkillEffect(Type type,
                unsigned duration = 1,
                unsigned level = 1);

    Type type() const;

    QString description() const;
    void setDescription(const QString &description);

    unsigned duration() const;
    void setDuration(const unsigned &value);

    unsigned level() const;
    void setLevel(const unsigned &value);


private:
    Type m_type;

    QString m_description;
    unsigned m_duration;
    unsigned m_level;
};

#endif // SKILLEFFECT_H
