#include "mainwindow.h"
#include "./ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    // 调用自定义的ui初始化
    initUi();

    // 调用信号和槽函数初始化
    initSignalSlots();
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


void MainWindow::on_actionFontBold_triggered(bool checked)
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


void MainWindow::on_actionFontUnderline_triggered(bool checked)
{
    QTextCharFormat fmt;
    fmt = ui->textEdit->currentCharFormat();
    fmt.setFontUnderline(checked);
    ui->textEdit->mergeCurrentCharFormat(fmt);
}


void MainWindow::on_textEdit_copyAvailable(bool b)
{
    // 更新剪切、复制、粘贴的enabled属性
    ui->actionCut->setEnabled(b);
    ui->actionCopy->setEnabled(b);
    ui->actionPaste->setEnabled(ui->textEdit->canPaste());
}


void MainWindow::on_textEdit_selectionChanged()
{
    // 更新粗体、斜体、下划线的action的checked属性
    QTextCharFormat fmt;
    // 获取文字的格式
    fmt = ui->textEdit->currentCharFormat();
    ui->actionFontItalic->setChecked(fmt.fontItalic());
    ui->actionFontBold->setChecked(fmt.font().bold());
    ui->actionFontUnderline->setChecked(fmt.fontUnderline());
}

void MainWindow::initSignalSlots() {
    // 信号与槽的关联
    connect(spinBoxFontSize, SIGNAL(valueChanged(int)), this, SLOT(on_spinBoxFontSize_valueChanged(int)));
    connect(fontComboBox, SIGNAL(currentIndexChanged(const QString &)), this, SLOT(on_fontComboBox_currentIndexChanged(const QString &)));
}

void MainWindow::on_spinBoxFontSize_valueChanged(int fontSize) {
    // 改变字体大小
    QTextCharFormat fmt;
    fmt.setFontPointSize(fontSize);
    ui->textEdit->mergeCurrentCharFormat(fmt);
    progressBar->setValue(fontSize);
}

void MainWindow::on_fontComboBox_currentIndexChanged(const QString &arg1) {
    // 设置字体
    QTextCharFormat fmt;
    fmt.setFontFamily(arg1);
    ui->textEdit->mergeCurrentCharFormat(fmt);
}