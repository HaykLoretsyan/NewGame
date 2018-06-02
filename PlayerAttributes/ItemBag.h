#ifndef ITEMBAG_H
#define ITEMBAG_H

#include <QVector>
#include <algorithm>

#include "Items/Item.h"


class ItemBag
{
public:
    ItemBag();

    void addItem(Item* item);
    Money sellItem(int id);

private:
    bool containsItem(int id);

private:
    QVector<Item*> m_items;
};

#endif // ITEMBAG_H
