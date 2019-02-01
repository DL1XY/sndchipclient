#include "network_handler.h"

NetworkHandler::NetworkHandler(QObject *parent) : QObject(parent)
{

}

void NetworkHandler::initUdp(QString ip, quint16 port)
{
    this->udpHandler = new UdpHandler(this, ip, port);
}
void NetworkHandler::writeCmd(NetworkCmd &cmd)
{
    // just UDP now
    if (udpHandler != nullptr)
    {
        UdpCommand udpCommand;
        memcpy(&udpCommand, &cmd, sizeof(UdpCommand));
        udpHandler->writeData(udpCommand);
     }
}

void NetworkHandler::readCmd()
{
  // this->udpHandler->readData();
}

quint8 NetworkHandler::getNextCmdCounter()
{
    if (cmdCounter < 0xFF)
    {
        ++cmdCounter;
    }
    else {
        cmdCounter = 0;
    }
    return cmdCounter;
}
/*
// COAP
void NetworkHandler::initCoap()
{
    m_coap = new CoapNetworkAccessManager(this);
    m_uploadData = QByteArray(".oO DATA Oo.");
}
*/
