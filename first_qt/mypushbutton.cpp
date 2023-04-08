#include "mypushbutton.h"
#include<QDebug>
MyPushButton::MyPushButton(QWidget *parent) : QPushButton(parent){
    qDebug() << "自定义的构造函数启动";
}
MyPushButton::~MyPushButton(){
    qDebug() << "自定义的析构函数启动";
}
