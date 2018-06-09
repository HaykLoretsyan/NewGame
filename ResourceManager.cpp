#include "ResourceManager.h"

ResourceManager::ResourceManager() :
    m_networkManager(nullptr),
    m_networkUsed(false)
{

}

void ResourceManager::useDatabase()
{
    m_networkUsed = false;

    initDatabase();
}

void ResourceManager::useNetwork()
{
    m_networkUsed = true;

    if(m_networkManager == nullptr) {
        m_networkManager = new QNetworkAccessManager();
    }
}

QString ResourceManager::accountName()
{
    QString result;

    if(!m_networkUsed) {
        QSettings settings("LoretsyanHayk", "NinjaTime");

        result = settings.value("accountName", "").toString();
    }

    return result;
}

void ResourceManager::registerAnAccount(QString username, QString password)
{
    if(!m_networkUsed) {
        QSettings settings("LoretsyanHayk", "NinjaTime");

        settings.setValue("accountName", username);
        settings.setValue("accountPassword", password);
    }
}

bool ResourceManager::hasAnyRegisteredAccount() const
{
    if(!m_networkUsed) {
        QSettings settings("LoretsyanHayk", "NinjaTime");

        if(settings.allKeys().contains("accountName")) {
            return true;
        }
    }

    return false;
}

Player *ResourceManager::player()
{
    return playerByAccountName(accountName());
}

Player *ResourceManager::playerByAccountName(QString accountName)
{
    // TODO query player from database or network by account
    if(accountName.isEmpty()) {
        return nullptr;
    }

    return nullptr;
}

MoneyBag *ResourceManager::moneyBagByAccountName(QString accountName)
{
    // TODO query player's money bag from database or network by account
    Q_UNUSED(accountName)

    return nullptr;
}

ItemBag *ResourceManager::itemBagByAccountName(QString accountName)
{
    // TODO query player's item bag from database or network by account
    Q_UNUSED(accountName)

    return nullptr;
}

Item *ResourceManager::createItemByName(QString itemName)
{
    // TODO get Item attributes by itemName, create item and return
    Q_UNUSED(itemName)

    return nullptr;
}

void ResourceManager::updateAccountData(Player *player)
{
    // TODO update data of player through network or database
    Q_UNUSED(player)
}

void ResourceManager::updateAccountMoney(QString accountName, Money money)
{
    // TODO update account's money bag
    Q_UNUSED(accountName)
    Q_UNUSED(money)

    throw IncompatibleWithServerException();
}

QString ResourceManager::introMovie()
{
    return QString(":/Resources/ninjas.gif");
}

QNetworkAccessManager *ResourceManager::networkManager() const
{
    return m_networkManager;
}

void ResourceManager::initDatabase() throw(ReourceInitException)
{
    if(!m_db.isValid()) {
        m_db = QSqlDatabase::addDatabase("QSQLITE", "NinjaTimeConnection");
    }

    if(!m_db.open()) {
        throw ReourceInitException();
    }
}
