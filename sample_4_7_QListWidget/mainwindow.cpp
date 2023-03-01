#include "mainwindow.h"
#include "./ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    setCentralWidget(ui->splitter);

    // 为ToolButton设置关联的Action
    setActionsForToolButton();

    createSelectionPopMenu();
}

void MainWindow::setActionsForToolButton() {
    ui->toolButtonInitList->setDefaultAction(ui->actionInitList);
    ui->toolButtonClearList->setDefaultAction(ui->actionClearList);
    ui->toolButtonInsertItem->setDefaultAction(ui->actionInsertItem);
    ui->toolButtonAppendItem->setDefaultAction(ui->actionAppendItem);
    ui->toolButtonDeleteCurrentItem->setDefaultAction(ui->actionDeleteCurrentItem);

    ui->toolButtonSelectAll->setDefaultAction(ui->actionSelectAll);
    ui->toolButtonSelectNone->setDefaultAction(ui->actionSelectNone);
    ui->toolButtonSelectReverse->setDefaultAction(ui->actionSelectReverse);
}

void MainWindow::on_actionInitList_triggered()
{
    // 初始化列表
    QListWidgetItem *item;
    bool checked = ui->checkBox->isChecked();

    ui->listWidget->clear();

    for (int i = 0; i < 10; i++) {
        QString str = QString::asprintf("Item %d", i);

        item = new QListWidgetItem();
        item->setText(str);
        item->setCheckState(Qt::Checked);

        if (checked) {
            item->setFlags(Qt::ItemIsSelectable | Qt::ItemIsEditable | Qt::ItemIsUserCheckable | Qt::ItemIsEnabled);
        } else {
            item->setFlags(Qt::ItemIsSelectable | Qt::ItemIsUserCheckable | Qt::ItemIsEnabled);
        }

        ui->listWidget->addItem(item);
    }
}

void MainWindow::on_actionInsertItem_triggered()
{
    bool checked = ui->checkBox->isChecked();

    QListWidgetItem *item = new QListWidgetItem("New Inserted Item");
    item->setCheckState(Qt::Checked);

    if (checked) {
        item->setFlags(Qt::ItemIsSelectable | Qt::ItemIsEditable | Qt::ItemIsUserCheckable | Qt::ItemIsEnabled);
    } else {
        item->setFlags(Qt::ItemIsSelectable | Qt::ItemIsUserCheckable | Qt::ItemIsEnabled);
    }

    ui->listWidget->insertItem(ui->listWidget->currentRow(), item);
}

void MainWindow::on_actionDeleteCurrentItem_triggered()
{
    int currentIndex = ui->listWidget->currentRow();
    QListWidgetItem *item = ui->listWidget->takeItem(currentIndex);
    delete item;
}

void MainWindow::on_actionClearList_triggered()
{
    ui->listWidget->clear();
}

void MainWindow::on_actionSelectAll_triggered()
{
    int count = ui->listWidget->count();
    for (int i = 0; i < count; i++) {
        QListWidgetItem *item = ui->listWidget->item(i);
        item->setCheckState(Qt::Checked);
    }
}


void MainWindow::on_actionSelectNone_triggered()
{
    int count = ui->listWidget->count();
    for (int i = 0; i < count; i++) {
        QListWidgetItem *item = ui->listWidget->item(i);
        item->setCheckState(Qt::Unchecked);
    }
}


void MainWindow::on_actionSelectReverse_triggered()
{
    int count = ui->listWidget->count();
    for (int i = 0; i < count; i++) {
        QListWidgetItem *item = ui->listWidget->item(i);
        if (item->checkState() != Qt::Checked) {
            item->setCheckState(Qt::Checked);
        } else {
            item->setCheckState(Qt::Unchecked);
        }
    }
}

void MainWindow::on_checkBox_clicked(bool checked)
{
    int count = ui->listWidget->count();
    for (int i = 0; i < count; i++) {
        QListWidgetItem *item = ui->listWidget->item(i);
        if (checked) {
            item->setFlags(Qt::ItemIsSelectable | Qt::ItemIsEditable | Qt::ItemIsUserCheckable | Qt::ItemIsEnabled);
        } else {
            item->setFlags(Qt::ItemIsSelectable | Qt::ItemIsUserCheckable | Qt::ItemIsEnabled);
        }
    }
}


void MainWindow::on_listWidget_currentItemChanged(QListWidgetItem *current, QListWidgetItem *previous)
{
    QString str;
    if (current != NULL) {
        if (previous == NULL) {
            str = "当前项：" + current->text();
        } else {
            str = "当前项：" + current->text() + "；前一项：" + previous->text();
        }
        ui->lineEdit->setText(str);
    }
}

void MainWindow::createSelectionPopMenu() {
    // 创建下拉菜单
    // 创建弹出式菜单
    QMenu *menu = new QMenu(this);
    menu->addAction(ui->actionSelectAll);
    menu->addAction(ui->actionSelectNone);
    menu->addAction(ui->actionSelectReverse);

    // 项选择按钮
    ui->toolButtonSelectItem->setPopupMode(QToolButton::MenuButtonPopup);
    ui->toolButtonSelectItem->setToolButtonStyle(Qt::ToolButtonTextBesideIcon);
    ui->toolButtonSelectItem->setDefaultAction(ui->actionSelectPopMenu);
    // 设置下拉菜单
    ui->toolButtonSelectItem->setMenu(menu);

    // 工具栏上的下拉菜单
    QToolButton *toolButton = new QToolButton(this);
    toolButton->setPopupMode(QToolButton::InstantPopup);
    toolButton->setToolButtonStyle(Qt::ToolButtonTextUnderIcon);
    toolButton->setDefaultAction(ui->actionSelectPopMenu);
    toolButton->setMenu(menu);

    ui->toolBarMenu->addWidget(toolButton);
    ui->toolBarMenu->addSeparator();
    ui->toolBarMenu->addAction(ui->actionExit);
}


void MainWindow::on_listWidget_customContextMenuRequested(const QPoint &pos)
{
    Q_UNUSED(pos);

    QMenu *menu = new QMenu(this);
    menu->addAction(ui->actionInitList);
    menu->addAction(ui->actionClearList);
    menu->addAction(ui->actionInsertItem);
    menu->addAction(ui->actionAppendItem);
    menu->addAction(ui->actionDeleteCurrentItem);
    menu->addSeparator();
    menu->addAction(ui->actionSelectAll);
    menu->addAction(ui->actionSelectNone);
    menu->addAction(ui->actionSelectReverse);

    menu->exec(QCursor::pos());
    delete menu;
}



MainWindow::~MainWindow()
{
    delete ui;
}
