#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include "custom_image_widget.h"

QT_BEGIN_NAMESPACE
namespace Ui { class MainWindow; }
QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

    // 显示图片
    void showImage(QImage image);

private slots:
    void on_toolButton_clicked();

private:
    Ui::MainWindow *ui;
    CustomImageWidget *m_customImageWidget;
};
#endif // MAINWINDOW_H
