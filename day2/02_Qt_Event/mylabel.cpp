#include "mylabel.h"
#include<QDebug>
#include<QMouseEvent>
myLabel::myLabel(QWidget *parent)
    : QLabel{parent}
{
    //设置鼠标追踪
    setMouseTracking(true); //无需按下即可追踪鼠标位置
}
void myLabel::enterEvent(QEnterEvent *event) //鼠标进入事件
{
    qDebug() << "鼠标进入";
}
void myLabel::leaveEvent(QEvent *event) //鼠标离开事件
{
    qDebug() << "鼠标离开";
}


void myLabel::mouseMoveEvent(QMouseEvent *ev)
{
//     if(ev->buttons() & Qt::RightButton){
        QString str = QString("鼠标移动 x = %1   y = %2   gx = %3  gy = %4")
                .arg(ev->x()).arg(ev->y()).arg(ev->globalX()).arg(ev->globalY());
         qDebug() << str;
//     }
}

void myLabel::mousePressEvent(QMouseEvent *ev)
{
    //左键才打印信息
    if(ev->button() == Qt::RightButton){
        QString str = QString("鼠标按下 x = %1   y = %2   gx = %3  gy = %4")
                .arg(ev->x()).arg(ev->y()).arg(ev->globalX()).arg(ev->globalY());
         qDebug() << str;
    }
}

bool myLabel::event(QEvent *e) //(不建议使用)
{
    //如果是鼠标按下，在event事件分发中做拦截操作
    if(e->type() == QEvent::MouseButtonPress)
    {
        QMouseEvent *ev = static_cast<QMouseEvent *>(e);
        QString str = QString("Event中： 鼠标按下 x = %1   y = %2   gx = %3  gy = %4")
                .arg(ev->x()).arg(ev->y()).arg(ev->globalX()).arg(ev->globalY());
         qDebug() << str;

         return true;
    }

    //其他的事件 交给父类处理 默认处理
    return QLabel::event(e);
}

void myLabel::mouseReleaseEvent(QMouseEvent *ev)
{
     if(ev->button() == Qt::RightButton){
        QString str = QString("鼠标释放 x = %1   y = %2   gx = %3  gy = %4")
                .arg(ev->x()).arg(ev->y()).arg(ev->globalX()).arg(ev->globalY());
         qDebug() << str;
     }
}
