#ifndef CUSTOMWINDOW_H
#define CUSTOMWINDOW_H

#include <QMainWindow>

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

    static QString getList(int prUser, int page = 1, int limit = 15)
    {
        page -= 1;
        page *= 10;
        return QString::asprintf("select id, phone, pr_user, status from crm_leads where pr_user=%d limit %d OFFSET %d", prUser, limit, page);
    };


private slots:
    void on_previous_page_clicked();

    void on_next_page_clicked();

private:




};

#endif // CUSTOMWINDOW_H
