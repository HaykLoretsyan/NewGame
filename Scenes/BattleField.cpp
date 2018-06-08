#include "BattleField.h"

BattleField::BattleField()
{
}

void BattleField::activateCharacter(QString characterName)
{
    Q_UNUSED(characterName)
}

void BattleField::takeAction(FightAction *action)
{
    Q_UNUSED(action)
}

void BattleField::activateScene()
{
    emit started();
}

void BattleField::deactivateScene()
{
}
