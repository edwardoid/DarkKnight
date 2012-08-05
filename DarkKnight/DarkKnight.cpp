#include "DarkKnight.h"
#include "ui_DarkKnight.h"
#include <QTime>
#include <Utils.h>

DarkKnight::DarkKnight(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::DarkKnight)
{
    ui->setupUi(this);
}

void DarkKnight::log(const QString &mess)
{
    ui->logTextEdit->appendPlainText(QString("%1: %2").arg(QTime::currentTime().toString(), mess));
}

DarkKnight::~DarkKnight()
{
    delete ui;
}
