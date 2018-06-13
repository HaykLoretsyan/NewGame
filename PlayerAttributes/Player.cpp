#include "Player.h"

Player::Player(QString accountName,
               Character *character,
               unsigned level,
               NinjaCharacteristics *characteristics,
               Gear *gear,
               Weapon *weapon,
               Affiliation affiliation) :
    m_account_name(accountName),
    m_character(character),
    m_level(level),
    m_characteristics(characteristics),
    m_gear(gear),
    m_weapon(weapon),
    m_affiliation(affiliation)
{

}

QString Player::accountName() const
{
    return m_account_name;
}

Character *Player::character() const
{
    return m_character;
}

unsigned Player::level() const
{
    return m_level;
}

Player::Affiliation Player::affiliation() const
{
    return m_affiliation;
}

NinjaCharacteristics *Player::characteristics() const
{
    return m_characteristics;
}

MoneyBag *Player::moneyBag() const
{
    return m_moneyBag;
}

ItemBag *Player::itemBag() const
{
    return m_itemBag;
}

Gear *Player::gear() const
{
    return m_gear;
}

void Player::changeGearTo(Gear *gear)
{
    m_gear = gear;
}

Weapon *Player::weapon() const
{
    return m_weapon;
}

void Player::changeWeaponTo(Weapon *weapon)
{
    m_weapon = weapon;
}
