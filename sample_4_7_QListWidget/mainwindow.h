#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QListWidget>
#include <QMainWindow>

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
    void on_actionInitList_triggered();

    void on_actionInsertItem_triggered();

    void on_actionDeleteCurrentItem_triggered();

    void on_actionClearList_triggered();

    void on_actionSelectAll_triggered();

    void on_actionSelectNone_triggered();

    void on_actionSelectReverse_triggered();
    
    void on_checkBox_clicked(bool checked);

    void on_listWidget_currentItemChanged(QListWidgetItem *current, QListWidgetItem *previous);

    void on_listWidget_customContextMenuRequested(const QPoint &pos);

private:
    Ui::MainWindow *ui;
    void setActionsForToolButton();
    void createSelectionPopMenu();
};
#endif // MAINWINDOW_H
