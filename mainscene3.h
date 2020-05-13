#ifndef MAINSCENE3_H
#define MAINSCENE3_H

#include <QMainWindow>
#include "ui_mainscene.h"

namespace Ui {
class MainScene3;
}

class MainScene3 : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainScene3(QWidget *parent = nullptr);
    ~MainScene3();
    int NUM=4;
    #define RANDTIME 1234//打乱次数
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

#endif // MAINSCENE3_H
