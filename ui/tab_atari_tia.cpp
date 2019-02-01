#include "tab_atari_tia.h"
#include <QGridLayout>

TabAtariTia::TabAtariTia(QWidget *parent) : QWidget(parent)
{
    QLabel *lblFunc       = new QLabel("FUNCTION");
    QLabel *lblVolume       = new QLabel("VOLUME");
    QLabel *lblFrequency    = new QLabel("FREQUENCY");
    QLabel *lblControl      = new QLabel("CONTROL");

    lblFunc->setAlignment(Qt::AlignTop);
    lblVolume->setAlignment(Qt::AlignTop);
    lblFrequency->setAlignment(Qt::AlignTop);
    lblControl->setAlignment(Qt::AlignTop);

    QWidget *widget = new QWidget(this);
    QGridLayout *layoutFunc = new QGridLayout;
    layoutFunc->addWidget(lblFunc, 0, 0);
    layoutFunc->addWidget(lblVolume, 1, 0);
    layoutFunc->addWidget(lblFrequency, 2, 0);
    layoutFunc->addWidget(lblControl, 3, 0);
    widget->setLayout(layoutFunc);

    widgetAUD0 = new AtariTiaAudioChannelWidget (this, 0);
    widgetAUD1 = new AtariTiaAudioChannelWidget (this, 1);

    QGridLayout *layout = new QGridLayout;

   // QVBoxLayout *mainLayout = new QVBoxLayout;

    layout->addWidget(widgetAUD0, 0, 1);
    //layout->addWidget(widget, 0, 2);
    layout->addWidget(widgetAUD1, 0, 2);
    this->setLayout(layout);
}

AtariTiaAudioChannelWidget *TabAtariTia::getWidgetAUD0() const
{
    return widgetAUD0;
}

AtariTiaAudioChannelWidget *TabAtariTia::getWidgetAUD1() const
{
    return widgetAUD1;
}
