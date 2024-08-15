#include "customwindow.h"
#include "ui_customwindow.h"
#include <QDebug>
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

    // 查询数据
    QSqlTableModel *model = this->tableList();
    ui->admin->setEditTriggers(QAbstractItemView::NoEditTriggers);
    ui->admin->setModel(model);

    // 设置总页数
    QString total_num = QString::number(this->tableListTotal());
    ui->total_page_num->setText(total_num);
}

CustomWindow::~CustomWindow()
{
    delete ui;
}

void CustomWindow::on_previous_page_clicked()
{
    bool ok;
    int current_page_num = ui->current_page_num->text().toInt(&ok, 10);

    // 判断是否为第一页
    if (1 == current_page_num)
    {
        QMessageBox::warning(this, tr("提示"),tr("当前已经是最小页数"));
        return;
    }

    // 查询上一页
    current_page_num -= 1;
    QSqlTableModel *model = this->tableList(current_page_num);
    ui->admin->setEditTriggers(QAbstractItemView::NoEditTriggers);
    ui->admin->setModel(model);
    ui->current_page_num->setText(QString::number(current_page_num));

    // 设置总页数
    QString total_num = QString::number(this->tableListTotal());
    ui->total_page_num->setText(total_num);
}


void CustomWindow::on_next_page_clicked()
{
    bool ok;
    int current_page_num = ui->current_page_num->text().toInt(&ok, 10);
    int total_page_num = ui->total_page_text->text().toInt(&ok, 10);

    // 判断是否为最后一页
    int max_page = ceil(total_page_num/10);
    if (current_page_num == max_page)
    {
        QMessageBox::warning(this, tr("提示"),tr("当前已经是最大页数"));
        return;
    }

    // 查询上一页
    current_page_num += 1;
    QSqlTableModel *model = this->tableList(current_page_num);
    ui->admin->setEditTriggers(QAbstractItemView::NoEditTriggers);
    ui->admin->setModel(model);
    ui->current_page_num->setText(QString::number(current_page_num));

    // 设置总页数
    QString total_num = QString::number(this->tableListTotal());
    ui->total_page_num->setText(total_num);


}


