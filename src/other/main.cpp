#include <QApplication>
#include "startwindow.h"
#include "dialog.h"
int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    startwindow s;
    s.setFixedSize(920, 600);
   s.setWindowTitle("PlantsVsZombies");
    s.show();
    return a.exec();
}
