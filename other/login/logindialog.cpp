#include "logindialog.h"
#include "ui_logindialog.h"
#include <QMessageBox>

LoginDialog::LoginDialog(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::LoginDialog)
{
    ui->setupUi(this);
}

LoginDialog::~LoginDialog()
{
    delete ui;
}

void LoginDialog::on_logiBtn_clicked()
{
   if(ui->usrLineEdit->text().trimmed() == tr("Wkingbai") &&
           ui->pwdLineEdit->text() == tr("123456")){
       accept();
   }
   else{
        QMessageBox::warning(this, tr("警告"), tr("用户名和密码错误"),
                            QMessageBox::Yes);
        //清空内容，设置定位光标
        ui->usrLineEdit->clear();
        ui->pwdLineEdit->clear();
        ui->usrLineEdit->setFocus();
   }
}

