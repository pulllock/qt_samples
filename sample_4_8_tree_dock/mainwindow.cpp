#include <QFileDialog>
#include "mainwindow.h"
#include "./ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    // 设置中心布局组件
    this->setCentralWidget(ui->scrollArea);

    // 状态栏显示文件名
    fileNameLabel = new QLabel("");
    ui->statusbar->addWidget(fileNameLabel);

    // 初始化目录树
    initTree();
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::initTree() {
    // 初始化目录树
    QString dataStr = "";
    ui->treeWidget->clear();

    QTreeWidgetItem *item = new QTreeWidgetItem(MainWindow::topItem);
    // 第1列的文字
    item->setText(MainWindow::colItem,"图片文件");
    // 第2列
    item->setText(MainWindow::colItemType,"type = topItem");
    item->setFlags(Qt::ItemIsSelectable | Qt::ItemIsUserCheckable | Qt::ItemIsEnabled | Qt::ItemIsAutoTristate);
    item->setCheckState(colItem,Qt::Checked);

    item->setData(MainWindow::colItem,Qt::UserRole,QVariant(dataStr));
    // 添加顶层节点
    ui->treeWidget->addTopLevelItem(item);
}

void MainWindow::on_actionAddFolder_triggered()
{
    // 添加组节点
    // 选择目录
    QString dir = QFileDialog::getExistingDirectory();
    if (!dir.isEmpty()) {
        // 当前节点
        QTreeWidgetItem *item = ui->treeWidget->currentItem();
        // 在当前节点下面添加一个组节点
        addFolderItem(item, dir);
    }
}

void MainWindow::addFolderItem(QTreeWidgetItem *parItem, QString dirName) {
    // 从完整的目录名中获得最后的文件夹名
    QString finalDirName = getFinalFolderName(dirName);

    QTreeWidgetItem *item;
    item = new QTreeWidgetItem(MainWindow::groupItem);

    item->setText(colItem, finalDirName);
    item->setText(colItemType, "type = groupItem");
    item->setFlags(Qt::ItemIsSelectable | Qt::ItemIsUserCheckable | Qt::ItemIsEnabled | Qt::ItemIsAutoTristate);
    item->setCheckState(colItem, Qt::Checked);
    item->setData(colItem,Qt::UserRole,QVariant(dirName));

    // 父节点下面添加子节点
    parItem->addChild(item);
}

QString MainWindow::getFinalFolderName(const QString &fullPathName) {
    // 从完整的目录名中获得最后的文件夹名
    int length = fullPathName.length();
    int index = fullPathName.lastIndexOf("/");
    return fullPathName.right(length - index - 1);
}

void MainWindow::on_actionAddFiles_triggered()
{
    // 添加图片文件节点
    QStringList files = QFileDialog::getOpenFileNames(this, "选择一个或多个文件", "", "Images(*.jpg)");
    if (files.isEmpty()) {
        return;
    }

    QTreeWidgetItem *parItem, *item;
    item = ui->treeWidget->currentItem();
    // 当前节点是图片节点
    if (item->type() == imageItem) {
        parItem = item->parent();
    } else {
        parItem = item;
    }

    for (int i = 0; i < files.size(); i++) {
        // 得到一个文件名
        QString fileName = files.at(i);
        // 添加一个图片节点
        addImageItem(parItem, fileName);
    }
}

void MainWindow::addImageItem(QTreeWidgetItem *parItem, QString fileName) {
    // 添加一个图片文件节点
    // 获得最后的文件名称
    QString NodeText = getFinalFolderName(fileName);
    QTreeWidgetItem *item;
    // 节点类型imageItem
    item = new QTreeWidgetItem(MainWindow::imageItem);

    item->setText(colItem,NodeText);
    item->setText(colItemType,"type = imageItem");
    item->setFlags(Qt::ItemIsSelectable | Qt::ItemIsUserCheckable | Qt::ItemIsEnabled | Qt::ItemIsAutoTristate);
    item->setCheckState(colItem,Qt::Checked);
    // 完整文件名称
    item->setData(colItem,Qt::UserRole,QVariant(fileName));
    // 在父节点下面添加子节点
    parItem->addChild(item);
}

void MainWindow::on_treeWidget_currentItemChanged(QTreeWidgetItem *current, QTreeWidgetItem *previous)
{
    Q_UNUSED(previous);

    if (current == NULL) {
        return;
    }

    int type = current->type();
    switch (type) {
        case topItem:
            ui->actionAddFolder->setEnabled(true);
            ui->actionAddFiles->setEnabled(true);
            ui->actionDeleteItem->setEnabled(false);
            break;
        case groupItem:
            ui->actionAddFolder->setEnabled(true);
            ui->actionAddFiles->setEnabled(true);
            ui->actionDeleteItem->setEnabled(true);
            break;
        case imageItem:
            ui->actionAddFolder->setEnabled(false);
            ui->actionAddFiles->setEnabled(true);
            ui->actionDeleteItem->setEnabled(true);
            displayImage(current);
            break;
    }
}

void MainWindow::displayImage(QTreeWidgetItem *item) {
    QString fileName = item->data(colItem, Qt::UserRole).toString();
    fileNameLabel->setText(fileName);
    currentPixmap.load(fileName);
    on_actionFitHeight_triggered();
}

void MainWindow::on_actionDeleteItem_triggered()
{
    QTreeWidgetItem *item = ui->treeWidget->currentItem();
    QTreeWidgetItem *parentItem = item->parent();
    parentItem->removeChild(item);
    delete item;
}


void MainWindow::on_actionFitHeight_triggered()
{
    // 适应高度展示图片
    int height = ui->scrollArea->height();
    int realHeight = currentPixmap.height();
    // 当前显示比例，必须转换为浮点数
    currentPixmapRatio = float(height) / realHeight;
    // 图片缩放到指定高度
    QPixmap pix = currentPixmap.scaledToHeight(height - 30);
    ui->label->setPixmap(pix);
}


void MainWindow::on_actionFitWidth_triggered()
{

}


void MainWindow::on_actionZoomRealSize_triggered()
{
    currentPixmapRatio = 1;
    ui->label->setPixmap(currentPixmap);
}


void MainWindow::on_actionZoomOut_triggered()
{
    // 缩小显示
    currentPixmapRatio = currentPixmapRatio * 0.8;
    int width = currentPixmapRatio * currentPixmap.width();
    int height =currentPixmapRatio * currentPixmap.height();
    QPixmap pix = currentPixmap.scaled(width,height);
    ui->label->setPixmap(pix);
}


void MainWindow::on_actionZoomIn_triggered()
{
    // 放大显示
    currentPixmapRatio = currentPixmapRatio * 1.2;
    int width = currentPixmapRatio * currentPixmap.width();
    int height =currentPixmapRatio * currentPixmap.height();
    QPixmap pix = currentPixmap.scaled(width,height);
    ui->label->setPixmap(pix);
}


void MainWindow::on_actionDockVisible_triggered(bool arg1)
{
    ui->dockWidget->setVisible(arg1);
}


void MainWindow::on_actionFloat_triggered(bool checked)
{
    ui->dockWidget->setFloating(checked);
}


void MainWindow::on_dockWidget_topLevelChanged(bool topLevel)
{
    ui->actionFloat->setChecked(topLevel);
}


void MainWindow::on_dockWidget_visibilityChanged(bool visible)
{
    ui->actionDockVisible->setChecked(visible);
}

