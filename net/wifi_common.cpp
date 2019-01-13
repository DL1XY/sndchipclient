#include "wifi_common.h"

WifiCommon::WifiCommon(QWidget* parent)
    : QWidget(parent) {


}

// UDP
void WifiCommon::initSocket()
{
    udpSocket = new QUdpSocket(this);
    udpSocket->bind(QHostAddress::LocalHost, 7755);
}

void WifiCommon::readPendingDatagrams()
{

}


// COAP
void WifiCommon::initCoap()
{
    m_coap = new CoapNetworkAccessManager(this);
    m_uploadData = QByteArray(".oO DATA Oo.");
}
