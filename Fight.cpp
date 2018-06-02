#include "Fight.h"

Fight::Fight(QVector<Player *> firstTeam, QVector<Player *> secondTeam)
{
    for(Player* player : firstTeam) {
        m_allPlayers.insert(player, PlayerSide::READ);
    }

    for(Player* player : secondTeam) {
        m_allPlayers.insert(player, PlayerSide::BLUE);
    }
}
