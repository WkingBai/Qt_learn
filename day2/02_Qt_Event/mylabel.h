#ifndef MYLABEL_H
#define MYLABEL_H

#include <QLabel>

class myLabel : public QLabel
{
    Q_OBJECT
public:
    explicit myLabel(QWidget *parent = nullptr);

    void enterEvent(QEnterEvent *event); //鼠标进入事件

    void leaveEvent(QEvent *); //鼠标离开事件

    //鼠标移动，按下，释放事件

    virtual void mouseMoveEvent(QMouseEvent *ev) ;

    virtual void mousePressEvent(QMouseEvent *ev) ;

    virtual void mouseReleaseEvent(QMouseEvent *ev) ;

    //通过event事件分发器 拦截 鼠标按下事件
    bool event(QEvent *);

signals:

};

#endif // MYLABEL_H
