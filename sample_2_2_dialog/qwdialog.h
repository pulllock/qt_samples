#ifndef QWDIALOG_H
#define QWDIALOG_H

#include <QDialog>

QT_BEGIN_NAMESPACE
namespace Ui { class QWDialog; }
QT_END_NAMESPACE

class QWDialog : public QDialog
{
    Q_OBJECT

public:
    QWDialog(QWidget *parent = nullptr);
    ~QWDialog();

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

private:
    Ui::QWDialog *ui;
};
#endif // QWDIALOG_H
