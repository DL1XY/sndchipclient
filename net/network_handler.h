#ifndef NETWORK_HANDLER_H
#define NETWORK_HANDLER_H

#include <QUdpSocket>
#include <QWidget>
#include <QString>
#include <QUrl>
#include <QObject>
#include <QHostInfo>
#include <QHostAddress>

#include <QSignalSpy>
#include <QtTest>

#include "coap_handler.h"
#include "udp_handler.h"
using namespace std;
class NetworkHandler: public QWidget {

Q_OBJECT

public:
    explicit NetworkHandler(QWidget* parent = nullptr);

    virtual ~NetworkHandler() {
        delete udpHandler;
        delete coapHandler;
    }

private:
    QString ssid;
    QString password;
    QString ip;
    unsigned int port;

    // Wifi
    void connectWifi();
    void disconnectWifi();

    // UDP Client
    UdpHandler* udpHandler;

    //void initSocket();
    //void readPendingDatagrams();



    // CoAP Client
    CoapHandler *coapHandler;
    //CoapNetworkAccessManager *m_coap;
    //QByteArray m_uploadData;

    void initCoap();

    // MQTT

};

#endif // NETWORK_HANDLER_H
