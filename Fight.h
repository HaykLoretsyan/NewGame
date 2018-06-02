#ifndef FIGHT_H
#define FIGHT_H

#include <QThread>
#include <QMap>

#include "PlayerAttributes/Player.h"
#include "NinjaSkills/Skill.h"
#include "NinjaSkills/SkillEffect.h"


class Fight : public QThread
{
    enum class PlayerSide
    {
        READ,
        BLUE
    };

public:
    Fight(QVector<Player*> firstTeam, QVector<Player*> secondTeam);

private:
    QMap<Player*, PlayerSide> m_allPlayers;

};

#endif // FIGHT_H
