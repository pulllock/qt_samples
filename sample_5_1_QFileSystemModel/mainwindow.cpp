#include "mainwindow.h"
#include "./ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    fileSystemModel = new QFileSystemModel(this);
    // 设置根目录
    fileSystemModel->setRootPath(QDir::currentPath());
    // 设置数据模型
    ui->treeView->setModel(fileSystemModel);
    ui->listView->setModel(fileSystemModel);
    ui->tableView->setModel(fileSystemModel);

    // treeView单击时，其目录设置为listView和tableView的根节点
    connect(ui->treeView, SIGNAL(clicked(QModelIndex)), ui->listView, SLOT(setRootIndex(QModelIndex)));
    connect(ui->treeView, SIGNAL(clicked(QModelIndex)), ui->tableView, SLOT(setRootIndex(QModelIndex)));
}

MainWindow::~MainWindow()
{
    delete ui;
}


void MainWindow::on_treeView_clicked(const QModelIndex &index)
{
    // 设置复选框：是否是目录
    ui->checkBox->setChecked(fileSystemModel->isDir(index));

    ui->labelPath->setText(fileSystemModel->filePath(index));
    ui->labelFileType->setText(fileSystemModel->type(index));
    ui->labelFileName->setText(fileSystemModel->fileName(index));

    int size = fileSystemModel->size(index) / 1024;
    if (size < 1024) {
        ui->labelFileSize->setText(QString("%1 KB").arg(size));
    } else {
        ui->labelFileSize->setText(QString::asprintf("%.1f MB", size / 1024.0));
    }
}

