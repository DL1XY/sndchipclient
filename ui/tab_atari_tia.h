#ifndef TAB_ATARI_TIA_H
#define TAB_ATARI_TIA_H

#include <QWidget>
#include "ui/atari_tia_audiochannel_widget.h"

class TabAtariTia : public QWidget
{
    Q_OBJECT
public:
    explicit TabAtariTia(QWidget *parent = nullptr);

signals:

public slots:

private:

    AtariTiaAudioChannelWidget* widgetAUD0;
    AtariTiaAudioChannelWidget* widgetAUD1;

};

#endif // TAB_ATARI_TIA_H
