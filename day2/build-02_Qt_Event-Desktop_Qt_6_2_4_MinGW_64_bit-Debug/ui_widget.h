/********************************************************************************
** Form generated from reading UI file 'widget.ui'
**
** Created by: Qt User Interface Compiler version 6.2.4
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_WIDGET_H
#define UI_WIDGET_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QLabel>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QWidget>
#include "mylabel.h"

QT_BEGIN_NAMESPACE

class Ui_Widget
{
public:
    myLabel *label;
    QLabel *label_time;
    QLabel *label_time2;
    QLabel *label_time3;
    QPushButton *btn;

    void setupUi(QWidget *Widget)
    {
        if (Widget->objectName().isEmpty())
            Widget->setObjectName(QString::fromUtf8("Widget"));
        Widget->resize(800, 600);
        label = new myLabel(Widget);
        label->setObjectName(QString::fromUtf8("label"));
        label->setGeometry(QRect(0, 10, 321, 161));
        label->setFrameShape(QFrame::Box);
        label_time = new QLabel(Widget);
        label_time->setObjectName(QString::fromUtf8("label_time"));
        label_time->setGeometry(QRect(360, 70, 181, 51));
        label_time->setFrameShape(QFrame::StyledPanel);
        label_time2 = new QLabel(Widget);
        label_time2->setObjectName(QString::fromUtf8("label_time2"));
        label_time2->setGeometry(QRect(360, 150, 181, 41));
        label_time2->setFrameShape(QFrame::WinPanel);
        label_time3 = new QLabel(Widget);
        label_time3->setObjectName(QString::fromUtf8("label_time3"));
        label_time3->setGeometry(QRect(360, 20, 181, 31));
        label_time3->setFrameShape(QFrame::Panel);
        label_time3->setFrameShadow(QFrame::Sunken);
        btn = new QPushButton(Widget);
        btn->setObjectName(QString::fromUtf8("btn"));
        btn->setGeometry(QRect(590, 20, 75, 24));

        retranslateUi(Widget);

        QMetaObject::connectSlotsByName(Widget);
    } // setupUi

    void retranslateUi(QWidget *Widget)
    {
        Widget->setWindowTitle(QCoreApplication::translate("Widget", "Widget", nullptr));
        label->setText(QString());
        label_time->setText(QString());
        label_time2->setText(QString());
        label_time3->setText(QString());
        btn->setText(QCoreApplication::translate("Widget", "\346\232\202\345\201\234", nullptr));
    } // retranslateUi

};

namespace Ui {
    class Widget: public Ui_Widget {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_WIDGET_H
