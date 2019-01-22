#ifndef COAP_HANDLER_H
#define COAP_HANDLER_H
#include <QSignalSpy>
#include "coapnetworkaccessmanager.h"
class CoapHandler: public QObject
{
    Q_OBJECT

public:
    explicit CoapHandler(QObject *parent = nullptr);

    virtual ~CoapHandler()
    {
        delete m_coap;
    }
private:
    CoapNetworkAccessManager *m_coap;
    QByteArray m_uploadData;

private slots:
    CoapReply* get(QUrl &url);
    CoapReply* put(QUrl &url);
    CoapReply* post(QUrl &url);
    CoapReply* del(QUrl &url);
};
#endif // COAP_HANDLER_H
