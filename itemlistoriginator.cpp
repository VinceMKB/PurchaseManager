
#include "itemlistoriginator.h"

void ItemListOriginator::setState(const QStringList &state)
{
    this->state = state;
}

ItemListMemento ItemListOriginator::savetoMemento()const
{
    return ItemListMemento(state);
}

void ItemListOriginator::restorefromMemento(const ItemListMemento &memento)
{
    state = memento.getState();
}

QStringList ItemListOriginator::getState() const
{
    return state;
}
