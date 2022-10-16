#include "mywidget.h"
#include <QPushButton>
#include "mypushbutton.h"
#include "QDebug"
myWidget::myWidget(QWidget *parent)
    : QWidget(parent)
{
    //创建第一个按钮
    QPushButton *btn = new QPushButton;
    //btn->show(); //show以顶层方式弹出窗口控件
    //让btn对象依赖在mywidget窗口中
    btn->setParent(this);

    //显示文本
    btn->setText("第一个按钮");

    //创建第二个按钮
    QPushButton *btn2 = new QPushButton("第二个按钮",this); //按照控件的大小创建窗口

    //移动btn2按钮
    btn2->move(100,100);

    //重置按钮大小
    btn2->resize(100,30);

    //重置窗口大小(非固定）
    resize(600,400);

     //设置固定窗口大小
    setFixedSize(600, 400);

    //设置窗口标题
    setWindowTitle("第一个窗口");

    //创建一个自己的按钮对象
    mypushbutton *myBtn = new mypushbutton;
    myBtn->setText("我自己的按钮");

    myBtn->move(200,0);
    myBtn->setParent(this); //设置到对象树中，父类析构时会将子类全部析构

    //需求 ： 点击我的按钮 关闭窗口
    // 参数1：信号的发送者  参数2：发送的信号（函数的地址） 参数3：信号的接受者 参数4：处理的槽函数（函数的地址）
    //connect( myBtn, &mypushbutton::clicked, this, &myWidget::close );
    connect(myBtn, &QPushButton::clicked, this, &QWidget::close );
}

myWidget::~myWidget()
{
    qDebug() << "myWidget的析构调用";
}

