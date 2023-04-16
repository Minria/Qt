#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <QDebug>
#include <QDialog>
MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    // 点击新建按钮，触发功能
    connect(ui->actionnew,&QAction::triggered,[=](){
//                QDialog dlg(this);
//                dlg.resize(200,100);
//                dlg.exec();
//                qDebug() << "模态对话框弹出";

                QDialog* dlg = new QDialog(this);
                dlg->resize(200,100);
                dlg->setAttribute(Qt::WA_DeleteOnClose);
                dlg->show();
            });
}

MainWindow::~MainWindow()
{
    delete ui;
}

