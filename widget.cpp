#include "widget.h"
#include "teacher.h"
#include "student.h"
#include "QPushButton"
#include "QDebug"
// Teacher 类 老师类
// Student 类 学生类
// 下课后，老师会触发一个信号，饿了，学生响应信号，请客吃饭


Widget::Widget(QWidget *parent)
    : QWidget(parent)
{

    // 创建老师对象
    this->zt = new Teacher(this);
    // 创建学生对象
    this->st = new Student(this);

    // 老师饿了
//    connect(zt,&Teacher::hungry, st,&Student::treat);

    // 连接带参数的 信号和槽
    // 指针 -> 地址
    // 函数指针 -> 函数地址
//    void(Teacher:: *teacherSignal)(QString) = &Teacher::hungry;
//    void(Student:: *studentSlot)(QString) = &Student::treat;
//    connect(zt,teacherSignal, st, studentSlot);
    // 调用下课信号
//    classIsOver();
    // 点击连接信号
//    connect(btn,&QPushButton::clicked,this,&Widget::classIsOver);

    // 点击下课按钮再下课
    QPushButton *btn = new QPushButton("下课", this);
    // 重置窗口大小
    this->resize(600,400);

    // 无参信号和槽连接
    void(Teacher:: *teacherSignal2)(void) = &Teacher::hungry;
    void(Student:: *studentSlot2)(void) = &Student::treat;
    connect(zt,teacherSignal2,st,studentSlot2);

    // 信号连接信号
    connect(btn,&QPushButton::clicked,zt,teacherSignal2);

    // 断开信号
//    disconnect(zt,teacherSignal2,st,studentSlot2);

    // 拓展
    // 1. 信号是可以连接信号
    // 2. 一个信号可以连接多个槽函数
    // 3. 多个信号可以连接同一个槽函数
    // 4. 信号和槽函数的类型必须一一对应
    // 5. 信号的参数可以多于槽

    // lambda 表达式 = 值传递  作用域问题 & 引用传递
    QPushButton *btn2 = new QPushButton;
    [=](){
        btn->setText("aaa");
        btn2->setText("bbbb"); // btn2 看不到
    }();

    // mutable关键字 用于修饰值传递变量，修改的是拷贝，不是本体

    // lambda 返回值
    int ref = []()->int{ return 1000;}();

    qDebug() << "ret =" << ref;

    // 利用lamba 表达式 实现点击按钮 关闭窗口
    QPushButton *btn3 = new QPushButton;
    btn3->setParent(this);
    btn3->setText("关闭");
    btn3->move(100,0);
    connect(btn3,&QPushButton::clicked,this,[=](){
        this->close();
    });
}

void Widget::classIsOver()
{
    // 下课函数 触发老师饿了的信号
//    emit zt->hungry();
    emit zt->hungry("宫保鸡丁");
}

Widget::~Widget()
{
}

