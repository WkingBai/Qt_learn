#ifndef STUDENT_H
#define STUDENT_H

#include <QObject>
class Student : public QObject
{
    Q_OBJECT
public:
    explicit Student(QObject *parent = nullptr);
    //早期QT版本 槽函数必须写在public slots下，现版本写道public或全局下
    //返回值void， 需要声明， 也需要实现
    //可以有参数， 可以发生重载
    void treat();
    void treat(QString foodName);
signals:
};

#endif // STUDENT_H
