#include "coap_handler.h"

CoapHandler::CoapHandler(QObject *parent) : QObject(parent)
{
    m_coap = new CoapNetworkAccessManager(this);
}


CoapReply* CoapHandler::get(QUrl &url)
{
    CoapRequest request(url);
    qDebug() << request.url().toString();

    QSignalSpy spy(m_coap, SIGNAL(replyFinished(CoapReply*)));
    CoapReply *reply = m_coap->get(request);
    spy.wait(10000);

    qDebug() << reply;

    return reply;
}

CoapReply* CoapHandler::put(QUrl &url)
{
    CoapRequest request(url);
    qDebug() << request.url().toString();

    QSignalSpy spy(m_coap, SIGNAL(replyFinished(CoapReply*)));
    CoapReply *reply = m_coap->put(request);
    spy.wait(10000);

    qDebug() << reply;

    return reply;
}

CoapReply* CoapHandler::post(QUrl &url)
{
    CoapRequest request(url);
    qDebug() << request.url().toString();

    QSignalSpy spy(m_coap, SIGNAL(replyFinished(CoapReply*)));
    CoapReply *reply = m_coap->post(request);
    spy.wait(10000);

    qDebug() << reply;

    return reply;
}

CoapReply* CoapHandler::del(QUrl &url)
{
    CoapRequest request(url);
    qDebug() << request.url().toString();

    QSignalSpy spy(m_coap, SIGNAL(replyFinished(CoapReply*)));
    CoapReply *reply = m_coap->deleteResource(request);
    spy.wait(10000);

    qDebug() << reply;

    return reply;
}
