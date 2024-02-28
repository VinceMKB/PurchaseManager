
#include "itemlistmemento.h"

ItemListMemento::ItemListMemento() : state(QStringList())
{

}

ItemListMemento::ItemListMemento(const QStringList &state) : state(state)
{

}

QStringList ItemListMemento::getState() const
{
    return state;
}
