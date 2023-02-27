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

private slots:
    void on_actionFontBold_triggered(bool checked);

    void on_actionFontItalic_triggered(bool checked);

    void on_actionFontUnderline_triggered(bool checked);

    void on_textEdit_copyAvailable(bool b);

    void on_textEdit_selectionChanged();

    // 改变字体大小的槽函数
    void on_spinBoxFontSize_valueChanged(int fontSize);

    // 选择字体的槽函数
    void on_fontComboBox_currentIndexChanged(const QString &arg1);

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

    // 初始化关联信号和槽函数
    void initSignalSlots();
};
#endif // MAINWINDOW_H
