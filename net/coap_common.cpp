#include "coap_common.h"

CoapCommon::CoapCommon(QObject *parent) : QObject(parent)
{
    m_coap = new CoapNetworkAccessManager(this);
}


CoapReply* CoapCommon::get(QUrl &url)
{
    CoapRequest request(url);
    qDebug() << request.url().toString();

    QSignalSpy spy(m_coap, SIGNAL(replyFinished(CoapReply*)));
    CoapReply *reply = m_coap->get(request);
    spy.wait(10000);

    qDebug() << reply;

    return reply;
}

CoapReply* CoapCommon::put(QUrl &url)
{
    CoapRequest request(url);
    qDebug() << request.url().toString();

    QSignalSpy spy(m_coap, SIGNAL(replyFinished(CoapReply*)));
    CoapReply *reply = m_coap->put(request);
    spy.wait(10000);

    qDebug() << reply;

    return reply;
}

CoapReply* CoapCommon::post(QUrl &url)
{
    CoapRequest request(url);
    qDebug() << request.url().toString();

    QSignalSpy spy(m_coap, SIGNAL(replyFinished(CoapReply*)));
    CoapReply *reply = m_coap->post(request);
    spy.wait(10000);

    qDebug() << reply;

    return reply;
}

CoapReply* CoapCommon::del(QUrl &url)
{
    CoapRequest request(url);
    qDebug() << request.url().toString();

    QSignalSpy spy(m_coap, SIGNAL(replyFinished(CoapReply*)));
    CoapReply *reply = m_coap->deleteResource(request);
    spy.wait(10000);

    qDebug() << reply;

    return reply;
}
