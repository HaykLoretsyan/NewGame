#ifndef RESOURCEMANAGER_H
#define RESOURCEMANAGER_H

#include <QtNetwork/QNetworkAccessManager>
#include <QSqlDatabase>
#include <QString>

#include "CustomExceptions.h"
#include "PlayerAttributes/Player.h"


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

    // API
    Player* playerByAccountName(QString accountName);

private:
    void initDatabase() throw(ReourceInitException);

private:
    QSqlDatabase m_db;
    QNetworkAccessManager* m_networkManager;

    bool m_networkUsed;
};

#endif // RESOURCEMANAGER_H
