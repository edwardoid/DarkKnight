#include "AssertDialog.h"
#include "ui_AssertDialog.h"

AssertDialog::AssertDialog(QString exp, int line, QString file) :
    QDialog(0),
    ui(new Ui::AssertDialog)
{
    ui->setupUi(this);
    ui->expLabel->setText(exp);
    ui->lineLabel->setText(QString::number(line));
    ui->fileLabel->setText(file);
}

AssertDialog::~AssertDialog()
{
    delete ui;
}

void AssertDialog::on_buttonBox_rejected()
{
    done(QDialog::Rejected);
}
