#include "widget.h"
#include "ui_widget.h"
#include <QPushButton>
//Teacher 类 老师类
//Student 类 学生类
//下课后， 老师会触发一个信号（饿了），学生响应信号（请客吃饭）

Widget::Widget(QWidget *parent)
    : QWidget(parent)
    , ui(new Ui::Widget)
{
    ui->setupUi(this);

    //创建一个老师对象
    this->zt = new Teacher(this);

    //创建一个学生对象
    this->st = new Student(this);

    //老师饿了 学生请客
    //connect(zt, &Teacher::hungry, st, &Student::treat);
    //出现重载
    void(Teacher:: *teacherSignal)(QString) = &Teacher::hungry;
    void(Student:: *studentSlot)(QString) = &Student::treat;
    connect(zt, teacherSignal, st, studentSlot);

    //调用下课
    classIsOver();

    //点击一个下课了的按钮 ， 再触发下课
    QPushButton *btn = new QPushButton("下课", this);
    this->resize(600,400);
    //connect(btn,&QPushButton::clicked, this, &Widget::classIsOver);

    //无参信号和槽
    void(Teacher:: *teacherSignal2)() = &Teacher::hungry;
    void(Student:: *studentSlot2)() = &Student::treat;
    connect(zt, teacherSignal2, st, studentSlot2);

    //信号连接信号
    connect(btn, &QPushButton::clicked, zt, teacherSignal2);

    //断开信号
    //disconnect(zt, teacherSignal2, st, studentSlot2);

//    [=](){
//        btn->setText("不下课");
//    }();

    //利用lambda表达式 实现点击按钮 关闭窗口
    QPushButton *btn2 = new QPushButton;
    btn2->setText("关闭");
    btn2->move(100,0);
    btn2->setParent(this);
    connect(btn2, &QPushButton::clicked, this, [=](){
        emit zt->hungry("宫保鸡丁");
        btn2->setText("aaa");
    });
}

//下课后， 老师会触发一个信号（饿了）
void Widget::classIsOver()
{
    //触发关键字 emit
    //emit zt->hungry();
    emit zt->hungry("宫保鸡丁");
}

Widget::~Widget()
{
    delete ui;
}

