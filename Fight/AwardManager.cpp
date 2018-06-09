#include "AwardManager.h"

AwardManager::AwardManager()
{

}

Award AwardManager::generateAward()
{
    QRandomGenerator randomGenerator(QDateTime::currentSecsSinceEpoch());

    Award award;

    int moneyNumber = randomGenerator.bounded(1,4);

    switch(moneyNumber)
    {
    case 1: award.money = m_attributes.minMoney;
    case 2: award.money = (m_attributes.minMoney + m_attributes.maxMoney) / 2;
    default: award.money = m_attributes.maxMoney;
    }

    // TODO add random item generator
    award.items = m_mandatoryItems;

    return award;
}

AwardAttributes AwardManager::attributes() const
{
    return m_attributes;
}

void AwardManager::setAttributes(const AwardAttributes &attributes)
{
    m_attributes = attributes;
}

void AwardManager::addMandatoryItem(QString itemName)
{
    addMandatoryItem(ResourceManager::instance().createItemByName(itemName));
}

void AwardManager::addMandatoryItem(Item *item)
{
    m_mandatoryItems.push_back(item);
}
