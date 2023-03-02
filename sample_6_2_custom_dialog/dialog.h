#ifndef DIALOG_H
#define DIALOG_H

#include <QDialog>

namespace Ui {
class Dialog;
}

class Dialog : public QDialog
{
    Q_OBJECT

public:
    explicit Dialog(QWidget *parent = nullptr);
    ~Dialog();
    // 返回对话框中的输入框中的值
    QString lineEditValue();
    // 设置对话框中的输入框中的值
    void setLineEditValue(QString value);

private slots:
    void on_pushButtonOk_clicked();

    void on_pushButtonCancel_clicked();

private:
    Ui::Dialog *ui;
};

#endif // DIALOG_H
