#ifndef PLUGINLOADER_H
#define PLUGINLOADER_H

#include <QMap>
#include <QString>
#include <QDir>
#include <QPluginLoader>
#include <QObject>
#include <QDebug>
#include "Framework.h"
#include <Logger.h>

template<typename T>
class PluginLoader
{
public:
    static QMap<QString, T> load(QString dir);
};

template<typename T>
QMap<QString, T> PluginLoader<T>::load(QString dir)
{
    QMap<QString, T> loadedPlugins;
    QDir pluginsDir = QDir(dir);

    foreach (QString fileName, pluginsDir.entryList(QDir::Files)) {

         QPluginLoader loader(pluginsDir.absoluteFilePath(fileName));
         QObject *plugin = loader.instance();
         if (plugin)
         {
             T pluginInstance = dynamic_cast<T>(plugin);
             if(pluginInstance)
             {
                 loadedPlugins.insert(pluginInstance->name(),
                                      pluginInstance);
                 qDebug() << "Loaded : " << pluginInstance->name();
                 Framework::instance()->logger()->log(QObject::tr("Loaded: %1").arg(pluginInstance->name()));
             }
         }
         else Framework::instance()->logger()->log(QObject::tr("Error: %1").arg(loader.errorString()));
     }
    return loadedPlugins;
}

#endif // PLUGINLOADER_H
