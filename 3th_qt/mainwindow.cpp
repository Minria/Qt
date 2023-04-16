#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <QMenuBar>
#include <QToolBar>
#include <QPushButton>
#include <QLabel>
#include <QDockWidget>
#include <QTextEdit>
MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    resize(600,400);
    // 创建菜单栏
    QMenuBar* bar = new QMenuBar();
    setMenuBar(bar); // 将菜单栏放入窗口中
    // 创建菜单
    QMenu* file = bar->addMenu("文件");
    QMenu* edit = bar->addMenu("编辑");
    // 创建菜单项
    QAction* newAction = file->addAction("新建");
    // 这是分割符
    file->addSeparator();
    QAction* deleteAction = file->addAction("删除");
    edit->addAction("修改");
    //创建工具栏，工具栏可以有多个
    QToolBar* toolBar = new QToolBar(this);
    addToolBar(Qt::LeftToolBarArea,toolBar);
    toolBar->setFloatable(false); // 是否浮动
    toolBar->setMovable(false); // 是否移动
    toolBar->addAction(newAction);
    toolBar->addAction(deleteAction);
    // 工具栏加入插件
    QPushButton* btn = new QPushButton("aa",this);
    toolBar->addWidget(btn);
    //创建状态栏  只有一个
    QStatusBar* st = statusBar();
    // 设置到窗口中
    setStatusBar(st);
    QLabel* lable = new QLabel("提示信息",this);
    st->addWidget(lable);
    QLabel* lable2 = new QLabel("右侧提示信息",this);
    st->addPermanentWidget(lable2);
    // 浮动窗口 可以有多个
    QDockWidget* dock = new QDockWidget("浮动",this);
    addDockWidget(Qt::BottomDockWidgetArea,dock);
    //设置后期停靠区域，只允许上下
    dock->setAllowedAreas( Qt::TopDockWidgetArea | Qt::BottomDockWidgetArea );
    // 设置中心部件 只能一个
    QTextEdit* qedit = new QTextEdit(this);
    setCentralWidget(qedit);
}

MainWindow::~MainWindow()
{
    delete ui;
}

