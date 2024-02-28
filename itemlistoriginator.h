
#ifndef ITEMLISTORIGINATOR_H
#define ITEMLISTORIGINATOR_H

#include "itemlistmemento.h"

#include <QStringList>


class ItemListOriginator
{
public:
    void setState(const QStringList &state);
    QStringList getState()const;
    ItemListMemento savetoMemento() const;
    void restorefromMemento(const ItemListMemento &memento);
private:
    QStringList state;
};

#endif // ITEMLISTORIGINATOR_H
