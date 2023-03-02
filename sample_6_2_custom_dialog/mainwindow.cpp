#include "mainwindow.h"
#include "./ui_mainwindow.h"
#include "dialog.h"

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


void MainWindow::on_pushButtonMain_clicked()
{
    // 动态创建模态对话框
    Dialog *dialog = new Dialog(this);
    Qt::WindowFlags flags = dialog->windowFlags();
    dialog->setWindowFlags(flags | Qt::MSWindowsFixedSizeDialogHint);
    dialog->setLineEditValue(ui->lineEditMain->text());

    int result = dialog->exec();
    if (result == QDialog::Accepted) {
        QString value = dialog->lineEditValue();
        ui->lineEditMain->setText(value);
    }

    delete dialog;
}

