#include "Item.h"

Item::Item(QString name,
           Money cost,
           QPixmap icon) :
    m_name(name),
    m_cost(cost),
    m_icon(icon),
    m_id(generateUniqueId())
{

}

Item::Item(const Item &other) :
    m_name(other.name()),
    m_cost(other.cost()),
    m_icon(other.icon()),
    m_id(other.id())
{

}

QString Item::name() const
{
    return m_name;
}

Money Item::cost() const
{
    return m_cost;
}

QPixmap Item::icon() const
{
    return m_icon;
}

int Item::id() const
{
    return m_id;
}

int Item::generateUniqueId()
{
    static int id = 1;

    return id++;
}
