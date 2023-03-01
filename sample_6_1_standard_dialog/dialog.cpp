#include <QDir>
#include <QFileDialog>
#include <QColorDialog>
#include <QFontDialog>
#include "dialog.h"
#include "./ui_dialog.h"

Dialog::Dialog(QWidget *parent)
    : QDialog(parent)
    , ui(new Ui::Dialog)
{
    ui->setupUi(this);
}

Dialog::~Dialog()
{
    delete ui;
}


void Dialog::on_pushButtonOpenFile_clicked()
{
    QString currentPath = QDir::currentPath();
    QString title = "选择一个文件";
    QString filter = "文本文件(*.txt);;图片文件(*.jpg *.gif);;所有文件(*.*)";
    QString fileName = QFileDialog::getOpenFileName(this, title, currentPath, filter);
    if (!fileName.isEmpty()) {
        ui->plainTextEdit->appendPlainText(fileName);
    }
}


void Dialog::on_pushButtonOpenFiles_clicked()
{
    QString currentPath = QDir::currentPath();
    QString title = "选择多个文件";
    QString filter = "文本文件(*.txt);;图片文件(*.jpg *.gif);;所有文件(*.*)";
    QStringList fileNames = QFileDialog::getOpenFileNames(this, title, currentPath, filter);
    for (int i = 0; i < fileNames.count(); i++) {
        ui->plainTextEdit->appendPlainText(fileNames.at(i));
    }
}


void Dialog::on_pushButtonSelectDir_clicked()
{
    QString currentPath = QCoreApplication::applicationDirPath();
    QString title = "选择一个目录";
    QString selectedDir = QFileDialog::getExistingDirectory(this, title, currentPath, QFileDialog::ShowDirsOnly);
    if (!selectedDir.isEmpty()) {
        ui->plainTextEdit->appendPlainText(selectedDir);
    }
}


void Dialog::on_pushButtonSaveFile_clicked()
{
    QString currentPath = QCoreApplication::applicationDirPath();
    QString title = "保存文件";
    QString filter = "h文件(*.h);;C++文件(.cpp);;所有文件(*.*)";
    QString fileName = QFileDialog::getSaveFileName(this, title, currentPath, filter);
    if (!fileName.isEmpty()) {
        ui->plainTextEdit->appendPlainText(fileName);
    }
}


void Dialog::on_pushButtonSelectColor_clicked()
{
    QPalette palette = ui->plainTextEdit->palette();
    QColor currentColor = palette.color(QPalette::Text);
    QColor color = QColorDialog::getColor(currentColor, this, "选择颜色");
    if (color.isValid()) {
        palette.setColor(QPalette::Text, color);
        ui->plainTextEdit->setPalette(palette);
    }
}


void Dialog::on_pushButtonSelectFont_clicked()
{
    QFont currentFont = ui->plainTextEdit->font();
    bool ok = false;
    QFont font = QFontDialog::getFont(&ok, currentFont);
    if (ok) {
        ui->plainTextEdit->setFont(font);
    }
}


void Dialog::on_pushButtonQuestion_clicked()
{

}


void Dialog::on_pushButtonInformation_clicked()
{

}


void Dialog::on_pushButtonWarning_clicked()
{

}


void Dialog::on_pushButtonCritical_clicked()
{

}


void Dialog::on_pushButtonAbout_clicked()
{

}


void Dialog::on_pushButtonAboutQt_clicked()
{

}


void Dialog::on_pushButtonString_clicked()
{

}


void Dialog::on_pushButtonInt_clicked()
{

}


void Dialog::on_pushButtonFloat_clicked()
{

}


void Dialog::on_pushButtonItem_clicked()
{

}


void Dialog::on_pushButton_17_clicked()
{

}

