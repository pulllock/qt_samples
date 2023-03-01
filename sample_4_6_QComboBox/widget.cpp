#include <QMenu>
#include <QTextBlock>
#include "widget.h"
#include "./ui_widget.h"

Widget::Widget(QWidget *parent)
    : QWidget(parent)
    , ui(new Ui::Widget)
{
    ui->setupUi(this);
}

void Widget::on_pushButtonInitList_clicked()
{
    // 清空下拉框
    ui->comboBoxSimpleList->clear();

    // 初始化下拉框
    for (int i = 0; i < 20; i++) {
        ui->comboBoxSimpleList->addItem(QString::asprintf("Item %d", i));
    }
}


void Widget::on_pushButtonInitCity_clicked()
{
    // 清空下拉框
    ui->comboBoxCityList->clear();

    QMap<QString, int> cityZoneMap;
    cityZoneMap.insert("北京", 10);
    cityZoneMap.insert("上海", 21);
    cityZoneMap.insert("天津", 22);
    cityZoneMap.insert("大连", 411);
    cityZoneMap.insert("锦州", 416);

    foreach (const QString &str, cityZoneMap.keys()) {
        ui->comboBoxCityList->addItem(str, cityZoneMap.value(str));
    }
}

void Widget::on_pushButtonClearList_clicked()
{
    ui->comboBoxSimpleList->clear();
}


void Widget::on_pushButtonPutToComboBox_clicked()
{
    // 将plainTextEdit中的内容逐行添加为ComboBox的项
    QTextDocument *doc = ui->plainTextEdit->document();
    // 回车符是一个block
    int count = doc->blockCount();
    ui->comboBoxSimpleList->clear();
    for (int i = 0; i < count; ++i) {
        // 文本中的一段
        QTextBlock textLine = doc->findBlockByNumber(i);
        QString str = textLine.text();
        ui->comboBoxSimpleList->addItem(str);
    }
}


void Widget::on_pushButtonClearText_clicked()
{
    ui->plainTextEdit->clear();
}

void Widget::on_comboBoxSimpleList_currentIndexChanged(const QString &text)
{
    ui->plainTextEdit->appendPlainText(text);
}

void Widget::on_comboBoxCityList_currentIndexChanged(const QString &text)
{
    QString zone = ui->comboBoxCityList->currentData().toString();
    ui->plainTextEdit->appendPlainText("地区：" + text + "，区号：" + zone);
}

void Widget::on_plainTextEdit_customContextMenuRequested(const QPoint &pos)
{
    // 创建并显示标准弹出式菜单
    QMenu *menu = ui->plainTextEdit->createStandardContextMenu();
    menu->exec(pos);

}

Widget::~Widget()
{
    delete ui;
}

