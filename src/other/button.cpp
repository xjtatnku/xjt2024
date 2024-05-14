#include "button.h"

Button::Button(QSound *s, QTimer *t)
{
    sound = s;
    timer = t;
}
//返回 按钮 所在的矩形区域
QRectF Button::boundingRect() const
{
    return QRectF(-80, -20, 160, 40);
}
//绘制按钮，根据是否点击按钮 绘制 “pause” 或者 “continue”
void Button::paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget)
{
        Q_UNUSED(option)
        Q_UNUSED(widget)
        // 绘制按钮图片
        painter->drawPixmap(QRect(-80, -20, 160, 40), QPixmap(":/images/Button.png"));
        // 设置文本格式
        QFont font("Calibri", 18, QFont::Bold, true);
        painter->setFont(font);
        // 绘制文本
        if (timer->isActive())
        {
            painter->setPen(Qt::green);
            painter->drawText(boundingRect(), Qt::AlignCenter, "PAUSE");
        }
        else
        {
            painter->setPen(Qt::red);
            painter->drawText(boundingRect(), Qt::AlignCenter, "CONTINUE");
        }
}
//鼠标左键点击事件：更改定时器（停止or启动）
void Button::mousePressEvent(QGraphicsSceneMouseEvent *event)
{
    if (event->button() == Qt::LeftButton)
    {
        if (timer->isActive())
        {
            //sound->stop();
            timer->stop();
        }
        else
        {
            //sound->play();
            timer->start();
        }
    }
    update();
}
