
#include "ui_mainscene.h"
#include <QPainter>
#include<QLabel>
#include<QPushButton>
#include<string>
#include<iostream>
#include<QDebug>
#include<QKeyEvent>
#include <QPainter>
#include <stdlib.h>
#include <time.h>
#include<QDialog>
#include<QMessageBox>
#include<QTimerEvent>
#include "mainwindow.h"
#include "mainscene4.h"


//全局
#define ZOOM 1

#define POINT 100




MainScene4::MainScene4(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainScene)
{


    ui->setupUi(this);

    Game = new int* [NUM];//申请动态内存空间
    for (int i = 0; i < NUM; i++)//为每个位置再申请10个内存空间
        Game[i] = new int[NUM];



    //退出
    connect(ui->actiontuic,&QAction::triggered,[=](){
        this->close();
    });
    //新游戏
    connect(ui->actiond,&QAction::triggered,[=](){
        this->CreatNewGame();
    });
    //开发者信息
    connect(ui->action1_2,&QAction::triggered,[=]{
        QMessageBox::information(this,"开发者信息","开发者: 小成");
    });
    //游戏说明
    connect(ui->action1,&QAction::triggered,[=](){
        QMessageBox::information(this,"游戏说明","按“↑”、“↓”、“←”、“→”对空白方块进行操作");
    });
    this->setFixedSize(480*ZOOM,640*ZOOM);
    this->setWindowIcon(QPixmap(":/game/MNLS.png"));
    this->setWindowTitle("拼图");
    //打印输出框


    init();

    //显示拼图
    this->update();
}
//初始化操作
void MainScene4::init(){
    X=NUM-1;
    Y=NUM-1;
    //设置界面
    for(int i=0;i<NUM;i++){
        for(int j=0;j<NUM;j++){
            Game[i][j]=i*NUM+j;
        }
    }
    //设置步数和时间的字体
    QPalette pe;
    pe.setColor(QPalette::WindowText, Qt::white);
    ui->label->move(90,530);
    ui->label_2->move(340,530);
    ui->label->setPalette(pe);
    ui->label_2->setPalette(pe);


    CreatNewGame();
    //    timerId=startTimer(1000);
}

void MainScene4::CreatNewGame(){
    //打乱的拼图
    steps=0;
    ui->label_2->setText(QString::number(steps));
    srand((unsigned)time(NULL));
    //增加游戏打乱随机度
    for(int i=0;i<RANDTIME;i++){
        int r=rand() % NUM;
        if(r==0&&Y>0){
            GoUp();
        }else if(r==1&&Y<NUM-1){
            GoDown();
        }else if(r==2&&X>0){
            GoLeft();
        }else if(r==3&&X<NUM-1){
            GoRight();
        }

    }
    //开始计时
    killTimer(timerId);
    timerId=startTimer(1000);
    ui->label->setText("0");
    //开始声音

    nowTime = 0;

    //游戏开始
}

//计时器
void MainScene4::timerEvent(QTimerEvent *){

    ui->label->setText(QString::number(nowTime++));

}
void MainScene4::paintEvent(QPaintEvent*)
{
    //背景打印
    QPainter painter (this);
    QPixmap pix,pix2;

    pix.load(":/game/BG.png");
    pix2.load(":/game/frame.png");
    painter.drawPixmap(0,0,this->width(),this->height(),pix);
    painter.drawPixmap((this->width()-420)/2,(this->height()-420)/2,420,420,pix2);
    //时间
    QPixmap timeBox,stepBox;

    timeBox.load(":/game/textBox.png");
    stepBox.load(":/game/textBox.png");
    painter.drawPixmap(500,100,150,80,timeBox);
    painter.drawPixmap(500,300,150,80,stepBox);

    //步数

    //显示步数


    //显示游戏主体

    for(int i=0;i<NUM;i++)
    {
        for(int j=0;j<NUM;j++)
        {
            //计算当前图片名
            if(NUM==2)
            {
                char nowPic[20]=":/game/alock/";
                Game[i][j]>=10?nowPic[13]=Game[i][j]/10+'0',nowPic[14]=Game[i][j]%10+'0':nowPic[13]=Game[i][j]%10+'0';
                strcat(nowPic,".png");
                //qDebug()<<"PicName:"<<nowPic<<"  Number:"<<Game[i][j];
                QPixmap temPic;
                temPic.load(nowPic);
                painter.drawPixmap((this->width()-NUM*POINT)/2+j*POINT,(this->height()-NUM*POINT)/2+i*POINT,POINT,POINT,temPic);
            }
            if(NUM==3)
            {
                char nowPic[20]=":/game/clock/";
                Game[i][j]>=10?nowPic[13]=Game[i][j]/10+'0',nowPic[14]=Game[i][j]%10+'0':nowPic[13]=Game[i][j]%10+'0';
                strcat(nowPic,".png");
                //qDebug()<<"PicName:"<<nowPic<<"  Number:"<<Game[i][j];
                QPixmap temPic;
                temPic.load(nowPic);
                painter.drawPixmap((this->width()-NUM*POINT)/2+j*POINT,(this->height()-NUM*POINT)/2+i*POINT,POINT,POINT,temPic);
            }


            if(NUM==4)
            {
                char nowPic[20]=":/game/block/";
                Game[i][j]>=10?nowPic[13]=Game[i][j]/10+'0',nowPic[14]=Game[i][j]%10+'0':nowPic[13]=Game[i][j]%10+'0';
                strcat(nowPic,".png");
                //qDebug()<<"PicName:"<<nowPic<<"  Number:"<<Game[i][j];
                QPixmap temPic;
                temPic.load(nowPic);
                painter.drawPixmap((this->width()-NUM*POINT)/2+j*POINT,(this->height()-NUM*POINT)/2+i*POINT,POINT,POINT,temPic);
            }
            if(NUM==5)
            {
                char nowPic[20]=":/game/elock/";
                Game[i][j]>=10?nowPic[13]=Game[i][j]/10+'0',nowPic[14]=Game[i][j]%10+'0':nowPic[13]=Game[i][j]%10+'0';
                strcat(nowPic,".png");
                //qDebug()<<"PicName:"<<nowPic<<"  Number:"<<Game[i][j];
                QPixmap temPic;
                temPic.load(nowPic);
                painter.drawPixmap((this->width()-NUM*POINT)/2+j*POINT,(this->height()-NUM*POINT)/2+i*POINT,POINT,POINT,temPic);
            }

        }
    }
}


