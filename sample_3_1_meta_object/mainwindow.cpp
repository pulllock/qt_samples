#include <QMetaProperty>
#include "mainwindow.h"
#include "./ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    boy = new QPerson("李四");
    boy->setProperty("score", 95);
    boy->setProperty("age", 10);
    boy->setProperty("sex", "Boy");

    connect(boy, &QPerson::ageChanged, this, &MainWindow::on_ageChanged);

    girl = new QPerson("小红");
    girl->setProperty("score", 99);
    girl->setProperty("age", 11);
    girl->setProperty("sex", "Girl");

    connect(girl, &QPerson::ageChanged, this, &MainWindow::on_ageChanged);

    ui->spinBoxBoy->setProperty("isBoy", true);
    ui->spinBoxGirl->setProperty("isBoy", false);

    connect(ui->spinBoxGirl, SIGNAL(valueChanged(int)), this, SLOT(on_spin_valueChanged(int)));
    connect(ui->spinBoxBoy, SIGNAL(valueChanged(int)), this, SLOT(on_spin_valueChanged(int)));
}

void MainWindow::on_ageChanged(int value)
{
    // 宏Q_UNUSED(name)，用在函数定义中不在函数体里使用的参数，如果不使用该宏定义，编译器会出现参数未使用的警告
    Q_UNUSED(value);
    // 使用qobject_cast()进行动态投射
    QPerson *aPerson = qobject_cast<QPerson *>(sender());
    QString name = aPerson->property("name").toString();
    QString sex = aPerson->property("sex").toString();
    int age = aPerson->age();

    ui->plainTextEdit->appendPlainText(name + ", " + sex + ", " + QString::asprintf("年龄=%d", age));
}

void MainWindow::on_spin_valueChanged(int arg1)
{
    Q_UNUSED(arg1);
    QSpinBox *spinBox = qobject_cast<QSpinBox *>(sender());
    if (spinBox->property("isBoy").toBool()) {
        boy->setAge(spinBox->value());
    } else {
        girl->setAge(spinBox->value());
    }
}

void MainWindow::on_pushButtonClear_clicked()
{

}

void MainWindow::on_pushButtonBoyInc_clicked()
{

}

void MainWindow::on_pushButtonGirlInc_clicked()
{

}

void MainWindow::on_pushButtonClassInfo_clicked()
{
    const QMetaObject *meta = boy->metaObject();
    ui->plainTextEdit->clear();
    ui->plainTextEdit->appendPlainText("元对象信息：\n");
    ui->plainTextEdit->appendPlainText(QString("类名称：%1\n").arg(meta->className()));
    ui->plainTextEdit->appendPlainText("property: ");
    for (int i = meta->propertyOffset(); i < meta->propertyCount(); i++) {
        QMetaProperty prop = meta->property(i);
        const char* propName = prop.name();
        QString propValue = boy->property(propName).toString();
        ui->plainTextEdit->appendPlainText(QString("属性名称：%1， 属性值：%2").arg(propName).arg(propValue));
    }

    ui->plainTextEdit->appendPlainText(" ");
    ui->plainTextEdit->appendPlainText("classInfo: ");

    for (int i = meta->classInfoOffset(); i < meta->classInfoCount(); i++) {
        QMetaClassInfo classInfo = meta->classInfo(i);
        ui->plainTextEdit->appendPlainText(QString("Name：%1; Value: %2").arg(classInfo.name()).arg(classInfo.value()));
    }
}

MainWindow::~MainWindow()
{
    delete ui;
}

