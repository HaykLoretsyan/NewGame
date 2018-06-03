#include "Player.h"

Player::Player(QString accountName,
               Character *character,
               NinjaCharacteristics *characteristics,
               Gear *gear,
               Weapon *weapon,
               bool isBot) :
    m_account_name(accountName),
    m_character(character),
    m_characteristics(characteristics),
    m_gear(gear),
    m_weapon(weapon),
    m_isBot(isBot)
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

NinjaCharacteristics *Player::characteristics() const
{
    return m_characteristics;
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
