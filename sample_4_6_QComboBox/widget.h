#ifndef WIDGET_H
#define WIDGET_H

#include <QWidget>

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
    void on_pushButtonInitList_clicked();

    void on_pushButtonInitCity_clicked();

    void on_pushButtonClearList_clicked();

    void on_pushButtonPutToComboBox_clicked();

    void on_pushButtonClearText_clicked();

    void on_comboBoxSimpleList_currentIndexChanged(const QString &text);

    void on_comboBoxCityList_currentIndexChanged(const QString &text);

    void on_plainTextEdit_customContextMenuRequested(const QPoint &pos);

private:
    Ui::Widget *ui;
};
#endif // WIDGET_H
