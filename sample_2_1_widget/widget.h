#ifndef WIDGET_H
#define WIDGET_H

#include <QWidget>

QT_BEGIN_NAMESPACE
// 声明一个命名空间Ui，包含一个类Widget，此Widget类是ui_widget.h文件里定义的类
namespace Ui { class Widget; }
QT_END_NAMESPACE

// Widget继承自QWidget
class Widget : public QWidget
{
    // 宏Q_OBJECT，用来使用Qt的信号和槽机制
    Q_OBJECT

public:
    // 构造函数
    Widget(QWidget *parent = nullptr);

    // 析构函数
    ~Widget();

private:
    // 这个指针指向了可视化设计界面，后面要访问界面上的组件都需要通过这个指针
    Ui::Widget *ui;
};
#endif // WIDGET_H
