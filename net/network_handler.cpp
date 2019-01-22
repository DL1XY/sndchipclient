#include "network_handler.h"

NetworkHandler::NetworkHandler(QWidget* parent)
    : QWidget(parent) {

    this->coapHandler = new CoapHandler(this);
}
/*
// UDP
void NetworkHandler::initSocket()
{
    udpSocket = new QUdpSocket(this);
    udpSocket->bind(QHostAddress::LocalHost, 7755);
}

void NetworkHandler::readPendingDatagrams()
{

}


// COAP
void NetworkHandler::initCoap()
{
    m_coap = new CoapNetworkAccessManager(this);
    m_uploadData = QByteArray(".oO DATA Oo.");
}
*/
