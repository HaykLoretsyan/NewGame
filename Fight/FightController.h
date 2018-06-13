#ifndef GIGHTCONTROLLER_H
#define GIGHTCONTROLLER_H

#include <QObject>
#include <QVector>
#include <QMap>
#include <QString>

#include "Fight/FightAction.h"
#include "Fight/Ninja.h"


class FightController : public QObject
{
    Q_OBJECT

public:
    FightController(QMap<QString, Ninja*> ninjas);
    virtual ~FightController() = 0;

    virtual void activate(Ninja* ninja) = 0;

    virtual void selfRequestHandler(FightActionRequest request) = 0;
    virtual void networkActionHandler(FightAction* action) = 0;

public slots:
    void handleSelfRequest(FightActionRequest request) { selfRequestHandler(request); }
    void handleNetworkAction(FightAction* action) { networkActionHandler(action); }

signals:
    void action(FightAction* action);

protected:
    QVector<FightAction*> m_allActions;
    QMap<QString, Ninja*> m_allNinjas;

protected:
    Ninja* m_self;
};

#endif // GIGHTCONTROLLER_H
