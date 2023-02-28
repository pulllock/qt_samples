#include "widget.h"
#include "./ui_widget.h"

Widget::Widget(QWidget *parent)
    : QWidget(parent)
    , ui(new Ui::Widget)
{
    ui->setupUi(this);
}

void Widget::on_pushButtonCalculate_clicked()
{
    // 数量
    QString str = ui->lineEditNumber->text();
    int number = str.toInt();

    // 单价
    str = ui->lineEditPrice->text();
    float price = str.toFloat();

    // 总价
    float totalPrice = number * price;

    str = QString::asprintf("%.2f", totalPrice);
    ui->lineEditTotalPrice->setText(str);
}

void Widget::on_pushButtonDec_clicked()
{
    // 读取十进制，转换为其他进制
    QString str = ui->lineEditDec->text();
    // 默认十进制
    int val = str.toInt();

    // 转为十六进制
    str = str.setNum(val, 16);
    str = str.toUpper();
    ui->lineEditHex->setText(str);

    // 转为二进制
    str = str.setNum(val, 2);
    ui->lineEditBin->setText(str);
}


void Widget::on_pushButtonBin_clicked()
{
    // 读取二进制，转换为其他进制
    QString str = ui->lineEditBin->text();
    bool ok;
    // 以二进制数读入
    int val = str.toInt(&ok, 2);

    // 转为十进制
    str = QString::number(val, 10);
    ui->lineEditDec->setText(str);

    // 转为十六进制
    str = str.setNum(val, 16);
    str = str.toUpper();
    ui->lineEditHex->setText(str);
}


void Widget::on_pushButtonHex_clicked()
{
    // 读取十六进制，转换为其他进制
    QString str = ui->lineEditHex->text();
    bool ok;
    // 以十六进制数读入
    int val = str.toInt(&ok, 16);

    // 转为十进制
    str = QString::number(val, 10);
    ui->lineEditDec->setText(str);

    // 转为二进制
    str = QString::number(val, 2);
    ui->lineEditBin->setText(str);
}

Widget::~Widget()
{
    delete ui;
}

