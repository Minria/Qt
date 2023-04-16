#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    ui->actionNew->setIcon(QIcon(":/image‪/image2.png"));
    ui->actionOpen->setIcon(QIcon(":/image‪/image2.png"));
}

MainWindow::~MainWindow()
{
    delete ui;
}

