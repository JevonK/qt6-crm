#include "mainwindow.h"
#include "./ui_mainwindow.h"
#include "loginwindow.h"

#include "QSqlTableModel"
#include "QTableView"
#include <QTemporaryFile>
#include <QDebug>>
#include <QSettings>

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    QSettings settings;

    // 获取用户id
    int userid = settings.value("userid").toInt();
    qDebug() << userid;

    // 查询数据
    QSqlTableModel *model = new QSqlTableModel;
    QString sql = QString::asprintf("select id, phone, pr_user, status from crm_leads where pr_user=%d limit 10", userid);
    model->setQuery(sql);
    model->setEditStrategy(QSqlTableModel::OnManualSubmit);
    model->select();
    model->setHeaderData(0, Qt::Horizontal, tr("序号"));
    model->setHeaderData(1, Qt::Horizontal, tr("手机号"));
    model->setHeaderData(2, Qt::Horizontal, tr("负责人"));
    model->setHeaderData(3, Qt::Horizontal, tr("状态"));
    ui->admin->setEditTriggers(QAbstractItemView::NoEditTriggers);
    ui->admin->setModel(model);

}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::on_pushButton_2_clicked()
{
    this->close();
    loginwindow *loginUi = new loginwindow();
    loginUi->show();
}

