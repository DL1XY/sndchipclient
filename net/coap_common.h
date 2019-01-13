#ifndef COAPCOMMANDS_H
#define COAPCOMMANDS_H
#include <QSignalSpy>
#include "coapnetworkaccessmanager.h"
class CoapCommon: public QObject
{
    Q_OBJECT

public:
    explicit CoapCommon(QObject *parent = nullptr);

    virtual ~CoapCommon()
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
#endif // COAPCOMMANDS_H
