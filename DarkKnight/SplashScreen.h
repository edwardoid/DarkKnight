#ifndef SPLASHSCREEN_H
#define SPLASHSCREEN_H

#include <QSplashScreen>

class Framework;

class SplashScreen : public QSplashScreen
{
    Q_OBJECT
public:
    explicit SplashScreen(Framework* fw, QWidget *parent = 0);
    void load();
private slots:
    void log(const QString& mess);
private:
    Framework* m_fw;
};

#endif // SPLASHSCREEN_H
