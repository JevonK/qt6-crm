#include "loginwindow.h"
#include "ui_loginwindow.h"
#include "mainwindow.h"
#include <QCryptographicHash>
#include <QSqlQuery>
#include <QSqlRecord>
#include <QSettings>
#include <QMessageBox>

loginwindow::loginwindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::loginwindow)
{
    ui->setupUi(this);

    // 设置提醒文案
    ui->lineEdit->setPlaceholderText("请输入用户名");
    ui->lineEdit_2->setPlaceholderText("请输入密码");

    // 设置字符长度
    ui->lineEdit->setMaxLength(20);
    ui->lineEdit_2->setMaxLength(20);

    // 设置为密码输入框
    ui->lineEdit_2->setEchoMode(QLineEdit::Password);

}

loginwindow::~loginwindow()
{
    delete ui;
}

void loginwindow::on_pushButton_clicked()
{
    // 获取参数
    MainWindow *mainUi = new MainWindow();
    QString username = ui->lineEdit->text();
    QString password = ui->lineEdit_2->text();
    // 验证参数不能为空
    if(username.isEmpty() || password.isEmpty())
    {
        QMessageBox::critical(this, tr("提示"), tr("用户名或密码不能为空"));
        return;
    }

    // md5 加密
    QByteArray pwd = QCryptographicHash::hash(password.toLatin1(), QCryptographicHash::Md5 );


    // 获取用户信息
    QString sql = QString("select * from admin where username='%1' and pwd='%2'").arg(username).arg(pwd.toHex());

    QSqlQuery query(sql);
    int usernameNo = query.record().indexOf("username");
    int idNo = query.record().indexOf("admin_id");
    QSettings settings;
    while (query.next()) {
        // 设置登录参数
        qDebug() << query.value(idNo).toString() << query.value(usernameNo).toString();
        settings.setValue("isLogin", 1);
        settings.setValue("userid", query.value(idNo).toString());
        settings.setValue("username", query.value(usernameNo).toString());

        // 关闭当前ui，打开主页
        this->close();
        mainUi->show();
    }

    if (settings.value("isLogin").toInt() != 1)
    {
        QMessageBox::critical(this, tr("提示"), tr("用户名或密码错误"));
        return;
    }

}


