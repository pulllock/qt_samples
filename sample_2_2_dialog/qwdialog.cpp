#include "qwdialog.h"
#include "./ui_qwdialog.h"

QWDialog::QWDialog(QWidget *parent)
    : QDialog(parent)
    , ui(new Ui::QWDialog)
{
    ui->setupUi(this);

    // 将设置颜色的单选框的clicked()信号和设置颜色的槽函数进行关联
    connect(ui->radioButtonRed, SIGNAL(clicked()), this, SLOT(setTextFontColor()));
    connect(ui->radioButtonBlack, SIGNAL(clicked()), this, SLOT(setTextFontColor()));
    connect(ui->radioButtonBlue, SIGNAL(clicked()), this, SLOT(setTextFontColor()));
}

QWDialog::~QWDialog()
{
    delete ui;
}


void QWDialog::on_checkBoxUnderline_clicked(bool checked)
{
    QFont font = ui->plainTextEdit->font();
    font.setUnderline(checked);
    ui->plainTextEdit->setFont(font);
}


void QWDialog::on_checkBoxItalic_clicked(bool checked)
{
    QFont font = ui->plainTextEdit->font();
    font.setItalic(checked);
    ui->plainTextEdit->setFont(font);
}


void QWDialog::on_checkBoxBold_clicked(bool checked)
{
    QFont font = ui->plainTextEdit->font();
    font.setBold(checked);
    ui->plainTextEdit->setFont(font);
}

void QWDialog::setTextFontColor()
{
    QPalette palette = ui->plainTextEdit->palette();
    if (ui->radioButtonBlack->isChecked()) {
        palette.setColor(QPalette::Text, Qt::black);
    } else if (ui->radioButtonBlue->isChecked()) {
        palette.setColor(QPalette::Text, Qt::blue);
    } else if (ui->radioButtonRed->isChecked()) {
        palette.setColor(QPalette::Text, Qt::red);
    } else {
        palette.setColor(QPalette::Text, Qt::black);
    }

    ui->plainTextEdit->setPalette(palette);
}

