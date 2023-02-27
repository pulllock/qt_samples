#include "dialog.h"
#include <QFont>
#include <QHBoxLayout>

Dialog::Dialog(QWidget *parent)
    : QDialog(parent)
{
    // 界面创建与布局
    initUi();

    // 信号与槽的关联
    initSignalSlots();

    setWindowTitle("Dialog Manual");
}

void Dialog::initUi()
{
    // 创建3个复选框，并且水平布局
    checkBoxUnderline = new QCheckBox(tr("Underline"));
    checkBoxItalic = new QCheckBox(tr("Italic"));
    checkBoxBold = new QCheckBox(tr("Bold"));

    QHBoxLayout *hBoxLayoutCheckbox = new QHBoxLayout;
    hBoxLayoutCheckbox->addWidget(checkBoxUnderline);
    hBoxLayoutCheckbox->addWidget(checkBoxItalic);
    hBoxLayoutCheckbox->addWidget(checkBoxBold);

    // 创建三个单选框，并且水平布局
    radioButtonBlack = new QRadioButton(tr("Black"));
    radioButtonBlue = new QRadioButton(tr("Blue"));
    radioButtonRed = new QRadioButton(tr("Red"));

    QHBoxLayout *hBoxLayoutRadioButton = new QHBoxLayout;
    hBoxLayoutRadioButton->addWidget(radioButtonBlack);
    hBoxLayoutRadioButton->addWidget(radioButtonBlue);
    hBoxLayoutRadioButton->addWidget(radioButtonRed);

    // 窗机三个按钮，并且水平布局
    pushButtonOk = new QPushButton(tr("确定"));
    pushButtonCancel = new QPushButton(tr("取消"));
    pushButtonClose = new QPushButton(tr("关闭"));

    QHBoxLayout *hBoxLayoutPushButton = new QHBoxLayout;
    hBoxLayoutPushButton->addStretch();
    hBoxLayoutPushButton->addWidget(pushButtonOk);
    hBoxLayoutPushButton->addWidget(pushButtonCancel);
    hBoxLayoutPushButton->addStretch();
    hBoxLayoutPushButton->addWidget(pushButtonClose);

    // 创建文本编辑器，并设置初始字体
    plainTextEdit = new QPlainTextEdit;
    plainTextEdit->setPlainText("Hello, World!\n\nIt's my demo");
    QFont font = plainTextEdit->font();
    font.setPointSize(20);
    plainTextEdit->setFont(font);

    // 创建垂直布局，并设置为主布局
    QVBoxLayout *vBoxLayoutMain = new QVBoxLayout;
    vBoxLayoutMain->addLayout(hBoxLayoutCheckbox);
    vBoxLayoutMain->addLayout(hBoxLayoutRadioButton);
    vBoxLayoutMain->addWidget(plainTextEdit);
    vBoxLayoutMain->addLayout(hBoxLayoutPushButton);

    // 设置为窗体的主布局
    setLayout(vBoxLayoutMain);
}

void Dialog::initSignalSlots()
{
    // 设置复选框点击的信号和槽的关联
    connect(checkBoxUnderline, SIGNAL(clicked(bool)), this, SLOT(on_checkBoxUnderline_clicked(bool)));
    connect(checkBoxItalic, SIGNAL(clicked(bool)), this, SLOT(on_checkBoxItalic_clicked(bool)));
    connect(checkBoxBold, SIGNAL(clicked(bool)), this, SLOT(on_checkBoxBold_clicked(bool)));

    // 设置单选框点击的信号和槽的关联
    connect(radioButtonBlack, SIGNAL(clicked()), this, SLOT(setTextFontColor()));
    connect(radioButtonBlue, SIGNAL(clicked()), this, SLOT(setTextFontColor()));
    connect(radioButtonRed, SIGNAL(clicked()), this, SLOT(setTextFontColor()));

    // 设置按钮点击的信号和槽的关联
    connect(pushButtonOk, SIGNAL(clicked()), this, SLOT(accept()));
    connect(pushButtonCancel, SIGNAL(clicked()), this, SLOT(reject()));
    connect(pushButtonClose, SIGNAL(clicked()), this, SLOT(close()));
}

void Dialog::on_checkBoxUnderline_clicked(bool checked)
{
    QFont font = plainTextEdit->font();
    font.setUnderline(checked);
    plainTextEdit->setFont(font);
}

void Dialog::on_checkBoxItalic_clicked(bool checked)
{
    QFont font = plainTextEdit->font();
    font.setItalic(checked);
    plainTextEdit->setFont(font);
}

void Dialog::on_checkBoxBold_clicked(bool checked)
{
    QFont font = plainTextEdit->font();
    font.setBold(checked);
    plainTextEdit->setFont(font);
}

void Dialog::setTextFontColor() {
    QPalette palette = plainTextEdit->palette();
    if (radioButtonBlack->isChecked()) {
        palette.setColor(QPalette::Text, Qt::black);
    } else if (radioButtonBlue->isChecked()) {
        palette.setColor(QPalette::Text, Qt::blue);
    } else if (radioButtonRed->isChecked()) {
        palette.setColor(QPalette::Text, Qt::red);
    } else {
        palette.setColor(QPalette::Text, Qt::black);
    }

    plainTextEdit->setPalette(palette);
}

Dialog::~Dialog()
{
}

