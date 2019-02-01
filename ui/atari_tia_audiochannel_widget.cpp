#include "atari_tia_audiochannel_widget.h"
#include <QGridLayout>
#include <QPushButton>
#include "controller/ataritiacontroller.h"

AtariTiaAudioChannelWidget::AtariTiaAudioChannelWidget(QWidget *parent, qint8 channel) : QWidget(parent)
{
    this->channel = channel;

    createVolumeUi();
    createFrequencyUi();
    createControlUi();
    createMuteUi();
    createSoloUi();

    QString lblStr = "AUD";
    lblStr.append(QString::number(channel));

    QLabel *lbl = new QLabel(lblStr);
    lbl->setAlignment(Qt::AlignCenter);

    ctrlDecText = new QLineEdit("                    ");
    ctrlDecText->setReadOnly(true);
    ctrlDecText->setAlignment(Qt::AlignHCenter);
    ctrlDecText->setMinimumWidth(250);
    ctrlDecText->setText(ATARI_TIA_AUDC_Descriptions[0]);

    QLabel *lblVol = new QLabel("VOL");
    QLabel *lblFreq = new QLabel("FREQ");
    QLabel *lblCtrl = new QLabel("CTRL");

    QGridLayout *layout = new QGridLayout;
    int descX = 0;
    int knobX = 1;

    if (channel == 0)
    {
       lblVol->setAlignment(Qt::AlignRight|Qt::AlignCenter);
       lblFreq->setAlignment(Qt::AlignRight|Qt::AlignCenter);
       lblCtrl->setAlignment(Qt::AlignRight|Qt::AlignCenter);
    }
    else
    {
        descX = 1;
        knobX = 0;
    }
    layout->addWidget(lbl, 0, knobX);
    layout->addWidget(dialVolume, 1, knobX );
    layout->addWidget(lblVol,1,descX);

    layout->addWidget(dialFrequency, 2, knobX);
    layout->addWidget(lblFreq, 2, descX);

    layout->addWidget(dialControl, 3, knobX);
    layout->addWidget(lblCtrl, 3, descX);

    layout->addWidget(ctrlDecText, 4, knobX, Qt::AlignHCenter);
    layout->addWidget(btnMute, 5, knobX, Qt::AlignHCenter);
    layout->addWidget(btnSolo, 6, knobX, Qt::AlignHCenter);
    this->setLayout(layout);

    connect(dialVolume, SIGNAL(valueChanged(double)), this, SLOT(volChanged(double)));
    connect(dialFrequency, SIGNAL(valueChanged(double)), this, SLOT(freqChanged(double)));
    connect(dialControl, SIGNAL(valueChanged(double)), this, SLOT(ctrlChanged(double)));

    connect(btnMute, SIGNAL(toggled(bool)), this, SLOT(muteToggle(bool)));
    connect(btnSolo, SIGNAL(toggled(bool)), this, SLOT(soloToggle(bool)));
}

void AtariTiaAudioChannelWidget::createVolumeUi()
{

    dialVolume = new QwtKnob(this);
    dialVolume->setTotalSteps(15);
    dialVolume->setSingleSteps(1);
    dialVolume->setScaleStepSize(1);
    dialVolume->setScale(0,15);
    dialVolume->setKnobWidth(KNOB_WIDTH);
    dialVolume->setMarkerSize(QwtKnob::Tick);
    dialVolume->setKnobStyle(QwtKnob::Sunken);
    dialVolume->show();

}

void AtariTiaAudioChannelWidget::createFrequencyUi()
{
    dialFrequency = new QwtKnob(this);
    dialFrequency->setTotalSteps(31);
    dialFrequency->setSingleSteps(1);
    dialFrequency->setScaleStepSize(2);
    dialFrequency->setScale(0,31);
    dialFrequency->setKnobWidth(KNOB_WIDTH);
    dialFrequency->setMarkerSize(QwtKnob::Tick);
    dialFrequency->setKnobStyle(QwtKnob::Sunken);
    dialFrequency->show();
}

void AtariTiaAudioChannelWidget::createControlUi()
{
    dialControl = new QwtKnob(this);
    dialControl->setTotalSteps(15);
    dialControl->setSingleSteps(1);
    dialControl->setScaleStepSize(1);
    dialControl->setScale(0,15);
    dialControl->setKnobWidth(KNOB_WIDTH);
    dialControl->setMarkerSize(QwtKnob::Tick);
    dialControl->setKnobStyle(QwtKnob::Sunken);
    dialControl->show();
}

void AtariTiaAudioChannelWidget::setController(AtariTiaController *value)
{
    controller = value;
}

void AtariTiaAudioChannelWidget::volChanged(double value)
{
    controller->changeVolume(channel, static_cast<char>(value));
}

void AtariTiaAudioChannelWidget::freqChanged(double value)
{
    controller->changeFrequency(channel, static_cast<char>(value));
}

void AtariTiaAudioChannelWidget::ctrlChanged(double value)
{
    ctrlDecText->setText(ATARI_TIA_AUDC_Descriptions[static_cast<int>(value)]);
    controller->changeControl(channel, static_cast<char>(value));
}

void AtariTiaAudioChannelWidget::createMuteUi()
{
    btnMute = new QPushButton("MUTE");
    btnMute->setCheckable(true);
    btnMute->setMaximumSize(100,100);
    QPalette palMute = btnMute->palette();
    palMute.setColor(QPalette::Button, QColor(Qt::blue));
    btnMute->setAutoFillBackground(true);
    btnMute->setPalette(palMute);
    btnMute->update();

}

void AtariTiaAudioChannelWidget::createSoloUi()
{
    btnSolo = new QPushButton("SOLO");
    btnSolo->setCheckable(true);
    btnSolo->setMaximumSize(100,100);
    QPalette palSolo = btnMute->palette();
    palSolo.setColor(QPalette::Button, QColor(Qt::yellow));
    btnSolo->setAutoFillBackground(true);
    btnSolo->setPalette(palSolo);
    btnSolo->update();
}

void AtariTiaAudioChannelWidget::muteToggle(bool val)
{
    isMute = val;
    // TODO
}

void AtariTiaAudioChannelWidget::soloToggle(bool val)
{
    isSolo = val;
    controller->setStereo(val);
}
