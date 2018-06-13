#include "BattleField.h"

BattleField::BattleField(QVector<Player *> firstTeam,
                         QVector<Player *> secondTeam,
                         QString fightPlace) :
    m_firstTeam(firstTeam),
    m_secondTeam(secondTeam)
{
    Q_UNUSED(fightPlace)
}

void BattleField::activateCharacter(QString characterName)
{
    Q_UNUSED(characterName)
}

void BattleField::changeCharacterProgress(QString characterName, double percent)
{
    Q_UNUSED(characterName)
    Q_UNUSED(percent)
}

void BattleField::takeAction(FightAction *action)
{
    Q_UNUSED(action)
}

void BattleField::showAward(Award award)
{
    Q_UNUSED(award)
}

void BattleField::activateScene()
{
    emit started();
}

void BattleField::deactivateScene()
{

}
