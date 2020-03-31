#pragma once

#include <QObject>
#include <QFileSystemWatcher>

class QmlMonitor : public QObject
{

public:
    explicit QmlMonitor(QObject *parent = nullptr);

private:
    QFileSystemWatcher fsw;

signals:
    void qmlChanged(const QString &);

};
