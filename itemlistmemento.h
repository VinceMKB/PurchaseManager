
#ifndef ITEMLISTMEMENTO_H
#define ITEMLISTMEMENTO_H

#include <QStringList>


class ItemListMemento
{
public:
    ItemListMemento();
    ItemListMemento(const QStringList &state);
    QStringList getState() const;
private:
    QStringList state;

};

#endif // ITEMLISTMEMENTO_H
