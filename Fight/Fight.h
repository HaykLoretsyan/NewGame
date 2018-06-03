#ifndef FIGHT_H
#define FIGHT_H

#include <QObject>
#include <QMap>

#include "PlayerAttributes/Player.h"
#include "NinjaSkills/Skill.h"
#include "NinjaSkills/SkillEffect.h"
#include "NinjaState.h"


class Fight : public QObject
{
    Q_OBJECT

public:
    Fight(QVector<Player*> firstTeam, QVector<Player*> secondTeam);

    QMap<Player*, NinjaState*> allPlayers() const;

public slots:
    void start();
    void end();

private:
    QMap<Player*, NinjaState*> m_allPlayers;

    unsigned timeToHit;

};

#endif // FIGHT_H
