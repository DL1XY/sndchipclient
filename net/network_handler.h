#ifndef NETWORK_HANDLER_H
#define NETWORK_HANDLER_H

#include <QUdpSocket>
#include <QWidget>
#include <QString>
#include <QUrl>
#include <QObject>
#include <QHostInfo>
#include <QHostAddress>
#include "udp_handler.h"

struct NetworkCmd
{
    char target;
    char cmdId;
    char dataLength;
    char *data;
    char cmdCounter;
};

class NetworkHandler: public QObject {

Q_OBJECT

public:
    explicit NetworkHandler(QObject* parent = nullptr);

    virtual ~NetworkHandler() {
        delete udpHandler;
        //delete coapHandler;
    }
    void initUdp(QString ip, quint16 port);

    void writeCmd(NetworkCmd &cmd);
    quint8 getNextCmdCounter();

private:
    QString ssid;
    QString password;

    quint8 cmdCounter = 0;

    // Wifi
   // void connectWifi();
   // void disconnectWifi();

    // UDP Client
    UdpHandler* udpHandler = nullptr;


    void readCmd();


    //void initSocket();
    //void readPendingDatagrams();



    // CoAP Client
    // CoapHandler *coapHandler;
    //CoapNetworkAccessManager *m_coap;
    //QByteArray m_uploadData;

    //void initCoap();

    // MQTT

};

#endif // NETWORK_HANDLER_H
