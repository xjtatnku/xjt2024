#include "basiczombie.h"

//普通僵尸类
//有4种状态，正常行走，攻击植物，正常死亡，被烧焦（樱桃炸弹）

BasicZombie::BasicZombie()
{
    hp = hp_BasicZombie;
    atk = atk_Zombie;
    speed = speed_zombie_1;
    setMovie(":/images/ZombieWalk2.gif");
}

//僵尸的状态变化
void BasicZombie::advance(int phase)
{
    if (!phase)
        return;
    update();
    QList<QGraphicsItem *> items = collidingItems();
    //如果死亡
    if (hp <= 0)
    {
        if (state < ZombieType::DIE)
        {
            state = ZombieType::DIE;
            setMovie(":/images/ZombieDie.gif");
            setHead(":/images/ZombieHead.gif");
        }
        else if (movie->currentFrameNumber() == movie->frameCount() - 1)
            delete this;
        return;
    }
    //攻击植物
    else if (!items.isEmpty())
    {
        Plant *plant = qgraphicsitem_cast<Plant *>(items[0]);
        plant->hp -= atk;
        if (state != ZombieType::ATTACK)
        {
            state = ZombieType::ATTACK;
            setMovie(":/images/ZombieAttack.gif");
        }
        if(plant->hp<=0||items.isEmpty())
        {
            state = ZombieType::WALK;
            setMovie(":/images/ZombieWalk2.gif");
        }
        return;
    }
    setX(x() - speed);
    //update();
}
