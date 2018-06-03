#ifndef SKILLCHARACTERISTICS_H
#define SKILLCHARACTERISTICS_H

#include <QPixmap>
#include <QVector>
#include <QString>

#include "SkillEffect.h"

#include "Items/Money.h"

struct SkillCharacteristics
{
    QString name;
    QString description;

    QPixmap* icon;
    Money cost;

    unsigned damage;
    unsigned energyConsume;
    QVector<SkillEffect> rivalEffects;
    QVector<SkillEffect> selfEffects;
};

#endif // SKILLCHARACTERISTICS_H
