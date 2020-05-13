#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "mainscene.h"
#include "mainscene2.h"
#include "mainscene3.h"
#include "mainscene4.h"

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    this->setFixedSize(375,494);
    this->setWindowTitle("拼图");

}

MainWindow::~MainWindow()
{
    delete ui;
}


void MainWindow::on_pushButton_clicked()
{
    //打开2*2
    MainScene *m2=new MainScene;
    m2->show();
    this->close();


}

void MainWindow::on_pushButton_2_clicked()
{
    //打开3*3
    MainScene2 *m3=new MainScene2;
    m3->show();
    this->close();
}

void MainWindow::on_pushButton_3_clicked()
{
    //打开4*4
    MainScene3 *m4=new MainScene3;
    m4->show();
    this->close();
}

void MainWindow::on_pushButton_4_clicked()
{
    //打开5*5
    MainScene4 *m5=new MainScene4;
    m5->show();
    this->close();
}
