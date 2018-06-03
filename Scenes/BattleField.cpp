#include "BattleField.h"

BattleField::BattleField(Fight* fight) :
    m_fight(fight)
{

}

void BattleField::activateScene()
{
    m_fight->start();
}

void BattleField::deactivateScene()
{
    m_fight->end();
}
