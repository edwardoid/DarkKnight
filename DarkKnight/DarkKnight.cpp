#include "DarkKnight.h"
#include "ui_DarkKnight.h"

#include <Utils.h>

DarkKnight::DarkKnight(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::DarkKnight)
{
    ui->setupUi(this);
    ASSERT(false);
}

DarkKnight::~DarkKnight()
{
    delete ui;
}
