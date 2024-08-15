#ifndef CUSTOMWINDOW_H
#define CUSTOMWINDOW_H

#include <QMainWindow>
#include <QSettings>
#include "QSqlTableModel"
#include <QSqlQuery>

namespace Ui {
class CustomWindow;
}

class CustomWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit CustomWindow(QWidget *parent = nullptr);
    ~CustomWindow();
    Ui::CustomWindow *ui;

    // 列表数据
    static QSqlTableModel *tableList(int page = 1, int limit = 15)
    {
        page -= 1;
        page *= 10;
        QSettings settings("myCompany", QSettings::IniFormat);
        int userid = settings.value("users/userid").toInt();
        QSqlTableModel *model = new QSqlTableModel;
        QString sql = QString::asprintf("select id, phone, pr_user, status from crm_leads where pr_user=%d limit %d OFFSET %d", userid, limit, page);
        model->setQuery(sql);
        model->setEditStrategy(QSqlTableModel::OnManualSubmit);
        model->select();
        model->setHeaderData(0, Qt::Horizontal, CustomWindow::tr("序号"));
        model->setHeaderData(1, Qt::Horizontal, CustomWindow::tr("手机号"));
        model->setHeaderData(2, Qt::Horizontal, CustomWindow::tr("负责人"));
        model->setHeaderData(3, Qt::Horizontal, CustomWindow::tr("状态"));
        return model;
    }

    // 获取数据总数据量
    static int tableListTotal()
    {
        QSettings settings("myCompany", QSettings::IniFormat);
        int userid = settings.value("users/userid").toInt();
        QSqlQuery query;
        QString sql = QString::asprintf("select count(id) as total from crm_leads where pr_user=%d", userid);
        query.exec(sql);
        int total = 0;
        while(query.next())
        {
            total = query.value("total").toInt();
            break;
        }
        return total;
    }


private slots:
    void on_previous_page_clicked();

    void on_next_page_clicked();

private:




};

#endif // CUSTOMWINDOW_H
