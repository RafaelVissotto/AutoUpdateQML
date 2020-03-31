#include "qmlmonitor.h"

QmlMonitor::QmlMonitor(QObject *parent)
    : QObject(parent)
//    , fsw(QStringList(QML_DIR))
    , fsw(QStringList(QStringLiteral(QML_DIR) + "ModifyMe.qml"))
{
//    connect(&fsw, &QFileSystemWatcher::directoryChanged, this, &QmlMonitor::qmlChanged);
    connect(&fsw, &QFileSystemWatcher::fileChanged, this, &QmlMonitor::qmlChanged);
}
