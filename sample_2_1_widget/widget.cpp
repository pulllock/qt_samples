#include "widget.h"
// Qt编译生成的与UI文件widget.ui对应的类定义文件
#include "./ui_widget.h"

// Widget类的实现

// 构造函数：执行父类QWidget的构造函数，创建一个Ui::Widget类的对象ui，这个ui就是Widget的private部分定义的指针变量ui
Widget::Widget(QWidget *parent)
    : QWidget(parent)
    // 构造函数初始化列表，用来初始化私有成员ui
    , ui(new Ui::Widget)
{
    // 执行了Ui::Widget类的setupUi()函数，这个函数实现窗口的生成与各种属性的设置、信号与槽的关联
    ui->setupUi(this);
}

// 析构函数
Widget::~Widget()
{
    // 删除使用new创建的指针ui
    delete ui;
}

