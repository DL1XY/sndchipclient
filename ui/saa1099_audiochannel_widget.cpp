#include "saa1099_audiochannel_widget.h"
#include <QGridLayout>


SAA1099AudioChannelWidget::SAA1099AudioChannelWidget(QWidget *parent, unsigned int channel) : QWidget(parent)
{
    this->channel = channel;

    createAmplitude();
    createOctave();
    createFrequency();
    createEnvAndNoise();
    createMute();
    createSolo();


    QString lblStr = "CH#";
    lblStr.append(QString::number(channel));

    QFont fontChannel( "Arial", 16, QFont::Bold);
    QFont fontDesc( "Arial", 8, QFont::Bold);

    // btn fonts
    ampCh0Knob->setFont(fontDesc);
    ampCh1Knob->setFont(fontDesc);
    QLabel *lbl = new QLabel(lblStr);
    lbl->setAlignment(Qt::AlignCenter);
    lbl->setFont(fontChannel);

    QLabel *lblAmp = new QLabel("AMPLITUDE");
    lblAmp->setAlignment(Qt::AlignCenter);
    lblAmp->setFont(fontDesc);

    QLabel *lblOctave = new QLabel("OCTAVE");
    lblOctave->setAlignment(Qt::AlignCenter);
    lblOctave->setFont(fontDesc);

    QLabel *lblFreq = new QLabel("FREQUENCY");
    lblFreq->setAlignment(Qt::AlignCenter);
    lblFreq->setFont(fontDesc);

    QGridLayout *layout = new QGridLayout;
    layout->addWidget(lbl, 0, 0, 1, 2);
    layout->addWidget(lblAmp, 1, 0, 1, 2);

    layout->addWidget(ampCh0Knob, 2, 0, 1, 1);
    layout->addWidget(ampCh1Knob, 2, 1, 1, 1);

    layout->addWidget(lblOctave, 3, 0, 1, 2);
    layout->addWidget(octaveKnob, 4, 0, 1, 2, Qt::AlignHCenter);

    layout->addWidget(lblFreq, 5,0, 1, 2);
    layout->addWidget(freqKnob, 6, 0, 1, 2, Qt::AlignHCenter);

    layout->addWidget(btnEnv1, 7, 0, 1, 2, Qt::AlignHCenter);
    layout->addWidget(btnEnv2, 8, 0, 1, 2, Qt::AlignHCenter);
    layout->addWidget(btnNoise, 9, 0, 1, 2, Qt::AlignHCenter);

    layout->addWidget(btnMute, 10, 0, 1, 2, Qt::AlignHCenter);
    layout->addWidget(btnSolo, 11, 0, 1, 2, Qt::AlignHCenter);
    this->setLayout(layout);
}

void SAA1099AudioChannelWidget::createAmplitude()
{
    ampCh0Knob = new QwtKnob(this);
    ampCh0Knob->setTotalSteps(15);
    ampCh0Knob->setSingleSteps(1);
    ampCh0Knob->setScaleStepSize(15);
    ampCh0Knob->setScale(0,15);
    ampCh0Knob->setKnobWidth(30);
    ampCh0Knob->setMarkerSize(QwtKnob::Tick);
    ampCh0Knob->setKnobStyle(QwtKnob::Sunken);
    ampCh0Knob->show();

    ampCh1Knob = new QwtKnob(this);
    ampCh1Knob->setTotalSteps(15);
    ampCh1Knob->setSingleSteps(1);
    ampCh1Knob->setScaleStepSize(15);
    ampCh1Knob->setScale(0,15);
    ampCh1Knob->setKnobWidth(30);
    ampCh1Knob->setMarkerSize(QwtKnob::Tick);
    ampCh1Knob->setKnobStyle(QwtKnob::Sunken);
    ampCh1Knob->show();
}

void SAA1099AudioChannelWidget::createOctave()
{
    octaveKnob = new QwtKnob(this);
    octaveKnob->setTotalSteps(7);
    octaveKnob->setSingleSteps(1);
    octaveKnob->setScaleStepSize(7);
    octaveKnob->setScale(0,7);
    octaveKnob->setKnobWidth(60);
    octaveKnob->setMarkerSize(QwtKnob::Tick);
    octaveKnob->setKnobStyle(QwtKnob::Sunken);

    octaveKnob->show();
}

void SAA1099AudioChannelWidget::createFrequency()
{
    freqKnob = new QwtKnob(this);
    freqKnob->setTotalSteps(255);
    freqKnob->setSingleSteps(1);
    freqKnob->setScaleStepSize(255);
    freqKnob->setScale(0,255);
    freqKnob->setKnobWidth(100);
    freqKnob->setMarkerSize(QwtKnob::Tick);
    freqKnob->setKnobStyle(QwtKnob::Sunken);
    freqKnob->show();
}

void SAA1099AudioChannelWidget::createEnvAndNoise()
{
    btnEnv1 = new QPushButton("ENV 1");
    btnEnv1->setCheckable(true);
    btnEnv1->setMaximumSize(100,20);
    btnEnv1->setAutoFillBackground(true);

    QPalette palEnv = btnEnv1->palette();
    palEnv.setColor(QPalette::Button, QColor(Qt::darkGray));

    btnEnv1->setPalette(palEnv);
    btnEnv1->update();

    btnEnv2 = new QPushButton("ENV 2");
    btnEnv2->setCheckable(true);
    btnEnv2->setMaximumSize(100,20);
    btnEnv2->setAutoFillBackground(true);
    btnEnv2->setPalette(palEnv);
    btnEnv2->update();

    QPalette palNoise = btnEnv1->palette();
    palNoise.setColor(QPalette::Button, QColor(Qt::white));
    btnNoise = new QPushButton("NOISE");
    btnNoise->setCheckable(true);
    btnNoise->setMaximumSize(100,20);
    btnNoise->setAutoFillBackground(true);
    btnNoise->setPalette(palNoise);
    btnNoise->update();
}

void SAA1099AudioChannelWidget::createMute()
{
    btnMute = new QPushButton("MUTE");
    btnMute->setCheckable(true);
    btnMute->setMaximumSize(100,20);
    QPalette palMute = btnMute->palette();
    palMute.setColor(QPalette::Button, QColor(Qt::blue));
    btnMute->setAutoFillBackground(true);
    btnMute->setPalette(palMute);
    btnMute->update();

}

void SAA1099AudioChannelWidget::createSolo()
{
    btnSolo = new QPushButton("SOLO");
    btnSolo->setCheckable(true);
    btnSolo->setMaximumSize(100,20);
    QPalette palSolo = btnMute->palette();
    palSolo.setColor(QPalette::Button, QColor(Qt::yellow));
    btnSolo->setAutoFillBackground(true);
    btnSolo->setPalette(palSolo);
    btnSolo->update();
}
void SAA1099AudioChannelWidget::amplitudeCh0Changed(double value)
{

}

void SAA1099AudioChannelWidget::amplitudeCh1Changed(double value)
{}

void SAA1099AudioChannelWidget::freqChanged(double value)
{}

void SAA1099AudioChannelWidget::octaveChanged(double value)
{}

void SAA1099AudioChannelWidget::env1Toggle(bool val)
{
    isEnv1 = val;
}

void SAA1099AudioChannelWidget::env2Toggle(bool val)
{
    isEnv2 = val;
}

void SAA1099AudioChannelWidget::noiseToggle(bool val)
{
    isNoise = val;
}
void SAA1099AudioChannelWidget::muteToggle(bool val)
{
    isMute = val;
}


void SAA1099AudioChannelWidget::soloToggle(bool val)
{
    isSolo = val;
}
