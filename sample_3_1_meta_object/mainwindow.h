#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include "qperson.h"

#include <QMainWindow>

QT_BEGIN_NAMESPACE
namespace Ui { class MainWindow; }
QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
    Q_OBJECT

private:
    QPerson *boy;
    QPerson *girl;
public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

private:
    Ui::MainWindow *ui;
private slots:
    // 自定义槽函数
    void on_ageChanged(int value);
    void on_spin_valueChanged(int arg1);

    // 按钮槽函数
    void on_pushButtonClear_clicked();
    void on_pushButtonBoyInc_clicked();
    void on_pushButtonGirlInc_clicked();
    void on_pushButtonClassInfo_clicked();
};
#endif // MAINWINDOW_H
