#include "udp_handler.h"

UdpHandler::UdpHandler(QObject* parent, QString ip, quint16 port)
    : QObject(parent), ip(ip), port(port){

    this->initSocket();
}

// UDP
void UdpHandler::initSocket()
{
    udpSocket = new QUdpSocket(this);
    udpSocket->bind(QHostAddress(ip), port);

    connect(udpSocket, SIGNAL(readyRead()), this, SLOT(readData()));

}

void UdpHandler::readData()
{
    while (udpSocket->hasPendingDatagrams()) {
            QNetworkDatagram datagram = udpSocket->receiveDatagram();
            UdpCommand cmd;
            QByteArray data = datagram.data();
            memcpy(&cmd, data, sizeof(data));
            processData(cmd);
        }
}

void UdpHandler::writeData(UdpCommand &cmd)
{
    char buffer[sizeof(cmd)];
    memcpy(buffer, &cmd, sizeof(cmd));
    udpSocket->writeDatagram(QNetworkDatagram(buffer));
}

void UdpHandler::processData(UdpCommand &cmd)
{
    // TODO
}

