#include "tab_sn76489.h"
#include <QGridLayout>

TabSN76489::TabSN76489(QWidget *parent) : QWidget(parent)
{
    QGridLayout *layout = new QGridLayout;
    channel1 = new SN76489AudioChannelWidget(nullptr, 1);
    channel2 = new SN76489AudioChannelWidget(nullptr, 2);
    channel3 = new SN76489AudioChannelWidget(nullptr, 3);
    noise = new SN76489NoiseWidget;

    layout->addWidget(channel1, 0, 0, Qt::AlignTop);
    layout->addWidget(channel2, 0, 1, Qt::AlignTop);
    layout->addWidget(channel3, 0, 2, Qt::AlignTop);
    layout->addWidget(noise, 0, 3, Qt::AlignTop);
    this->setLayout(layout);
}
