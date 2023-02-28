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
    int number = ui->spinBoxNumber->value();
    float price = ui->doubleSpinBoxPrice->value();
    float total = number * price;
    ui->doubleSpinBoxTotalPrice->setValue(total);
}

void Widget::on_pushButtonDec_clicked()
{
    int val = ui->spinBoxDec->value();
    ui->spinBoxBin->setValue(val);
    ui->spinBoxHex->setValue(val);
}


void Widget::on_pushButtonBin_clicked()
{
    int val = ui->spinBoxBin->value();
    ui->spinBoxDec->setValue(val);
    ui->spinBoxHex->setValue(val);
}


void Widget::on_pushButtonHex_clicked()
{
    int val = ui->spinBoxHex->value();
    ui->spinBoxDec->setValue(val);
    ui->spinBoxBin->setValue(val);
}

Widget::~Widget()
{
    delete ui;
}
