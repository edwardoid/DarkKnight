#ifndef DARKKNIGHT_H
#define DARKKNIGHT_H

#include <QMainWindow>

namespace Ui {
class DarkKnight;
}

class DarkKnight : public QMainWindow
{
    Q_OBJECT
    
public:
    explicit DarkKnight(QWidget *parent = 0);
    ~DarkKnight();
    
private:
    Ui::DarkKnight *ui;
};

#endif // DARKKNIGHT_H
