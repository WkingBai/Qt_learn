#include "widget.h"
#include "ui_widget.h"
#include<QPainter> //画家类

Widget::Widget(QWidget *parent)
    : QWidget(parent)
    , ui(new Ui::Widget)
{
    ui->setupUi(this);
    QTimer *timer = new QTimer(this);
    timer->start(500);

    connect(timer, &QTimer::timeout, [=](){
        posX += 20;
        update();
    });

    connect(ui->pushButton, &QPushButton::clicked, [=](){
        posY += 20;
        update();
    });

    connect(ui->btn, &QPushButton::clicked,[=](){
        if(ui->btn->text() == "stop"){
             timer->stop();
             ui->btn->setText("start");
        }
        else{
             timer->start();
             ui->btn->setText("stop");
        }
    });
}


void Widget::paintEvent(QPaintEvent *){
    QPainter painter(this);
    if(posX > this->width()){
        posX = 0;
    }
    if(posY > this->height()){
        posY = 0;
    }

    painter.drawPixmap(posX,posY,QPixmap(":/Image/2.jpg"));
}
Widget::~Widget()
{
    delete ui;
}