//判断游戏是否胜利
bool MainScene4::ifWin()
{
    bool win=true;
    for(int i=0;i<NUM;i++){
        for(int j=0;j<NUM;j++){
            if(Game[i][j]!=i*NUM+j){
                win=false;
                break;
            }
        }
    }
    //胜利则播放音乐,弹出对话框
    if(win){
        killTimer(timerId);

        QString winMess="恭喜你，胜利了！\n用    时:  ";
        winMess+=QString::number(nowTime);
        winMess+="  秒\n步    数:  ";
        winMess+=QString::number(steps);
        winMess+="  步";
        int result=QMessageBox::information(this,"你赢了！",winMess);
        if(result==QMessageBox::Ok){
            this->CreatNewGame();
        }

    }

    return win;
}


void MainScene4::GoUp(){
    //交换数组元素
    int temp=Game[Y][X];
    Game[Y][X]=Game[Y-1][X];
    Game[Y-1][X]=temp;
    Y--;
    //重新显示
    this->update();
}
void MainScene4::GoDown(){
    //交换数组元素
    int temp=Game[Y][X];
    Game[Y][X]=Game[Y+1][X];
    Game[Y+1][X]=temp;
    Y++;
    //重新显示
    this->update();
}
void MainScene4::GoLeft(){
    //交换数组元素
    int temp=Game[Y][X];
    Game[Y][X]=Game[Y][X-1];
    Game[Y][X-1]=temp;
    X--;
    //重新显示
    this->update();
}
void MainScene4::GoRight(){
    //交换数组元素
    int temp=Game[Y][X];
    Game[Y][X]=Game[Y][X+1];
    Game[Y][X+1]=temp;
    X++;
    //重新显示
    this->update();
}


//按键操作
void MainScene4::keyPressEvent(QKeyEvent  *event)
{
    this->setFocusPolicy(Qt::StrongFocus);


    if(event->key()==Qt::Key_Up)
    {
        qDebug()<<"按下了 ↑按键";
        if(Y>0){
            GoUp();
            steps++;
            ui->label_2->setText(QString::number(steps));
        }
    }else if(event->key()==Qt::Key_Down){
        qDebug()<<"按下了 ↓按键";
        if(Y<NUM-1){
            GoDown();
            steps++;
            ui->label_2->setText(QString::number(steps));
        }
    }else if(event->key()==Qt::Key_Left){
        qDebug()<<"按下了 ←按键";
        if(X>0){
            GoLeft();
            steps++;
            ui->label_2->setText(QString::number(steps));
        }
    }else if(event->key()==Qt::Key_Right){
        qDebug()<<"按下了 →按键";
        if(X<NUM-1){
            GoRight();
            steps++;
            ui->label_2->setText(QString::number(steps));
        }
    }
    this->ifWin();
}
MainScene4::~MainScene4()
{
    delete [] Game;
    delete ui;
}

void MainScene4::on_actBack_triggered()
{
    this->close();
    MainWindow *m=new MainWindow;
    m->show();

}
