#include "saa1099_envelope_widget.h"
#include <QGridLayout>
#include <QLabel>
#include <QSlider>
#include <QButtonGroup>
#include <QPushButton>
SAA1099EnvelopeWidget::SAA1099EnvelopeWidget(QWidget *parent, unsigned int channel) : QWidget(parent)
{
    this->channel = channel;
    QFont fontChannel( "Arial", 16, QFont::Bold);
    QFont fontHeader( "Arial", 8, QFont::Bold);
    QFont fontBtn( "Arial", 6, QFont::Bold);

    QButtonGroup *btnGroupChannelEnv = new QButtonGroup;
    QPushButton *btnEnvLR = new QPushButton ("R=L");
    QPushButton *btnEnvLRInv = new QPushButton ("R=~L");
    btnEnvLR->setCheckable(true);
    btnEnvLRInv->setCheckable(true);
    btnEnvLR->setFont(fontBtn);
    btnEnvLRInv->setFont(fontBtn);
    btnGroupChannelEnv->addButton(btnEnvLR);
    btnGroupChannelEnv->addButton(btnEnvLRInv);

    QButtonGroup *btnGroupBits = new QButtonGroup;
    QPushButton *btnEnv4bits = new QPushButton ("4 BITS");
    QPushButton *btnEnv3bits = new QPushButton ("3 BITS");
    btnEnv4bits->setCheckable(true);
    btnEnv3bits->setCheckable(true);
    btnEnv4bits->setFont(fontBtn);
    btnEnv3bits->setFont(fontBtn);
    btnGroupBits->addButton(btnEnv4bits);
    btnGroupBits->addButton(btnEnv3bits);

    QButtonGroup *btnGroupClock = new QButtonGroup;
    QPushButton *btnEnvClockInt = new QPushButton ("INTERNAL");
    QPushButton *btnEnvClockExt = new QPushButton ("EXTERNAL");
    btnEnvClockInt->setCheckable(true);
    btnEnvClockExt->setCheckable(true);
    btnEnvClockInt->setFont(fontBtn);
    btnEnvClockExt->setFont(fontBtn);
    btnGroupClock->addButton(btnEnvClockInt);
    btnGroupClock->addButton(btnEnvClockExt);


    QButtonGroup *btnGroupReset = new QButtonGroup;
    QPushButton *btnEnvReset = new QPushButton ("RESET");
    QPushButton *btnEnvEnable = new QPushButton ("ENABLE");
    btnEnvReset->setCheckable(true);
    btnEnvEnable->setCheckable(true);
    btnEnvReset->setFont(fontBtn);
    btnEnvEnable->setFont(fontBtn);
    btnGroupReset->addButton(btnEnvReset);
    btnGroupReset->addButton(btnEnvEnable);

    QButtonGroup *btnGroupMode = new QButtonGroup;
    QPushButton *btnModeZeroAmp = new QPushButton ("0 AMPLTD");
    QPushButton *btnModeMaxAmp = new QPushButton ("MAX AMPLTD");

    QPushButton *btnModeSingleDecay = new QPushButton ("SNGL DECAY");
    QPushButton *btnModeRepDecay= new QPushButton ("RPTV DECAY");

    QPushButton *btnModeSingleTriangle = new QPushButton ("SNGL TRNGL");
    QPushButton *btnModeRepTriangle = new QPushButton ("RPTV TRNGL");

    QPushButton *btnModeSingleAttack = new QPushButton ("SNGL ATTACK");
    QPushButton *btnModeRepAttack = new QPushButton ("RPTV ATTACK");

    btnModeZeroAmp->setCheckable(true);
    btnModeMaxAmp->setCheckable(true);
    btnModeSingleDecay->setCheckable(true);
    btnModeRepDecay->setCheckable(true);
    btnModeSingleTriangle->setCheckable(true);
    btnModeRepTriangle->setCheckable(true);
    btnModeSingleAttack->setCheckable(true);
    btnModeRepAttack->setCheckable(true);

    btnModeZeroAmp->setFont(fontBtn);
    btnModeMaxAmp->setFont(fontBtn);
    btnModeSingleDecay->setFont(fontBtn);
    btnModeRepDecay->setFont(fontBtn);
    btnModeSingleTriangle->setFont(fontBtn);
    btnModeRepTriangle->setFont(fontBtn);
    btnModeSingleAttack->setFont(fontBtn);
    btnModeRepAttack->setFont(fontBtn);

    btnGroupMode->addButton(btnModeZeroAmp);
    btnGroupMode->addButton(btnModeMaxAmp);
    btnGroupMode->addButton(btnModeSingleDecay);
    btnGroupMode->addButton(btnModeRepDecay);
    btnGroupMode->addButton(btnModeSingleTriangle);
    btnGroupMode->addButton(btnModeRepTriangle);
    btnGroupMode->addButton(btnModeSingleAttack);
    btnGroupMode->addButton(btnModeRepAttack);



    QGridLayout *layout = new QGridLayout;

    QString channelStr = QString("ENV CH#");
    channelStr.append(QString::number((int)channel));

    QLabel *lblChannel = new QLabel(channelStr);
    lblChannel->setFont(fontChannel);
    layout->addWidget(lblChannel, 0, 0, 1, 2, Qt::AlignHCenter);

    QLabel *lblEnvLR = new QLabel("L/R ENVELOP");
    lblEnvLR->setFont(fontHeader);
    layout->addWidget(lblEnvLR, 1, 0, 1, 2, Qt::AlignHCenter);
    layout->addWidget(btnEnvLR, 2,0);
    layout->addWidget(btnEnvLRInv, 2,1);

    QLabel *lblEnvBit = new QLabel("BIT RESOLUTION");
    lblEnvBit->setFont(fontHeader);
    layout->addWidget(lblEnvBit, 3, 0, 1, 2, Qt::AlignHCenter);
    layout->addWidget(btnEnv4bits,4,0);
    layout->addWidget(btnEnv3bits,4,1);

    QLabel *lblEnvClock = new QLabel("CLOCK");
    lblEnvClock->setFont(fontHeader);
    layout->addWidget(lblEnvClock, 5, 0, 1, 2, Qt::AlignHCenter);
    layout->addWidget(btnEnvClockInt,6,0);
    layout->addWidget(btnEnvClockExt,6,1);

    QLabel *lblEnvOnOff = new QLabel("ENVELOPE ON/OFF");
    lblEnvOnOff->setFont(fontHeader);
    layout->addWidget(lblEnvOnOff, 7, 0, 1, 2, Qt::AlignHCenter);
    layout->addWidget(btnEnvReset,8,0);
    layout->addWidget(btnEnvEnable,8,1);

    QLabel *lblEnvMode = new QLabel("ENVELOPE MODE");
    lblEnvMode->setFont(fontHeader);
    layout->addWidget(lblEnvMode, 9, 0, 1, 2, Qt::AlignHCenter);
    layout->addWidget(btnModeZeroAmp,10,0);
    layout->addWidget(btnModeMaxAmp,10,1);
    layout->addWidget(btnModeSingleDecay,11,0);
    layout->addWidget(btnModeRepDecay,11,1);
    layout->addWidget(btnModeSingleTriangle,12,0);
    layout->addWidget(btnModeRepTriangle,12,1);
    layout->addWidget(btnModeSingleAttack,13,0);
    layout->addWidget(btnModeRepAttack,13,1);


    this->setLayout(layout);
}
