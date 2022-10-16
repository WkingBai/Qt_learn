#include "widget.h"
#include "ui_widget.h"
#include<QMouseEvent>
#include<QDebug>

Widget::Widget(QWidget *parent)
    : QWidget(parent)
    , ui(new Ui::Widget)
{
    ui->setupUi(this);

    //启动定时器
   id1 =  startTimer(1000); //参数1 间隔（ms) ,返回值 timeId;
   id2 = startTimer(2000);

   //定时器第二种方式(建议）
   QTimer *timer = new QTimer(this);
   //启动定时器
   timer->start(500);

   connect(timer, &QTimer::timeout, [=](){
       static int num = 1;
       //label_time 每隔0.5s +1
       ui->label_time3->setText(QString::number(num++));
   });

   //点击暂停按钮 停止定时器
   connect(ui->btn, &QPushButton::clicked,[=](){
       if(ui->btn->text() == "暂停"){
            timer->stop();
            ui->btn->setText("开始");
       }
       else{
            timer->start();
            ui->btn->setText("暂停");
       }
   });

   //给label 安装事件过滤器
   //步骤1：安装事件过滤器
   ui->label->installEventFilter(this);

}

//步骤2：重写eventfilter事件
 bool Widget::eventFilter(QObject *obj, QEvent *e)
 {
     if(obj == ui->label){
         if(e->type() == QEvent::MouseButtonPress){
             QMouseEvent *ev = static_cast<QMouseEvent *>(e);
             QString str = QString("事件过滤器中： 鼠标按下 x = %1   y = %2   gx = %3  gy = %4")
                     .arg(ev->x()).arg(ev->y()).arg(ev->globalX()).arg(ev->globalY());
              qDebug() << str;

              return true;
         }
     }

     //其他默认处理
     return QWidget::eventFilter(obj,e);
 }

void Widget::timerEvent(QTimerEvent *ev)
{
    if(ev->timerId() == id1){
        static int num = 1;
        //label_time 每隔1s +1
        ui->label_time->setText(QString::number(num++));
    }

    if(ev->timerId() == id2){
        static int num2 = 1;
        ui->label_time2->setText(QString::number(num2++));
    }
    //label_time2 每隔2s +1
}

Widget::~Widget()
{
    delete ui;
}

