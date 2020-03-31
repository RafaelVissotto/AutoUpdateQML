#include <QGuiApplication>
#include <QQmlApplicationEngine>
#include <QFileSystemWatcher>

int main(int argc, char *argv[])
{
    QCoreApplication::setAttribute(Qt::AA_EnableHighDpiScaling);

    QGuiApplication app(argc, argv);

    QQmlApplicationEngine *engine = new QQmlApplicationEngine();
    const QUrl url(QStringLiteral(QML_DIR) + QStringLiteral("ModifyMe.qml"));
    QObject::connect(engine, &QQmlApplicationEngine::objectCreated,
                     &app, [url](QObject *obj, const QUrl &objUrl) {
        if (!obj && url == objUrl)
            QCoreApplication::exit(-1);
    }, Qt::QueuedConnection);


    /* Will monitor qml folder,
     * so any changes done in a file into that folder, will trigger the lambda function,
     * which will delete engine and recreate it to reload the qml app
     */
    QFileSystemWatcher fsw(QStringList(QML_DIR));
    QObject::connect(&fsw, &QFileSystemWatcher::directoryChanged,
                     [&] {
                        engine->deleteLater();
                        engine = new QQmlApplicationEngine();
                        engine->load(url);
                     }
    );


    engine->load(url);

    return app.exec();
}
