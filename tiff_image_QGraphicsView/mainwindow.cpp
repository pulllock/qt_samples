#include "mainwindow.h"
#include "./ui_mainwindow.h"
#include <QDir>
#include <QFileDialog>

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
    if (fileName.isEmpty()) {
        return;
    }

    // 输入框里显示图片的文件名
    ui->lineEdit->setText(fileName);

    QImage *image = new QImage(fileName);
    showImage(*image);
}

void MainWindow::showImage(QImage image) {
    // 创建显示容器
    QGraphicsScene *scene = new QGraphicsScene();

    // 向容器中添加文件
    QPixmap imageFile = QPixmap::fromImage(image);
    // scene->addPixmap(imageFile);

    // 实例化自定义的图片组件
    m_customImageWidget = new CustomImageWidget(&imageFile);

    // QGraphicsView的宽度
    int graphicsViewWidth = ui->graphicsView->width();
    // QGraphicsView的高度
    int graphicsViewHeight = ui->graphicsView->height();

    // 调用自定义图片组件的setQGraphicsViewWidthAndHeight方法设置图片在QGraphicsView中的实际展示宽高
    m_customImageWidget->setQGraphicsViewWidthAndHeight(graphicsViewWidth, graphicsViewHeight);

    // 将自定义的图片组件实例添加到QGraphicsScene容器中
    scene->addItem(m_customImageWidget);

    // 使用QGraphicsView显示容器的内容
    // 使QGraphicsView的大小固定在原始大小，不会随图片的放大而放大，防止图片放大后重新缩小的时候视窗太大而不方便观察图片
    // 默认状态下图片放大的时候视窗两边会自动出现滚动条，并且视窗内的视野会变大
    ui->graphicsView->setSceneRect(QRectF(-(graphicsViewWidth / 2), -(graphicsViewHeight / 2), graphicsViewWidth, graphicsViewHeight));
    ui->graphicsView->setScene(scene);
    // ui->graphicsView->show();

    // 界面的焦点设置到QGraphicsView上
    ui->graphicsView->setFocus();
}
