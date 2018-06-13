#ifndef ARENA_H
#define ARENA_H

#include <QObject>
#include <QVector>

#include "ResourceManager.h"
#include "PlayerAttributes/Player.h"

#include "Scene.h"
#include "BattleField.h"

#include "Fight/Fight.h"



class Arena : public Scene
{
    Q_OBJECT

public:
    Arena(Player* player);

    // Scene interface
public:
    void activateScene() override;
    void deactivateScene() override;

public slots:
    void fightABot(int botNumber);
    void searchForAPlayer();

private:
    void createBattleField(QVector<Player*>& firstTeam, QVector<Player*>& secondTeam);

private:
    Player* m_player;
    BattleField* m_battleField;
    Fight* m_fight;

    QVector<Player*> m_bots;
};

#endif // ARENA_H
