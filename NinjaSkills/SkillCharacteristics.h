#ifndef SKILLCHARACTERISTICS_H
#define SKILLCHARACTERISTICS_H

#include <QPixmap>
#include <QVector>
#include <QString>

#include "SkillEffect.h"

struct SkillCharacteristics
{
    QString name;
    QString description;

    QPixmap* icon;

    unsigned costInGold;
    unsigned costInTokens;

    unsigned damage;
    unsigned accuracy;

    QVector<SkillEffect> effects;
};

#endif // SKILLCHARACTERISTICS_H
