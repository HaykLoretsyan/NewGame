#include "Fight.h"

Fight::Fight(BattleField *battleField,
             QVector<Player *> firstTeam,
             QVector<Player *> secondTeam,
             bool isOnlineFight) :
    m_battleField(battleField)
{
    for(Player* player : firstTeam) {
        Ninja* ninja = new Ninja(player->characteristics(),
                                 player->weapon(),
                                 player->gear(),
                                 Ninja::Side::Red,
                                 Ninja::Control(player->affiliation())
                                 );

        m_allNinjas.insert(player->accountName(), ninja);
    }

    for(Player* player : secondTeam) {
        Ninja* ninja = new Ninja(player->characteristics(),
                                 player->weapon(),
                                 player->gear(),
                                 Ninja::Side::Blue,
                                 Ninja::Control(player->affiliation())
                                 );

        m_allNinjas.insert(player->accountName(), ninja);
    }

    createController(isOnlineFight);

    connect(battleField, &BattleField::started, this, &Fight::start);
    connect(battleField, &BattleField::resumed, this, &Fight::resume);
    connect(battleField, &BattleField::finished, this, &Fight::finish);
}

QMap<QString, Ninja *> Fight::allNinjas() const
{
    return m_allNinjas;
}

unsigned Fight::timeToHit() const
{
    return m_timeToHit;
}

void Fight::start()
{
    m_timer = new QTimer();
    m_timer->setInterval(500);

    connect(m_timer, &QTimer::timeout, this, &Fight::onTimer);

    m_timer->start();

}

void Fight::resume()
{
    m_timer->start();
}

void Fight::finish()
{
    // TODO Award management
}

void Fight::onTimer()
{
    for(auto it = m_allNinjas.begin(); it != m_allNinjas.end(); ++it) {
        it.value()->incrementCurrentPosition();

        if(it.value()->position() >= timeToHit()) {
            if(m_timer->isActive()) {
                m_timer->stop();
            }

            m_controller->activate(it.value());
            m_battleField->activateCharacter(it.key());
            break;
        }
    }
}

void Fight::onAction(FightAction *action)
{
    m_battleField->takeAction(action);
}

void Fight::createController(bool isOnlineFight)
{
    unsigned maxSpeed = m_allNinjas.values().first()->characteristics()->speed;

    for(Ninja* ninja : m_allNinjas.values()) {
        if(ninja->characteristics()->speed > maxSpeed) {
            maxSpeed = ninja->characteristics()->speed;
        }
    }

    m_timeToHit = 10 * maxSpeed;

    if(isOnlineFight) {
        m_controller = new FightNetworkController(QVector<Ninja*>::fromList(m_allNinjas.values()));
    }
    else
    {
        m_controller = new FightLocalController(QVector<Ninja*>::fromList(m_allNinjas.values()));
    }

    connect(m_controller, &FightController::action, this, &Fight::onAction);
    connect(m_battleField, &BattleField::actionRequest, m_controller, &FightController::handleSelfRequest);

    if(isOnlineFight) {
        // TODO add networking
        // connect( ... , ... , m_controller, &FightController::handleNetworkAction)
    }
}
