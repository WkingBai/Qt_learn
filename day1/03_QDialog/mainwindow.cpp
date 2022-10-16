#include "mainwindow.h"
#include "ui_mainwindow.h"
#include<QDialog>
#include<QDebug>
#include<QMessageBox>
#include<QColorDialog>
#include<QFileDialog>
#include<QFontDialog>

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    //点击新建按钮 弹出对话框
    connect(ui->actionnew,&QAction::triggered,[=](){
        //对话框 分类
//        //1.模态对话框（打开对话框后，不能对其他窗口操作）
//        QDialog dlg(this);
//        dlg.resize(200,100); //对话框尺寸
//        dlg.exec(); //模态形式(有阻塞功能）
//        qDebug() <<"模态对话框弹出了";
//        //2.非模态对话框（打开对话框后，可以对其他窗口进行操作）
//        QDialog *dlg2 = new QDialog(this);
//        dlg2->resize(200,100);
//        dlg2->show(); //非模态形式(无阻塞功能)
//        dlg2->setAttribute(Qt::WA_DeleteOnClose); //55号 属性（关闭即释放内存）
//        qDebug() <<"非模态对话框弹出了";

        //消息对话框
        //错误对话框
//        QMessageBox::critical(this,"critical","错误");

         //信息对话框
//        QMessageBox::information(this,"information","信息");
        \
        //问题对话框
//        if(QMessageBox::Save == QMessageBox::question(this,"question","问题",QMessageBox::Save | QMessageBox::Cancel,QMessageBox::Cancel))
//        {
//            qDebug()<<"保存";
//        }
//        else
//        {
//            qDebug()<<"取消";
//        }

        //警告对话框
//        QMessageBox::warning(this,"warning","警告");

        //其他对话框
        //颜色对话框
//        QColor color = QColorDialog::getColor(QColor(255,0,0));
//        qDebug() << "r = " << color.red() << "g = " << color.green() << "b = " << color.blue();

        //文件对话框
//        QString str = QFileDialog::getOpenFileName(this,"打开文件","E:\\Qt","(*.txt)");
//        qDebug() << str;

        //字体对话框
        bool flag;
        QFont font = QFontDialog::getFont(&flag,QFont("华文彩云",36));
        qDebug() << "字体： " << font.family().toUtf8().data() << "字号： " << font.pointSize()
                 << "是否加粗： " << font.bold() << "是否倾斜： " << font.italic();
    });
}

MainWindow::~MainWindow()
{
    delete ui;
}

