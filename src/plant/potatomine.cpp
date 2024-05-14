#include "potatomine.h"

PotatoMine::PotatoMine()
{
    hp = hp_NormalPlant;
    time = int(15.0 * 1000 / 33);
    setMovie(":/images/PotatoMine1.gif");
}

QRectF PotatoMine::boundingRect() const
{
    return state == 2 ? QRectF(-75, -75, 150, 150) : Plant::boundingRect();
}

//根据计数器和状态，进行碰撞检测，完成行动和状态转移
void PotatoMine::advance(int phase)
{
    if (!phase)
        return;
    update();
    if (hp <= 0)
        delete this;
    //起爆状态
    else if (state == 0 && ++counter >= time)
    {
        state = 1;
        counter = 0;
        time = int(1.0 * 1000 / 33);
        setMovie(":/images/PotatoMine.gif");
    }
    //遇到僵尸就爆炸，变为爆炸状态
    else if (state == 1 && ++counter >= time)
    {
        counter = 0;
        QList<QGraphicsItem *> items = collidingItems();
        if (!items.isEmpty())
        {
            state = 2;
            setMovie(":/images/PotatoMineBomb.gif");
            foreach (QGraphicsItem *item, items)
            {
                Zombie *zombie = qgraphicsitem_cast<Zombie *>(item);
                zombie->hp =0;
                delete zombie;
            }
        }
    }
    //爆炸后，删除对象
    else if (state == 2 && movie->currentFrameNumber() == movie->frameCount() - 1)
        delete this;
}

bool PotatoMine::collidesWithItem(const QGraphicsItem *other, Qt::ItemSelectionMode mode) const
{
    Q_UNUSED(mode)
    return other->type() == Zombie::Type && qFuzzyCompare(other->y(), y()) && qAbs(other->x() - x()) < 50;
}

