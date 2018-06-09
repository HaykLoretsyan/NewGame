#ifndef AWARDMANAGER_H
#define AWARDMANAGER_H

#include <QVector>
#include <QRandomGenerator>
#include <QDateTime>

#include "Award.h"

#include "Items/Item.h"
#include "Items/Money.h"
#include "Items/Weapon.h"
#include "Items/Supportive.h"

#include "ResourceManager.h"


class AwardManager
{
public:
    AwardManager();

    /**
     * @brief generateAward generating award according to
     *        award attributes (m_attributes)
     * @return
     */
    Award generateAward();

    /**
     * @brief attributes
     * @return m_attributes
     */
    AwardAttributes attributes() const;

    /**
     * @brief setAttributes set m_attributes to attributes
     * @param attributes
     */
    void setAttributes(const AwardAttributes &attributes);

    /**
     * @brief addMandatoryItem add item with itemName as part of the award
     * @param itemName
     */
    void addMandatoryItem(QString itemName);

    /**
     * @brief addMandatoryItem add item as part of the award
     * @param item
     */
    void addMandatoryItem(Item* item);

private:
    AwardAttributes m_attributes;

    QVector<Item*> m_mandatoryItems;
};

#endif // AWARDMANAGER_H
