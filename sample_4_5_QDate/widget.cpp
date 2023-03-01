#include "widget.h"
#include "./ui_widget.h"

#include <QTimer>

Widget::Widget(QWidget *parent)
    : QWidget(parent)
    , ui(new Ui::Widget)
{
    ui->setupUi(this);
    timer = new QTimer(this);
    timer->stop();
    // 设置周期，1000ms
    timer->setInterval(1000);

    timeCounter = new QElapsedTimer();

    connect(timer, SIGNAL(timeout()), this, SLOT(on_timer_timeout()));
}

void Widget::on_pushButtonReadCurrentDateTime_clicked()
{
    QDateTime currentDateTime = QDateTime::currentDateTime();

    ui->timeEdit->setTime(currentDateTime.time());
    ui->lineEditTime->setText(currentDateTime.toString("HH:mm:ss"));

    ui->dateEdit->setDate(currentDateTime.date());
    ui->lineEditDate->setText(currentDateTime.toString("yyyy-MM-dd"));

    ui->dateTimeEdit->setDateTime(currentDateTime);
    ui->lineEditDateTime->setText(currentDateTime.toString("yyyy-MM-dd HH:mm:ss"));
}

void Widget::on_pushButtonSetTime_clicked()
{
    QString time = ui->lineEditTime->text();
    time = time.trimmed();

    if (!time.isEmpty()) {
        QTime qTime = QTime::fromString(time, "HH:mm:ss");
        ui->timeEdit->setTime(qTime);
    }
}


void Widget::on_pushButtonSetDate_clicked()
{
    QString date = ui->lineEditDate->text();
    date = date.trimmed();

    if (!date.isEmpty()) {
        QDate qDate = QDate::fromString(date, "yyyy-MM-dd");
        ui->dateEdit->setDate(qDate);
    }
}


void Widget::on_pushButtonSetDateTime_clicked()
{
    QString dateTime = ui->lineEditDateTime->text();
    dateTime = dateTime.trimmed();

    if (!dateTime.isEmpty()) {
        QDateTime qDateTime = QDateTime::fromString(dateTime, "yyyy-MM-dd HH:mm:ss");
        ui->dateTimeEdit->setDateTime(qDateTime);
    }
}

void Widget::on_calendarWidget_selectionChanged()
{
    QDate qDate = ui->calendarWidget->selectedDate();
    QString date = qDate.toString("yyyy-MM-dd");
    ui->lineEditCalendar->setText(date);
}

void Widget::on_timer_timeout() {
    // 定时器中断响应
    QTime currentTime = QTime::currentTime();
    ui->lcdNumberHour->display(currentTime.hour());
    ui->lcdNumberMinute->display(currentTime.minute());
    ui->lcdNumberSecond->display(currentTime.second());

    int val = ui->progressBar->value();
    val++;
    if (val > 100) {
        val = 0;
    }

    ui->progressBar->setValue(val);
}

void Widget::on_pushButtonStart_clicked()
{
    timer->start();
    timeCounter->start();
    ui->pushButtonStart->setEnabled(false);
    ui->pushButtonStop->setEnabled(true);
    ui->pushButtonSetInterval->setEnabled(false);
}


void Widget::on_pushButtonStop_clicked()
{
    timer->stop();
    int elapsed = timeCounter->elapsed();
    int ms = elapsed % 1000;
    int second = elapsed / 1000;
    QString str = QString::asprintf("流逝时间：%d 秒，%d 毫秒", second, ms);
    ui->labelElapsTIme->setText(str);

    ui->pushButtonStart->setEnabled(true);
    ui->pushButtonStop->setEnabled(false);
    ui->pushButtonSetInterval->setEnabled(true);
}

Widget::~Widget()
{
    delete ui;
}

