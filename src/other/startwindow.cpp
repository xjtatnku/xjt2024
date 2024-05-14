#include "startwindow.h"

startwindow::startwindow()
{
    flag=true;
  scene = new QGraphicsScene(this);
  scene->setSceneRect(20, 60, 920, 700);
  view = new QGraphicsView(scene, this);
  view->resize(920, 800);
  view->setRenderHint(QPainter::Antialiasing);
  view->setBackgroundBrush(QPixmap(":/images/start3.jpg"));
}
void startwindow::mousePressEvent(QMouseEvent *event)
{
    if (event->button() == Qt::LeftButton)
    {
        MainWindow *w=new MainWindow;
       w->setFixedSize(940, 600);
       w->setWindowTitle("PlantsVsZombies");
        w->show();
       close();
    }
    if (event->button() == Qt::RightButton)
    {
        close();
    }
}

