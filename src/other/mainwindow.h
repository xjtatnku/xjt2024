#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QGraphicsScene>
#include <QGraphicsView>
#include <QMediaPlayer>
#include <QSound>
#include <QTimer>
#include<QUrl>
#include "shop.h"
#include "card.h"
#include "shovel.h"
#include "button.h"
#include "map.h"
#include "mower.h"
#include "../zombie/basiczombie.h"
#include "../zombie/conezombie.h"
#include "../zombie/bucketzombie.h"
#include "../zombie/screenzombie.h"
#include "../zombie/rugbyzombie.h"
#include "init.h"


/*主界面：
 * 背景地图 商店（卡片槽） 卡片 铲子 割草机 右上角按钮
 * 添加僵尸函数  检查胜负函数
 *
MainWindow控制整个游戏的运行，具体流程为：
1. 播放背景音乐
2. 创建场景（背景图），设置边界
3. 创建商店（卡片槽）、卡片、铲子、地图、割草机，加入场景
4. 创建视图，设置背景和大小
5. 创建计时器，将计时器事件timeout()绑定到场景advance()
6. 将计时器事件绑定到僵尸生成函数addZombie()和胜负判断函数check()
 * */

class MainWindow : public QMainWindow
{
    Q_OBJECT
public:
    explicit MainWindow(QWidget *parent = nullptr);
    ~MainWindow() override;
    void addZombie();
    void check();
private:
    QSound *sound;
    QTimer *timer;
    QGraphicsScene *scene;
    QGraphicsView *view;
    Shop *shop;
    Shovel *shovel;
    Button *button;
    Map *map;
    static int ZOMBIE_GEN_TIMES_NOW;

};



#endif // MAINWINDOW_H
