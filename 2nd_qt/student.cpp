#include "student.h"
#include <QDebug>
Student::Student(QObject *parent) : QObject(parent){

}

void Student::treat(){
    qDebug()<<"请客吃饭";
}
void Student::treat(QString name){
    //QString 转 char*

    qDebug()<< "请吃" << name.toUtf8().data();
}
