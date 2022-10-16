#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    //添加菜单栏图标
   // ui->actionnew->setIcon(QIcon("E:/Qt/Image/stinkbug.png"));

    //是要添加Qt资源
    ui->actionnew->setIcon(QIcon(":/Image/1.png"));
    ui->actionoprn->setIcon(QIcon(":/Image/2.jpg"));

}

MainWindow::~MainWindow()
{
    delete ui;
}

