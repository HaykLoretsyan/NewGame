#ifndef RESOURCEMANAGER_H
#define RESOURCEMANAGER_H

#include <QtNetwork/QNetworkAccessManager>
#include <QSqlDatabase>
#include <QSettings>
#include <QString>

#include "Items/Item.h"
#include "CustomExceptions.h"
#include "PlayerAttributes/Player.h"
#include "PlayerAttributes/MoneyBag.h"
#include "PlayerAttributes/ItemBag.h"


class ResourceManager
{
private:
    ResourceManager();

public:
    static ResourceManager& instance() {
        static ResourceManager manager;

        return manager;
    }

    void useDatabase();
    void useNetwork();

    bool networkUsed() const;

    // API
    QString accountName();
    void registerAnAccount(QString username, QString password);
    bool hasAnyRegisteredAccount() const;

    Player* player();
    Player* playerByAccountName(QString accountName);
    QVector<Player*> botsForLevel(unsigned level);
    MoneyBag* moneyBagByAccountName(QString accountName);
    ItemBag* itemBagByAccountName(QString accountName);

    Item* createItemByName(QString itemName);

    void updateAccountData(Player* player);
    void updateAccountMoney(QString accountName, Money money);

    QString introMovie();

    QNetworkAccessManager* networkManager() const;

private:
    void initDatabase() throw(ReourceInitException);

private:
    QSqlDatabase m_db;
    QNetworkAccessManager* m_networkManager;

    bool m_networkUsed;
};

#endif // RESOURCEMANAGER_H
