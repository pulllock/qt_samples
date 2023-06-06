#include "mainwindow.h"
#include "./ui_mainwindow.h"
#include "QDir"
#include "QFileDialog"

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
}

MainWindow::~MainWindow()
{
    delete ui;
}


void MainWindow::on_toolButton_clicked()
{
    // 获取系统当前目录
    QString currentPath = QDir::currentPath();
    // 对话框标题
    QString dialogTitle = "选择一个文件";
    // 文件过滤器
    QString filter = "图片文件(*.jpg *.gif *.png *.tif *.tiff);;所有文件(*.*)";
    QString fileName = QFileDialog::getOpenFileName(this, dialogTitle, currentPath, filter);
    if (!fileName.isEmpty()) {
        ui->lineEdit->setText(fileName);
        QImage *image = new QImage();
        image->load(fileName);
        ui->label->setPixmap(QPixmap::fromImage(*image).scaled(ui->label->size()));
    }
}

