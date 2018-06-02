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

void ResourceManager::initDatabase() throw(ReourceInitException)
{
    if(!m_db.isValid()) {
        m_db = QSqlDatabase::addDatabase("QSQLITE", "NinjaTimeConnection");
    }

    if(!m_db.open()) {
        throw ReourceInitException();
    }
}