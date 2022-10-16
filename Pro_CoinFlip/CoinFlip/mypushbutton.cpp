#include "mypushbutton.h"
#include<QPushButton>
#include<QDebug>
#include<QPropertyAnimation>

//MyPushButton::MyPushButton(QWidget *parent)
//    : QPushButton{parent}
//{

//}
MyPushButton::MyPushButton(QString normalImg, QString pressImg)
{
    this->normalImgPath = normalImg;
    this->pressImgPath = pressImg;

    QPixmap pix;
    bool ret = pix.load(normalImg);
    if(!ret){
        qDebug() << "图片加载失败";
        return;
    }
    //设置图片固定大小
    this->setFixedSize(pix.width(), pix.height());

    //设置不规则图片样式
    this->setStyleSheet("QPushButton{border:0px;}");

    //设置图标
    this->setIcon(pix);

    //设置图标大小
    this->setIconSize(QSize(pix.width(),pix.height()));

}

void MyPushButton::zoom1()
{
    //创建动态对象
    QPropertyAnimation * animation = new QPropertyAnimation(this, "geometry");

    //设置动画的时间间隔
    animation->setDuration(500);

    //起始位置
    animation->setStartValue(QRect(img_x,img_y,this->width(),this->height()));

    //结束位置
    animation->setEndValue((QRect(img_x,img_y+10,this->width(),this->height())));

    //设置弹跳曲线
    animation->setEasingCurve(QEasingCurve::OutElastic);

    //执行动画
    animation->start();
}


void MyPushButton::zoom2()
{
    //创建动态对象
    QPropertyAnimation * animation = new QPropertyAnimation(this, "geometry");

    //设置动画的时间间隔
    animation->setDuration(500);

    //起始位置
    animation->setStartValue(QRect(img_x,img_y+10,this->width(),this->height()));

    //结束位置
    animation->setEndValue((QRect(img_x,img_y,this->width(),this->height())));

    //设置弹跳曲线
    animation->setEasingCurve(QEasingCurve::OutElastic);

    //执行动画
    animation->start();
}


void MyPushButton::mousePressEvent(QMouseEvent *e)
{
    if(this->pressImgPath !="") //传入按下图片不为空 按下时切换图片
    {
        QPixmap pix;
        bool ret = pix.load(this->pressImgPath);
        if(!ret){
            qDebug() << "图片加载失败";
            return;
        }
        //设置图片固定大小
        this->setFixedSize(pix.width(), pix.height());

        //设置不规则图片样式
        this->setStyleSheet("QPushButton{border:0px;}");

        //设置图标
        this->setIcon(pix);

        //设置图标大小
        this->setIconSize(QSize(pix.width(),pix.height()));
    }

    //让父类执行其他效果
    return QPushButton::mousePressEvent(e);
}

void MyPushButton::mouseReleaseEvent(QMouseEvent *e)
{
    if(this->pressImgPath !="") //传入按下图片不为空 按下时切换图片
    {
        QPixmap pix;
        bool ret = pix.load(this->normalImgPath);
        if(!ret){
            qDebug() << "图片加载失败";
            return;
        }
        //设置图片固定大小
        this->setFixedSize(pix.width(), pix.height());

        //设置不规则图片样式
        this->setStyleSheet("QPushButton{border:0px;}");

        //设置图标
        this->setIcon(pix);

        //设置图标大小
        this->setIconSize(QSize(pix.width(),pix.height()));
    }

    //让父类执行其他效果
    return QPushButton::mouseReleaseEvent(e);
}
