#include "AuthorsDialog.h"
#include "ui_AuthorsDialog.h"

AuthorsDialog::AuthorsDialog(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::AuthorsDialog)
{
    ui->setupUi(this);
}

AuthorsDialog::~AuthorsDialog()
{
    delete ui;
}
