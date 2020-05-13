#ifndef MAINSCENE2_H
#define MAINSCENE2_H

#include <QMainWindow>
#include "ui_mainscene.h"

namespace Ui {
class MainScene2;
}

class MainScene2 : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainScene2(QWidget *parent = 0);
    ~MainScene2();
    //#define NUM 2//拼图的长宽，暂时固定，不可修改，后期优化
int NUM=3;
#define RANDTIME 999//打乱次数
#define VOLUME 10
    void paintEvent(QPaintEvent *);
    bool ifWin();
    void keyPressEvent(QKeyEvent *event);
    void CreatNewGame();
    void timerEvent(QTimerEvent *);

    int X,Y;
    int nowTime = 0,steps=0;
    int timerId;



private slots:
    void on_actBack_triggered();

private:
    int NUm=3;
    Ui::MainScene *ui;

    //int Game[NUM][NUM];
    int **Game;
    void init();
    void GoUp();
    void GoDown();
    void GoLeft();
    void GoRight();

};

#endif // MAINSCENE2_H
