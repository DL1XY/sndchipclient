#ifndef MQTT_HANDLER_H
#define MQTT_HANDLER_H

#include <QObject>

class MqttHandler: public QObject
{
    Q_OBJECT

public:
    explicit MqttHandler(QObject *parent = nullptr);

    virtual ~MqttHandler()
    {

    }

};

#endif // MQTT_HANDLER_H
