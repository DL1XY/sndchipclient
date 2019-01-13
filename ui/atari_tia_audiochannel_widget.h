#ifndef ATARI_TIA_AUDIOCHANNEL_WIDGET_H
#define ATARI_TIA_AUDIOCHANNEL_WIDGET_H

#include <QWidget>

#include <QLabel>
#include <QLineEdit>
#include <QPushButton>
#include <qwt_knob.h>
class AtariTiaAudioChannelWidget : public QWidget
{
    Q_OBJECT
public:
    explicit AtariTiaAudioChannelWidget(QWidget *parent = nullptr, unsigned int channel = 0);


public slots:
    void volChanged(double value);
    void freqChanged(double value);
    void ctrlChanged(double value);
    void muteToggle(bool val);
    void soloToggle(bool val);
private:
    void createMute();
    void createSolo();
    void createVolume();
    void createFrequency();
    void createControl();


    QwtKnob *dialVolume;
    QwtKnob *dialFrequency;
    QwtKnob *dialControl;
    QLineEdit *ctrlDecText;

    QPushButton *btnMute;
    QPushButton *btnSolo;
    unsigned int channel;

    const int KNOB_WIDTH = 90;

    bool isMute = false;
    bool isSolo = false;

};

#endif // ATARI_TIA_AUDIOCHANNEL_WIDGET_H
