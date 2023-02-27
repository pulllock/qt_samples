#ifndef DIALOG_H
#define DIALOG_H
#include <QDialog>
#include <QCheckBox>
#include <QRadioButton>
#include <QPlainTextEdit>
#include <QPushButton>

#include <QDialog>

class Dialog : public QDialog
{
    Q_OBJECT

private:
    // 复选框
    QCheckBox *checkBoxUnderline;
    QCheckBox *checkBoxItalic;
    QCheckBox *checkBoxBold;

    // 单选框
    QRadioButton *radioButtonBlack;
    QRadioButton *radioButtonRed;
    QRadioButton *radioButtonBlue;

    // 文本编辑
    QPlainTextEdit *plainTextEdit;

    // 按钮
    QPushButton *pushButtonOk;
    QPushButton *pushButtonCancel;
    QPushButton *pushButtonClose;

    // ui创建与初始化
    void initUi();

    // 初始化信号和槽的链接
    void initSignalSlots();

private slots:
    /**
     * 下划线复选框点击的槽函数
     * @param checked
     */
    void on_checkBoxUnderline_clicked(bool checked);

    /**
     * 斜体复选框点击的槽函数
     * @param checked
     */
    void on_checkBoxItalic_clicked(bool checked);

    /**
     * 加粗复选框点击的槽函数
     * @param checked
     */
    void on_checkBoxBold_clicked(bool checked);

    /**
     * 设置字体颜色槽函数
     */
    void setTextFontColor();
public:
    Dialog(QWidget *parent = nullptr);
    ~Dialog();
};
#endif // DIALOG_H
