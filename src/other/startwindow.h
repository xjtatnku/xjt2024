#ifndef STARTWINDOW_H
#define STARTWINDOW_H
#include<QMouseEvent>
#include<QGraphicsScene>
#include<QMainWindow>
#include<QGraphicsView>
#include "mainwindow.h"
#include<QDebug>
class startwindow: public QMainWindow
{
public:
    startwindow();
    void mousePressEvent(QMouseEvent *event);
    QGraphicsScene *scene;
    QGraphicsView *view;
    bool flag;
};
#endif // STARTWINDOW_H
