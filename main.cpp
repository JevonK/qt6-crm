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
    db.setPassword("");    //安装 Mysql 设置的密码

    MainWindow w;
    loginwindow *loginUi = new loginwindow();
    // 判断是否登录
    QSettings settings;
    settings.clear();
    QString isLogin = settings.value("isLogin").toString();
    if (isLogin != "1")
    {
        loginUi->show();
    } else {
        w.show();
    }

    int nRut = a.exec();
    if(0 == nRut)
    {
        settings.setValue("isLogin", "0");
        db.close();
    }
    return nRut;
}
