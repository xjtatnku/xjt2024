#include "peashooter.h"

Peashooter::Peashooter()
{
    atk = atk_Peashooter;
    hp = hp_NormalPlant;
    time = int(1.4 * 1000 / 33);
    setMovie(":/images/Peashooter.gif");
}

void Peashooter::advance(int phase)
{
    if (!phase)
        return;
    update();
    if (hp <= 0)
        delete this;
    else if (++counter >= time)
    {
        counter = 0;
        if (!collidingItems().isEmpty())
        {
            Pea *pea = new Pea(atk);
            pea->setPos(x() + 32, y());
            scene()->addItem(pea);
        }
    }
}

bool Peashooter::collidesWithItem(const QGraphicsItem *other, Qt::ItemSelectionMode mode) const
{
    Q_UNUSED(mode)
    return other->type() == Zombie::Type && qFuzzyCompare(other->y(), y());
}
