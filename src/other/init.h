#ifndef INIT_H
#define INIT_H
//初始化工作
//僵尸的数量
#define ZOMBIE_GEN_TIMES 40
//产生一个僵尸的时间
#define GEN_ONE_TIME 400

//初始化阳光值
#define INIT_SUN_NUM 100

//初始化卡片冷却时间
#define cooltime_SunFlower  220
#define cooltime_Peashooter 220
#define cooltime_CherryBomb 600
#define cooltime_WallNut    600
#define cooltime_PotatoMine 600
#define cooltime_SnowPea    220
#define cooltime_Repeater   220

//植物
#define hp_WallNut 6000
#define hp_NormalPlant 400

#define atk_Peashooter 27
#define atk_Repeater 27
#define atk_SnowPea 27

//僵尸
#define hp_BasicZombie  270
#define hp_ConeZombie  570
#define hp_ScreenZombie  1200
#define hp_BucketZombie  1200
#define hp_FootballZombie  1350

#define atk_Zombie  (3.7)

#define speed_zombie_1  (78.0 * 33 / 1000 / 4.9)
#define speed_zombie_2  (58.0 * 33 / 1000 / 2.7)

#endif // INIT_H
