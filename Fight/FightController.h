#ifndef GIGHTCONTROLLER_H
#define GIGHTCONTROLLER_H

#include <QObject>
#include <QVector>

#include "Fight/FightAction.h"
#include "Fight/Ninja.h"


class FightController : public QObject
{
    Q_OBJECT

public:
    FightController(QVector<Ninja*> ninjas);
    ~FightController();

    virtual void activate(Ninja* ninja) = 0;

    virtual void selfRequestHandler(FightActionRequest request) = 0;
    virtual void networkActionHandler(FightAction* action) = 0;

public slots:
    void handleSelfRequest(FightActionRequest request) { selfRequestHandler(request); }
    void handleNetworkAction(FightAction* action) { networkActionHandler(action); }

signals:
    void action(FightAction* action);

private:
    QVector<FightAction*> m_allActions;
    QVector<Ninja*> m_allNinjas;
};

#endif // GIGHTCONTROLLER_H
