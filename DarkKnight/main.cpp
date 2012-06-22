#include <QApplication>
#include "DarkKnight.h"
#include <Framework.h>

int main(int argc, char *argv[])
{
    Framework::instance();
    QApplication a(argc, argv);
    DarkKnight w;
    w.show();
    
    return a.exec();
}
