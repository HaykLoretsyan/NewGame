#include "Player.h"

Player::Player(QString accountName) :
    m_account_name(accountName)
{

}

QString Player::accountName() const
{
    return m_account_name;
}
