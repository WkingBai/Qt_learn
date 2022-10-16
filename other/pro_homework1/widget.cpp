#include "widget.h"
#include "ui_widget.h"
#include<QPushButton>
#include<QDialog>

Widget::Widget(QWidget *parent)
    : QWidget(parent)
    , ui(new Ui::Widget)
{
    ui->setupUi(this);
    QPushButton *btn = new QPushButton("开始",this);
    btn->move(100,100);
    QWidget *nw = new QWidget;
    connect(btn, &QPushButton::clicked, this,[=](){
        if(btn->text() == "开始"){
            btn->setText("关闭");
            nw->show();
        }
        else{
            btn->setText("开始");
            nw->close();
        }
    });

}

Widget::~Widget()
{
    delete ui;
}

