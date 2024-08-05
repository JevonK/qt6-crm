#include "customwindow.h"
#include "ui_customwindow.h"
#include <QDebug>>
#include <QSettings>
#include "QSqlTableModel"
#include "QTableView"
#include <QTemporaryFile>
#include <QMessageBox>

CustomWindow::CustomWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::CustomWindow)
{
    ui->setupUi(this);

    QSettings settings("myCompany", QSettings::IniFormat);

    // 获取用户id
    int userid = settings.value("users/userid").toInt();
    qDebug() << "userid:" << userid;

    // 查询数据
    QSqlTableModel *model = new QSqlTableModel;
    QString sql = this->getList(userid);
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

CustomWindow::~CustomWindow()
{
    delete ui;
}

void CustomWindow::on_previous_page_clicked()
{
    QSettings settings("myCompany", QSettings::IniFormat);
    bool ok;
    int current_page_num = ui->current_page_num->text().toInt(&ok, 16);

    // 判断是否为第一页
    if (1 == current_page_num)
    {
        QMessageBox::warning(this, tr("提示"),tr("当前已经是最小页数"));
    }

    // 查询上一页
    current_page_num--;
    int userid = settings.value("users/userid").toInt();
    QSqlTableModel *model = new QSqlTableModel;
    QString sql = this->getList(userid);
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


void CustomWindow::on_next_page_clicked()
{
    QSettings settings("myCompany", QSettings::IniFormat);
    bool ok;
    int current_page_num = ui->current_page_num->text().toInt(&ok, 16);
    int total_page_num = ui->total_page_text->text().toInt(&ok, 16);

    // 判断是否为最后一页
    int max_page = ceil(total_page_num/10);
    if (current_page_num == max_page)
    {
        QMessageBox::warning(this, tr("提示"),tr("当前已经是最大页数"));
    }

    // 查询上一页
    current_page_num++;
    int userid = settings.value("users/userid").toInt();
    QSqlTableModel *model = new QSqlTableModel;
    QString sql = this->getList(userid);
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

