#ifndef PLAYER_H
#define PLAYER_H

#include <QObject>
#include <QString>

#include "NinjaCharacteristics.h"
#include "Character.h"

#include "Items/Gear.h"
#include "Items/Weapon.h"

#include "MoneyBag.h"
#include "ItemBag.h"


class Player : public QObject
{
    Q_OBJECT

public:
    Player(QString accountName,
           Character* character,
           NinjaCharacteristics* characteristics,
           Gear* gear,
           Weapon* weapon,
           bool isBot = true);

    QString accountName() const;
    Character* character() const;

    NinjaCharacteristics* characteristics() const;

    MoneyBag* moneyBag() const;
    ItemBag* itemBag() const;

    Gear* gear() const;
    void changeGearTo(Gear* gear);
    Weapon* weapon() const;
    void changeWeaponTo(Weapon* weapon);

private:
    QString m_account_name;
    Character* m_character;

    NinjaCharacteristics* m_characteristics;

    MoneyBag* m_moneyBag;
    ItemBag* m_itemBag;

    Gear* m_gear;
    Weapon* m_weapon;

private:
    bool m_isBot;
};

#endif // PLAYER_H
