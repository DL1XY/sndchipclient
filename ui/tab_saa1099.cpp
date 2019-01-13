#include "ui/tab_saa1099.h"
#include <QGridLayout>
TabSaa1099::TabSaa1099(QWidget *parent) : QWidget(parent)
{
    QGridLayout *layout = new QGridLayout;

    for(int i=0; i < 6; i++)
    {
        channels[i] = new SAA1099AudioChannelWidget(this, (unsigned int)i);
        layout->addWidget(channels[i], 0, i, 4, 1);
    }
    env0Widget = new SAA1099EnvelopeWidget(nullptr,0);
    layout->addWidget(env0Widget, 0, 6, 3, 1);
    env1Widget = new SAA1099EnvelopeWidget(nullptr,1);
    layout->addWidget(env1Widget, 0, 7, 3, 1);
    noiseWidget = new SAA1099NoiseWidget;
    layout->addWidget(noiseWidget, 3, 6, 1, 2, Qt::AlignHCenter);

    this->setLayout(layout);
}
