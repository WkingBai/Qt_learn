#include "mywidget.h"
#include <QApplication>


int main(int argc, char *argv[])
{
    //a应用程序对象，再Qt中，应用程序对象有且仅有一个
    QApplication a(argc, argv);
    //窗口对象  mywidget父类->Qwidget(空窗口)
    myWidget w;
    //显示窗口
    w.show();

    //让应用程序对象进入消息循环
    return a.exec();
}
