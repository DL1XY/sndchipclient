#ifndef SAA1099_ENVNOISE_WIDGET_H
#define SAA1099_ENVNOISE_WIDGET_H

#include <QWidget>

class SAA1099EnvelopeWidget : public QWidget
{
    Q_OBJECT
public:
    explicit SAA1099EnvelopeWidget(QWidget *parent = nullptr, unsigned int channel=0);

signals:

public slots:

private:
    unsigned int channel;
};

#endif // SAA1099_ENVNOISE_WIDGET_H
