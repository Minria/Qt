#ifndef TEACHER_H
#define TEACHER_H

#include <QObject>

class Teacher : public QObject
{
    Q_OBJECT
public:
    explicit Teacher(QObject *parent = nullptr);

signals:
    // 自定义信号，协助这里
    // 只需要声明，不需要实现
    // 可以重载
    void hungry();
    void hungry(QString name);
};

#endif // TEACHER_H
