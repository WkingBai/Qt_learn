#include "widget.h"
#include "ui_widget.h"
#include<QMovie>

Widget::Widget(QWidget *parent)
    : QWidget(parent)
    , ui(new Ui::Widget)
{
    ui->setupUi(this);
    //栈控件使用
    //设置默认定位 scrollArea
    ui->stackedWidget->setCurrentIndex(1);
    //scrollArea按钮
    connect(ui->pushButton, &QPushButton::clicked, [=](){
        ui->stackedWidget->setCurrentIndex(0);
    });

    connect(ui->pushButton_2, &QPushButton::clicked, [=](){
        ui->stackedWidget->setCurrentIndex(1);
    });

    //下拉框
    ui->comboBox->addItem("BH");
    ui->comboBox->addItem("BC");
    //点按钮选中BC
    connect(ui->pushButton_BC,&QPushButton::clicked,[=](){
//        ui->comboBox->setCurrentIndex(1);
        ui->comboBox->setCurrentText("BC");
    });
    \
    //利用QLabel显示图片
    ui->label->setPixmap(QPixmap(":/Image/1.png"));

    //利用QLabel显示 git动态图片
    QMovie *movie = new QMovie(":/Image/2.gif");
    ui->label->setMovie(movie);

    //播放动图
    movie->start();
}

Widget::~Widget()
{
    delete ui;
}

