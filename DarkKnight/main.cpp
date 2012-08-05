#include <QApplication>
#include "DarkKnight.h"
#include "SplashScreen.h"
#include <Framework.h>

int main(int argc, char *argv[])
{
	QApplication a(argc, argv);
	DarkKnight w;
    Framework::instance()->setLogger(&w);
    SplashScreen ss(Framework::instance(), &w);
    ss.show();
    ss.load();
    w.show();
    ss.finish(&w);
	return a.exec();
}
