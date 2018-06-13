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

    enum class Affiliation
    {
        Self,
        Network,
        Bot
    };

public:
    Player(QString accountName,
           Character* character,
           unsigned level,
           NinjaCharacteristics* characteristics,
           Gear* gear,
           Weapon* weapon,
           Affiliation affiliation = Affiliation::Self);

    QString accountName() const;
    Character* character() const;
    unsigned level() const;

    Player::Affiliation affiliation() const;

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
    unsigned m_level;

    NinjaCharacteristics* m_characteristics;

    MoneyBag* m_moneyBag;
    ItemBag* m_itemBag;

    Gear* m_gear;
    Weapon* m_weapon;

private:
    Affiliation m_affiliation;
};

#endif // PLAYER_H
