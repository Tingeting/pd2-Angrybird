#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    ui->win->hide();
    // Enable the event Filter
    qApp->installEventFilter(this);
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::showEvent(QShowEvent *)
{
    // Set QGraphicsScene
    scene = new QGraphicsScene(0,0,width()-2,ui->graphicsView->height()-2);
    ui->graphicsView->setScene(scene);

    // Set World
    world = new b2World(b2Vec2(0.0f, -9.8f));

    // Weight 32m, Height 18m
    GameItem::setGlobalSize(QSizeF(32,18),size());


    // Set Land
    land = new Land(16.0, 1.5, 32.0, 1.0, QPixmap(":/ground.png").scaled(320*5,160*2),world,scene);

    // Set Background
    bg = new Bg(0,0,QPixmap(":/image/bg.jpg").scaled(1600,935),world,scene);

    // Set Shooter
    shooter = new Shooter(150,650,QPixmap(":/image/launcher.png").scaled(75,150),world,scene);

    // Set Things
    thing();


    // Timer
    connect(&timer,SIGNAL(timeout()),this,SLOT(tick()));
    connect(this,SIGNAL(quitGame()),this,SLOT(QUITSLOT()));
    connect(&timer,SIGNAL(timeout()),this,SLOT(next()));
    connect(&timer,SIGNAL(timeout()),this,SLOT(slot()));
    connect(&timer,SIGNAL(timeout()),this,SLOT(WinLose()));
    timer.start(100/6);


}

void MainWindow::WinLose(){


}

void MainWindow::slot(){

    a--;
    if(a<=0){

        a=500;
    }
}

bool MainWindow::eventFilter(QObject *, QEvent *event)
{
    // Press Mouse Button
    if(event->type() == QEvent::MouseButtonPress)
    {
        QMouseEvent *keyEvent = static_cast<QMouseEvent *>(event);

        if(Birdlist[birdkind]->flying)
        {
            Birdlist[birdkind]->SpecialEffect();
            Birdlist[birdkind]->flying = false;

            if(birdkind==3){

                delete PigList[0];
                delete PigList[1];
                delete PigList[2];
                delete PigList[3];
                delete PigList[4];
    PigList[0]=NULL;
    PigList[1]=NULL;
    PigList[2]=NULL;
    PigList[3]=NULL;
    PigList[4]=NULL;
                ui->win->show();

            }

        }

        if(num==0){

            if((190-50)<keyEvent->x() && keyEvent->x()<(190+50))
            if((600-50)<keyEvent->y() && keyEvent->y()<(600+50)){

                start.setX(keyEvent->x());
                start.setY(keyEvent->y());
                num=1;
            }
        }
    }

    // Move Mouse Button
    if(event->type() == QEvent::MouseMove){

        QMouseEvent *keyEvent = static_cast<QMouseEvent *>(event);

        if(num==1||num==2){

            float x=3.4-((start.x()-keyEvent->x())/60.0);
            float y=6.5+((start.y()-keyEvent->y())/60.0);
            Birdlist[birdkind]->g_body->SetTransform(b2Vec2(x,y),0);
            num=2;
        }
    }

    // Release Mouse Button
    if(event->type() == QEvent::MouseButtonRelease){

        QMouseEvent *keyEvent = static_cast<QMouseEvent *>(event);

        if(num==2){

            end.setX(keyEvent->x());
            end.setY(keyEvent->y());
            Birdlist[birdkind]->g_body->SetType(b2_dynamicBody);
            Birdlist[birdkind]->setLinearVelocity(b2Vec2((start.x()-end.x())/7.5,-(start.y()-end.y())/7.5));
            num=3;
            Birdlist[birdkind]->flying = true;
        }
    }
    return false;
}

void MainWindow::next(){

    if(num==3&&a==5){

        delete Birdlist[birdkind];
        Birdlist[birdkind]=NULL;

        if(birdkind<3){

            birdkind++;
            shooter->waiting(Birdlist[birdkind]);
            num=0;
        }
        else{

 // 決定勝負
        }

    }
}


