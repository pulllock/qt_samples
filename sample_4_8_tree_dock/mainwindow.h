#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QLabel>
#include <QTreeWidgetItem>

QT_BEGIN_NAMESPACE
namespace Ui { class MainWindow; }
QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
    Q_OBJECT

private:
    enum treeItemType {topItem = 1001, groupItem, imageItem};
    enum treeColNum {colItem = 0, colItemType = 1};

    // 状态栏文件名显示
    QLabel *fileNameLabel;

    // 当前图片
    QPixmap currentPixmap;

    // 当前图片的缩放比例
    float currentPixmapRatio;

    // 目录树初始化
    void initTree();

    // 添加目录
    void addFolderItem(QTreeWidgetItem *parItem, QString dirName);

    // 提取目录名称
    QString getFinalFolderName(const QString &fullPathName);

    // 添加图片
    void addImageItem(QTreeWidgetItem *parItem, QString fileName);

    // 显示一个图片节点的图片
    void displayImage(QTreeWidgetItem *item);

    // 遍历改变节点标题
    void changeItemCaption(QTreeWidgetItem *item);

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

private slots:
    void on_actionAddFolder_triggered();

    void on_actionAddFiles_triggered();

    void on_treeWidget_currentItemChanged(QTreeWidgetItem *current, QTreeWidgetItem *previous);

    void on_actionDeleteItem_triggered();

    void on_actionFitHeight_triggered();

    void on_actionFitWidth_triggered();

    void on_actionZoomRealSize_triggered();

    void on_actionZoomOut_triggered();

    void on_actionZoomIn_triggered();

    void on_actionDockVisible_triggered(bool arg1);

    void on_actionFloat_triggered(bool checked);

    void on_dockWidget_topLevelChanged(bool topLevel);

    void on_dockWidget_visibilityChanged(bool visible);

private:
    Ui::MainWindow *ui;
};
#endif // MAINWINDOW_H
