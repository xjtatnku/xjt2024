#include "pea.h"
#include "../zombie/zombie.h"

//豌豆子弹
Pea::Pea(int attack, bool flag)
{
    snow = flag;
    atk = attack;
    speed = 360.0 * 33 / 1000;
}

QRectF Pea::boundingRect() const
{
    return QRectF(-12, -28, 24, 24);
}
//绘制豌豆子弹
void Pea::paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget)
{
    Q_UNUSED(option)
    Q_UNUSED(widget)
    painter->drawPixmap(QRect(-12, -28, 24, 24), QPixmap(snow ? ":/images/PeaSnow.png" : ":/images/Pea.png"));
}

//碰撞检测
bool Pea::collidesWithItem(const QGraphicsItem *other, Qt::ItemSelectionMode mode) const
{
    Q_UNUSED(mode)
    return other->type() == Zombie::Type && qFuzzyCompare(other->y(), y()) && qAbs(other->x() - x()) < 15;
}

//完成行动和状态转移
void Pea::advance(int phase)
{
    if (!phase)
        return;
    update();
    QList<QGraphicsItem *> items = collidingItems();
    if (!items.isEmpty())
    {
        Zombie *zombie = qgraphicsitem_cast<Zombie *>(items[qrand() % items.size()]);
        zombie->hp -= atk;
        if (snow && zombie->speed > 0.5)
            zombie->speed /= 3;
        delete this;
        return;
    }
    setX(x() + speed);
    if (x() > 1069)
        delete this;
}
