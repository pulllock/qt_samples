#ifndef WIDGET_H
#define WIDGET_H

#include <QWidget>
#include <QElapsedTimer>

QT_BEGIN_NAMESPACE
namespace Ui { class Widget; }
QT_END_NAMESPACE

class Widget : public QWidget
{
    Q_OBJECT

public:
    Widget(QWidget *parent = nullptr);
    ~Widget();

private slots:
    void on_pushButtonReadCurrentDateTime_clicked();

    void on_pushButtonSetTime_clicked();

    void on_pushButtonSetDate_clicked();

    void on_pushButtonSetDateTime_clicked();

    void on_calendarWidget_selectionChanged();

    // 定时溢出处理的槽函数
    void on_timer_timeout();

    void on_pushButtonStart_clicked();

    void on_pushButtonStop_clicked();

private:
    Ui::Widget *ui;

    // 定时器
    QTimer *timer;

    // 计时器
    QElapsedTimer *timeCounter;
};
#endif // WIDGET_H
