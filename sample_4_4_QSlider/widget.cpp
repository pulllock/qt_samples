#include "widget.h"
#include "./ui_widget.h"

Widget::Widget(QWidget *parent)
    : QWidget(parent)
    , ui(new Ui::Widget)
{
    ui->setupUi(this);

    connect(ui->horizontalSliderGreen, SIGNAL(valueChanged(int)), this, SLOT(on_horizontalSliderRed_valueChanged(int)));
    connect(ui->horizontalSliderBlue, SIGNAL(valueChanged(int)), this, SLOT(on_horizontalSliderRed_valueChanged(int)));
    connect(ui->horizontalSliderAlpha, SIGNAL(valueChanged(int)), this, SLOT(on_horizontalSliderRed_valueChanged(int)));
}

void Widget::on_horizontalSliderRed_valueChanged(int value)
{
    // 拖动Red，Greed，Blue颜色滑动条时设置textEdit的底色
    Q_UNUSED(value);

    int R = ui->horizontalSliderRed->value();
    int G = ui->horizontalSliderGreen->value();
    int B = ui->horizontalSliderBlue->value();
    int alpha = ui->horizontalSliderAlpha->value();

    QColor color;
    color.setRgb(R, G, B, alpha);

    QPalette palette = ui->textEdit->palette();
    palette.setColor(QPalette::Base, color);
    ui->textEdit->setPalette(palette);
}

void Widget::on_dial_valueChanged(int value)
{
    // 设置LCD的值等于Dial的值
    ui->lcdNumber->display(value);
}

void Widget::on_radioButtonDec_clicked()
{
    // 设置LCD十进制显示
    // 设置位数
    ui->lcdNumber->setDigitCount(3);
    ui->lcdNumber->setDecMode();
}


void Widget::on_radioButtonBin_clicked()
{
    // 设置LCD二进制显示
    // 设置位数
    ui->lcdNumber->setDigitCount(8);
    ui->lcdNumber->setBinMode();
}


void Widget::on_radioButtonOct_clicked()
{
    // 设置LCD八进制显示
    // 设置位数
    ui->lcdNumber->setDigitCount(4);
    ui->lcdNumber->setOctMode();
}


void Widget::on_radioButtonHex_clicked()
{
    // 设置LCD十六进制显示
    // 设置位数
    ui->lcdNumber->setDigitCount(3);
    ui->lcdNumber->setHexMode();
}

Widget::~Widget()
{
    delete ui;
}


