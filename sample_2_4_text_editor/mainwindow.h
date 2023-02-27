#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QLabel>
#include <QProgressBar>
#include <QSpinBox>
#include <QFontComboBox>

QT_BEGIN_NAMESPACE
namespace Ui { class MainWindow; }
QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

private:
    Ui::MainWindow *ui;

    // 状态栏里显示当前文件的Label
    QLabel *labelCurrentFile;

    // 状态栏上的进度条
    QProgressBar *progressBar;

    // 字体大小的SpinBox
    QSpinBox *spinBoxFontSize;

    // 字体名称的ComboBox
    QFontComboBox *fontComboBox;

    // 代码实现的UI初始化
    void initUi();
};
#endif // MAINWINDOW_H
