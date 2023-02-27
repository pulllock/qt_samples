#include "mainwindow.h"
#include "./ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    // 调用自定义的ui初始化
    initUi();
}

void MainWindow::initUi() {
    // 状态栏上添加组件
    labelCurrentFile = new QLabel;
    labelCurrentFile->setMinimumWidth(150);
    labelCurrentFile->setText("当前文件：");
    // 添加到状态栏
    ui->statusbar->addWidget(labelCurrentFile);

    progressBar = new QProgressBar;
    progressBar->setMaximumWidth(200);
    progressBar->setMinimum(5);
    progressBar->setMaximum(50);
    progressBar->setValue(ui->textEdit->font().pointSize());
    ui->statusbar->addWidget(progressBar);

    // 工具栏上添加组件
    spinBoxFontSize = new QSpinBox;
    spinBoxFontSize->setMinimum(5);
    spinBoxFontSize->setMaximum(50);
    spinBoxFontSize->setValue(ui->textEdit->font().pointSize());
    spinBoxFontSize->setMinimumWidth(50);

    ui->toolBar->addWidget(new QLabel("字体大小"));
    ui->toolBar->addWidget(spinBoxFontSize);

    // 分隔条
    ui->toolBar->addSeparator();

    ui->toolBar->addWidget(new QLabel("字体"));
    fontComboBox = new QFontComboBox;
    fontComboBox->setMinimumWidth(150);
    ui->toolBar->addWidget(fontComboBox);

    setCentralWidget(ui->textEdit);
}

MainWindow::~MainWindow()
{
    delete ui;
}


void MainWindow::on_actioFontBold_triggered(bool checked)
{
    QTextCharFormat fmt;
    fmt = ui->textEdit->currentCharFormat();
    if (checked) {
        fmt.setFontWeight(QFont::Bold);
    } else {
        fmt.setFontWeight(QFont::Normal);
    }

    ui->textEdit->mergeCurrentCharFormat(fmt);
}


void MainWindow::on_actionFontItalic_triggered(bool checked)
{
    QTextCharFormat fmt;
    fmt = ui->textEdit->currentCharFormat();
    fmt.setFontItalic(checked);
    ui->textEdit->mergeCurrentCharFormat(fmt);
}


void MainWindow::on_actionuFontUnderline_triggered(bool checked)
{
    QTextCharFormat fmt;
    fmt = ui->textEdit->currentCharFormat();
    fmt.setFontUnderline(checked);
    ui->textEdit->mergeCurrentCharFormat(fmt);
}

