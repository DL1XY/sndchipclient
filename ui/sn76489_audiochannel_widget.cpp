#include "sn76489_audiochannel_widget.h"

#include <QGridLayout>
#include <QLabel>
#include "qwt_knob.h"

SN76489AudioChannelWidget::SN76489AudioChannelWidget(QWidget *parent, unsigned int channel) : QWidget(parent)
{
    this->channel = channel;

    QFont fontChannel( "Arial", 16, QFont::Bold);
    QFont fontDesc( "Arial", 6, QFont::Bold);

    QString lblStr = "TONE ";
    lblStr.append(QString::number(channel));
    QLabel *lblTone = new QLabel(lblStr);
    lblTone->setFont(fontChannel);

    QwtKnob *knobFrequency = new QwtKnob(this);
    knobFrequency->setTotalSteps(1023);
    knobFrequency->setSingleSteps(1);
    knobFrequency->setScaleStepSize(1023);
    knobFrequency->setScale(0,1023);
    knobFrequency->setKnobWidth(100);
    knobFrequency->setMarkerSize(QwtKnob::Tick);
    knobFrequency->setKnobStyle(QwtKnob::Sunken);
    knobFrequency->show();

    QwtKnob *knobAttenuation = new QwtKnob(this);
    knobAttenuation->setTotalSteps(4);
    knobAttenuation->setSingleSteps(4);
    knobAttenuation->setScaleStepSize(4);
    knobAttenuation->setScale(0,16);
    knobAttenuation->setKnobWidth(100);
    knobAttenuation->setMarkerSize(QwtKnob::Tick);
    knobAttenuation->setKnobStyle(QwtKnob::Sunken);
    knobAttenuation->show();

    QGridLayout *layout = new QGridLayout;
    layout->addWidget(lblTone,0,0,Qt::AlignHCenter);
    layout->addWidget(knobFrequency,1,0,Qt::AlignHCenter);
    layout->addWidget(knobAttenuation,2,0,Qt::AlignHCenter);
    this->setLayout(layout);
}
