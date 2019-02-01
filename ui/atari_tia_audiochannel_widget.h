#ifndef ATARI_TIA_AUDIOCHANNEL_WIDGET_H
#define ATARI_TIA_AUDIOCHANNEL_WIDGET_H

#include <QWidget>

#include <QLabel>
#include <QLineEdit>
#include <QPushButton>
#include <qwt_knob.h>
#include "controller/ataritiacontroller.h"

class AtariTiaAudioChannelWidget : public QWidget
{
    Q_OBJECT
public:
    explicit AtariTiaAudioChannelWidget(QWidget *parent = nullptr, qint8 channel = 0);


    void setController(AtariTiaController *value);

public slots:
    void volChanged(double value);
    void freqChanged(double value);
    void ctrlChanged(double value);
    void muteToggle(bool val);
    void soloToggle(bool val);

private:
    void createMuteUi();
    void createSoloUi();
    void createVolumeUi();
    void createFrequencyUi();
    void createControlUi();

    AtariTiaController *controller;

    QwtKnob *dialVolume;
    QwtKnob *dialFrequency;
    QwtKnob *dialControl;
    QLineEdit *ctrlDecText;

    QPushButton *btnMute;
    QPushButton *btnSolo;
    qint8 channel;

    const int KNOB_WIDTH = 90;

    bool isMute = false;
    bool isSolo = false;

};

#endif // ATARI_TIA_AUDIOCHANNEL_WIDGET_H
