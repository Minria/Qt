#include "widget.h"
#include "ui_widget.h"
#include "student.h"
#include "teacher.h"
#include <QPushButton>
Widget::Widget(QWidget *parent)
    : QWidget(parent)
    , ui(new Ui::Widget)
{
    ui->setupUi(this);
    this->t = new Teacher(this);
    this->s = new Student(this);
    // 先连接，后触发  直接触发
//    connect(t,&Teacher::hungry,s,&Student::treat);
    // 重载后需要指定
    void(Teacher:: *tSignal)(QString) = &Teacher::hungry;
    void(Student:: *sSlot)(QString) = &Student::treat;
    connect(t,tSignal,s,sSlot);
    // 调用下课函数后触发
//    classIsOver();

    // 点击一个按钮再下课
    QPushButton* btn = new QPushButton("下课",this);
    this->resize(600,600);
    // 信号触发槽函数
    void(Teacher:: *tSignal2)(void) = &Teacher::hungry;
    void(Student:: *sSlot2)(void) = &Student::treat;
//    connect(btn,&QPushButton::clicked,this,&Widget::classIsOver);
//    connect(btn,&QPushButton::clicked,s,sSlot2);
    // 信号连接信号
    connect(t,tSignal2,s,sSlot2);
    connect(btn,&QPushButton::clicked,t,tSignal2);
    //disconnect(); 断开连接
}
void Widget::classIsOver(){
//    emit t->hungry();
    emit t->hungry("宫保鸡丁");
}


Widget::~Widget(){
    delete ui;
}

