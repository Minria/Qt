#include "widget.h"
#include "ui_widget.h"
#include <QPushButton>
#include <QDebug>
#include "mypushbutton.h"
Widget::Widget(QWidget *parent)
    : QWidget(parent)
    , ui(new Ui::Widget)
{
    ui->setupUi(this);
    // 第一个按钮
    QPushButton* btn = new QPushButton; //  按钮的创建
//    btn->show(); // show以顶层窗口弹出
    btn->setParent(this);
    btn->setText("点击送地狱火");
    // 第二个按钮
    QPushButton* btn2 = new QPushButton("第二个按钮",this);
    btn2->move(100,100);
    // 修改窗口大小
    resize(600,400);
    // 锁定窗口大小
    setFixedSize(600,400);
    // 修改窗口标题
    setWindowTitle("Test");
    MyPushButton* myBtn = new MyPushButton;
    myBtn->setText("自定义按钮");
    myBtn->move(200,100);
    myBtn->setParent(this);
    // 定义需求： 点击自定义按钮，关闭窗口
    // 按钮 - 点击 - 窗口  - 关闭
    // connect（信号的发送者，发送具体的信号，信号的接受者，信号的处理（槽））
    connect(myBtn,&QPushButton::clicked,this,&QWidget::close);
}

Widget::~Widget()
{
    delete ui;
    qDebug() << "父类函数的析构函数启动";
}

