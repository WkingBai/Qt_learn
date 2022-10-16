#include "mycoin.h"
#include<QDebug>

//MyCoin::MyCoin(QWidget *parent)
//    : QWidget{parent}
//{

//}

MyCoin::MyCoin(QString btnImg)
{
    QPixmap pix;
    bool ret = pix.load(btnImg);
    if(!ret){
        QString str = QString("图片 %1 加载失败").arg(btnImg);
        qDebug() << str;
        return;
    }
    this->setFixedSize(pix.width(), pix.height());
    this->setStyleSheet("QPushButton{border:0px;}");
    this->setIcon(pix);
    this->setIconSize(QSize(pix.width(), pix.height()));

    //初始化反面定时器
    timer1 = new QTimer(this);
    timer2 = new QTimer(this);

    //监听翻转信号
    connect(timer1, &QTimer::timeout,[=](){
        QPixmap pix;
        QString str = QString(":/res/Coin000%1.png").arg(this->min++);
        pix.load(str);

        this->setFixedSize(pix.width(), pix.height());
        this->setStyleSheet("QPushButton{border:0px;}");
        this->setIcon(pix);
        this->setIconSize(QSize(pix.width(), pix.height()));

        //判断 如果翻完了，将min置为1
        if(this->min > this->max){
            this->min = 1;
            isAnimation = false;
            timer1->stop();
        }
    });

    connect(timer2, &QTimer::timeout,[=](){
        QPixmap pix;
        QString str = QString(":/res/Coin000%1.png").arg(this->max--);
        pix.load(str);

        this->setFixedSize(pix.width(), pix.height());
        this->setStyleSheet("QPushButton{border:0px;}");
        this->setIcon(pix);
        this->setIconSize(QSize(pix.width(), pix.height()));

        //判断 如果翻完了，将min置为1
        if(this->min > this->max){
            this->max = 8;
            isAnimation = false;
            timer2->stop();
        }
    });
}


//改变flag函数（正反面标志）
void MyCoin::changeFlag()
{
    if(this->flag)
    {
        //翻面定时器
        timer1->start(30);
        isAnimation = true;
        this->flag = false;
    }
    else{
        timer2->start(30);
        isAnimation = true;
        this->flag = true;
    }
}

void MyCoin::mousePressEvent(QMouseEvent *e)
{
    if(this->isAnimation || this->isWin){
        return;
    }
    else{
        QPushButton::mousePressEvent(e);
    }
}
