#ifndef DARKKNIGHT_H
#define DARKKNIGHT_H

#include <QMainWindow>
#include <Logger.h>

namespace Ui {
class DarkKnight;
}

class DarkKnight : public QMainWindow, public Logger
{
    Q_OBJECT
    
public:
    explicit DarkKnight(QWidget *parent = 0);
    virtual ~DarkKnight();
    virtual void log(const QString &mess);
private:
    Ui::DarkKnight *ui;
};

#endif // DARKKNIGHT_H
