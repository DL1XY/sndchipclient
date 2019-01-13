#ifndef TAB_SAA1099_H
#define TAB_SAA1099_H

#include <QWidget>
#include "ui/saa1099_audiochannel_widget.h"
#include "ui/saa1099_envelope_widget.h"
#include "ui/saa1099_noise_widget.h"
class TabSaa1099 : public QWidget
{
    Q_OBJECT
public:
    explicit TabSaa1099(QWidget *parent = nullptr);

signals:

public slots:
private:
    SAA1099AudioChannelWidget *channels[6];
    SAA1099EnvelopeWidget *env0Widget;
    SAA1099EnvelopeWidget *env1Widget;
    SAA1099NoiseWidget *noiseWidget;
};

#endif // TAB_SAA1099_H
