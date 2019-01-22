#ifndef UDP_HANDLER_H
#define UDP_HANDLER_H

#include <QUdpSocket>
#include <QWidget>
#define MAX_PAYLOAD 512;

// General UDP Commands 0x00 - 0x0F
#define UDP_CMD_INIT        0x00;
#define UDP_CMD_RESET       0x01;
#define UDP_CMD_GET_STATUS  0x02;



struct UdpCommand
{
    char cmdId;
    char *data;
};




class UdpHandler: public QWidget {

Q_OBJECT

public:
    explicit UdpHandler(QWidget* parent = nullptr);

    virtual ~UdpHandler() {
        delete udpSocket;

    }

private:

    QString ip;
    unsigned int port;

    // UDP Client
    QUdpSocket* udpSocket;
   // void initSocket();
   // void readPendingDatagrams();

    // MQTT

};

#endif // UDP_HANDLER_H
