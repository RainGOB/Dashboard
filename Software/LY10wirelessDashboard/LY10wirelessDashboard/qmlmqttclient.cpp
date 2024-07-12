#include "qmlmqttclient.h"
#include <QDebug>

QmlMqttSubscription::QmlMqttSubscription(QMqttSubscription *s, QmlMqttClient *c)
    : sub(s)
    , client(c)
{
    connect(sub, &QMqttSubscription::messageReceived, client,&QmlMqttClient::onDataRec);
    m_topic = sub->topic();
}

QmlMqttSubscription::~QmlMqttSubscription()
{
}

QmlMqttClient::QmlMqttClient(QObject *parent)
    : QMqttClient(parent)
{
    connect(&m_client, &QMqttClient::stateChanged, this, &QmlMqttClient::stateChanged);
}


void QmlMqttClient::parse(QByteArray package)
{
    QString message = QString(package);
    message = message.mid(0,message.size() );

    //取消大括号
    if(message.size()>=2 && message.front() == '{' && message.back() == '}'){
        message = message.mid(1,message.size() - 2);
    }
    //分割字符串用逗号为分隔符
    QStringList packageStr = message.split(',');
    qDebug()<<packageStr;
    if(packageStr[0] == "1")
    {
        setCarSpeed(packageStr[1].toInt());
        setThroPos(packageStr[2].toInt());
        setBatAlarm(packageStr[3].toInt());
        setLmotorSpeed(packageStr[4].toInt());
        setRmotorSpeed(packageStr[5].toInt());
        setBatAlarm(packageStr[6].toInt());
        setBatLevel(packageStr[7].toInt());
        setGearMode(packageStr[8].toInt());
        setCarMode(packageStr[9].toInt());
        setAcc_x(packageStr[10].toFloat());
        setAcc_y(packageStr[11].toFloat());
        setAcc_z(packageStr[12].toFloat());
    }
    else
    {
        setLmotortorq(packageStr[1].toInt());
        setRmotortorq(packageStr[2].toInt());
        setBatVol(packageStr[3].toInt());
        setCarDistance(packageStr[4].toInt());
        setMcu1Temp(packageStr[5].toInt());
        setMcu2Temp(packageStr[6].toInt());
        setBrakeTravel(packageStr[7].toInt());
        setLmotorTemp(packageStr[8].toInt());
        setRmotorTemp(packageStr[9].toInt());
        setLbatAlr(packageStr[10].toInt());
        setAngle(packageStr[11].toInt());
    }
}

QMqttClient::ClientState QmlMqttClient::state() const
{
    return m_client.state();
}

void QmlMqttClient::setState(const ClientState &newState)
{
    m_client.setState(newState);
}

void QmlMqttClient::connectToHost()
{
    m_client.setHostname("nas.lyracing.cn");
    m_client.setPort(1883);
    m_client.setUsername("lingyun");
    m_client.setPassword("lingyun666");
    m_client.connectToHost();
}

void QmlMqttClient::disconnectFromHost()
{
    m_client.disconnectFromHost();
}


QmlMqttSubscription* QmlMqttClient::subscribe(const QString &topic)
{
    auto sub = m_client.subscribe(topic, 0);
    auto result = new QmlMqttSubscription(sub, this);
    return result;
}


void QmlMqttClient::onDataRec(const QMqttMessage &qmsg)
{
    qDebug()<<"message is "<<qmsg.payload();
    parse(qmsg.payload());

//    emit messageReceived(qmsg.payload());
}

