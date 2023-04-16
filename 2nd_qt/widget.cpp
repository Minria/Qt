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
    // 通过按钮来触发下课函数
//    connect(btn,&QPushButton::clicked,this,&Widget::classIsOver);
    // 信号触发槽函数
    void(Teacher:: *tSignal2)(void) = &Teacher::hungry;
    void(Student:: *sSlot2)(void) = &Student::treat;
    // 通过按钮来触发请客吃饭函数
//    connect(btn,&QPushButton::clicked,s,sSlot2);
    // 信号连接信号
    // 将老师饥饿和学生请客吃饭绑定
    // 按钮来触发老师饥饿
    connect(t,tSignal2,s,sSlot2);
    connect(btn,&QPushButton::clicked,t,tSignal2);
//    disconnect(t,tSignal2,s,sSlot2); 断开连接
    //拓展
    //1、信号是可以连接信号
    //2、一个信号可以连接多个槽函数
    //3、多个信号 可以连接 同一个槽函数
    //4、信号和槽函数的参数 必须类型一一对应
    //5、信号和槽的参数个数  是不是要一致？信号的参数个数 可以多余槽函数的参数个数
}
void Widget::classIsOver(){
//    emit t->hungry();
    emit t->hungry("宫保鸡丁");
}


Widget::~Widget(){
    delete ui;
}

