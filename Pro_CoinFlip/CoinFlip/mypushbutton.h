#ifndef MYPUSHBUTTON_H
#define MYPUSHBUTTON_H

#include <QPushButton>

class MyPushButton : public QPushButton
{
    Q_OBJECT
public:
    //explicit MyPushButton(QWidget *parent = nullptr);
    //构造函数 参数1:正常显示的图片路径   参数2:按下后显示的图片路径
    MyPushButton(QString normalImg, QString pressImg = "");

    QString normalImgPath; //正常显示的图片路径
    QString pressImgPath;  //按下后显示的图片路径

    //弹跳的特效
    void zoom1();//向上跳
    void zoom2();//向下跳
    int img_x;
    int img_y;

    //重写按钮 按下和释放 事件
    void mousePressEvent(QMouseEvent *e);
    void mouseReleaseEvent(QMouseEvent *e);

signals:

};

#endif // MYPUSHBUTTON_H
