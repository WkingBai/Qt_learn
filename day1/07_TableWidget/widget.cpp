#include "widget.h"
#include "ui_widget.h"

Widget::Widget(QWidget *parent)
    : QWidget(parent)
    , ui(new Ui::Widget)
{
    ui->setupUi(this);

    //TableWidget控件
    //设置列数
    ui->tableWidget->setColumnCount(3);

    //设置水平表头
    ui->tableWidget->setHorizontalHeaderLabels(QStringList() <<"姓名" <<"性别" <<"年龄");

    //设置行数
    ui->tableWidget->setRowCount(5);

    //设置正文
//    ui->tableWidget->setItem(0,0,new QTableWidgetItem("压索"));
    QStringList nameList;
    nameList <<"亚索" << "石头" <<"刀妹" <<"左移" << "米沙拉";

    QStringList sexList;
    sexList << "男" << "男" << "女" << "女" << "女";

    QStringList yearList;
    yearList << "35" <<"100" <<"19" <<"3000" <<"18";

    for(int i = 0; i < 5; ++i){
        int col = 0;
        ui->tableWidget->setItem(i,col++,new QTableWidgetItem(nameList[i]));
        ui->tableWidget->setItem(i,col++,new QTableWidgetItem(sexList[i]));
        ui->tableWidget->setItem(i,col++,new QTableWidgetItem(yearList[i]));
    }
}

Widget::~Widget()
{
    delete ui;
}

