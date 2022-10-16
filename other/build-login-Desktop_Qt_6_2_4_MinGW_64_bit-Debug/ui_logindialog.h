/********************************************************************************
** Form generated from reading UI file 'logindialog.ui'
**
** Created by: Qt User Interface Compiler version 6.2.4
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_LOGINDIALOG_H
#define UI_LOGINDIALOG_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QDialog>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QPushButton>

QT_BEGIN_NAMESPACE

class Ui_LoginDialog
{
public:
    QLabel *label;
    QLabel *label_2;
    QLineEdit *usrLineEdit;
    QLineEdit *pwdLineEdit;
    QPushButton *logiBtn;
    QPushButton *exitBtn;

    void setupUi(QDialog *LoginDialog)
    {
        if (LoginDialog->objectName().isEmpty())
            LoginDialog->setObjectName(QString::fromUtf8("LoginDialog"));
        LoginDialog->resize(400, 300);
        label = new QLabel(LoginDialog);
        label->setObjectName(QString::fromUtf8("label"));
        label->setGeometry(QRect(60, 60, 53, 16));
        label_2 = new QLabel(LoginDialog);
        label_2->setObjectName(QString::fromUtf8("label_2"));
        label_2->setGeometry(QRect(60, 90, 53, 16));
        usrLineEdit = new QLineEdit(LoginDialog);
        usrLineEdit->setObjectName(QString::fromUtf8("usrLineEdit"));
        usrLineEdit->setGeometry(QRect(110, 60, 141, 21));
        usrLineEdit->setEchoMode(QLineEdit::Normal);
        pwdLineEdit = new QLineEdit(LoginDialog);
        pwdLineEdit->setObjectName(QString::fromUtf8("pwdLineEdit"));
        pwdLineEdit->setGeometry(QRect(110, 90, 141, 21));
        pwdLineEdit->setEchoMode(QLineEdit::Password);
        logiBtn = new QPushButton(LoginDialog);
        logiBtn->setObjectName(QString::fromUtf8("logiBtn"));
        logiBtn->setGeometry(QRect(80, 140, 75, 24));
        exitBtn = new QPushButton(LoginDialog);
        exitBtn->setObjectName(QString::fromUtf8("exitBtn"));
        exitBtn->setGeometry(QRect(190, 140, 75, 24));

        retranslateUi(LoginDialog);
        QObject::connect(exitBtn, &QPushButton::clicked, LoginDialog, qOverload<>(&QDialog::close));

        QMetaObject::connectSlotsByName(LoginDialog);
    } // setupUi

    void retranslateUi(QDialog *LoginDialog)
    {
        LoginDialog->setWindowTitle(QCoreApplication::translate("LoginDialog", "Dialog", nullptr));
        label->setText(QCoreApplication::translate("LoginDialog", "\347\224\250\346\210\267\345\220\215\357\274\232", nullptr));
        label_2->setText(QCoreApplication::translate("LoginDialog", "\345\257\206   \347\240\201\357\274\232", nullptr));
        usrLineEdit->setPlaceholderText(QCoreApplication::translate("LoginDialog", "please input user", nullptr));
        pwdLineEdit->setPlaceholderText(QCoreApplication::translate("LoginDialog", "please input password", nullptr));
        logiBtn->setText(QCoreApplication::translate("LoginDialog", "\347\231\273 \345\275\225", nullptr));
        exitBtn->setText(QCoreApplication::translate("LoginDialog", "\351\200\200 \345\207\272", nullptr));
    } // retranslateUi

};

namespace Ui {
    class LoginDialog: public Ui_LoginDialog {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_LOGINDIALOG_H
