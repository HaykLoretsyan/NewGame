#include "Fight.h"

Fight::Fight(QVector<Player *> firstTeam, QVector<Player *> secondTeam)
{
    for(Player* player : firstTeam) {
        NinjaState* state = new NinjaState(player->characteristics(),
                                           player->weapon(),
                                           player->gear(),
                                           NinjaState::Side::RED);

        m_allPlayers.insert(player, state);
    }

    for(Player* player : secondTeam) {
        NinjaState* state = new NinjaState(player->characteristics(),
                                           player->weapon(),
                                           player->gear(),
                                           NinjaState::Side::BLUE);

        m_allPlayers.insert(player, state);
    }

    unsigned maxSpeed = m_allPlayers.keys().first()->characteristics()->speed;

    for(Player* player : m_allPlayers.keys()) {
        if(player->characteristics()->speed > maxSpeed) {
            maxSpeed = player->characteristics()->speed;
        }
    }

    timeToHit = 10 * maxSpeed;
}

QMap<Player *, NinjaState *> Fight::allPlayers() const
{
    return m_allPlayers;
}

void Fight::start()
{

}

void Fight::end()
{

}
