#ifndef TAB_SN76489_H
#define TAB_SN76489_H

#include <QWidget>
#include "ui/sn76489_audiochannel_widget.h"
#include "ui/sn76489_noise_widget.h"

class TabSN76489 : public QWidget
{
    Q_OBJECT
public:
    explicit TabSN76489(QWidget *parent = nullptr);

signals:

public slots:


private:
    SN76489AudioChannelWidget *channel1;
    SN76489AudioChannelWidget *channel2;
    SN76489AudioChannelWidget *channel3;
    SN76489NoiseWidget *noise;
};

#endif // TAB_SN76489_H
