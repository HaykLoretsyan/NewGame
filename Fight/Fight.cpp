#include "Fight.h"

Fight::Fight(BattleField *battleField,
             QVector<Player *> firstTeam,
             QVector<Player *> secondTeam,
             bool isOnlineFight) :
    m_self(nullptr),
    m_battleField(battleField),
    m_timer(nullptr),
    m_awardManager(nullptr)
{
    // Initializing first(red) team ninjas
    for(Player* player : firstTeam) {
        Ninja* ninja = new Ninja(player->characteristics(),
                                 player->weapon(),
                                 player->gear(),
                                 Ninja::Side::Red,
                                 Ninja::Control(player->affiliation())
                                 );

        m_allNinjas.insert(player->accountName(), ninja);

        if(player->affiliation() == Player::Affiliation::Self) {
            m_self = player;
        }
    }

    // Initializing second(blue) team ninjas
    for(Player* player : secondTeam) {
        Ninja* ninja = new Ninja(player->characteristics(),
                                 player->weapon(),
                                 player->gear(),
                                 Ninja::Side::Blue,
                                 Ninja::Control(player->affiliation())
                                 );

        m_allNinjas.insert(player->accountName(), ninja);

        if(player->affiliation() == Player::Affiliation::Self) {
            m_self = player;
        }
    }

    if(m_self == nullptr) {
        throw IllegalFightCreation();
    }

    createController(isOnlineFight);

    connect(battleField, &BattleField::started, this, &Fight::start);
    connect(battleField, &BattleField::resumed, this, &Fight::resume);
    connect(battleField, &BattleField::finished, this, &Fight::finish);
}

Fight::~Fight()
{
    for(auto it = m_allNinjas.begin(); it != m_allNinjas.end(); ++it) {
        delete it.value();
    }

    delete m_timer;
    delete m_awardManager;
}

QMap<QString, Ninja *> Fight::allNinjas() const
{
    return m_allNinjas;
}

unsigned Fight::timeToHit() const
{
    return m_timeToHit;
}

AwardManager *Fight::awardManager() const
{
    return m_awardManager;
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
    if(m_awardManager == nullptr) {
        m_battleField->showAward(Award());
    }

    Award award(m_awardManager->generateAward());

    m_self->moneyBag()->addMoney(award.money);
    m_self->itemBag()->addItems(award.items);

    m_battleField->showAward(award);
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
