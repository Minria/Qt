#include "widget.h"

#include <QApplication>

// Teacher class
// Student class
// 下课后，老师触发一个信号，饿了，学生响应信号，请客吃饭
int main(int argc, char *argv[]){
    QApplication a(argc, argv);
    Widget w;
    w.show();
    return a.exec();
}
