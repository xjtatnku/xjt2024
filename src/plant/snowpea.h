#ifndef SNOWPEA_H
#define SNOWPEA_H

#include "plant.h"
#include "../zombie/zombie.h"
#include "../other/pea.h"

//寒冰豌豆射手

class SnowPea : public Plant
{
public:
    SnowPea();
    void advance(int phase) override;
    bool collidesWithItem(const QGraphicsItem *other, Qt::ItemSelectionMode mode) const override;
};
#endif // SNOWPEA_H