void MainWindow::thing(){

    // Set Pig
    Pig *pig  = new Pig(15,6,0.65,&timer,QPixmap(":/image/pig.png").scaled(87,87),world,scene);
    Pig *pig1 = new Pig(18,4,0.65,&timer,QPixmap(":/image/pig.png").scaled(87,87),world,scene);
    Pig *pig2 = new Pig(21,6,0.65,&timer,QPixmap(":/image/pig.png").scaled(87,87),world,scene);
    Pig *pig3 = new Pig(24,4,0.65,&timer,QPixmap(":/image/pig.png").scaled(87,87),world,scene);
    Pig *pig4 = new Pig(27,6,0.65,&timer,QPixmap(":/image/pig.png").scaled(87,87),world,scene);

    PigList.push_back(pig);
    PigList.push_back(pig1);
    PigList.push_back(pig2);
    PigList.push_back(pig3);
    PigList.push_back(pig4);

    // Set Barrier
    Barrier *barrier1 = new Barrier(world);
    Barrier *barrier2 = new Barrier(world);
    Barrier *barrier3 = new Barrier(world);

    barrier1->create_reg(15.4,3,1,0.5,&timer,QPixmap(":/image/b1.png").scaled(85,85),world,scene);
    barrier2->create_reg(21.4,3,1,0.5,&timer,QPixmap(":/image/b1.png").scaled(85,85),world,scene);
    barrier3->create_reg(27.4,3,1,0.5,&timer,QPixmap(":/image/b1.png").scaled(85,85),world,scene);

    Blist.push_back(barrier1);
    Blist.push_back(barrier2);
    Blist.push_back(barrier3);

    // Set Birdies
    Bird *birdie = new Bird(4.0f,4.0f,0.5f,&timer,QPixmap(":/image/birdie.png").scaled(80,80),world,scene);
    Bird *birdie1 = new Firstbird(6.0f,3.0f,0.5f,&timer,QPixmap(":/image/birdie01.png").scaled(80,80),world,scene);
    Bird *birdie2 = new Secondbird(7.5f,3.0f,0.5f,&timer,QPixmap(":/image/birdie02.png").scaled(80,80),world,scene);
    Bird *birdie3 = new Thirdbird(9.0f,3.0f,0.5f,&timer,QPixmap(":/image/birdie03.png").scaled(80,80),world,scene);

    Birdlist.push_back(birdie);
    Birdlist.push_back(birdie1);
    Birdlist.push_back(birdie2);
    Birdlist.push_back(birdie3);

    shooter->waiting(Birdlist[0]);

    // Static Birdies
    Birdlist[0]->g_body->SetType(b2_staticBody);
    Birdlist[1]->g_body->SetType(b2_staticBody);
    Birdlist[2]->g_body->SetType(b2_staticBody);
    Birdlist[3]->g_body->SetType(b2_staticBody);

}

void MainWindow::closeEvent(QCloseEvent *){

    emit quitGame();
}

void MainWindow::tick(){

    world->Step(1.0/60.0,6,2);
    scene->update();
}

void MainWindow::QUITSLOT(){

    std::cout << "Quit Game Signal receive !" << std::endl ;
    exit(1);
}


void MainWindow::on_pushButton_clicked()
{
    emit quitGame();
}

void MainWindow::on_pushButton_2_clicked()
{

    ui->win->hide();
    birdkind=0;
    num=0;
    a=500;

    delete Birdlist[0];
    delete Birdlist[1];
    delete Birdlist[2];
    delete Birdlist[3];
    Birdlist[0]=NULL;
    Birdlist[1]=NULL;
    Birdlist[2]=NULL;
    Birdlist[3]=NULL;
    Birdlist.clear();

    delete PigList[0];
    delete PigList[1];
    delete PigList[2];
    delete PigList[3];
    delete PigList[4];
    PigList[0]=NULL;
    PigList[1]=NULL;
    PigList[2]=NULL;
    PigList[3]=NULL;
    PigList[4]=NULL;
    PigList.clear();

    delete Blist[0];
    delete Blist[1];
    delete Blist[2];
    Blist[0]=NULL;
    Blist[1]=NULL;
    Blist[2]=NULL;
    Blist.clear();

    thing();
    timer.start(100/6);

}
