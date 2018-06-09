#include "ItemBag.h"

ItemBag::ItemBag()
{

}

void ItemBag::addItem(Item* item)
{
    if(containsItem(item->id())) {
        return;
    }

    m_items.push_back(item);
}

void ItemBag::addItems(QVector<Item *> items)
{
    m_items += items;
}

Money ItemBag::sellItem(int id)
{
    Money result;

    if(!containsItem(id)) {
        return result;
    }

    for(int i = 0; i < m_items.size(); ++i) {
        if(m_items[i]->id() == id) {
            result = m_items[i]->cost();

            m_items.remove(i);
            break;
        }
    }

    return result;
}

bool ItemBag::containsItem(int id)
{
    auto it = std::find_if(m_items.begin(), m_items.end(), [=](Item* item) { return item->id() == id; });

    return it != m_items.end();
}
