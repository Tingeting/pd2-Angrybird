#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QGraphicsScene>
#include <QList>
#include <QDesktopWidget>
#include <QTimer>
#include <Box2D/Box2D.h>
#include <QMouseEvent>
#include <iostream>

#include <gameitem.h>
#include <land.h>
#include <pig.h>
#include <barrier.h>
#include <shooter.h>
#include <bg.h>

#include <bird.h>
#include <firstbird.h>
#include <secondbird.h>
#include <thirdbird.h>

#include <QDebug>
#include <vector>

namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = 0);
    ~MainWindow();
    void showEvent(QShowEvent *);
    bool eventFilter(QObject *,QEvent *event);
    void closeEvent(QCloseEvent *);



signals:
    // Signal for closing the game
    void quitGame();

private slots:
    void tick();
    void QUITSLOT();
    void next();
    void slot();
    void WinLose();

    void on_pushButton_clicked();
    void on_pushButton_2_clicked();

private:
    Ui::MainWindow *ui;
    QGraphicsScene *scene;
    b2World *world;

    // Pointer
    Land *land;
    Barrier *barrier;
    Shooter *shooter;
    Bird *bird;
    Firstbird *firstbird;
    Secondbird *secondbird;
    Thirdbird *thirdbird;
    Bg *bg;

    //Qlist
    QList<GameItem *> itemList;
    QList<Pig *> PigList;
    QList<Barrier *>Blist;
    QList<Shooter *>Shooterlist;
    QList<Bird *>Birdlist;

    QTimer timer;
    QTimer *timer1;

    QPoint start;
    QPoint end;



    void thing();

    int birdkind=0;
    int num=0;
    int num2=0;
    int a=500;
};

#endif // MAINWINDOW_H
