#ifndef SAA1099_AUDIOCHANNEL_WIDGET_H
#define SAA1099_AUDIOCHANNEL_WIDGET_H

#include <QWidget>
#include <QPushButton>
#include <QLabel>
#include <qwt_knob.h>
class SAA1099AudioChannelWidget: public QWidget
{
    Q_OBJECT
public:
    explicit SAA1099AudioChannelWidget(QWidget *parent = nullptr, unsigned int channel = 0);

public slots:

    void amplitudeCh0Changed(double value);
    void amplitudeCh1Changed(double value);
    void freqChanged(double value);
    void octaveChanged(double value);

    void env1Toggle(bool val);
    void env2Toggle(bool val);
    void noiseToggle(bool val);

    void muteToggle(bool val);
    void soloToggle(bool val);

private:
    void createAmplitude();
    void createOctave();
    void createFrequency();
    void createEnvAndNoise();
    void createSolo();
    void createMute();

    QwtKnob *ampCh0Knob;
    QwtKnob *ampCh1Knob;
    QwtKnob *octaveKnob;
    QwtKnob *freqKnob;

    QPushButton *btnEnv1;
    QPushButton *btnEnv2;
    QPushButton *btnNoise;

    QPushButton *btnMute;
    QPushButton *btnSolo;

    unsigned int channel;

    bool isMute = false;
    bool isSolo = false;

    bool isEnv1 = false;
    bool isEnv2 = false;
    bool isNoise = false;
};

#endif // SAA1099_AUDIOCHANNEL_WIDGET_H
