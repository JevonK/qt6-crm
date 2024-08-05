#include "mainwindow.h"
#include "./ui_mainwindow.h"
#include "./customwindow.h"

#include <QDebug>>

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    CustomWindow* customUI = new CustomWindow(this);
    QHBoxLayout *layout = new QHBoxLayout(this);
    layout->addWidget(customUI);
    ui->main->setLayout(layout);

}

MainWindow::~MainWindow()
{
    delete ui;
}


