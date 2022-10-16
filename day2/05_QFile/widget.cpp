#include "widget.h"
#include "ui_widget.h"
#include<QFileDialog>
#include<QFile>
#include<QStringConverter>
#include<QFileInfo>
#include<QDebug>

Widget::Widget(QWidget *parent)
    : QWidget(parent)
    , ui(new Ui::Widget)
{
    ui->setupUi(this);

    //点击选取文件按钮, 弹出选取文件对话框
    connect(ui->pushButton, &QPushButton::clicked, [=](){
        QString path = QFileDialog::getOpenFileName(this, "打开文件","E:\\桌面\\");
        //将路径放入到lineEdit中
        ui->lineEdit->setText(path);


        //读取内容放入 textEdit 中
        //QFile 默认支持格式为utf-8
        QFile file(path);
        //设置打开方式
        file.open(QIODeviceBase::ReadOnly);

        //读取文件
//        QByteArray array = file.readAll();
        QByteArray array;
        while(!file.atEnd()){
            array += file.readLine();
        }
        //将读取的数据 放入textEdit中
        ui->textEdit->setText(array);

        //对文件对象进行关闭
        file.close();

        //进行写文件
//        file.open(QIODevice::Append);
//        file.write("\n大货辅料夸奖哈得过来看");
//        file.close();

        //QFileInfo 文件信息类
        QFileInfo info(path);
        qDebug() << "大小:" <<  info.size() << "后缀名:" << info.suffix() << "文件名称:" << info.fileName()
               <<"文件路径:" << info.path();
        qDebug() << "创建时间:" << info.birthTime().toString("yyyy/MM/dd hh:mm:ss");
        qDebug() << "最后修改时间:" << info.lastModified().toString("yyyy/MM/dd hh:mm:ss");
    });
}

Widget::~Widget()
{
    delete ui;
}

