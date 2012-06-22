#ifndef ASSERTDIALOG_H
#define ASSERTDIALOG_H

#include <QDialog>

namespace Ui {
class AssertDialog;
}

class AssertDialog : public QDialog
{
    Q_OBJECT
    
public:
    explicit AssertDialog(QString exp, int line, QString file);
    ~AssertDialog();
    
private slots:
    void on_buttonBox_rejected();

private:
    Ui::AssertDialog *ui;
};

#endif // ASSERTDIALOG_H
