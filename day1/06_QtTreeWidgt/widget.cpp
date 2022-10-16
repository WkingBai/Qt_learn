#include "widget.h"
#include "ui_widget.h"

Widget::Widget(QWidget *parent)
    : QWidget(parent)
    , ui(new Ui::Widget)
{
    ui->setupUi(this);
    //treeWidget树控件使用

    //设置水平头
    ui->treeWidget->setHeaderLabels(QStringList()<<"英雄"<<"英雄介绍");

    QTreeWidgetItem *item1 = new QTreeWidgetItem(QStringList()<<"力量");
    QTreeWidgetItem *item2 = new QTreeWidgetItem(QStringList()<<"智力");
    QTreeWidgetItem *item3 = new QTreeWidgetItem(QStringList()<<"敏捷");
    //加载顶层节点
    ui->treeWidget->addTopLevelItem(item1);
    ui->treeWidget->addTopLevelItem(item2);
    ui->treeWidget->addTopLevelItem(item3);

    //追加子节点
     QTreeWidgetItem *figure1 = new QTreeWidgetItem(QStringList()<<"野蛮人" <<" 聚怪，进度，但输出不足");
     item1->addChild(figure1);
}

Widget::~Widget()
{
    delete ui;
}

