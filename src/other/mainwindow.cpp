#include "mainwindow.h"

/*MainWindow控制整个游戏的运行，具体流程为：
1. 播放背景音乐
2. 创建场景，设置边界
3. 创建商店（卡片槽）、卡片、铲子、地图、割草机，加入场景（背景图）
4. 创建视图，设置背景和大小
5. 创建计时器，将计时器事件timeout()绑定到场景advance()
6. 将计时器事件绑定到僵尸生成函数addZombie()和胜负判断函数check()
*/
int MainWindow::ZOMBIE_GEN_TIMES_NOW=0;

MainWindow::MainWindow(QWidget *parent) : QMainWindow(parent)
{
    setWindowIcon(QIcon("./images/window.ico"));
    qsrand(uint(QTime(0,0,0).secsTo(QTime::currentTime())));
    sound = new QSound(":/images/music.wav");
   // sound = new QMediaPlayer;
    //sound->setMedia(QUrl::fromLocalFile(":/images/music.wav"));
    //sound->setVolume(50);
    sound->setLoops(QSound::Infinite);
    sound->play();
    timer = new QTimer;
    scene = new QGraphicsScene(this);
    scene->setSceneRect(150, 0, 950, 600);
    //禁用了索引方法，使得场景中的项按照添加的顺序进行绘制
    scene->setItemIndexMethod(QGraphicsScene::NoIndex);
    //背景图
    view = new QGraphicsView(scene, this);
    view->resize(952, 602);
    view->setRenderHint(QPainter::Antialiasing);
    view->setBackgroundBrush(QPixmap(":/images/Background.jpg"));
    view->setCacheMode(QGraphicsView::CacheBackground);
    view->setViewportUpdateMode(QGraphicsView::BoundingRectViewportUpdate);
    //加入卡片槽等部件
    shop = new Shop;
    shop->setPos(520, 45);
    scene->addItem(shop);

    shovel = new Shovel;
    shovel->setPos(830, 40);
    scene->addItem(shovel);

    button = new Button(sound, timer);
    button->setPos(970, 20);
    scene->addItem(button);

    map = new Map;
    map->setPos(618, 326);
    scene->addItem(map);

    for (int i = 0; i < 5; ++i)
    {
        Mower *mower = new Mower;
        mower->setPos(210, 130 + 98 * i);
        scene->addItem(mower);
    }
    //绑定信号和槽函数
    connect(timer, &QTimer::timeout, scene, &QGraphicsScene::advance);
    connect(timer, &QTimer::timeout, this, &MainWindow::addZombie);
    connect(timer, &QTimer::timeout, this, &MainWindow::check);
    sound->play();
    timer->start(33);
    view->show();
}

MainWindow::~MainWindow()
{
    delete sound;
    delete timer;
    delete scene;
    delete view;
    delete shop;
    delete shovel;
    delete map;
    delete button;
}

//生成僵尸
void MainWindow::addZombie()
{

     static int time = GEN_ONE_TIME;
     static int counter = 0;
     static int adder=1;
    if (ZOMBIE_GEN_TIMES_NOW < ZOMBIE_GEN_TIMES)
    {
        if (++counter >= time)
        {
            ZOMBIE_GEN_TIMES_NOW++;
            counter =8*adder;
            adder++;
            int type = qrand() % 50;
            int i = qrand() % 5;
            Zombie *zombie;
            if (type < 12)
                zombie = new BasicZombie();
            else if (type+adder < 30&&adder>5)
                zombie = new ConeZombie();
            else if (type+adder < 52&&adder>10)
                zombie = new BucketZombie();
             else if (type+adder < 77&&adder>15)
                zombie = new RugbyZombie();
            else  if(adder<12)
                zombie = new BasicZombie();
            else
                zombie = new ConeZombie();
            zombie->setPos(1028, 130 + 98 * i);
            scene->addItem(zombie);
            if(adder<5)
                time-=10*adder;
            else if(adder<10)
            time-=18*adder;
            else if(adder<15)
            time-=20*adder;
            else if(adder<20)
                time=130;
            else if(adder<33)
                time=410+0.5*adder;
            else if(adder<45)
                time=370;
        }
    }
    
}

void MainWindow::check()
{
    const QList<QGraphicsItem *> items = scene->items();
        bool zombiesReachedLeft = false;
        bool noZombiesRemaining = true;

        foreach (QGraphicsItem *item, items)
        {
            if (item->type() == Zombie::Type)
            {
                Zombie *zombie = qgraphicsitem_cast<Zombie *>(item);
                if (zombie->x() < 200)
                {
                    zombiesReachedLeft = true;
                    break;
                }
                noZombiesRemaining = false;
            }
        }
        if (zombiesReachedLeft)
        {
            // 输了
            QPixmap loseImage(":/images/ZombiesWon.png");
            QGraphicsPixmapItem *loseItem = scene->addPixmap(loseImage);
            loseItem->setPos(336, 92);
            scene->advance();
            timer->stop();
            return;
        }
        if (noZombiesRemaining && ZOMBIE_GEN_TIMES_NOW == ZOMBIE_GEN_TIMES)
        {
            // 赢了
            QPixmap winImage(":/images/Win.jpg");
            QGraphicsPixmapItem *winItem = scene->addPixmap(winImage);
            winItem->setPos(326, 82);
            scene->advance();
            timer->stop();
            return;
        }
}

