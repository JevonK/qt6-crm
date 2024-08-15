#include "mainwindow.h"
#include "loginwindow.h"

#include <QApplication>
#include <QLocale>
#include <QTranslator>
#include "QSqlDatabase.h"
#include <QSettings>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);

    QTranslator translator;
    const QStringList uiLanguages = QLocale::system().uiLanguages();
    for (const QString &locale : uiLanguages) {
        const QString baseName = "crm_" + QLocale(locale).name();
        if (translator.load(":/i18n/" + baseName)) {
            a.installTranslator(&translator);
            break;
        }
    }

    QSqlDatabase db = QSqlDatabase::addDatabase("QMYSQL");
    db.setHostName("127.0.0.1");  //连接本地主机
    db.setPort(3306);
    db.setDatabaseName("crm6.me");  //Mysql 创建的数据库名称
    db.setUserName("root");
    db.setPassword("123456");    //安装 Mysql 设置的密码
    bool ok = db.open();
    if (ok){
        qDebug() << "mysql link success";
    }
    else {
        qDebug() <<  "mysql link failed";
    }

    // 判断是否登录
    QSettings settings("myCompany", QSettings::IniFormat);
    QString isLogin = settings.value("users/isLogin").toString();
    if (isLogin != "1")
    {
        loginwindow *loginUi = new loginwindow();
        loginUi->show();
    } else {
        MainWindow *w = new MainWindow();
        w->show();
    }

    int nRut = a.exec();
    if(0 == nRut)
    {
        // settings.clear();
        db.close();
    }
    return nRut;
}
