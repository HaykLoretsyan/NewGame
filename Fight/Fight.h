#ifndef FIGHT_H
#define FIGHT_H

#include <QObject>
#include <QString>
#include <QMap>
#include <QTimer>

#include "CustomExceptions.h"

#include "Scenes/BattleField.h"

#include "PlayerAttributes/Player.h"
#include "NinjaSkills/Skill.h"
#include "NinjaSkills/SkillEffect.h"

#include "AwardManager.h"
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
    ~Fight();

    /**
     * @brief allNinjas
     * @return all Fighting ninjas
     */
    QMap<QString, Ninja*> allNinjas() const;

    /**
     * @brief timeToHit time span to pass until your
     *        turn (depends on each ninja's speed)
     */
    unsigned timeToHit() const;

    /**
     * @brief awardManager
     * @return award management system
     */
    AwardManager* awardManager() const;

public slots:
    /**
     * @brief start starting the battle
     */
    void start();

    /**
     * @brief resume resuming after action
     */
    void resume();

    /**
     * @brief finish finishing the battle
     */
    void finish();

    /**
     * @brief onTimer making progress on timer timeout
     */
    void onTimer();

    /**
     * @brief onAction on requesting action by any ninja
     * @param action
     */
    void onAction(FightAction* action);

private: // Helper functions
    void createController(bool isOnlineFight);

private:
    Player* m_self;
    BattleField* m_battleField;
    FightController* m_controller;

    QMap<QString, Ninja*> m_allNinjas;
    unsigned m_timeToHit;

private:
    QTimer* m_timer;

private:
    AwardManager* m_awardManager;

};

#endif // FIGHT_H
