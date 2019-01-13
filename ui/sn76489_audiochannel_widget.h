#ifndef SN76489_AUDIOCHANNEL_WIDGET_H
#define SN76489_AUDIOCHANNEL_WIDGET_H

#include <QWidget>

class SN76489AudioChannelWidget : public QWidget
{
    Q_OBJECT
public:
    explicit SN76489AudioChannelWidget(QWidget *parent = nullptr, unsigned int channel=0);

signals:

public slots:
private:
    unsigned int channel;
};

#endif // SN76489_AUDIOCHANNEL_WIDGET_H
