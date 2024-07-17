#include "qmlmqttclient.h"
#include <QtQml/QQmlApplicationEngine>
#include <QApplication>



int main(int argc, char *argv[])
{
    QApplication a(argc, argv);

    qmlRegisterType<QmlMqttClient>("MqttClient",1,0,"MqttClient");
    qmlRegisterUncreatableType<QmlMqttSubscription>("MqttClient", 1, 0, "MqttSubscription", QLatin1String("Subscriptions are read-only"));

    QQmlApplicationEngine engine;

    const QUrl url(QStringLiteral("qrc:/main.qml"));
    QObject::connect(&engine, &QQmlApplicationEngine::objectCreated,
        &a, [url](QObject *obj, const QUrl &objUrl) {
            if (!obj && url == objUrl)
                QCoreApplication::exit(-1);
        }, Qt::QueuedConnection);
    engine.load(url);

    return a.exec();
}
