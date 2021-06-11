#include "student.h"
#include "QDebug"
Student::Student(QObject *parent) : QObject(parent)
{

}


void Student::treat()
{
    qDebug() << "请老师吃饭";
}

void Student::treat(QString foodName)
{
    // QString -> char * 先转成 QBtyeArray （ .toUtf8() ） 再转char *
    qDebug() << "请老师吃饭，老师要吃饭：" << foodName.toUtf8().data();
}
