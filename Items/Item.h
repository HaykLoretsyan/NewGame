#ifndef ITEM_H
#define ITEM_H

#include <QString>
#include <QPixmap>

#include "Money.h"


class Item
{
public:
    Item(QString name,
         Money cost,
         QPixmap icon);

    Item(const Item & other);

    QString name() const;
    Money cost() const;
    QPixmap icon() const;

    int id() const;

private:
    static int generateUniqueId();

private:
    QString m_name;
    Money m_cost;
    QPixmap m_icon;

    int m_id;
};

#endif // ITEM_H
