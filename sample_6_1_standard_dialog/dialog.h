#ifndef DIALOG_H
#define DIALOG_H

#include <QDialog>

QT_BEGIN_NAMESPACE
namespace Ui { class Dialog; }
QT_END_NAMESPACE

class Dialog : public QDialog
{
    Q_OBJECT

public:
    Dialog(QWidget *parent = nullptr);
    ~Dialog();

private slots:
    void on_pushButtonOpenFile_clicked();

    void on_pushButtonOpenFiles_clicked();

    void on_pushButtonSelectDir_clicked();

    void on_pushButtonSaveFile_clicked();

    void on_pushButtonSelectColor_clicked();

    void on_pushButtonSelectFont_clicked();

    void on_pushButtonQuestion_clicked();

    void on_pushButtonInformation_clicked();

    void on_pushButtonWarning_clicked();

    void on_pushButtonCritical_clicked();

    void on_pushButtonAbout_clicked();

    void on_pushButtonAboutQt_clicked();

    void on_pushButtonString_clicked();

    void on_pushButtonInt_clicked();

    void on_pushButtonFloat_clicked();

    void on_pushButtonItem_clicked();

    void on_pushButtonClear_clicked();

private:
    Ui::Dialog *ui;
};
#endif // DIALOG_H
