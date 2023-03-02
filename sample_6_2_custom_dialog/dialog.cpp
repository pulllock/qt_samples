#include "dialog.h"
#include "ui_dialog.h"

Dialog::Dialog(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::Dialog)
{
    ui->setupUi(this);
}

Dialog::~Dialog()
{
    delete ui;
}

QString Dialog::lineEditValue() {
    return ui->lineEditDialog->text();
}

void Dialog::setLineEditValue(QString value) {
    ui->lineEditDialog->setText(value);
}

void Dialog::on_pushButtonOk_clicked()
{

}


void Dialog::on_pushButtonCancel_clicked()
{

}

