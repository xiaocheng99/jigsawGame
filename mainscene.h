#ifndef MAINSCENE_H
#define MAINSCENE_H

#include <QMainWindow>

namespace Ui {
class MainScene;
}

class MainScene : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainScene(QWidget *parent = 0);
    ~MainScene();

    int NUM=2;//这个就是代表是2*2的
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
    int NUm=2;
    Ui::MainScene *ui;

    //int Game[NUM][NUM];
    int **Game;
    void init();
    void GoUp();
    void GoDown();
    void GoLeft();
    void GoRight();

};

#endif // MAINSCENE_H
