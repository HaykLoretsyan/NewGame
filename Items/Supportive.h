#ifndef SUPPORTIVE_H
#define SUPPORTIVE_H

#include <QMap>

#include "Item.h"


class Supportive : public Item
{
public:
    enum class EFFECT
    {
        HealthGain,
        EnergyGain,
        HealthRegeneration,
        EnergyRegeneration
    };

public:
    Supportive(QString name,
               Money cost,
               QPixmap icon);

    Supportive(const Supportive & other);

    void addEffect(EFFECT effect, unsigned power);
    QMap<EFFECT, unsigned> effects() const;

    unsigned healthGain() const;
    unsigned energyGain() const;
    unsigned healthRegeneration() const;
    unsigned energyRegeneration() const;

private:
    QMap<EFFECT, unsigned> m_effects;

};

#endif // SUPPORTIVE_H
