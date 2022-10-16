#include "widget.h"
#include "ui_widget.h"
#include<QPainter> //画家类

Widget::Widget(QWidget *parent)
    : QWidget(parent)
    , ui(new Ui::Widget)
{
    ui->setupUi(this);

    //点击移动按钮 移动图片
    connect(ui->pushButton, &QPushButton::clicked,[=](){
         posX += 20;
        //手动调用绘图事件，使用update更新
        update();
    });
}
void Widget::paintEvent(QPaintEvent *) //系统自动调用
{
//    QPainter painter(this); //this指定的是绘图的设备

//    //设置画笔颜色
//    QPen pen(QColor(255,0,0));
//    //设置画笔宽度
//    pen.setWidth(3);
//    //设置画笔风格
//    pen.setStyle(Qt::DashLine);
//    //让画家使用这个笔
//    painter.setPen(pen);

//    //画刷
//    QBrush brush(QColor(123,255,121));
//    //设置画刷风格
//    brush.setStyle(Qt::Dense1Pattern);
//    //让画家使用画笔
//    painter.setBrush(brush);

//    //画线
//    painter.drawLine(QPoint(0,0), QPoint(100,100));

//    //画圆
//    painter.drawEllipse(QPoint(100,100),50,50);

//    //画矩形
//    painter.drawRect(QRect(75,75,50,50));

//    //画文字
//    painter.drawText(QRect(10,200,200,200),"good good learn, day day up");


    ////////////////////////////////高级设置////////////////////////////////////
//    QPainter painter(this);
//    painter.drawEllipse(QPoint(100,50),50,50);
//    //设置 抗锯齿能力 效率低一点
//    painter.setRenderHint(QPainter::Antialiasing);
//    painter.drawEllipse(QPoint(200,50),50,50);

//    painter.drawRect(QRect(20,20,50,50));
//    //让画家移动位置开始画图
//    painter.translate(100,0);
//    //保存画家状态
//    painter.save();
//    painter.drawRect(QRect(20,20,50,50));
//    painter.translate(100,0);
//    //还原画家状态
//    painter.restore();
//    painter.drawRect(QRect(20,20,50,50));

    ///////////////////////////////利用画家画图片///////////////////////////////
    QPainter painter(this);
    //如果超出屏幕 从0开始
    if(posX > this->width()){
        posX = 0;
    }
    painter.drawPixmap(posX,100,QPixmap(":/Image/1.png"));

}

Widget::~Widget()
{
    delete ui;
}

