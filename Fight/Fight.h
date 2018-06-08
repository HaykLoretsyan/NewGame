#ifndef FIGHT_H
#define FIGHT_H

#include <QObject>
#include <QString>
#include <QMap>
#include <QTimer>

#include "Scenes/BattleField.h"

#include "PlayerAttributes/Player.h"
#include "NinjaSkills/Skill.h"
#include "NinjaSkills/SkillEffect.h"

#include "FightAction.h"
#include "FightNetworkController.h"
#include "FightLocalController.h"
#include "Ninja.h"


class Fight : public QObject
{
    Q_OBJECT

public:
    Fight(BattleField* battleField,
          QVector<Player*> firstTeam,
          QVector<Player*> secondTeam,
          bool isOnlineFight = false);

    QMap<QString, Ninja*> allNinjas() const;

    unsigned timeToHit() const;

public slots:
    void start();
    void resume();
    void finish();

    void onTimer();

    void onAction(FightAction* action);

private:
    void createController(bool isOnlineFight);

private:
    BattleField* m_battleField;
    FightController* m_controller;

    QMap<QString, Ninja*> m_allNinjas;
    unsigned m_timeToHit;

private:
    QTimer* m_timer;

};

#endif // FIGHT_H
