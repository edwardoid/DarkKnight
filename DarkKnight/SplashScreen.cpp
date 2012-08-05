#include "SplashScreen.h"
#include <QApplication>
#include <Framework.h>
#include <PluginLoader.h>
#include <Utils.h>
#include <Logger.h>
#include <QDebug>

SplashScreen::SplashScreen(Framework* fw, QWidget *parent)
    : QSplashScreen(parent)
    , m_fw(fw)
{
    ASSERT(fw);
    connect(this, SIGNAL(messageChanged(const QString&)),
            this, SLOT(log(const QString&)));
    QPixmap(":/splash.png");
    setPixmap(QPixmap(":/main/splash"));
}

void SplashScreen::load()
{
    ASSERT(m_fw);
    const int align = Qt::AlignRight | Qt::AlignBottom;
    log(tr("Starting in %1").arg(qApp->applicationDirPath()));
    showMessage(tr("Loading data stores..."), align);
    qApp->processEvents();
    m_fw->loadDataStores();

    showMessage(tr("Loading concepts..."), align);
    qApp->processEvents();
    m_fw->loadConcepts();

    showMessage(tr("Initializing data stores..."), align);
    qApp->processEvents();
    m_fw->initDataStores();

    showMessage(tr("Initializing concepts..."), align);
    qApp->processEvents();
    m_fw->loadConcepts();

    showMessage(tr("Loaded %1 concepts and %2 stores").arg(m_fw->concepts().size())
                                                      .arg(m_fw->dataStores().size()),
                align);
}

void SplashScreen::log(const QString &mess)
{
    m_fw->logger()->log(mess);
}
