#include "Arena.h"

Arena::Arena(Player *player) :
    m_player(player),
    m_battleField(nullptr),
    m_fight(nullptr),
    m_bots(ResourceManager::instance().botsForLevel(m_player->level()))
{

}

void Arena::activateScene()
{

}

void Arena::deactivateScene()
{

}

void Arena::fightABot(int botNumber)
{
    if(botNumber > m_bots.size() - 1) {
        throw IllegalFightCreation();
    }

    QVector<Player*> firstTeam;
    QVector<Player*> secondTeam;

    firstTeam.push_back(m_player);
    secondTeam.push_back(m_bots[botNumber]);

    createBattleField(firstTeam, secondTeam);
    changeScene("BattleField");

    m_fight = new Fight(m_battleField, firstTeam, secondTeam, ResourceManager::instance().networkUsed());
    m_fight->start();
}

void Arena::searchForAPlayer()
{
    if(!ResourceManager::instance().networkUsed()) {
        return;
    }
}

void Arena::createBattleField(QVector<Player *> &firstTeam, QVector<Player *> &secondTeam)
{
    if(m_battleField != nullptr) {
        delete m_battleField;
    }

    m_battleField = new BattleField(firstTeam, secondTeam, "Arena");

    addScene("BattleField", m_battleField);
}
