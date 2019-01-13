#ifndef NEWORKSERVICE_H
#define NEWORKSERVICE_H

#include <QUdpSocket>
#include <QWidget>
#include <string>
#include <QUrl>
#include <QObject>
#include <QHostInfo>
#include <QHostAddress>

#include <QSignalSpy>
#include <QtTest>

#include "coapnetworkaccessmanager.h"
#include "coappdu.h"
#include "coapreply.h"
#include "corelinkparser.h"
#include "coapobserveresource.h"
using namespace std;
class WifiCommon: public QWidget {

 Q_OBJECT

public:
    WifiCommon(QWidget* parent = nullptr);

private:
    string ssid;
    string password;
    string ip;
    unsigned int port;

    // Wifi
    void connectWifi();
    void disconnectWifi();

    // UDP Client
    QUdpSocket* udpSocket;
    void initSocket();
    void readPendingDatagrams();

    // CoAP Client
    CoapNetworkAccessManager *m_coap;
    QByteArray m_uploadData;

    void initCoap();

};

#endif // NEWORKSERVICE_H
