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

Player *ResourceManager::playerByAccountName(QString accountName)
{
    // TODO query player from database or network by account
    Q_UNUSED(accountName)

    return nullptr;
}

MoneyBag *ResourceManager::moneyBagByAccountName(QString accountName)
{
    // TODO query player's money bag from database or network by account
    Q_UNUSED(accountName)

    return nullptr;
}

void ResourceManager::updateAccountMoney(QString accountName,
                                         unsigned goldSpent,
                                         unsigned tokenSpent,
                                         unsigned redGemSpent,
                                         unsigned blueGemSpent,
                                         unsigned greenGemSpent)
{
    // TODO update account's money bag
    Q_UNUSED(accountName)
    Q_UNUSED(goldSpent)
    Q_UNUSED(tokenSpent)
    Q_UNUSED(redGemSpent)
    Q_UNUSED(blueGemSpent)
    Q_UNUSED(greenGemSpent)

    throw IncompatibleWithServerException();
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
