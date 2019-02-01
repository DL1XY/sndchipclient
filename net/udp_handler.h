#ifndef UDP_HANDLER_H
#define UDP_HANDLER_H

#include <QUdpSocket>
#include <QWidget>
#include <QNetworkDatagram>
#define MAX_PAYLOAD 512;

// General UDP Commands 0x00 - 0x0F
#define UDP_CMD_INIT        0x00;
#define UDP_CMD_RESET       0x01;
#define UDP_CMD_GET_STATUS  0x02;



struct UdpCommand
{
    char target;
    char cmdId;
    char dataLength;
    char *data;
    char cmdCounter;
};




class UdpHandler: public QObject {

Q_OBJECT

public:
    explicit UdpHandler(QObject* parent = nullptr, QString ip="127.0.0.1", quint16 port = 7799);

    virtual ~UdpHandler() {
        delete udpSocket;

    }
    void writeData(UdpCommand &cmd);
private:

    QString ip;
    quint16 port;

    // UDP Client
    QUdpSocket* udpSocket;
    void initSocket();
    void processData(UdpCommand &cmd);
public slots:
    void readData();

};

#endif // UDP_HANDLER_H
