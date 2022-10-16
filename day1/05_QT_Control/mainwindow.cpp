#include "mainwindow.h"
#include "ui_mainwindow.h"
#include<QDebug>
#include<QListWidgetItem>>
MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    //设置单选按钮 （男）
    ui->radioButton_man->setChecked(true);

    //单选按钮，选择女，打印信息
    connect(ui->radioButton_woman,&QRadioButton::clicked, [=](){
        qDebug()<<"女性";
    });

    //多选按钮
    connect(ui->checkBox_4, &QCheckBox::stateChanged,[=](int state){
        qDebug() << state;
    });

    //利用listWidget写诗
//    QListWidgetItem *item = new QListWidgetItem("Python is best");
//    //将一行诗放入到listWidget控件中
//    ui->listWidget->addItem(item);
//    item->setTextAlignment(Qt::AlignHCenter);

    //QStringList
    QStringList list;
    list << "python is best" << "but c++ is more";
    ui->listWidget->addItems(list);
}

MainWindow::~MainWindow()
{
    delete ui;
}

