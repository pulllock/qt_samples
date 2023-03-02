#include <QDir>
#include <QFileDialog>
#include <QColorDialog>
#include <QFontDialog>
#include <QLineEdit>
#include <QInputDialog>
#include <QMessageBox>
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
    QString title = "Question消息框";
    QString info = "文件已被修改，是否保存修改？";

    // 默认按钮
    QMessageBox::StandardButton defaultButton = QMessageBox::NoButton;

    // 选择的按钮
    QMessageBox::StandardButton result;

    result = QMessageBox::question(
            this,
            title,
            info,
            QMessageBox::Yes | QMessageBox::No | QMessageBox::Cancel,
            defaultButton
            );
    if (result == QMessageBox::Yes) {
        ui->plainTextEdit->appendPlainText("Question消息框：Yes被选择");
    } else if (result == QMessageBox::No) {
        ui->plainTextEdit->appendPlainText("Question消息框：No被选择");
    } else if (result == QMessageBox::Cancel) {
        ui->plainTextEdit->appendPlainText("Question消息框：Cancel被选择");
    } else {
        ui->plainTextEdit->appendPlainText("Question消息框：无选择");
    }
}


void Dialog::on_pushButtonInformation_clicked()
{
    QString title = "Information消息框";
    QString info = "已设置";
    QMessageBox::information(this, title, info, QMessageBox::Ok, QMessageBox::NoButton);
}


void Dialog::on_pushButtonWarning_clicked()
{
    QString title = "Warning消息框";
    QString info = "警告";
    QMessageBox::warning(this, title, info);
}


void Dialog::on_pushButtonCritical_clicked()
{
    QString title = "Critical消息框";
    QString info = "验证警告";
    QMessageBox::critical(this, title, info);
}


void Dialog::on_pushButtonAbout_clicked()
{
    QString title = "About消息框";
    QString info = "About......";
    QMessageBox::about(this, title, info);
}


void Dialog::on_pushButtonAboutQt_clicked()
{
    QString title = "AboutQt消息框";
    QMessageBox::aboutQt(this, title);
}


void Dialog::on_pushButtonString_clicked()
{
    QString title = "输入文字对话框";
    QString labelText = "请输入文件名";
    QString defaultText = "新建文件.txt";
    QLineEdit::EchoMode echoMode = QLineEdit::Normal;
    bool ok = false;
    QString text = QInputDialog::getText(this, title, labelText, echoMode, defaultText, &ok);
    if (ok && !text.isEmpty()) {
        ui->plainTextEdit->appendPlainText(text);
    }
}


void Dialog::on_pushButtonInt_clicked()
{
    QString title = "输入整数对话框";
    QString labelText = "设置字体大小";
    int defaultValue = ui->plainTextEdit->font().pointSize();
    int min = 6;
    int max = 50;
    int step = 1;
    bool ok = false;
    int value = QInputDialog::getInt(this, title, labelText,defaultValue, min, max, step, &ok);
    if (ok) {
        QFont font = ui->plainTextEdit->font();
        font.setPointSize(value);
        ui->plainTextEdit->setFont(font);
    }
}


void Dialog::on_pushButtonFloat_clicked()
{
    QString title = "输入浮点数对话框";
    QString labelText = "输入一个浮点数";
    float defaultValue = 3.13;
    float min = 0;
    float max = 10000;
    // 小数点位数
    int decimals = 2;
    bool ok = false;
    float value = QInputDialog::getDouble(this, title, labelText, defaultValue, min, max, decimals, &ok);
    if (ok) {
        QString str = QString::asprintf("输入了一个浮点数：%.2f", value);
        ui->plainTextEdit->appendPlainText(str);
    }
}


void Dialog::on_pushButtonItem_clicked()
{
    QStringList items;
    items << "优秀" << "良好" << "合格" << "不合格";
    QString title = "条目选择对话框";
    QString labelText = "选择级别";
    // 初始选择项
    int currentIndex = 0;
    // ComboBox是否可编辑
    bool editable = true;
    bool ok = false;
    QString text = QInputDialog::getItem(this, title, labelText, items, currentIndex, editable, &ok);
    if (ok && !text.isEmpty()) {
        ui->plainTextEdit->appendPlainText(text);
    }
}


void Dialog::on_pushButtonClear_clicked()
{
    ui->plainTextEdit->clear();
}

